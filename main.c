#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
    printf("I've thought of a secret word! Will you?\n\n");
    // show hint
    showHint();

    // accept guess inputs until the limit is reached
    int guessNumber;
    for (guessNumber = 1; guessNumber <= MAX_GUESSES; guessNumber++)
    {
        printf("Guess %d of %d: ", guessNumber, MAX_GUESSES);

        // accept input for guess
        char guess[MAX_CHARS];
        gets(guess);

        // integer will change if user gets secret word right
        int isRight = 0;

        // if guess is the secret word
        if (checkGuess(guess) == 1)
        {
            isRight = 1;
        }
        // if check was returned positive...
        if (isRight == 1)
        {
            // report to user success, and end loop
            printf("You got it! That's the secret word!");
            break;
        }

        // if user has used their last guess and check still has not reported positive...
        if (isRight == 0 && guessNumber == MAX_GUESSES)
        {
            // tell the user they didn't get it
            printf("Sorry, but you didn't get it. Try again next time.");
        }
    }

    return 0;
}

