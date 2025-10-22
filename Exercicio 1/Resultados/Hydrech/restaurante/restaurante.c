#include <stdio.h>
#include <string.h>

#include "restaurante.h"
#include "alimento.h"

#define MAX_N_ALIMENTOS 10

/**
 * @brief cria um tipo tRestaurante a partir dos parametros
 * @param nome nome do restaurante a ser criado
 * @return tipo tRestaurante inicializado, com a array de alimentos vazia e numeroAlimentos zerado
 */
tRestaurante criaRestaurante(char *nome)
{
    tRestaurante r;

    strcpy(r.nome, nome);
    r.numeroAlimentos = 0;

    return r;
}

/**
 * @brief lê as informações do restaurante e retorna o tipo tRestaurante atualizado
 * a partir da entrada
 * Dica:
 * Aqui usa-se o scanf para ler o nome, numeroAlimentos e os alimentos a serem armazenados na array de alimentos
 * Após isso, use a funcao criaRestaurante para retornar o tRestaurante inicializado com as informações lidas
 * @return tipo tRestaurante inicializado
 */
tRestaurante leRestaurante()
{

    char nome[32];
    scanf("%[^\n]\n", nome);
    tRestaurante r;
    r = criaRestaurante(nome);
    return r;
}

/**
 * @brief adiciona um tipo tAlimento a array de alimentos de um restaurante
 * @param r restaurante a ter o alimento cadastrado
 * @param a alimento a ser cadastrado
 * @return tRestaurante atualizado com o alimento cadastrado
 */
tRestaurante cadastraAlimento(tRestaurante r, tAlimento a)
{
    r.alimentos[r.numeroAlimentos] = a;
    r.numeroAlimentos++;
    return r;
}

/**
 * @brief consome um alimento, armazenado na array de alimentos
 * @param nome nome do alimento a ser consumido
 * Dica:
 * Utilize o nome para pesquisar o alimento dentro da array de alimentos
 * Use a strcmp da biblioteca string.h para comparar os nomes
 * @param qtd quantidade a ser consumida
 * @return restaurante atualizado
 */
tRestaurante consumirAlimentoRestaurante(tRestaurante r, char *nome, float qtd)
{
    for (int i = 0; i < r.numeroAlimentos; i++)
    {
        if (strcmp(r.alimentos[i].nome, nome) == 0)
        {
            r.alimentos[i] = consumirAlimento(r.alimentos[i], qtd);
        }
    }
    return r;
}

/**
 * @brief retorna a quantidade consumida por todos os alimentos do restaurante
 * @param r restaurante a ter a quantidade consumida retornada
 * @return quantidade em gramas consumida ao total
 */
float quantidadeConsumida(tRestaurante r)
{
    float quantidadeConsumida = 0;
    for (int i = 0; i < r.numeroAlimentos; i++)
    {
        quantidadeConsumida += r.alimentos[i].qtdConsumida;
    }
    return quantidadeConsumida;
}

/**
 * @brief retorna a renda total de todos os alimentos produzidos pelo restaurante
 * @param r restaurante a ter a renda total retornada
 * @return renda total
 */
float rendaTotal(tRestaurante r)
{
    float renda = 0;
    for (int i = 0; i < r.numeroAlimentos; i++)
    {
        renda += rendaAlimento(r.alimentos[i]);
    }
    return renda;
}

/**
 * @brief imprime as informações do restaurante, seguindo as regras de formatação do exercicio
 * Exemplo:
 * Nome: Bicho Guloso
 * Alimentos:
 * --------------------
 * Nome: pudim de arroz
 * Quantidade: 1200.00 gramas
 * Preco: R$ 12.00/kg
 * Quantidade consumida: 200.00 gramas
 * Renda: R$ 2.40
 * --------------------
 * --------------------
 * Nome: pudim de linguica
 * Quantidade: 2000.00 gramas
 * Preco: R$ 21.00/kg
 * Quantidade consumida: 1000.00 gramas
 * Renda: R$ 21.00
 * --------------------
 * Quantidade total consumida: 1200.00 gramas
 * Renda total: R$ 23.40
 */
void imprimeRestaurante(tRestaurante r)
{
    printf("Nome: %s\n", r.nome);
    printf("Alimentos:\n");
    for (int i = 0; i < r.numeroAlimentos; i++)
    {
        imprimeAlimento(r.alimentos[i]);
    }
    printf("Quantidade total consumida: %.2f\n", quantidadeConsumida(r));
    printf("Renda total: R$ %.2f\n", rendaTotal(r));
}