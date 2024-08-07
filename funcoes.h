#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std; 

void geraVetorRandomico(int v[], int n){
    for (int i = 0; i < n; i++){
        v[i] = rand() % 1000;
    }
}
void imprimeVetor(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}
void heapChecker(int vet[], int n){
    for (int i = 0; i < n; i++){
        if(vet[i] > vet[2*i+1] || vet[i] > vet[2*i+2]){
            //pov: não é pra dar erro
            cout<<"erro"<<endl;
        }
    }
}
#endif