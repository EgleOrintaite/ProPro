#include <stdio.h>
#include <library.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char results[256];
    char *line;
    line = (char*)malloc(1 * sizeof(char));
    memset(line, 0, sizeof(char));

    printf("Parasykite failo pavadinima, kuriame yra duomenys (.txt formatu)\n");
    FILE* fd = Files("r");

    printf("Parasykite failo pavadinima, kuriame norite matyti rezultatus (.txt formatu)\n");
    FILE *fr = Files("w");
    size_t lenght = 256;
    ssize_t read;
    char *text = NULL;
    int pirmas = 1;
    while((read = getline(&text, &lenght, fd)) != -1)
    {
        if(pirmas)
        {
            pirmas = 0;
        }
        else{
            fputs("\n", fr);
        }
        int l = read;
        if(read >= 255)
        {
            l = 255;
        }
        line = realloc(line, l*sizeof(char));
        for(int i = 0;i < l;i++)
        {
            line[i] = text[i];
        }
        line[l] = '\0';
        FindingWords(line, results);
        fputs(results, fr);
        memset(results, 0, 256 * sizeof(char));
        memset(line, 0, l*sizeof(char));
    }

    return 0;
}