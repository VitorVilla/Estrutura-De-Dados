#include <iostream>
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

Pessoa *bubble_sort(Pessoa user[2])
{
    Pessoa aux;
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < 1; i++)
        {
            if (user[i].data.ano < user[i + 1].data.ano or user[i].data.mes < user[i + 1].data.mes or user[i].data.dia < user[i + 1].data.dia)
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

    Pessoa user[2], sla[2];

    user[2] = *cadastro(user);
    sla[2] = *bubble_sort(user);

    cout << "O nome é: " << sla[0].nome << endl;
    cout << "A data é: " << sla[0].data.dia << "/" << sla[0].data.mes << "/" << sla[0].data.ano << endl;

    return 0;
}
