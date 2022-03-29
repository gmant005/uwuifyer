#include <stdio.h>

int c, lastc, sword = 0;
// c is the current char.
// lastc is the previous char.
// sword is used to track if its on the same word, this is used to determine if a word should be modified.
int main()
{
    for (; (c = getchar()) != EOF; lastc = c)
    {
        c =(c == 'r' || c == 'l' ? 'w' : c);
        c =(c == 'R' || c == 'L' ? 'W' : c);

        if (c == ' ') // checks if its on a space to determine if its at the end of a word.
            {
                sword = 0;
            }

        if (sword == 0) // if the word hasnt been modified yet it will allow it to be modified.
        {
            if (c == 'n') // puts a y after a n in a word.
            {
                putchar(c);
                putchar('y');
                sword = 1;
            } else if (c == 'u') // puts uwu after a u in a word.
            {
                putchar(c);
                putchar('w');
                putchar('u');
                sword = 1;
            } else if (c == ' ') // puts ~ after an a in a word that ends in a.
            {
                if (lastc == 'a')
                {
                    putchar('~');
                    putchar(c);
                } else
                {
                    putchar(c);
                }
            } else // if none of the previous conditions apply it just puts the char.
            {
                putchar(c);
            }
/*            if (c == 'o') // for extra owo uncomment this. its a bad idea.
            {
                putchar(c);
                putchar('w');
                putchar('o');
                sword = 1;
            } else {
                putchar(c);
            }
*/        } else // this puts a char is the previous condition doesnt apply, So typpicly when the word has already been modified.
        {
        putchar(c);
        }

    }

}
