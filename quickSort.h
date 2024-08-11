#ifndef QUICK_h
#define QUICK_h

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

#endif