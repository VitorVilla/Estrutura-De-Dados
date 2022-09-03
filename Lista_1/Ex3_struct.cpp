#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

struct Ponto
{
    float x;
    float y;
};

float calculo(Ponto PA, Ponto PB)
{
    float dist;
    dist = pow((PA.x - PB.x), 2) + pow((PA.y - PB.y), 2);
    return sqrt(dist);
}

int main()
{

    Ponto PA, PB;

    cout << "Digite X de ponto A: ";
    cin >> PA.x;

    cout << "Digite Y de ponto A: ";
    cin >> PA.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto B: ";
    cin >> PB.x;

    cout << "Digite Y de ponto B: ";
    cin >> PB.y;

    cout << "----------------------- \n";

    cout << "A distancia entre o ponto A (" << PA.x << "," << PA.y << ") "
         << "e o ponto B (" << PB.x << "," << PB.y << ")"
         << " é de: " << calculo(PA, PB) << endl;

    return 0;
}
