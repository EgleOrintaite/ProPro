#include <stdio.h>
#include <library.h>
#include <string.h>
#include <stdlib.h>

int txtvalidacija(char name[])
{
    int strlenght = strlen(name);
    if(name[strlenght -1] == 't' && name[strlenght -2] == 'x' && name[strlenght -3] == 't' && name[strlenght -4] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

FILE *Files(char purpose[])
{
    FILE *fd = NULL;
    char name[256];

    scanf("%s", &name);
    while(!txtvalidacija(name))
    {
        printf("Netinkamai irasytas failo pavadinimas. Parasykite failo pavadinima (.txt formatu)\n"); 
        scanf("%s", &name);
    }
    fd = fopen(name, purpose);

    while(fd == NULL)
    {
        printf("Failas neegzistuoja\n");
        scanf("%s", name);
        while(!txtvalidacija(name))
        {
            printf("Netinkamai irasytas failo pavadinimas. Parasykite failo pavadinima (.txt formatu)\n"); 
            scanf("%s", &name);
        }
        fd = fopen(name, purpose);
    }
    return fd;
}

int CorrectWord(char* word)
{ 
    int strlenght = strlen(word);
    if(strlenght == 0)
    {
        return 0;
    }
    for(int i = 0;i < strlenght;i++)
    {
        if(strlenght - 1 - 2*i < 0)
        {
            break;
        }
        else if(word[i] != word[strlenght -1 - i])
        {
            return 0;
        }
    }
    return 1;
}

void puttinginresults(char word[], char results[], int *q, int lenght)
{
    if(CorrectWord(word))
    {
        int temp = *q;
        if(temp != 0)
        {
            results[temp] = ' ';
            temp++;
        }
        for(int x = temp, j = 0; x < temp + lenght; x++, j++)
        {
            results[x] = word[j];
        }
        temp += lenght;
        *q = temp;
    }
}

char FindingWords(char text[], char results[])
{
    int i = 0, q = 0;
    char word[256];
    memset(word, 0, 256 * sizeof(char)); // clear malloc memory

    int j = 0;
    while(text[i] != '\0')
    {
        if(text[i] != ' ' && text[i] != '\n')
        {
            word[j] = text[i];
            j++;
        }
        else
        {
            puttinginresults(word, results, &q, j);
            j = 0;
            memset(word, 0, 256 * sizeof(char)); // clear malloc memory
        }
        i++;
    }
    puttinginresults(word, results, &q, j);
    results[q] = '\0';
}