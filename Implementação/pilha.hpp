#define MAX_PRODUTOS 10
#define MAX_ENTREGA 7

#include <iostream>

using namespace std;

typedef struct Produto
{
    int codigo;
    char nome[100];
    float valor_produto;
};

#define NUM_PRODUTOS_CARDAPIO 5
Produto cardapio[NUM_PRODUTOS_CARDAPIO];

typedef struct Pedido
{
    int codigo;
    int produtos[MAX_PRODUTOS];
    int total_produtos = 0;
    float valor_pedido = 0;
    float distancia = 0;
};

typedef struct Pilha
{
    Pedido pedidos[MAX_ENTREGA];
    int topo;
};

void Pilha_Inicializa(Pilha *pilha); //Cria pilha vazia
bool Pilha_Vazia(Pilha pilha); //retorna TRUE para pilha vazia, e FALSE para pilha com pelo menos 1 pedido inserido
bool Pilha_Cheia(Pilha pilha); //retorna TRUE para pilha cheia, e FALSE para pilha com nenhum 1 pedido inserido
void Pilha_Empilha(Pilha *pilha, Pedido pedido); //insere no topo da pilha
bool Pilha_Desempilha(Pilha *pilha); //remove do topo da pilha
void Pilha_Imprime(Pilha pilha, bool imprimirProdutos); //exibe a pilha com os pedidos, e os produtos dentro do pedido
void imprimePedido(Pedido pedido, bool imprimirProdutos); //exibe o pedido com o produto
void imprimeProdutos(Pedido pedido); //exibe o produto
int Pilha_Tamanho(Pilha pilha); //retorna a quantidade de itens a ser entregue
Pedido Pilha_Topo(Pilha pilha); // retorna o topo da pilha
Pilha Pilha_Ordena(Pilha pilha); //ordena a pilha com base na distancia
