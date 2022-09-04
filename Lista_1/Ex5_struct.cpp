#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

struct Prod
{
    char nome[15];
    int codigo;
    int quantidade;
    float preco;
};

struct Pedido
{
    int codigo_produto;
    int qunatidade_produto;
};

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Prod produtos[2];
    Pedido pedido;
    string resp = "sim";

    for (int i = 0; i < 2; i++)
    {
        cout << "Digite o código do produto " << i + 1 << endl;
        cin >> produtos[i].codigo;
        cout << "Digite o nome do produto " << i + 1 << endl;
        cin >> produtos[i].nome;
        cout << "Digite o preço do produto " << i + 1 << endl;
        cin >> produtos[i].preco;
        cout << "Digite a quantidade do produto " << i + 1 << endl;
        cin >> produtos[i].quantidade;
        cout << "-------------------- \n";
    }

    while (resp == "sim")
    {
        cout << "Digite o código do produto: ";
        cin >> pedido.codigo_produto;
        cout << "Digite a quantidade do produto: ";
        cin >> pedido.qunatidade_produto;
        cout << "-------------------- \n";

        for (int i = 0; i < 2; i++)
        {
            if (pedido.codigo_produto == produtos[i].codigo)
            {
                if (pedido.qunatidade_produto <= produtos[i].quantidade)
                {
                    produtos[i].quantidade -= pedido.qunatidade_produto;
                    cout << "Item vendido: " << produtos[i].codigo << endl;
                    cout << "Quantidade vendida: " << pedido.qunatidade_produto << endl;
                    cout << "Restam no estoque: " << produtos[i].quantidade << endl;
                    cout << "-------------------- \n";
                }
                else if (pedido.qunatidade_produto > produtos[i].quantidade)
                {
                    cout << "Falha na compra produto em falta no estoque" << endl;
                    cout << "Produto " << pedido.codigo_produto << endl
                         << "Quantidade no estoque: " << produtos[i].quantidade << endl;
                    cout << "-------------------- \n";
                }
            }
        }
        cout << "Você deseja fazer novamente sim ou não" << endl;
        cin >> resp;
        cout << "-------------------- \n";
    }
}
