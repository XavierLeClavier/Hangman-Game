#include <stdio.h>
int main();

int lives;
bool foundword;
    char words[] = {"tissu", "tranche", "grele", "masse", "dessin", "portable", "trompette", "page", "fourmi", "cartouche", "pain"};
    int list_of_words[3];
    char tissu[] = {"t", "i", "s", "s", "u"};
    char tranche[] = {"t", "r", "a", "n", "c", "h", "e"};
    char grele[] = {"g", "r", "e", "l", "e"};

    list_of_words[0] = tissu;
    list_of_words[1] = tranche;
    list_of_words[2] = grele;

    // Access and print the elements of the list of lists
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < sizeof(list_of_lists[i]) / sizeof(int); j++) {
            printf("%d ", list_of_lists[i][j]);
        }
        printf("\n");
    }

    return 0;
}
foundword = False;
lives = 7;

word =

while (foundword == False and lives > 0){
    printf("")
}
