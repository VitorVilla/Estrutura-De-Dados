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

cad *cadastro(cad user[5])
{
    for (int i = 0; i < 5; i++)
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

cad *bubble_sort(cad user[5])
{
    cad aux;
    for (int c = 0; c < 5; c++)
    {
        for (int i = 0; i < 4; i++)
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

    cad user[5];

    user[5] = *cadastro(user);
    user[5] = *bubble_sort(user);

    cout << endl;

    for (int a = 0; a < 5; a++)
    {
        cout << "O nome é: " << user[a].nome << endl;
        cout << "O cpf é: " << user[a].cpf << endl;
        cout << "O valor é: " << user[a].valor_conta << endl;

        cout << "-------------------------------------- \n";
    }

    return 0;
}