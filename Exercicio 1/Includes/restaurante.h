#ifndef _RESTAURANTE_H
#define _RESTAURANTE_H

#include "alimento.h"

#define MAX_N_ALIMENTOS 10

typedef struct{

    char nome[32];
    int numeroAlimentos;
    tAlimento alimentos[MAX_N_ALIMENTOS];

} tRestaurante;

/**
 * @brief cria um tipo tRestaurante a partir dos parametros
 * @param nome nome do restaurante a ser criado
 * @return tipo tRestaurante inicializado, com a array de alimentos vazia e numeroAlimentos zerado
 */
tRestaurante criaRestaurante(char *nome);

/**
 * @brief lê as informações do restaurante e retorna o tipo tRestaurante atualizado
 * a partir da entrada
 * Dica:
 * Aqui usa-se o scanf para ler o nome, numeroAlimentos e os alimentos a serem armazenados na array de alimentos
 * Após isso, use a funcao criaRestaurante para retornar o tRestaurante inicializado com as informações lidas
 * @return tipo tRestaurante inicializado
 */
tRestaurante leRestaurante();

/**
 * @brief adiciona um tipo tAlimento a array de alimentos de um restaurante
 * @param r restaurante a ter o alimento cadastrado
 * @param a alimento a ser cadastrado
 * @return tRestaurante atualizado com o alimento cadastrado
 */
tRestaurante cadastraAlimento(tRestaurante r, tAlimento a);

/**
 * @brief consome um alimento, armazenado na array de alimentos
 * @param nome nome do alimento a ser consumido
 * Dica:
 * Utilize o nome para pesquisar o alimento dentro da array de alimentos
 * Use a strcmp da biblioteca string.h para comparar os nomes
 * @param qtd quantidade a ser consumida
 * @return restaurante atualizado
 */
tRestaurante consumirAlimentoRestaurante(tRestaurante r, char *nome, float qtd);

/**
 * @brief retorna a quantidade consumida por todos os alimentos do restaurante
 * @param r restaurante a ter a quantidade consumida retornada
 * @return quantidade em gramas consumida ao total
 */
float quantidadeConsumida(tRestaurante r);

/**
 * @brief retorna a renda total de todos os alimentos produzidos pelo restaurante
 * @param r restaurante a ter a renda total retornada
 * @return renda total
 */
float rendaTotal(tRestaurante r);

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
 void imprimeRestaurante(tRestaurante r);
#endif