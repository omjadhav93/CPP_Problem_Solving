#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int computer(){
    srand(time(NULL));
    return rand()%3;
}

int eachRound(){
    int pl1,pl2;
    printf(" What's your choice : ");
    scanf("%d",&pl1);
    pl2 = computer();
    if(pl1 == 0){
        printf(" Your choice is Rock.\n");
        if(pl2 == 1){
            printf(" Computer's choice is Paper.\n !!!YOU LOSS!!!\n");
            return 1;
        }else if(pl2 == 2){
            printf(" Computer's choice is Scissor.\n !!!YOU WON!!!\a\n");
            return 0;
        }else{
            printf(" Computer's choice is Rock.\n");
            printf(" It's a Tie , Choice Again : \n");
            return eachRound();
        }
    }else if(pl1 == 1){
        printf(" Your choice is Paper.\n");
        if(pl2 == 1){
            printf(" Computer's choice is Paper.\n");
            printf(" It's a Tie , Choice Again :\n ");
            return eachRound();
        }else if(pl2 == 2){
            printf(" Computer's choice is Scissor.\n !!!YOU LOSS!!!\n");
            return 0;
        }else{
            printf(" Computer's choice is Rock.\n !!!YOU WON!!!\a\n");
            return 1;
        }
    }else if(pl1 == 2){
        printf(" Your choice is Scissor.\n");
        if(pl2 == 1){
            printf(" Computer's choice is Paper.\n !!!YOU WON!!!\a\n");
            return 1;
        }else if(pl2 == 2){
            printf(" Computer's choice is Scissor.\n");
            printf(" It's a Tie , Choice Again :\n ");
            return eachRound();
        }else{
            printf(" Computer's choice is Rock.\n !!!YOU LOSS!!!\n");
            return 0;
        }
    }else{
        printf(" Wrong choice , choice again: \n");
        return eachRound();
    }
}

int main(){
    int p1 = 0,p2 = 0;
    printf("\t WELCOME TO ROCK,PAPER,SCISSOR \n How to play: \n You have to choice one of the following options using there respective number.\n Rock :- 0 \n Paper :- 1 \n Scissor :- 2 \n Then Computer will choice random , If you wins you will get 1 point  and there will 3 Rounds.\n\n");

    for (int i = 1; i <= 3; i++)
    {
        printf(" Round %d:\n",i);
        if(eachRound()) p1++;
        else p2++;
        printf("\n ___________________ \n|_______Score_______|\n|   YOU       COM   |\n|___________________|\n|    %d         %d    |\n|___________________|\n\n",p1,p2);
    }
    
    if (p1>p2)
    {
        printf("!!!CONGRATS!!!\n   YOU WON   \n   YOU WON   \n   YOU WON   \n\n");
    }else{
        printf(" Your Luck IS Not With You!\n BETTER LUCK NEXT TIME! \n\n");
    }
    
    printf(" END!\n\n");

    return 0;
}