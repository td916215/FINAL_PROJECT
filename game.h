#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define MAX_GUESSES 5
#define MAX_CHARS 25

void showHint(void);
int checkGuess(char input[MAX_GUESSES]);

// display the hint from hint.txt
void showHint()
{
    // open hint file
    FILE *hintPTR;
    hintPTR = fopen("F:\\Computer Programming\\Final_Project\\hint.txt", "r");

    // report problem if program can't find or read file
    if (hintPTR == NULL)
    {
        printf("Sorry! I can't find a hint.");
    }
    // otherwise print the hint
    else
    {
        char hintText;

        while ((hintText = fgetc(hintPTR)) != EOF)
        {
            printf("%c", hintText);
        }

        printf("%c\n\n", hintText);
    }

    // close hint file
    fclose(hintPTR);
}

// check the current guess
int checkGuess(char input[MAX_GUESSES])
{
    // open secret word file
    FILE *secretPTR;
    secretPTR = fopen("F:\\Computer Programming\\Final_Project\\secret.txt", "r");

    // report problem if program can't find or read file
    if (secretPTR == NULL)
    {
        printf("Something's wrong, and I can't find my secret word. Sorry!");
        return 0;
    }
    // otherwise check input to see what they got right
    else
    {
        // character to write secret word letters to
        char secretText;
        // iterator
        int i = 0;
        // number of letters user got right
        int correctLetters = 0;

        // while program can still write a new letter to secretText from the file...
        while ((secretText = fgetc(secretPTR)) != EOF)
        {
            // if input is not the right character
            if (secretText != input[i])
            {
                printf("_");
            }
            // if input is the right character
            else if (secretText == input[i])
            {
                printf("%c", secretText);
                // add 1 to the number of correct letters
                correctLetters++;
            }
            // if something else is read for some reason
            else
            {
                printf("?");
            }

            i++;
        }
        printf("\n\n");

        // if correct letters are equal to the iterator (number of letters in the file)...
        if (correctLetters == i)
        {
            // tell user they got it right and return positive value
            return 1;
        }
            // if not all letters are right...
        else
        {
            // do not return positive
            return 0;
        }
    }

    // close hint file
    fclose(secretPTR);
}

#endif // GAME_H_INCLUDED
