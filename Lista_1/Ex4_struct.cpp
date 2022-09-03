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

struct Triangulo
{
    Ponto A;
    Ponto B;
    Ponto C;
};

float calculo(Ponto PA, Ponto PB)
{
    float dist;
    dist = pow((PA.x - PB.x), 2) + pow((PA.y - PB.y), 2);
    return sqrt(dist);
}

void triangulo(Ponto pa, Ponto pb, Ponto pc, Ponto pA, Ponto pB, Ponto pC)
{
    Triangulo T1, T2;

    float a, b, c, ab, bb, cb;

    T1.A = pa;
    T1.B = pb;
    T1.C = pc;

    T2.A = pA;
    T2.B = pB;
    T2.C = pC;

    a = calculo(T1.A, T1.B);
    b = calculo(T1.B, T1.C);
    c = calculo(T1.A, T1.C);

    ab = calculo(T2.A, T2.B);
    bb = calculo(T2.B, T2.C);
    cb = calculo(T2.A, T2.C);

    if ((a == b) && (b == c))
    {
        cout << "O triângulo 1 é equilátero \n";
    }
    else if ((a != b) && (a != c) && (b != c))
    {
        cout << "O triângulo 1 é escaleno \n";
    }
    else
    {
        cout << "O triângulo 1 é isósceles \n";
    }

    cout << "----------------------- \n";

    if ((ab == bb) && (bb == cb))
    {
        cout << "O triângulo 2 é equilátero";
    }
    else if ((ab != bb) && (ab != cb) && (bb != cb))
    {
        cout << "O triângulo 2 é escaleno";
    }
    else
    {
        cout << "O triângulo 2 é isósceles";
    }
}

int main()
{

    Ponto pa, pb, pc, pA, pB, pC;

    cout << "Digite X de ponto A (triângulo 1): ";
    cin >> pa.x;

    cout << "Digite Y de ponto A (triângulo 1): ";
    cin >> pa.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto B (triângulo 1): ";
    cin >> pb.x;

    cout << "Digite Y de ponto B (triângulo 1): ";
    cin >> pb.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto C (triângulo 1): ";
    cin >> pc.x;

    cout << "Digite Y de ponto C (triângulo 1): ";
    cin >> pc.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto A (triângulo 2): ";
    cin >> pA.x;

    cout << "Digite Y de ponto A (triângulo 2): ";
    cin >> pA.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto B (triângulo 2): ";
    cin >> pB.x;

    cout << "Digite Y de ponto B (triângulo 2): ";
    cin >> pB.y;

    cout << "----------------------- \n";

    cout << "Digite X de ponto C (triângulo 2): \n";
    cin >> pC.x;

    cout << "Digite Y de ponto C (triângulo 2): \n";
    cin >> pC.y;

    triangulo(pa, pb, pc, pA, pB, pC);

    return 0;
}
