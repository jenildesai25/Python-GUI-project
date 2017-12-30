/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
//int dash_index_i;
//int dash_index_j;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
{
    // This is the variable total that I have taken to initialize d * d array
    //and total takes 1 less that number than d * d.
    int total = d*d;
    //This for loops set the d * d array numbers but it did not print it.
    for(int i = 0 ; i < d ; i++)
    {
        for(int j = 0 ; j < d ; j++)
        {
            //This line helps to set the board[i][j] to appropriate numbers.
            //The --total decrenebts 1 first and then set it to board variables.
            board[i][j] = --total;
        }
    }

    //If board has even dimension we change the way of the output variable like in the image of pset 3.
    if( (d * d) % 2 == 0)
    {
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;

    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // Here we prints the d * d array and when it gets to 0 we prints it with a dash otherwise we prints it with the number.
    for(int i = 0 ; i < d ; i++)
    {
        for(int j = 0 ; j < d ; j++)
        {
            if(board[i][j] == 0)
            {
                printf("  _");
            }
            else
            {
                printf("%3i" , board[i][j]);
            }

        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
{
    // if user input invalid numbers then I will return false and a message to try again later.
    if(tile < 1 || tile > (d * d) - 1)
    {
        return false;
    }

    int row = 0;
    int column = 0;
    //Here I have taken 2 for loops to find the location of the tile.
    for(int i = 0 ; i < d ; i++)
    {
        for(int j = 0 ; j < d ; j++)
        {
            if(board[i][j] == tile)
            {
                row = i;
                column = j;
            }
        }
    }

    //write 4 cases for above , below , left and right.
    if(row + 1 < d && board[row + 1][column] == 0)
    {
        board[row + 1][column] = board[row][column];
        board[row][column] = 0;
        return true;
    }
    else if(row - 1 >= 0 && board[row - 1][column] == 0)
    {
            board[row - 1][column] = board[row][column];
            board[row][column] = 0;
            return true;
    }
    else if(column + 1 < d && board[row][column + 1] == 0){
        board[row][column + 1] = board[row][column];
        board[row][column] = 0;
        return true;

    }
    else if(column - 1 >= 0 && board[row][column - 1]==0)
    {
        board[row][column - 1] = board[row][column];
        board[row][column] = 0;
        return true;

    }
    else{
        return false;
    }

}


/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
{
    // TODO
    int counter = 0;

    // Check each tile to ensure it's in order
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            // Check if last spot and if not correct value
            if (++counter != (d * d) && board[i][j] != counter)
            {
                return false;
            }
        }
    }
    return true;
}