#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main() {
    int lives;
    bool foundword, foundthisturn, play = true;

    char words[15][10] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};
    char *list_of_words[5];
    char *tissu[6][1] = {'t', 'i', 's', 's', 'u', '\0'};
    char *tranche[8][1] = {'t', 'r', 'a', 'n', 'c', 'h', 'e', '\0'};
    char *grele[6][1] = {'g', 'r', 'e', 'l', 'e', "\0"};
    char *masse[6][1] = {'m', 'a', 's', 's', 'e', '\0'};
    char *dessin[7][1] = {'d', 'e', 's', 's', 'i', 'n', '\0'};
    
    // Assign words from the 'words' array to 'list_of_words'
    list_of_words[0] = "tissu"; // "tissu"
    list_of_words[1] = "tranche"; // "tranche"
    list_of_words[2] = "grele"; // "grele"
    list_of_words[3] = "masse"; // "masse"
    list_of_words[4] = words[4]; // "dessin"
    while(play == true)
    {
        foundword = false;
        lives = 7;
        char list_of_found_letters[7][1];

        int random_num;
        srand(time(NULL)); // random number
        random_num = rand() % 5; // generate a random number between 0 and 4
        char *divword = list_of_words[random_num];
        char *word = words[random_num];
        char letter[2];
        int length = strlen(list_of_words[random_num]);
        char wordadvancement[length]; //creates a lists that will start empty and gradually fill with letters
        bool foundletters[length];//tells if the letter related to a given index is found

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
                    wordadvancement[i] = divword[i];
                }
                else if (foundletters[i] == false)
                {
                    wordadvancement[i] = '_';
                }
            }
            //this loops until either the word is found or lives have ran out
            printf("%s \nLettres mises: %s\nInsérez une lettre: ", wordadvancement, list_of_found_letters);
            scanf("%1s", &letter);
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
                strcat(*list_of_found_letters, letter);
            }
            foundword=true;
            for(int i=0; i<length; i++)
            {
                if (foundletters[i] == false)
                {
                    foundword=false;
                }
            }
            foundthisturn=false;
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
        char relaunched;
        printf(" Voulez vous recommencer?\nY ou N: ");
        scanf("%s", &relaunched);
        printf("%c", relaunched);
        if(relaunched=='y'||relaunched=='Y')
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