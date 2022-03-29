#include <stdio.h>

int c, lastc, countdown, hash, sword = 0;

int main()
{
    for (; (c = getchar()) != EOF; lastc = c)
    {
        c =(c == 'r' || c == 'l' ? 'w' : c);
        c =(c == 'R' || c == 'L' ? 'W' : c);
        if (c == ' ')
            {
                sword = 0;
            }

        if (sword == 0)
        {
            if (c == 'n')
            {
                putchar(c);
                putchar('y');
                sword = 1;
            } else if (c == 'u')
            {
                putchar(c);
                putchar('w');
                putchar('u');
                sword = 1;
            } else if (c == ' ')
            {
                if (lastc == 'a')
                {
                    putchar('~');
                    putchar(c);
                } else
                {
                    putchar(c);
                }
            } else
            {
                putchar(c);
            }
/*            if (c == 'o') // for extra owo uncomment this.
            {
                putchar(c);
                putchar('w');
                putchar('o');
                sword = 1;
            } else {
                putchar(c);
            }
*/        } else {
        putchar(c);
        }

    }

}
