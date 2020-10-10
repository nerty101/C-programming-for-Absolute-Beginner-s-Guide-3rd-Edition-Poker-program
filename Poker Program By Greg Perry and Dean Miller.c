#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

// constants for determining straights or flushes

#define FALSE 0
#define TRUE 1

// function prototyping

void printGreeting();
int getBet();
char getSuit(int suit);
char getRank(int rank);
void getFirstHand(int cardRank[], int cardSuit[]);
void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksinHand[], int suitsinHand[]);

main()
{
   int bet;
   int bank = 100;
   int i;
   int cardRank[5]; // will be one of 13 values (Ace-two)
   int cardSuit[5]; // will be one of 4 values (clubs, diamonds, hearts, spades)
   int finalRank[5];
   int finalSuit[5];
   int ranksinHand[13]; //used for evaluating the final hand
   int suitsinHand[4]; //used for evaluating the final hand
   int winnings;
   time_t t;
   char suit, rank, stillPlay;


   // Greeting at start of program

   printGreeting();

   // Loop for each hand

   do {
      bet = getBet();
      srand(time(&t));
      getFirstHand(cardRank, cardSuit);
      printf("Your five cards: \n");
      for (i = 0; i < 5; i++)
      {
         suit = getSuit(cardSuit[i]);
         rank = getRank(cardRank[i]);
         printf("Card #%d: %c%c\n", i+1, rank, suit);
      }

   // these arrays for computing value of hand must be zeroed out if player plays more than one hand


   for (i = 0; i < 4; i++)
   {
      suitsinHand[i] = 0;
   }

   for (i = 0; i < 13; i++)
   {
      ranksinHand[i] = 0;
   }


   getFinalHand(cardRank, cardSuit, finalRank, finalSuit, ranksinHand, suitsinHand);
   printf("Your five final cards: \n");
   for (i = 0; i < 5; i++)
   {

      suit = getSuit(finalSuit[i]);
      rank = getRank(finalRank[i]);
      printf("Card #%d: %c%c\n", i+1, rank, suit);
   }


   winnings = analyzeHand(ranksinHand, suitsinHand);
   printf("You won %d:\n", bet*winnings);
   bank = bank - bet + (bet*winnings);
   printf("\nYour bank is now %d.\n", bank);
   printf("\nDo you want to play again?");
   scanf(" %c", &stillPlay);
   } while (toupper(stillPlay) == 'Y');  // toupper is a function to convert characters into uppercase


   return;
}

// Print greeting and tell the values of hands

void printGreeting()
{

   printf("Welcome to C Poker Here are the rules:\n");
   printf("You start with 100 chips and can bet 1 to 5 per hand.\n");
   printf("You are dealt 5 cards, choose which to keep or discard.\n");
   printf("\n\n\t\t\t Here is the table of winnings for a bet of 1 chip:");
   printf("\n\nOne pair\t\t 1 chip");
   printf("\n\nTwo pair\t\t 2 chips");
   printf("\n\nThree of a kind\t\t 3 chips");
   printf("\n\nStraight\t\t 4 chips");
   printf("\n\nFlush\t\t 5 chips");
   printf("\n\nFull House\t\t 8 chips");
   printf("\n\nFour of a kind\t\t 10 chips");
   printf("\n\nStraight Flush\t\t 20 chips");
   printf("\n\n Have FUN!");
}


// Function to deal the hand

void getFirstHand(int cardRank[], int cardSuit[])
{
    int i, j;
    int cardDup;

    for (i = 0; i < 5; i++)
    {
        cardDup = 0;
        do 
        {      
            // card rank is one of 13 ( 2-A )
            cardRank[i] = (rand() % 13);
            // card suit is one of 4 (c, d, h, s)
            cardSuit[i] = (rand() %4);

            // Loop ensures each card is unique
            for (j=0; j < i; j++)
            {
                if ((cardRank[i] == cardRank[j]) && (cardSuit[i] == cardSuit[j]))
                {
                    cardDup = 1;
                }
            }
        }
        while (cardDup == 1);
    }

}

// Function that changes suit integer value to a character value

char getSuit(int suit)
{
    switch (suit)
    {
        case 0:
            return ('c');
        case 1:
            return ('d');
        case 2:
            return ('h');
        case 3:
            return ('s');
    }
}


// Function that changes rank integer value to rank character

char getRank(int rank)
{
    switch (rank)
    {
        case 0:
            return ('2');
        case 1:
            return ('3');
        case 2:
            return ('4');
        case 3:
            return ('5');
        case 4:
            return ('6');
        case 5:
            return ('7');
        case 6:
            return ('8');
        case 7:
            return ('9');
        case 8:
            return ('T');
        case 9:
            return ('J');
        case 10:
            return ('Q');
        case 11:
            return ('K');
        case 12:
            return ('A');

    }
}

// Function to get bet

int getBet()
{
    int bet;

    do // will keep running until bet between 0-5 is placed
    {
        printf("How much do you want to bet? (Enter a number between 1 and 5 to play");
        printf("or Enter 0 to quit game \n My bet is: ");
        scanf(" %d", &bet);

        if (bet >= 1 && bet <= 5)
        {
            return(bet);
        }
        else if (bet == 0)
        {
            exit(1);
        }
        else
        {
            printf("Please enter a bet between 1 and 5 to play");
            printf("or enter 0 to quit game \n My bet is: ");
        }
    }
    while ((bet < 0) || (bet > 5));
}


// This function looks through the hand one card at a time and asks the player if they want to 
// keep the card or get a replacement card

void getFinalHand(int cardRank[], int cardSuit[], int finalRank[], int finalSuit[], int ranksinHand[], int suitsinHand[])
{
    int i, j, cardDup;
    char suit, rank, ans;

    for (i=0; i < 5; i++)
    {
        suit = getSuit[i];
        rank = getRank[i];
        printf("Do you want to keep this card #%d: %c%c?", i+1, rank, suit);
        printf("\n Please answer (Y/N): ");
        scanf(" %c", &ans);
        if (toupper(ans) =='Y')
        {   
            finalRank[i] = cardRank[i];
            finalSuit[i] = cardSuit[i];
            ranksinHand[finalRank[i]]++;
            suitsinHand[finalSuit[i]]++;
            continue;
        }
        else if (toupper(ans) == 'N')
        {
            cardDup = 0;
            do 
            {
                cardDup = 0;
                finalRank[i] = (rand() % 13);
                finalSuit[i] = (rand() % 4);
                
                // First check the new card against the original 5
                for (j=0; j < 5; j++)
                {
                    if ((finalRank[i] == cardRank[j]) && (finalSuit[i] == cardSuit[j]))
                    {
                        cardDup = 1;
                    }
                }

                // check card against any new drawn card
                for (j=0; j < i; j++)
                {
                    if ((finalRank[i] == finalRank[j]) && (finalSuit[i] == finalSuit[j]))
                    {
                        cardDup ==1;
                    }
                }
            }
            while (cardDup == 1);
            ranksinHand[finalRank[i]]++;
            suitsinHand[finalSuit[i]]++;
            
        }
    }
}




// This last function reviews the final hand and determines the value of the hand

int analyzeHand(int rankinHand[], int suitsinHand[])
{
    int numConsec = 0;
    int i, rank, suit;
    int straight = FALSE;
    int flush = FALSE;
    int four = FALSE;
    int three = FALSE;
    int pairs = 0;


    for (suit = 0; suit < 4; suit++)
    {
        if (suitsinHand[suit] == 5)
        {
            flush = TRUE;
        }
    rank = 0;
    while (rankinHand[rank] == 0)
    {
        rank++;
    }
    for (; rank < 13 && ranksinHand[rank]; rank++)
    {
        numConsec++;
    }
    if (numConsec == 5)
    {
        straight = TRUE;
    }
    for (rank = 0; rank < 13; rank++)
    {
        if (ranksinHand[rank] == 4)
        {
            four = TRUE;
        }
        if (ranksinHand[rank] == 3)
        {
            three = TRUE;
        }
        if (ranksinHand[rank] == 2)
        {
            pairs++;
        }
    }


    if (straight && flush) 
    {
        printf("Straigth flush\n\n");
        return (20);
    }
    else if (four) 
    {
        printf("Four of a kind\n\n");
        return(10);
    }
    else if (three && pairs == 1) 
    {
        printf("Full house\n\n");
        return(8);
    }
    else if (flush) 
    {
        printf("Flush\n\n");
        return(5);
    }
    else if (straight) 
    {
        printf("Straight\n\n");
        return(4);
    }
    else if (three) 
    {
        printf("Three of a kind\n\n");
        return(3);
    }
    else if (pairs == 2) 
    {
        printf("Two pairs\n\n");
        return(2);
    }
    else if (pairs == 1) 
    {
        printf("Pair\n\n");
        return(1);
    }
    else  
    {
        printf("High card pays 0\n\n");
        return(0);
    }

}
