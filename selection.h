#ifndef selection_H
#define selection_H
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
#endif