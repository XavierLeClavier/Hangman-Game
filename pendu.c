#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main() {
    int lives;
    bool foundword, foundthisturn, play = true;
    char* words[] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};

    while(play == true)
    {
        foundword = false;
        lives = 7;
        char list_of_found_letters[] = "";

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
            // system("clear");
            printf("%s\n", word);
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
            printf("\nLettres mises: %s\nInsérez une lettre: ", list_of_found_letters);
            printf("comment ça mon keuf");
            scanf("%c", &letter);

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
                list_of_found_letters[7-lives]=letter;
            }
            
            for(int i=0; i<length; i++)
            {
                foundword=true;
                if (foundletters[i] == false)
                {
                    foundword=false;
                }
            }
        }

        // system("clear");
        if (lives <= 0)
        {
            printf("Vous avez perdu, le mot était %s", word);
        }
        else
        {
            printf("Bravo vous avez gagné! Le mot était bien %s", word);
        }
        char relaunched;
        printf(" Voulez vous recommencer?\nY ou N: ");
        scanf("%c", &relaunched);
        printf("%c", relaunched);
        if(relaunched== 'y' || relaunched == 'Y')
        {
            play = true;
        }
        else{
            play = false;
        }
    }

    // system("clear");
    printf("Merci d'avoir joué :)\n");
 
return 0;
}