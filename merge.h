#ifndef SELECTION_H
#define SELECTION_H

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

// implementação do merge sort dada em aula
void mergeCaniato(int vet[], int inicio, int meio, int fim){
    int i = inicio, j = meio+1, k = 0;
    int tamanho = fim-inicio+1;
    int aux[tamanho];
    while(i <= meio && j <= fim)
        if(vet[i] < vet[j])
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    while(i <= meio)
        aux[k++] = vet[i++];
    while(j <= fim)
        aux[k++] = vet[j++];
    for(i = inicio; i <= fim; i++)
    vet[i] = aux[i-inicio];
}
void auxMergeSortCaniato(int vet[], int inicio, int fim)
{
    if(inicio < fim){
        int meio = (inicio + fim)/2;
        auxMergeSortCaniato(vet, inicio, meio);
        auxMergeSortCaniato(vet, meio+1, fim);
        mergeCaniato(vet, inicio, meio, fim);
    }
}
void mergeSortCaniato(int vet[], int n){
    auxMergeSortCaniato(vet, 0, n-1);
}
////////////////////////
// implementação do merge sort feita por Miguel, um cado mais simples, porém gastando memoria
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

#endif