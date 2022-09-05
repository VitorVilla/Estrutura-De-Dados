#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Sorteio
{
    string nome;
    int num;
};

Sorteio numero(Sorteio sort)
{
    int numero;
    srand(time(NULL));
    numero = rand() % 10 + 1;
    sort.num = numero;
    return sort;
}

int main()
{

    setlocale(LC_ALL, "Portuguese");

    Sorteio sort;
    int escolha;

    sort = numero(sort);

    cout << "Digite um número: ";
    cin >> escolha;

    cout << "-------------------- \n";

    switch (sort.num)
    {
    case 1:
        sort.nome = "Vitor";
        break;

    case 2:
        sort.nome = "Thainá";
        break;

    case 3:
        sort.nome = "Bruno";
        break;

    case 4:
        sort.nome = "Pablo";
        break;

    case 5:
        sort.nome = "Daniel";
        break;

    case 6:
        sort.nome = "Murilo";
        break;

    case 7:
        sort.nome = "Witer";
        break;

    case 8:
        sort.nome = "Luiza";
        break;

    case 9:
        sort.nome = "Klayvert";
        break;

    case 10:
        sort.nome = "SAMA";
        break;
    }

    if (sort.num == escolha)
    {
        cout << "CHIERTO era esse número mesmo" << endl;
        cout << "A pessoa com esse numero era " << sort.nome << endl;
    }
    else
    {
        cout << "OLHA PRA MIM!, você errou" << endl;
        cout << "O número sorteado era: " << sort.num << endl;
        cout << "A pessoa com esse numero era " << sort.nome << endl;
    }

    return 0;
}
