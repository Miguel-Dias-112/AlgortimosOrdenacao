#ifndef BUBBLE_H
#define BUBBLE_H
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
#endif