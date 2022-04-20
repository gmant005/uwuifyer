#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// stdlib and time is needed for the s-stuttering

// Known issues :
// I need to change some of the ifs to switches / make everything better.
// I also need to make a way to input something without pipes

int c, lastc, sword = 0, F = 0;
// c is the current char.
// lastc is the previous char.
// sword is used to track if its on the same word, this is used to determine if a word should be modified.
int main(int argc, char *argv[])
{
    while ((++argv)[0]) // this will get any flags/arguments.
    {
            if (argv[0][0] == '-' )
            {
                    switch (argv[0][1])  {

                            default:
                                    printf("Unknown option -%c uwu -h for help\n\n", argv[0][1]); // if you put an invalid argument
                                    exit(0);
                                    break;
                            case 'H':
                            case 'h':
                                    printf("Function:\n    The output of the command you pipe into here will be uwued.\nUsage: uwu <args>\n    -h Displays this menu\n    -v Displays version\n    -f Adds faces\n"); // the help menu
                                    exit(0);
                                    break;
                            case 'V':
                            case 'v':
                                    printf("1.0.2\n"); //version
                                    exit(0);
                                    break;
                            case 'F':
                            case 'f':
                                    F = 1;
                                    break;
                    }
            }
    }
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
        if (lastc == ' ' && (rand() & 7) == 1 && c != ' ') // this will randomly make s-stutters
        {
            putchar(c);
            putchar('-');
        }
        if (c == '.' && lastc != '.' && F == 1) // checks if F is on and if c is .
        {
            int ran = (rand() % 5);
            switch(rand() % 5) // makes a random face.
            {
                case 1 :
                    printf(" (˘ω˘)");
                    break;
                case 2 :
                    printf(" (◡ ω ◡)");
                    break;
                case 3 :
                    printf(" (UᵕU❁)");
                    break;
                case 4 :
                    printf(" (Φ ω Φ)");
                    break;
                case 0 :
                    printf(" (≅ᆽ≅)");
                    break;
                default :
                    break;
            }
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
            } else if (c == ' ' || c == '\n') // puts '~' after an 'a' in a word that ends in 'a'.
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
