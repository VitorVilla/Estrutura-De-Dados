#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

/*Faça um programa que controle o fluxo de voos nos aeroportos do Brasil.Temos 5 aeroportos e 10 voos.

● Crie e leia do usuário um vetor de voos, sendo que cada voo contém um código de aeroporto de origem e um de destino.

● Crie um vetor de aeroportos, sendo que cada aeroporto contém seu código, nome, quantidade de voos que saem e quantidade de voos que chegam.

Nota : Cada aeroporto é identificado por um código inteiro entre 0 e 5. Não aceite aeroportos de código inexistente(faça a verificação).

CUIDADO : tem um valor em comum que interliga as duas structs.Tenha coerência na hora de popular as structs.Um aeroporto não pode ter mais de 10 voos nem de chegada e nem de saída, faça a verificação disso.

Por fim, exiba na tela o nome de cada aeroporto e os voos que chegaram e saíram dele, ou seja, o nome do aeroporto de origem do voo e o nome do aeroporto de destino do voo.

*/

struct Voos
{
    int cod_origem;
    int cod_destino;
};

struct Aeroportos
{
    int cod;
    string nome;
    int quant_vooS;
    int qunat_vooC;
};

int main()
{
    Voos voo[2];
    Aeroportos aero[5];

    for (int i = 0; i < 2; i++)
    {
        cout << "Digite o código do aeroporto (Só aceitamos codigod entre 0 e 5) " << i + 1 << endl;
        cin >> aero[i].cod;
        cout << "Digite o nome do aeroporto " << i + 1 << endl;
        cin >> aero[i].nome;
        cout << "Digite a qunatidade de voos que saem do aeroporto " << i + 1 << endl;
        cin >> aero[i].quant_vooS;
        cout << "Digite a quantidade de voos que chegam do aeroporto " << i + 1 << endl;
        cin >> aero[i].qunat_vooC;
        cout << "-------------------- \n";
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "";
    }

    //N ENTENDI O ENUNCIADO
}
