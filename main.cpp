
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "merge.h"

#include "selection.h"
#include "funcoes.h"
#include "bubble.h"
#include "heap.h"
#include "insertion.h"
#include <stdio.h>

#define TAMANHO 1000000

using namespace std; 
class MedeTempo {
    private:
        string funcao;
        clock_t inicio;
    public:
        MedeTempo(const string &f) {
            inicio = clock();
            funcao = f;
        }
        void MedeTempoFim() {
            clock_t total = clock() - inicio;
            cout << "Tempo para a funcao " << funcao << ": (segundos) "<< double(total)/CLOCKS_PER_SEC<<endl;
        }
};
void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}
int particionamento(int vet[], int inicio, int fim){
    // posicao inicial do pivo
    int meio = (inicio+fim)/2;
    // coloca pivo no inicio
    troca(&vet[meio], &vet[inicio]);
    int i = inicio;
    //compara os elementos pra frente do pivo com o pivo j anda o vetor todo i anda só os menores que o pivo
    // se j for menor que o pivo j troca com i
    
    for(int j = inicio+1; j <= fim; j++){
        if(vet[j] < vet[inicio]){
            i++;
            troca(&vet[i], &vet[j]); // troca com i
        }
    }
    // coloca pivo na posicao correta
    troca(&vet[inicio], &vet[i]);
    // retorna a posicao do pivo
    return i;
}
void auxQuickSort(int vet[], int inicio, int fim){
    //para a recursao se esq for maior que dir ou igual
    if(inicio < fim){
        // pega a posicao do pivo( meio do vetor)
        int p = particionamento(vet, inicio, fim);
        // ordena os elementos menores que o pivo
        auxQuickSort(vet, inicio, p-1);
        // ordena os elementos maiores que o pivo
        auxQuickSort(vet, p+1, fim);
    }
}
void quickSort(int vet[], int n){
    auxQuickSort(vet, 0, n-1);
}
void quickSort2(int vet[], int n){
    if (n<30)
    {
        insertionSort(vet, n);
    }else{
        auxQuickSort(vet, 0, n-1);
    }
}
int main(){
    int vet[TAMANHO] = {};
    //Se rodar todos juntos vai corromper a heap e não vai rodar o ultimo. 
    //Não sei o motivo, não fiz TAD, se conseguir resolver fica a vontade pra fazer um pull request :)

    MedeTempo mt1("quick");
    geraVetorRandomico(vet, TAMANHO);
    quickSort(vet, TAMANHO);
    mt1.MedeTempoFim();
    MedeTempo mt2("quick2");
    geraVetorRandomico(vet, TAMANHO);
    quickSort2(vet, TAMANHO);
    mt2.MedeTempoFim();
    MedeTempo mt3("heap");
    geraVetorRandomico(vet, TAMANHO);
    heapSort(vet, TAMANHO);
    mt3.MedeTempoFim();
    //imprimeVetor(vet, TAMANHO);
//     bublesort(vet, TAMANHO);
//     printf("Ordenado bubble\n");
//     mt.MedeTempoFim();
//     //imprimeVetor(vet, TAMANHO);
//     MedeTempo mt1("cocktailsort");
//     geraVetorRandomico(vet, TAMANHO);
//     //imprimeVetor(vet, TAMANHO);
//     cocktailsort(vet, TAMANHO);
//     printf("Ordenado cocktail\n");
//     mt1.MedeTempoFim();
//     //imprimeVetor(vet, TAMANHO);

//     MedeTempo mt2("gnomeSort");
//     geraVetorRandomico(vet, TAMANHO);
//     //imprimeVetor(vet, TAMANHO);
//     cocktailsort(vet, TAMANHO);
//     printf("Ordenado gnome\n");
//     mt2.MedeTempoFim();
//     //imprimeVetor(vet, TAMANHO);

//     MedeTempo mt3("selectionsort");
//     geraVetorRandomico(vet, TAMANHO);
//     //imprimeVetor(vet, TAMANHO);
//     selectionsort(vet, TAMANHO);
//     printf("Ordenado selection\n");
//     mt3.MedeTempoFim();
//     //imprimeVetor(vet, TAMANHO);

     
//     MedeTempo mt4("mergesort"); 
//     geraVetorRandomico(vet, 10);
//     //imprimeVetor(vet, 10);
//    // mergeSort(vet, 10);
//     printf("Ordenado merge\n");
//     mt4.MedeTempoFim();
//     //imprimeVetor(vet, 10);
//     cout<<endl;

//     MedeTempo mede("mergesort"); 
//     geraVetorRandomico(vet, 10);
//     imprimeVetor(vet, 10);
//     mergeSort(vet, 10);
//     printf("Ordenado merge\n");
//     mede.MedeTempoFim();
//     imprimeVetor(vet, 10);
//     cout<<endl;

    return 0;
}