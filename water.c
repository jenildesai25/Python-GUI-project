#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    printf("Enter the minutes you want for shower");
    int i = get_int();
    int j = i * 12 ; 
    printf("this is ammount of bottels you need %d\n",j);

}