#include <iostream>
#include <locale>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{

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

    Pessoa user[5];
    int auxD, auxM, auxA;
    string auxN;

    for (int i = 0; i < 5; i++)
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

    for (int i = 0; i < 5; i++)
    {
        for (int c = i + 1; c < 4; c++)
        {
            if (user[i].data.ano > user[c].data.ano)
            {
                auxA = user[i].data.ano;
                user[i].data.ano = user[c].data.ano;
                user[c].data.ano = auxA;

                auxM = user[i].data.mes;
                user[i].data.mes = user[c].data.mes;
                user[c].data.mes = auxM;

                auxD = user[i].data.dia;
                user[i].data.dia = user[c].data.dia;
                user[c].data.dia = auxD;

                auxN = user[i].nome;
                user[i].nome = user[c].nome;
                user[c].nome = auxN;
            }
            else if (user[i].data.mes > user[c].data.mes)
            {
                auxA = user[i].data.ano;
                user[i].data.ano = user[c].data.ano;
                user[c].data.ano = auxA;

                auxM = user[i].data.mes;
                user[i].data.mes = user[c].data.mes;
                user[c].data.mes = auxM;

                auxD = user[i].data.dia;
                user[i].data.dia = user[c].data.dia;
                user[c].data.dia = auxD;

                auxN = user[i].nome;
                user[i].nome = user[c].nome;
                user[c].nome = auxN;
            }
            else if (user[i].data.dia > user[c].data.dia)
            {
                auxA = user[i].data.ano;
                user[i].data.ano = user[c].data.ano;
                user[c].data.ano = auxA;

                auxM = user[i].data.mes;
                user[i].data.mes = user[c].data.mes;
                user[c].data.mes = auxM;

                auxD = user[i].data.dia;
                user[i].data.dia = user[c].data.dia;
                user[c].data.dia = auxD;

                auxN = user[i].nome;
                user[i].nome = user[c].nome;
                user[c].nome = auxN;
            }
        }
    }

    cout << "O nome é: " << user[0].nome << endl;
    cout << "A data é: " << user[0].data.dia << "/" << user[0].data.mes << "/" << user[0].data.ano << endl;

    return 0;
}
