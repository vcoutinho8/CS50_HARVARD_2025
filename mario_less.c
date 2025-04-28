#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int altura;
    do
    {
        altura = get_int("Altura: ");
    }
    while (altura < 1 || altura > 8);


    for (int i = 1; i <= altura; i++)
    {
        for (int y = 1; y <= altura - i; y++)
        {
            printf(" ");
        }

        for (int x = 1; x <= i; x++) 
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

