/****************************************************************************** 
 
This is to certify that this project is my own work, based on my personal 
efforts in studying and applying the concepts learned.  I have constructed  
the functions and their respective algorithms and corresponding code by  
myself.  The program was run, tested, and debugged by my own efforts.  I  
further certify that I have not copied in part or whole or otherwise  
plagiarized the work of other students and/or persons. 
 
Jan Kailu Eli A. Baradas - 12206717 - S12
 
******************************************************************************/ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
/*******************************************************************************
Description  : This function checks for the initial option in the start up menu
     @param  :  int *option - This parameter takes the option that the user takes to start the game, check the rules, or exit the game
     @return :  This funtion returns the option to start the game, check the rules, or exit the game
********************************************************************************/
void startmenu(int *option)
{

printf("Welcome to Mastermind!\nPress [1] to Start the game \nPress [2] to check the rules\nPress [3] to Exit\n\n");
        scanf("%d", &*option); 
}
/*******************************************************************************
Description  : This function checks for the difficulty that the user wants
     @param  : int *difficulty - This paramter stores the difficulty option taken by the user 
	 		   int *NumPegs - This parameter determines how many pegs or number options are available to the user 
			   int *NumGuesses - This parameter determines how many attempts or guesses are available to the user before they lose
     @return : difficulty menu and option 
********************************************************************************/
void selectDifficulty(int *difficulty, int *NumPegs, int *NumGuesses)
{
     printf("Select a difficulty: \n[1] EASY      | choose from 1-6 with 10 attempts \n[2] AVERAGE   | choose from 1-8 with 12 attempts\n[3] DIFFICULT | choose from 1-10 with 16 attempts\n[4] EXTREME   | choose from 1-12 with 20 attempts\n");
        scanf("%d", &*difficulty);
        switch(*difficulty)
        {
            case 1:
            {
                *NumPegs=6; 
                *NumGuesses=10;
                break;
            }
            case 2:
            {
                *NumPegs=8; 
                *NumGuesses=12;
                break;
            }
            case 3:
            {
                *NumPegs=10; 
                *NumGuesses=16;
                break;
            }
            case 4:
            {
                *NumPegs=12; 
                *NumGuesses=20;
                break;
            }
            default:
       		{
       		printf("haha very funny, now actually choose a difficulty\n");
        	printf("Select a difficulty: \n[1] EASY      | choose from 1-6 with 10 attempts \n[2] AVERAGE   | choose from 1-8 with 12 attempts\n[3] DIFFICULT | choose from 1-10 with 16 attempts\n[4] EXTREME   | choose from 1-12 with 20 attempts");
        	scanf("%d", &*difficulty);
			}
        }
}
/*******************************************************************************
Description  : This function randomizes and checks for 4 unique random numbers for the CodeBreaker to guess
     @param  : int *NumPegs - This variable represents the amount of pegs the user can guess as chosen from the difficulty
               int *num1 - This variable represents the first digit of 4 that the user has to guess to beat the codemaker
               int *num2 - This variable represents the second digit of 4 that the user has to guess to beat the codemaker
               int *num3 - This variable represents the Third digit of 4 that the user has to guess to beat the codemaker
               int *num4 - This variable represents the fourth digit of 4 that the user has to guess to beat the codemaker
     @return : This function returns 4 unique random numbers
********************************************************************************/
void randomizer(int *NumPegs, int *num1, int *num2, int *num3, int *num4)
 {
        {
        *num1 = rand() % *NumPegs;
        *num2 = rand() % *NumPegs;
        *num3 = rand() % *NumPegs;
        *num4 = rand() % *NumPegs;
        while(*num1==*num2||*num1==*num3||*num1==*num4||*num2==*num3||*num2==*num4||*num3==*num4)
        {
        *num1 = rand() % *NumPegs;
        *num2 = rand() % *NumPegs;
        *num3 = rand() % *NumPegs;
        *num4 = rand() % *NumPegs;
        }
        printf("%d %d %d %d\n", *num1, *num2, *num3, *num4);
        printf("\nGood luck!\n");
 }
 }
/*******************************************************************************
Description  : This function checks the answer of the CodeBreaker and outputs white and black pegs
     @param  : int guesses -
	 		   int ai_guesses - 
			   int *NumGuesses -  
			   int *guess1 -  
			   int *guess2 - 
			   int *guess3 - 
			   int *guess4 - 
			   int *black_pegs - 
			   int *white_pegs - 
			   int *num1 - 
			   int *num2 - 
			   int *num3 - 
			   int *num4 -
     @return : none
********************************************************************************/
void Checker(int *pscore, int *aiscore, int guesses, int ai_guesses, int *NumGuesses, int *guess1, int *guess2, int *guess3, int *guess4, int *black_pegs, int *white_pegs, int *num1, int *num2, int *num3, int *num4)
{
    while (guesses < *NumGuesses)
        {
            printf("\nYou are on Code Breaker Attempt #%d", guesses + 1);
            printf("\n----------------\n");
            printf("Enter your guess (X X X X): ");
            scanf(" %d %d %d %d", &*guess1, &*guess2, &*guess3, &*guess4);
            if (*guess1 == *num1)
            {
                *black_pegs +=1;
            }
            else if (*guess1 == *num2 || *guess1 == *num3 || *guess1 == *num4)
            {
                *white_pegs +=1;
            }

            if (*guess2 == *num2)
            {
                *black_pegs +=1;
            }
            else if (*guess2 == *num1 || *guess2 == *num3 || *guess2 == *num4)
            {
                *white_pegs +=1;
            }

            if (*guess3 == *num3)
            {
                *black_pegs +=1;
            }
            else if (*guess3 == *num1 || *guess3 == *num2 || *guess3 == *num4)
            {
                *white_pegs +=1;
            }

            if (*guess4 == *num4)
            {
                *black_pegs +=1;
            }
            else if (*guess4 == *num1 || *guess4 == *num2 || *guess4 == *num3)
            {
                *white_pegs +=1;
            }

            guesses +=1;
            *aiscore +=1;
            if (*black_pegs == 4)
            {
             while(*black_pegs !=0)
                {
                    printf("B ");
                    *black_pegs -=1;
                }
            printf("\nAi score: %d\n", *aiscore);
		    printf("Player score: %d\n",*pscore);
            printf("\n----------------\n");
                return;
            }
            else
            {
                while(*black_pegs !=0)
                {
                    printf("B ");
                    *black_pegs -=1;
                }
                while(*white_pegs !=0)
                {
                    printf("W ");
                    *white_pegs -=1;
                }
                
            }
        printf("\nAi score: %d\n", *aiscore);
		printf("Player score: %d\n",*pscore);
        printf("\n----------------\n");
            *black_pegs = 0;
            *white_pegs = 0;
        }
        printf("\nAi score: %d\n", *aiscore);
		printf("Player score: %d\n",*pscore);
        printf("\n----------------\n");
}
/*******************************************************************************
Description  : This function loops, randomizes, and checks for 4 unique random numbers for the pseudo-ai to try and guess the CodeMaker's secret code.
     @param  :  int *NumPegs - 
	 			int guesses -
				int ai_guesses -
				int *NumGuesses -
				int *guess1 -  
				int *guess2 - 
				int *guess3 -
				int *guess4 -  
				int *black_pegs -  
				int *white_pegs -  
				int *num1 -  
				int *num2 -  
				int *num3 -  
				int *num4 - 
     @return : none
********************************************************************************/
void makerchecker(int *pscore, int *aiscore, int *NumPegs, int guesses, int ai_guesses, int *NumGuesses, int *guess1, int *guess2, int *guess3, int *guess4, int *black_pegs, int *white_pegs, int *num1, int *num2, int *num3, int *num4)
{
    while (ai_guesses < *NumGuesses)
        {
        *guess1 = rand() % *NumPegs;
        *guess2 = rand() % *NumPegs;
        *guess3 = rand() % *NumPegs;
        *guess4 = rand() % *NumPegs;
        while(*guess1==*guess2||*guess1==*guess3||*guess1==*guess4||*guess2==*guess3||*guess2==*guess4||*guess3==*guess4)
        {
        *guess1 = rand() % *NumPegs;
        *guess2 = rand() % *NumPegs;
        *guess3 = rand() % *NumPegs;
        *guess4 = rand() % *NumPegs;
        }
        printf("\n\nAI is on Attempt #%d", ai_guesses + 1);
        printf("\n----------------\n");
        printf("Ai guessed: %d %d %d %d \n", *guess1, *guess2, *guess3, *guess4);
        usleep(640000);
            if (*guess1 == *num1)
            {
                *black_pegs+=1;
            }
            else if (*guess1 == *num2 || *guess1 == *num3 || *guess1 == *num4)
            {
                *white_pegs+=1;
            }

            if (*guess2 == *num2)
            {
                *black_pegs+=1;
            }
            else if (*guess2 == *num1 || *guess2 == *num3 || *guess2 == *num4)
            {
                *white_pegs+=1;
            }

            if (*guess3 == *num3)
            {
                *black_pegs+=1;
            }
            else if (*guess3 == *num1 || *guess3 == *num2 || *guess3 == *num4)
            {
                *white_pegs+=1;
            }

            if (*guess4 == *num4)
            {
                *black_pegs+=1;
            }
            else if (*guess4 == *num1 || *guess4 == *num2 || *guess4 == *num3)
            {
                *white_pegs+=1;
            }

            ai_guesses+=1;
            *pscore+=1;

            if (*black_pegs == 4)
            {
                break;
            }
            else
            {
                while(*black_pegs !=0)
                {
                    printf("B ");
                    *black_pegs-=1;
                }
                while(*white_pegs !=0)
                {
                    printf("W ");
                    *white_pegs-=1;
                }
            }
            printf("\nAi score: %d\n", *aiscore);
		    printf("Player score: %d\n",*pscore + 1);

            printf("---------------\n");

            *black_pegs = 0;
            *white_pegs = 0;
        }
}
/*******************************************************************************
Description  : This function displays the rules of the game
     @param  : int *option - This variable is the numerical option that the user inputs to proceed with the game.
     @return : returns the rules of the game or an invalid option if input is not 1
********************************************************************************/
void rules(int *option)
{
    printf("|---------------------------------------------------------------------------------|\n");
	printf("|                                   -The Rules-                                   |\n");
	printf("|1. The game will be played by two players, the User and the Pseudo-AI will be    |\n");
	printf("|   playing against each other. The role of the codemaker and codebreaker will    |\n");
	printf("|   switch between the User and the Pseudo-AI each game.                          |\n");
	printf("|2. Only an even number of games will be played, 2 to 10 games maximum.           |\n");
	printf("|3. A pattern of four code pegs is selected by the codemaker.                     |\n");
	printf("|	a. Duplication of code pegs will not be allowed.		          |\n");
	printf("|4. The chosen pattern is hidden from the codebreaker, only the codemaker will    |\n");
	printf("|   be able to see it                                                             |\n");
	printf("|5. Within a set amount of turns the code tries to predict the pattern in both    |\n");
	printf("|   sequence and color. The number of turns can vary depending on the chosen      |\n");
	printf("|   difficulty.                                                                   |\n");
	printf("|6. A row of code pegs is placed on the decoding board for each geuss.            |\n");
	printf("|7. The codemaker will then provide the codebreaker with feedback for each guess: |\n");
	printf("|	a. For each code peg from the guess that is accurate in both color and    |\n");
	printf("|      position, a black key peg is inserted.                                     |\n");
	printf("|	b. For each code peg from the guess that is accurate in color alone, a    |\n");
	printf("|       white peg is inserted.                                                    |\n");
	printf("|8. Once feedback is provided, another guess is made                              |\n");
	printf("|	a. Guesses and feedback will continue to alternate until the codebreaker  |\n");
	printf("|	   guesses correctly, or until the codebreaker reaches the maximum number |\n");
	printf("|	   of attempts.                                                           |\n");
	printf("|9. Players can only earn points when playing as the codemaker.                   |\n");
	printf("|	a. The codemaker gets one point for each guess the codebreaker makes.     |\n");
	printf("|	b. An extra point is earned by the codemaker if the codebreaker is unable |\n");
	printf("| 	   to guess the exact pattern within the given number of turns.           |\n");
	printf("|10. The winner is the one who has the most points after the agreed-upon number   |\n");
	printf("|    of games are played                                                          |\n");
	printf("|---------------------------------------------------------------------------------|\n");
	printf("Do you wish to proceed to the game? Press 1 to continue");
    scanf("%d", &*option);
    while(*option != 1)
    {
		printf("\nInvalid Input\n");
		printf("Press 1 to continue ");
		scanf(" %d", &*option);
    }

}
int main()
{   
    char play_again = 'y';
    int num1, num2, num3, num4;
    int guess1, guess2, guess3, guess4;
    int black_pegs = 0;
    int white_pegs = 0;
    int guesses = 0;
    int ai_guesses=0;
    int option;
    int difficulty;
    int NumPegs;
    int NumGuesses;
    int NumRounds;
    int i;
    int pscore=0;
    int aiscore=0;
    
    
    srand(time(NULL));

    startmenu(&option);

    switch(option)
    {
        case 1: 
    while (play_again == 'y')
    {
        selectDifficulty(&difficulty, &NumPegs, &NumGuesses);
        printf("How many rounds do you want to play?\n");
        printf("Note: you must give an even number (i.e 2, 4, 6, 8) \n");
        scanf("%d", &NumRounds);

    for(i=1; i<=NumRounds; i++)
    {
	
    if(i%2!=0)
        {
        randomizer( &NumPegs, &num1, &num2, &num3, &num4);
        Checker(&pscore, &aiscore, guesses, ai_guesses, &NumGuesses, &guess1, &guess2, &guess3, &guess4, &black_pegs, &white_pegs, &num1, &num2, &num3, &num4);
        black_pegs = 0;
        white_pegs = 0; 
        }
			

    else
        {
        black_pegs = 0;
        white_pegs = 0;
            printf("You are now the Code Maker, Enter a 4 digit number to set your code for the AI to guess (X X X X): ");
            scanf(" %1d %1d %1d %1d", &num1, &num2, &num3, &num4);

            makerchecker(&pscore, &aiscore, &NumPegs, guesses, ai_guesses, &NumGuesses, &guess1, &guess2, &guess3, &guess4, &black_pegs, &white_pegs, &num1, &num2, &num3, &num4);
            printf("---------------\n");

            black_pegs = 0;
            white_pegs = 0;
        }
	}
        if (black_pegs == 4)
        {
            printf("\nYOU WIN!\n");
        }
        else
        {
            printf("\nAI LOSES!\n");
        }
        black_pegs = 0;
        white_pegs = 0;
        guesses = 0;
         
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    }
	break;
    case 2:
       rules(&option);
       while (play_again == 'y')
    {
        selectDifficulty(&difficulty, &NumPegs, &NumGuesses);
        printf("How many rounds do you want to play?\n");
        printf("Note: you must give an even number (i.e 2, 4, 6, 8) \n");
        scanf("%d", &NumRounds);

    for(i=1; i<=NumRounds; i++)
    {
	
    if(i%2!=0)
        {
        randomizer( &NumPegs, &num1, &num2, &num3, &num4);
        Checker(&aiscore, &pscore, guesses, ai_guesses, &NumGuesses, &guess1, &guess2, &guess3, &guess4, &black_pegs, &white_pegs, &num1, &num2, &num3, &num4);
        black_pegs = 0;
        white_pegs = 0; 
        }
			

    else if (i%2==0)
        {
        black_pegs = 0;
        white_pegs = 0;
            printf("You are now the Code Maker, Enter a 4 digit number to set your code for the AI to guess: ");
            scanf(" %1d %1d %1d %1d", &num1, &num2, &num3, &num4);

            makerchecker(&aiscore, &pscore, &NumPegs, guesses, ai_guesses, &NumGuesses, &guess1, &guess2, &guess3, &guess4, &black_pegs, &white_pegs, &num1, &num2, &num3, &num4);
            printf("---------------\n");

            black_pegs = 0;
            white_pegs = 0;
        }
	}
        if (black_pegs == 4)
        {
            printf("\nYOU WIN!\n");
            printf("\nAi score: %d\n", aiscore);
		    printf("Player score: %d\n", pscore +1);
        }
        else
        {
            printf("\nAI LOSES!\n");
            printf("\nAi score: %d\n", aiscore);
		    printf("Player score: %d\n", pscore +1);
        }
        black_pegs = 0;
        white_pegs = 0;
        guesses = 0;
         
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &play_again);
        break;
    case 3: 
		printf("ok ba bye !!!");
		break;	    
    default: 
		printf("that was not an option :<");
    }  
    } 
}
