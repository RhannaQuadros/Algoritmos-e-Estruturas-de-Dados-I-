#include "pilha.hpp"

void Pilha_Inicializa(Pilha *pilha)
{
    pilha->topo = 0;
}

bool Pilha_Vazia(Pilha pilha)
{
    return pilha.topo == 0;
}

bool Pilha_Cheia(Pilha pilha)
{
    return pilha.topo == MAX_ENTREGA;
}

void Pilha_Empilha(Pilha *pilha, Pedido pedido)
{
    if (!Pilha_Cheia(*pilha))
    {
        pilha->pedidos[pilha->topo] = pedido;
        pilha->topo++;
    }
}

bool Pilha_Desempilha(Pilha *pilha)
{
    if (!Pilha_Vazia(*pilha))
    {
        pilha->topo--;
        return true;
    }
    return false;
}

void Pilha_Imprime(Pilha pilha, bool imprimirProdutos)
{
    for (int i = pilha.topo - 1; i >= 0; i--)
    {
        Pedido pedido = pilha.pedidos[i];
        imprimePedido(pedido, imprimirProdutos);
    }
}

void imprimePedido(Pedido pedido, bool imprimirProdutos)
{
    cout << "Cód. Pedido: " << pedido.codigo << endl;
    if (imprimirProdutos)
    {
        imprimeProdutos(pedido);
    }
    cout << "Valor do Pedido: R$" << pedido.valor_pedido << endl;
    cout << "Distância: " << pedido.distancia << " metros\n"
         << endl;
}

void imprimeProdutos(Pedido pedido)
{
    cout << "Produtos: " << endl;
    for (int i = 0; i < pedido.total_produtos; i++)
    {
        int codigoProduto = pedido.produtos[i];
        Produto produto = cardapio[codigoProduto - 1];
        cout << "\tCód. Produto: " << produto.codigo << endl;
        cout << "\tNome: " << produto.nome << endl;
        cout << "\tValor do Produto: " << produto.valor_produto << endl;
        cout << '\n';
    }
}

int Pilha_Tamanho(Pilha pilha)
{
    return pilha.topo;
}

Pedido Pilha_Topo(Pilha pilha)
{
    return pilha.pedidos[pilha.topo - 1];
}

Pilha Pilha_Ordena(Pilha pilha)
{
    Pilha auxPilha;
    Pilha_Inicializa(&auxPilha);

    while (!Pilha_Vazia(pilha))
    {
        Pedido pedido = Pilha_Topo(pilha);
        Pilha_Desempilha(&pilha);

        while (!Pilha_Vazia(auxPilha) && Pilha_Topo(auxPilha).distancia < pedido.distancia)
        {
            Pilha_Empilha(&pilha, Pilha_Topo(auxPilha));
            Pilha_Desempilha(&auxPilha);
        }
        Pilha_Empilha(&auxPilha, pedido);
    }
    return auxPilha;
}