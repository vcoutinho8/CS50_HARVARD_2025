#include <cs50.h>
#include <math.h>
#include <stdio.h>

bool validar_luhn(long numero)
{
    int soma = 0;
    int multiplicar = 0;

    while (numero > 0)
    {
        soma += numero % 10;
        numero /= 10;

        multiplicar = (numero % 10) * 2;
        soma += multiplicar / 10 + multiplicar % 10;
        numero /= 10;
    }
    return soma % 10 == 0;
}

int main(void)
{
    long cartao = get_long("Número: ");
    long cartao_copia = cartao;
    int digitos = 0;

    // Contar dígitos
    while (cartao_copia > 0)
    {
        cartao_copia /= 10;
        digitos++;
    }

    cartao_copia = cartao;

    if (!validar_luhn(cartao))
    {
        printf("INVÁLIDO\n");
        return 0;
    }

    // Verifica tipo de cartão
    if ((cartao >= 340000000000000 && cartao < 350000000000000) ||
        (cartao >= 370000000000000 && cartao < 380000000000000))
    {
        printf("AMEX\n");
    }
    else if (cartao >= 5100000000000000 && cartao < 5600000000000000)
    {
        printf("MASTERCARD\n");
    }
    else if ((digitos == 13 || digitos == 16) && cartao / (long)pow(10, digitos - 1) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVÁLIDO\n");
    }

    return 0;
}
