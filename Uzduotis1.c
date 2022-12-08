#include <stdio.h>

int main() {
   int Skaicius, BuvesSkaicius;
   float NariuSuma = 0, Suma = 0;
   scanf("%d", Skaicius);
   do
   {
       Suma += Skaicius;
       NariuSuma++;
       BuvesSkaicius = Skaicius;
       scanf("%d", Skaicius);
   }
   while(BuvesSkaicius <= Skaicius);
   printf("Sekos nariu skaičius: %d/n", NariuSuma);
   printf("Aritmetinis vidurkis: %.2lf", Suma/NariuSuma);
   return 0;
}
