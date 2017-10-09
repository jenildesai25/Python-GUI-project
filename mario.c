#include<cs50.h>
#include<stdio.h>

int main(void){
    int n;
    do{
        n = get_int();
    }while(n > 0 && n >=23);
    for (int k=0;k<n;k++)
    {
        for(int i = 0; i < n-1-k ; i++)
        {
            printf(" ");
        }
            for(int j = 0 ; j < n-(n-2)+k ; j++)
            {
                printf("#");
            }
    printf("\n");
    }
}