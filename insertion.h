#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
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
void insertionSort(int vet[], int n){
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
}

#endif