#include<stdlib.h>
#include<time.h>
int main(); {

int lives;
bool foundword;
char words[] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};
int list_of_words[3];
char tissu[] = {"t", "i", "s", "s", "u"};
char tranche[] = {"t", "r", "a", "n", "c", "h", "e"};
char grele[] = {"g", "r", "e", "l", "e"};
char masse[] = {"m", "a", "s", "s", "e"};
char dessin[] = {"d", "e", "s", "s", "i", "n"};

list_of_words[0] = tissu;
list_of_words[1] = tranche;
list_of_words[2] = grele;
list_of_words[3] = masse;
list_of_words[4] = dessin;

foundword = False;
lives = 7;

int random_num;
srand(time(NULL)); // seed the random number generator with the current time
random_num = rand() % 5; // generate a random number between 0 and 4
char divword = list_of_words[random_num];
char word = words[random_num];

while (foundword == False and lives > 0){
    int length = sizeof(list_of_words[random_num]) / sizeof(int);
    char wordadvancement[length];
    bool foundletters[length];
    for (int i = 0; i < length; i++) {
        foundletters[i] = False;
    }
    for (int i = 0; i < length; i++) {
        wordadvancement[i] = "_";
    }
    
        printf("Insérez une lettre");
    }
return 0;
}