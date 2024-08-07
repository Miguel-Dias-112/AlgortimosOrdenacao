
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "merge.h"

#include "selection.h"
#include "funcoes.h"
#include "bubble.h"
#include "insertion.h"
#include <stdio.h>

#define TAMANHO 10000

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
int main(){
    int vet[TAMANHO] = {};
    //Se rodar todos juntos vai corromper a heap e não vai rodar o ultimo. 
    //Não sei o motivo, não fiz TAD, se conseguir resolver fica a vontade pra fazer um pull request :)

    MedeTempo mt("bubblesort");
    geraVetorRandomico(vet, TAMANHO);
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