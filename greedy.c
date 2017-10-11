#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void){
    float input;
    //float roundof;
    do{
        printf("O hai! How much change is owed?\n");
        input = get_float();
        //roundof = round(input);
        //printf("%.00f \n",roundof);
    }while(input < 0);
    
   int multiplication;
   int numberOfCoins = 0;
   multiplication = input * 100;
   while (multiplication >= 25)
   {
       multiplication = multiplication - 25;
       numberOfCoins = numberOfCoins + 1;
   }
    while (multiplication >= 10)
   {
       multiplication = multiplication - 10;
       numberOfCoins = numberOfCoins + 1;
   }
   while (multiplication >= 5)
   {
       multiplication = multiplication - 5;
       numberOfCoins = numberOfCoins + 1;
   }
   while (multiplication >= 1)
   {
       multiplication = multiplication - 1;
       numberOfCoins = numberOfCoins + 1;
   }
    
    printf("Number of coins is %d \n" , numberOfCoins);
}