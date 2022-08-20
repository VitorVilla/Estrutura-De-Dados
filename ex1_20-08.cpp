#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
/* Com base nas fun��es matem�ticas crie um programa que 
utiliza uma fun��o que recebe um numero e retorna o 
quadrado desse valor. Fa�a duas fun�oes uma utilizando
passagem de parametro por valor e outra por referencia. */

void copia(int num);
void referencia(int num);

void copia (int num){
    num = pow(num,2);
}

void referencia(int *num){
    *num = pow(*num,2);
}

int main (){
    int num;
    
    cout << "Digite um número: ";
    cin >> num;
    
    copia(num);
    cout <<"O valor por copia é: " << num << endl;
    
    referencia(&num);
    cout <<"O valor por referencia é: " << num << endl;
}