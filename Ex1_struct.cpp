#include <iostream>
#include <math.h>
#include <locale>
#include <cstdlib>

using namespace std;

struct cad
{
    string nome;
    float cpf;
    float valor_conta;
};

cad *cadastro(cad user[2])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Digite o nome do usuário: ";
        cin >> user[i].nome;

        cout << "Digite o cpf do usuário: ";
        cin >> user[i].cpf;

        cout << "Digite o valor da conta: ";
        cin >> user[i].valor_conta;

        cout << endl;
    }
    return user;
}

cad *bubble_sort(cad user[2])
{
    cad aux;
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < 1; i++)
        {
            if (user[i].valor_conta < user[i + 1].valor_conta)
            {
                aux = user[i];
                user[i] = user[i + 1];
                user[i + 1] = aux;
            }
        }
    }
    return user;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    cad user[2], teste[2];

    user[2] = *cadastro(user);
    user[2] = *bubble_sort(user);
    
    cout << endl;

    for (int a = 0; a < 2; a++)
    {
        cout << "Os cpf são: " << user[a].cpf << endl;
        cout << "Os nomes são: " << user[a].nome << endl;
        cout << "O valor é: " << user[a].valor_conta << endl;

        cout << "-------------------------------------- \n";
    }

    return 0;
}