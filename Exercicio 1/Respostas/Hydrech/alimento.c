#include <stdio.h>
#include <string.h>

#include "alimento.h"

/**
 * @brief inicialzia um tipo tAlimento a partir dos parametros
 * qtdConsumida inicia-se = 0
 * @param nome nome do alimento a ser criado
 * @param qtd quantidade inicial em gramas do alimento a ser criado
 * @param preco preco, por QUILO, do alimento
 * @return tAlimento inicializado
 */
tAlimento criaAlimento(char *nome, float preco, float qtd)
{
    tAlimento a;
    strcpy(a.nome, nome);
    a.preco = preco;
    a.quantidade = qtd;
    a.qtdConsumida = 0;
    return a;
}

/**
 * @brief le as informações de um alimento
 * Dica:
 * Use o scanf para ler as informações do alimento (seguindo a formatação da entrada)
 * e chame a funcao criaAlimento para criar o alimento, passando como parametro as informações lidas pela entrada
 */
tAlimento leAlimento()
{
    char nome[32];
    float preco;
    float quantidade;
    float qtdConsumida = 0;

    scanf("%[^\n]\n", nome);
    scanf("%f %f\n", &preco, &quantidade);

    tAlimento a = criaAlimento(nome, preco, quantidade);
    return a;
}

/**
 * @brief Reduz a quantidade atual do alimento pela quantidade que será consumida
 * @param qtd quantidade do alimento, em gramas, que será consumida
 * @param alimento tAlimento que será consumido
 * @return tAlimento com a quantidade atualizada
 */
tAlimento consumirAlimento(tAlimento alimento, float qtd)
{
    alimento.quantidade -= qtd;
    alimento.qtdConsumida += qtd;
    return alimento;
}

/**
 * @brief calcula quanta renda o alimento gerou multiplicando o preço pela quantidade consumida
 * @param alimento tAlimento a ser retornado a renda
 * @return renda gerada pelo alimento
 */
float rendaAlimento(tAlimento alimento)
{
    return alimento.qtdConsumida * alimento.preco / 1000;
}

/**
 * @brief imprime as informações do alimento, seguindo as regras de formatação do exercicio
 * Exemplo:
 * --------------------
 * Nome: pudim de arroz
 * Quantidade: 1200 gramas
 * Preco: R$ 12.00/kg
 * Quantidade consumida: 200 gramas
 * Renda: R$ 2.4
 * --------------------
 */
void imprimeAlimento(tAlimento alimento)
{
    printf("--------------------\n");
    printf("Nome: %s\n", alimento.nome);
    printf("Quantidade: %.2f\n", alimento.quantidade);
    printf("Preco: R$ %.2f\n", alimento.preco);
    printf("Quantidade consumida: %.2f\n", alimento.qtdConsumida);
    printf("Renda: R$ %.2f\n", rendaAlimento(alimento));

    printf("--------------------\n");
}