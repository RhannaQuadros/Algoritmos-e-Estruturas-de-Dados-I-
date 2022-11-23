#include "listaSequencial.hpp"

void Lista_Inicializa(ListaSequencial *lista)
{
    if (!lista->listaCriada)
    {
        lista->listaCriada = true;
        lista->tamanho = 0;
    }
}

bool Lista_Vazia(ListaSequencial lista)
{
    return lista.tamanho == 0;
}

bool Lista_Cheia(ListaSequencial lista)
{
    return lista.tamanho == MAX_ENTREGA;
}

bool Lista_Insere(ListaSequencial *lista, Pedido pedido)
{
    if (!lista->listaCriada || Lista_Cheia(*lista))
    {
        return false;
    }
    lista->pedidos[lista->tamanho] = pedido;
    lista->tamanho++;
    return true;
}

void Lista_Imprime(ListaSequencial lista)
{
    for (int i = 0; i < lista.tamanho; i++)
    {
        Pedido pedido = lista.pedidos[i];
        imprimePedido(pedido, true);
    }
}

bool Lista_Remove_Id(ListaSequencial *lista, int id)
{
    if (Lista_Vazia(*lista))
    {
        return false;
    }

    for (int i = id; i < lista->tamanho; i++)
    {
        lista->pedidos[i] = lista->pedidos[i + 1];
    }

    lista->tamanho--;
    return true;
}

bool Lista_Remove(ListaSequencial *lista, Pedido pedido)
{
    if (Lista_Vazia(*lista))
    {
        cout << "Erro: Lista está vazia" << endl;
        return false;
    }

    int indice = IndeceDe(*lista, pedido);

    if (indice == -1)
    {
        return false;
    }

    return Lista_Remove_Id(lista, indice);
}

int IndeceDe(ListaSequencial lista, Pedido pedido)
{
    for (int i = 0; i < lista.tamanho; i++)
    {
        if (lista.pedidos[i].codigo == pedido.codigo)
        {
            return i;
        }
    }
    return -1;
}

int Lista_Tamanho(ListaSequencial lista)
{
    return lista.tamanho;
}
