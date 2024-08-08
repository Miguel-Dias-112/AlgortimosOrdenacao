
#ifndef heap_H
#define heap_H
void heapify(int vet[], int tam, int raiz) {
    int maior = raiz;         // Inicializa o maior como raiz
    int esq = 2 * raiz + 1;   // Esquerda = 2*i + 1
    int dir = 2 * raiz + 2;   // Direita = 2*i + 2

    // Verifica se o filho esquerdo é maior que a raiz
    if (esq < tam && vet[esq] > vet[maior])
        maior = esq;

    // Verifica se o filho direito é maior que o maior até agora
    if (dir < tam && vet[dir] > vet[maior])
        maior = dir;

    // Se o maior não for a raiz
    if (maior != raiz) {
        // Troca a raiz com o maior
        int aux = vet[raiz];
        vet[raiz] = vet[maior];
        vet[maior] = aux;

        // Recursivamente aplica o heapify na subárvore afetada
        heapify(vet, tam, maior);
    }
}
void BuildHeap(int vet[], int n){
    for (int i = n/2 ; i >= 0; i--){
        heapify(vet,n, i);
    } 
}
void heapSort(int vet[], int n){
    BuildHeap(vet, n);
    for (int i = n-1; i >= 0; i--){
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        heapify(vet, i, 0);
    }
}
#endif