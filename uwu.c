#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// stdlib and time is needed for the s-stuttering

int c, lastc, sword = 0;
// c is the current char.
// lastc is the previous char.
// sword is used to track if its on the same word, this is used to determine if a word should be modified.
int main()
{
    time_t t;
    srand((unsigned) time (&t));
    for (; (c = getchar()) != EOF; lastc = c)
    {
        if (lastc != 'o' && lastc != 'l') // this makes r and l into w and it parialy isnt working right now
        {
            c =(c == 'r' || c == 'l' ? 'w' : c);
            c =(c == 'R' || c == 'L' ? 'W' : c);
        }

        if (c == ' ' || c == '\n' ) // checks if its on a space to determine if its at the end of a word. This is used to prevent over uwuing.
            {
                sword = 0;
            }
        if (lastc == ' ' && (rand() & 7) == 1) // this will randomly make s-stutters
        {
            putchar(c);
            putchar('-');
        }
        if (sword == 0) // if the word hasnt been modified yet it will allow it to be modified.
        {
            if ((lastc =='n') && (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')) // this puts ya after an 'n' and 'y' if the letter after is 'a'
            {
                putchar('y');
                if (c!='a')
                {
                    putchar('a');
                }
                putchar(c);
            } else if (c == 'u') // puts uwu after a u in a word.
            {
                putchar(c);
                putchar('w');
                putchar('u');
                sword = 1;
            } else if (c == ' ') // puts '~' after an 'a' in a word that ends in 'a'.
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
/*            if (c == 'o') // for extra owo uncomment this. its a bad idea. you will also have to change some stuff to make it work.
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
