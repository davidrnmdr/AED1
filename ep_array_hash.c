#include <stdio.h>
#include <string.h>

int main()
{
    unsigned short numCases, numLines;
    unsigned short i, caseCount;
    unsigned short numLetters;
    unsigned int sumLetters;

    char str[60];

    scanf("%hu", &numCases);

    while (numCases--)
    {
        scanf("%hu", &numLines);

        caseCount = 0;
        sumLetters = 0;

        while (numLines--)
        {
            scanf(" %s", str);

            i = 0;
            numLetters = 0;

            while (str[i])
            {
                sumLetters += (str[i] - 'A') + caseCount + numLetters++;

                i++;
            }

            caseCount++;

            memset(str, 0, sizeof(str));
        }

        printf("%u\n", sumLetters);
    }

    return 0;
}
