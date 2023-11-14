#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main() {
    int lives;
    bool foundword, foundthisturn, play = true;
    char* words[] = {"tissu", "tranche", "bleu", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};

    while(play == true)
    {
        system("clear");
        foundword = false;
        lives = 7;
        char list_of_found_letters[8];
        list_of_found_letters[0] = '\0'; // Initialize the string

        srand(time(NULL)); // random number
        int random_num = rand() % 11;
        char *word = words[random_num];
        char letter, comparedletter;
        int length = strlen(words[random_num]);
        char wordadvancement[length]; //creates a lists that will start empty and gradually fill with letters
        bool foundletters[length]; //tells if the letter related to a given index is found

        for (int i = 0; i < length; i++)
        {
            foundletters[i] = false;
        }

        while (foundword == false && lives > 0)
        {
            system("clear");
            //the advancement is always recalculated
            for (int i = 0; i < length; i++) 
            {
                if (foundletters[i] == true)
                {
                    // wordadvancement[i] = word[i];
                    printf("%c", word[i]);
                }
                else
                {
                    //wordadvancement[i] = '_';
                    printf("%c", '_');
                }
            }

            //this loops until either the word is found or lives have ran out
            printf("\nIl vous reste %d vies", lives);
            printf("\nLettres mises: %s\nInsérez une lettre: ", list_of_found_letters);
            scanf(" %1c", &letter);

            foundthisturn=false;
            for (int i = 0; i < length; i++) 
            {
                comparedletter = word[i];
                if (comparedletter == letter) 
                {
                    foundletters[i] = true;
                    foundthisturn = true;
                }
            }

            if (foundthisturn == false)
            {
                lives = lives-1;
                strncat(list_of_found_letters, &letter, 1);
            }
            
            foundword = true;  // Assume the word is found until proven otherwise
            for (int i = 0; i < length; i++) 
            {
                if (foundletters[i] == false) {
                    foundword = false;
                    break; // No need to check the rest of the word
                }
            }

        }

        system("clear");
        if (lives <= 0)
        {
            printf("Vous avez perdu, le mot était %s", word);
        }
        else
        {
            printf("Bravo vous avez gagné! Le mot était bien %s", word);
        }
        printf(" Voulez vous recommencer?\nY ou N: ");
        scanf(" %c", &letter);
        if(letter== 'y' || letter == 'Y')
        {
            play = true;
        }
        else{
            play = false;
        }
    }

    system("clear");
    printf("Merci d'avoir joué :)\n");
 
return 0;
}