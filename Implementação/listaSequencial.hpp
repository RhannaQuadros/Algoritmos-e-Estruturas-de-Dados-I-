#ifndef LISTA_ARRANJO_H
#define LISTA_ARRANJO_H
#include "pilha.hpp"
#include <iostream>

using namespace std;

typedef struct ListaSequencial
{
    Pedido pedidos[MAX_ENTREGA];
    int tamanho;
    bool listaCriada = false;
};

void Lista_Inicializa(ListaSequencial *lista);               // Cria uma lista vazia
bool Lista_Vazia(ListaSequencial lista);                    // Retorna TRUE se a lista estiver vazia, FALSE caso contrário
bool Lista_Cheia(ListaSequencial lista);                    // Retorna TRUE se a lista estiver cheia, FALSE caso contrário
bool Lista_Insere(ListaSequencial *lista, Pedido pedido);    // Insere Pedido na lista ListaSequencial
void Lista_Imprime(ListaSequencial lista);                  // Imprime a lista
bool Lista_Remove_Id(ListaSequencial *lista, int id);        // Remove um Pedido da lista via ID
bool Lista_Remove(ListaSequencial *lista, Pedido pedido);    // Remove um Pedido da lista
int IndeceDe(ListaSequencial lista, Pedido pedido);         // Retorna o indice do pedido na lista, -1 se não tiver o pedido
int Lista_Tamanho(ListaSequencial lista);                   // Retorna o número de itens da lista

#endif
