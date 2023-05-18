#include <stdio.h>

//Ficha 3

//2)
void swapM (int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

//3)
void swap (int v[], int i, int j){
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

//4)
int soma (int v[], int N){
    int count = 0;
    for (int i = 0; i < N; i++){
        count += v[i];
    }
    return count;
}

//5)
void inverteArray (int v[], int N){
    for (int i = 0; i < (N/2); i++){
        swapM (&v[i], &v[N-i-1]);
    }
}


//6)
int maximum (int v[], int N, int *m){
    int temp = 0;
    if (N < 0) return 1;
    else {
        for (int i = 0; i < N; i++){
            if (v[i] > temp) temp = v[i];
        }
        *m = temp;
        return 0;
    }
}


//7)
void quadrados (int q[], int N){
    q[0] = 0;
    for (int a = 1; a < N; a++){
        q[a] = q[a-1] + 2*(a-1) + 1; //porque estamos a calcular a anterior a q[a+1] que tinha na formula do enunciado
    }
}
 

//8)
//a)
void pascal (int v[], int N){
    int i, j;
    for(j = 0; j < N; j++){
        for (i = j; i >= 0; i--){
            if (j == i) v[i] = 1;
            else v[i] += v[i-1];
        }
    }
}

//b) NOTA: não tive o cuidado dos espaços do triângulo porque não costuma sair isso no teste
void print_pascal (int v[], int N){
    int i, j;

    for(j = 0; j < N; j++){
        for (i = j; i >= 0; i--){
            if (j == i){ 
                v[i] = 1;
                printf("%d", v[i]);
                }
            else { 
                v[i] += v[i-1];
                printf("%d", v[i]);
            }
        }
    }
}
