#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <windows.h>
#include <fstream>
#include "listaSequencial.hpp"

using namespace std;

#define NOME_ARQUIVO "lanchonete.bin"
#define OPCAO_SAIDA 7

int codigoPedidoGlobal = 0;

bool carregaArquivo(ListaSequencial *listaSequencial); //abre o arquivo e insere os pedidos na pilha
void iniciaProdutos(); //insere os produtos no momento da inicialização
void adicionaProdutoCardapio(int codigo, char nome[], float valor_produto); //inserir os produtos no cardapio
void menu(); //menu de opções
void incluirPedido(ListaSequencial *listaSequencial); //inclui pedido na lista
void criaPedido(Pedido *pedido); //cria pedido para ser inserido na lista
void insereProdutos(Pedido *pedido); //insere produtos no pedido
bool validaCodigoProduto(int codigoProduto); //verifica se o codigo do produto existe
void listarPedidos(ListaSequencial listaSequencial); //lista todos os pedidos feitos
void verCardapio(); //mostra os produtos do cardapio
void consultarPedido(ListaSequencial listaSequencial); //verifica 1 pedido
void imprimirListaEntrega(Pilha *pilha, ListaSequencial listaSequencial); //mostra a pilha de entregas da menor distancia até a maior
void listaParaPilha(Pilha *pilha, ListaSequencial listaSequencial); //converte a lista de entregas para pilha de entregas
void lancarEntrega(Pilha *pilha, ListaSequencial *listaSequencial); //remove a entrega do topo
bool salvaArquivo(ListaSequencial *listaSequencial); //salva os pedidos da pilha no arquivo e depois fecha

#endif