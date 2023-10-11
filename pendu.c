#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

int main() {
    int lives;
    bool foundword;
    char words[][10] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};
    char *list_of_words[5];
    char tissu[] = {'t', 'i', 's', 's', 'u', '\0'};
    char tranche[] = {'t', 'r', 'a', 'n', 'c', 'h', 'e', '\0'};
    char grele[] = {'g', 'r', 'e', 'l', 'e', '\0'};
    char masse[] = {'m', 'a', 's', 's', 'e', '\0'};
    char dessin[] = {'d', 'e', 's', 's', 'i', 'n', '\0'};

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

    while (foundword == false && lives > 0) {
        int length = strlen(list_of_words[random_num]);
        char wordadvancement[length];
        bool foundletters[length];
        for (int i = 0; i < length; i++) {
            foundletters[i] = false;
        }
        for (int i = 0; i < length; i++) {
            if (foundletters[i] == true){
                wordadvancement[i] = divword[i];
            }
            else if (foundletters[i] == false){
                wordadvancement[i] = '_';
            }
        }

        printf("%c \nInsérez une lettre: ", wordadvancement);
        char letter;
        scanf(" %c", &letter);
        for (int i = 0; i < length; i++) {
            if (divword[i] == letter) {
                foundletters[i] = true;
            }
       
        }
    return 0;
}
}