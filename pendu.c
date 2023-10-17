#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main() {
    int lives;
    bool foundword, foundthisturn;
    char words[5][10] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};
    char *list_of_words[5];
    char tissu[6][1] = {'t', 'i', 's', 's', 'u', '\0'};
    char tranche[8][1] = {'t', 'r', 'a', 'n', 'c', 'h', 'e', '\0'};
    char grele[6][1] = {'g', 'r', 'e', 'l', 'e', "\0"};
    char masse[6][1] = {'m', 'a', 's', 's', 'e', '\0'};
    char dessin[7][1] = {'d', 'e', 's', 's', 'i', 'n', '\0'};

    list_of_words[0] = tissu;
    list_of_words[1] = tranche;
    list_of_words[2] = grele;
    list_of_words[3] = masse;
    list_of_words[4] = dessin;

    foundword = false;
    lives = 7;

    int random_num;
    srand(time(NULL)); // seed the random number generator with the current time
    random_num = rand() % 5; // generate a random number between 0 and 4
    char *divword = list_of_words[random_num];
    char *word = words[random_num];
    char letter;
    int length = strlen(list_of_words[random_num]);
    char wordadvancement[length];//creates a lists that will start empty and gradually fill with letters
    bool foundletters[length];//tells if the letter related to a given indexnis found

    for (int i = 0; i < length; i++) 
    {
        foundletters[i] = false;
    }
    while (foundword == false && lives > 0) 
    {
        //this loops until either the word is found or lives have ran out
        printf("%s \nInsérez une lettre: ", wordadvancement);
        scanf(" %s", &letter);
        // printf("%s \n", word);
        for (int i = 0; i < length; i++) 
        {
            if (divword[i] == letter||divword[i]=='\0') 
            {
                foundletters[i] = true;
                foundthisturn = true;
            }
        }
        if (foundthisturn == false)
        {
            lives = lives-1;
        }
        // printf("etape 1");
        //the advancement is always recalculated
        for (int i = 0; i < length; i++) 
        {
            if (foundletters[i] == true)
            {
                wordadvancement[i] = divword[i];
            }
            else if (foundletters[i] == false)
            {
                wordadvancement[i] = '_';
            }
        }
        // printf("etape 2");
        foundword=true;
        for(int i=0; i<length; i++)
        {
            if (foundletters[i] == false)
            {
                foundword=false;
            }
        }

        // printf("etape 3");
        foundthisturn=false;
        // printf("end turn");
    }

    // printf("fin de la boucle");
    if (lives <= 0)
    {
        printf("Vous avez perdu");
    }
    else
    {
        printf("Bravo vous avez gagné");
    }
 
return 0;
}