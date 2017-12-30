#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void){
    float input;
    do{
         printf("Enter the amount you want to make a change\n");      
         input = get_float();     
        }
    while(input < 0);
    
    int numberOfCoins = 0;
    input = input *100;
    
    while(input >=25){
        input = input / 25;
        numberOfCoins = numberOfCoins + input;
        //input = input % 25;
        
    }
    
    while(input >= 10)
    {
        input = input / 10;
        numberOfCoins = numberOfCoins + input;
    }
    while(input >= 5)
    {
        input = input / 5;
        numberOfCoins = numberOfCoins + input;
    }
    while(input >= 1)
    {
        input = input / 1;
        numberOfCoins = numberOfCoins + input;
    }
    printf("number of coins is %d",numberOfCoins);
}