#include<cs50.h>
#include<stdio.h>

int main(void){
    int n;
    
    do{
        printf("height ");
        n = get_int();
        
    }while(n > 0 && n >=23);
    
    for(int i=0 ; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i ; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < n - (n-1) + i;k++)
        {
            printf("#");
        }
        
        for(int j = 0; j < 3  ; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < n - (n-1) + i;k++)
        {
            printf("#");
        }
        printf("\n");
        
        
        
    }
    
}