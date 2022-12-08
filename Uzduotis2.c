/*
    LSP numeris: 2213778
    egleorintaite@gmail.com
    2 uzduotis
    3 variantas
*/
#include <stdio.h>

int intvalidacija()
{
    int n;
    while(1)
    {
        if(scanf("%d", &n) == 1 && getchar() == '\n')
        {
            return n;
        }
        else
        {
            printf("Ivestis nera naturalusis skaicius. Iveskite naturaluji skaiciu:\n");
            while(getchar() != '\n')
            {

            }
        }
    }
}

void poros(int* a, int* b)
{
    int x, y;
    while(1)
    {
        if(scanf("%d", &x) == 1 && getchar() == ' ')
        {
            if(scanf("%d", &y) == 1  && getchar() == '\n')
            {
                break;           
            }
            else{
                printf("Antras poros skaicius nera sveikas skaicius. Iveskite sveiku skaiciu pora: \n");
                while(getchar() != '\n')
                {

                }
            }
        }
        else{
            printf("Pirmas poros skaicius nera sveikas skaicius. Iveskite sveiku skaiciu pora: \n");
            while(getchar() != '\n')
            {

            }
        }
    }
    *a = x;
    *b = y;
}

int main() {

    int n = -1, count = 0;

    printf("Iveskite naturaluji skaiciu:\n");

    while(n < 0)
    {
        n = intvalidacija();
        if(n < 0)
        {
            printf("Ivestas sveikas skaicius nera naturalusis ( nera teigiamas). Iveskite naturaluji skaiciu:\n");
        }
    }

    int M[n][2], I[n][2], g;

    printf("Iveskite %d sveiku skaiciu poru: \n", n);

    for(int i = 0;i < n;i++)
    {
        poros(&M[i][0], &M[i][1]);
        (M[i][0] <= M[i][1]) ? (I[i][0] = M[i][0]) : (I[i][0] = M[i][1]);
        (M[i][0] >= M[i][1]) ? (I[i][1] = M[i][0]) : (I[i][1] = M[i][1]);
    }

    printf("Iveskite sveika skaiciu:\n");
    g = intvalidacija();

    printf("Rezultatai:\n");
    for(int i = 0;i < n;i++)
    {
        if(I[i][0] <= g && I[i][1] >= g)
        {
            printf("%d, %d\n", M[i][0], M[i][1]);
            count++;
        }
    }
    printf("Is viso tinkanciu poru buvo: %d\n", count);


    return 0;
}