
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <iostream>
#include <time.h>
const int TAMANHO = 10000;
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
void bublesort(int vet[], int n){
    int aux =0;
    for (int i = 0; i < n; i++){

        for (int j = 0; j < n; j++){
            if(vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
        
    }
    
}
void cocktailsort(int vet[], int n){
    int aux =0;
    for (int i = 0; i < n/2; i++){

        for (int j = 0; j < n; j++){
            if(vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
        for (int j = n; j >=0 ; j--){
            if(vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}
void gnomeSort(int vet[], int n){
    int i = 0;
    while(i < n){
        if(i == 0){
            i++;
        }
        if(vet[i] >= vet[i-1]){
            i++;
        }
        else{
            int aux = vet[i];
            vet[i] = vet[i-1];
            vet[i-1] = aux;
            i--;
        }
    }
}
int acharmenor(int vet[], int n){
    int menor = vet[0];
    int indice = 0;
    for (int i = 0; i < n; i++){
        if(vet[i] < menor){
            menor = vet[i];
            indice = i;
        }
    }
    return indice;
}
int selectionsort(int vet[], int n){
    if(n == 1){
        return vet[0];
    }
    int indicemenor = acharmenor(vet, n);
    
    int aux = vet[0];
    vet[0] = vet[indicemenor];
    vet[indicemenor] = aux;

    
    return selectionsort(vet+1, n-1);
}
int* mesclavetor(int v1[], int v2[], int n, int n2){
    int i = 0;
    int j = 0;
    int k = 0;
    int* vet = new int[n];

    while(i <n && j <n2){
        if(v1[i] < v2[j]){
            vet[k] = v1[i];
            i++;
        }
        else{
            vet[k] = v2[j];
            j++;
        }
        k++;
    }
    while(i <n){
        vet[k] = v1[i];
        i++;
        k++;
    }
    while(j <n2){
        vet[k] = v2[j];
        j++;
        k++;
    }
    return vet;
}
int mergeSort(int vet[], int n){
    if(n == 1){
        return vet[0];
    }
    int* v1 = new int[n/2];
    int* v2= new int[n-n/2];
    for (int i = 0; i < n/2; i++){
        v1[i] = vet[i];
        
    }
    for (int i = n/2; i < n; i++){
        v2[i-n/2] = vet[i];
    }
    mergeSort(v1, n/2);
    mergeSort(v2,   n-n/2);
    int* vetm = mesclavetor(v1, v2, n/2,n-n/2);
    for (int i = 0; i < n; i++){
        vet[i] = vetm[i];
    }
    return 0;
   
   
}
int insertionSort(int vet[], int n){
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while(j > 0 && vet[j] < vet[j-1]){
            int aux = vet[j];
            vet[j] = vet[j-1];
            vet[j-1] = aux;
            j--;
        }
    }
    return 0 ;
}
void heapChecker(int vet[], int n){
    for (int i = 0; i < n; i++){
        if(vet[i] > vet[2*i+1] || vet[i] > vet[2*i+2]){
            //pov: não é pra dar erro
            cout<<"erro"<<endl;
        }
    }
}
int main()
{
    int vet[TAMANHO] = {};
    //Se rodar todos juntos vai corromper a heap e não vai rodar o ultimo. 
    //Não sei o motivo, não fiz TAD, se conseguir resolver fica a vontade pra fazer um pull request :)

    // MedeTempo mt("bubblesort");
    // geraVetorRandomico(vet, TAMANHO);
    // //imprimeVetor(vet, TAMANHO);
    // bublesort(vet, TAMANHO);
    // printf("Ordenado bubble\n");
    // mt.MedeTempoFim();
    // //imprimeVetor(vet, TAMANHO);

    // MedeTempo mt1("cocktailsort");
    // geraVetorRandomico(vet, TAMANHO);
    // //imprimeVetor(vet, TAMANHO);
    // cocktailsort(vet, TAMANHO);
    // printf("Ordenado cocktail\n");
    // mt1.MedeTempoFim();
    // //imprimeVetor(vet, TAMANHO);

    // MedeTempo mt2("gnomeSort");
    // geraVetorRandomico(vet, TAMANHO);
    // //imprimeVetor(vet, TAMANHO);
    // cocktailsort(vet, TAMANHO);
    // printf("Ordenado gnome\n");
    // mt2.MedeTempoFim();
    // //imprimeVetor(vet, TAMANHO);

    // MedeTempo mt3("selectionsort");
    // geraVetorRandomico(vet, TAMANHO);
    // //imprimeVetor(vet, TAMANHO);
    // selectionsort(vet, TAMANHO);
    // printf("Ordenado selection\n");
    // mt3.MedeTempoFim();
    // //imprimeVetor(vet, TAMANHO);

     
    // MedeTempo mt4("mergesort"); 
    // geraVetorRandomico(vet, 10);
    // //imprimeVetor(vet, 10);
    // mergeSort(vet, 10);
    // printf("Ordenado merge\n");
    // mt4.MedeTempoFim();
    // //imprimeVetor(vet, 10);
    // cout<<endl;

        
    MedeTempo mede("mergesort"); 
    geraVetorRandomico(vet, 10);
    imprimeVetor(vet, 10);
    mergeSort(vet, 10);
    printf("Ordenado merge\n");
    mede.MedeTempoFim();
    imprimeVetor(vet, 10);
    cout<<endl;
    return 0;
}