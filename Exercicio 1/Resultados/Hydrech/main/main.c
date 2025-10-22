#include <stdio.h>
#include "restaurante.h"
#include "alimento.h"

int main()
{

    tAlimento alimento;
    tRestaurante restaurante = leRestaurante();

    char tipo;
    char nome[32];
    float qtd;

    while (scanf("%c\n", &tipo) && tipo != 'E')
    {
        switch (tipo)
        {
        case 'A':
            alimento = leAlimento();
            restaurante = cadastraAlimento(restaurante, alimento);
            break;
        case 'C':
            char nome[32];
            float qtd;
            scanf("%[^\n]\n", nome);
            scanf("%f\n", &qtd);
            restaurante = consumirAlimentoRestaurante(restaurante, nome, qtd);
            break;
        case 'I':
            imprimeRestaurante(restaurante);
            break;

        default:
            break;
        }
    }

    return 0;
}