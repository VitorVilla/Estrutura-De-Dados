#include <iostream>
#include <math.h>
#include <locale>
#include <cstdlib>

using namespace std;

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Pessoa
{
    string nome;
    Data data;
};

Pessoa *cadastro(Pessoa user[2])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "Digite o nome do usuário: ";
        cin >> user[i].nome;

        cout << "Digite o dia do seu nascimento: ";
        cin >> user[i].data.dia;

        cout << "Digite o mês do seu nascimento: ";
        cin >> user[i].data.mes;

        cout << "Digite o ano do seu nascimento: ";
        cin >> user[i].data.ano;

        cout << endl;
    }
    return user;
}

int main()
{

    Pessoa user[2];

    user[2] = *cadastro(user);

    for (int a = 0; a < 2; a++)
    {
        cout << "O nome é: " << user[a].nome << endl;
        cout << "A data é: " << user[a].data.dia << "/" << user[a].data.mes << "/" << user[a].data.ano << endl;

        cout << "-------------------------------------- \n";
    }

    return 0;
}
