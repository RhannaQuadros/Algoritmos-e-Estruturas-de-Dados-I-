#include "sistema.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    UINT UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    ListaEncadeada *listaEncadeada = new ListaEncadeada;
    CriaListaEncadeadaVazia(listaEncadeada);

    bool carregouComSucesso = carregaArquivo(listaEncadeada);

    if (!carregouComSucesso) //garantindo um carregamento com sucesso
    {
        cout << "Houve problemas ao carregar os funcionarios do arquivo: " << NOME_ARQUIVO << endl;
        system("pause");
    }

    int opcao;
    do
    {
        menu(); //chamando o menu
        cin >> opcao;
        cin.ignore();
        system("cls");

        switch (opcao)
        {
        case 1:
            incluiNovoFuncionario(listaEncadeada);
            break;
        case 2:
            incluiNovosProjetos(listaEncadeada);
            break;
        case 3:
            excluiProjetos(listaEncadeada);
            break;
        case 4:
            excluiFuncionariosSemProjetos(listaEncadeada);
            break;
        case 5:
            consultaFuncionario(listaEncadeada);
            break;
        case 6:
            imprimeContraCheque(listaEncadeada);
            break;
        }

    } while (opcao != OPCAO_SAIDA);

    bool salvouComSucesso = salvaArquivo(listaEncadeada);

    if (!salvouComSucesso) //garantindo um salvamento com sucesso
    {
        cout << "Houve problemas ao salvar os funcionarios no arquivo: " << NOME_ARQUIVO << endl;
    }

    return 0;
}