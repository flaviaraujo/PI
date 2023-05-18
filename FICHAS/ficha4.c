//FICHA 4 


//aux
int isVogal(char c){
    int i = c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    return i;
}

//2)
int retiraVogaisRep (char *s){
    char aux[1000];
    char c = s[0];
    int cont = 0;
    int i, j;
    
    aux[0] = c;
    cont++;
    
    for(i = 1; s[i]; i++){
        if (c != s[i]){
            aux[cont] = s[i];
            cont++;
        }
        c = s[i];
        
    }

    for(j = 0; aux[j]; j++){
        s[j] = aux[j];
    }
    
    s[cont] = '\0';
    
    return (i+1-cont);
}

//3)
int duplicaVogais (char *s){
    char aux[1000];
    int cont = 0;
    int i,j;
  
    for(i = 0, j = 0; s[i]; i++){
        aux[j] = s[i];
        j++;
        if (isVogal(s[i])){
            aux[j] = s[i];
            j++;
            cont++;
        }
    }
    aux[j] = '\0';

    for(j = 0; aux[j]; j++){
        s[j] = aux[j];
    }  
    s[j] = '\0';
    
    return (cont);
}


//2 ARRAYS ORDENADOS

//1)
int ordenado (int v[], int N){
    for(int i = 1; i < N; i++){
        if(v[i-1]>v[i]) return 0;
    }
    return 1;

}

//2)
void merge (int a[], int na, int b[], int nb, int r[]){
    int i = 0, ai = 0, bi = 0, prev = 0;
    while(i < nb+na){
        if(a[ai] > b[bi] || ai >= na-1){
            r[i] = b[bi];
            prev = b[bi];
            bi++;
        }
        else if (b[bi] > a[ai] || bi >= nb-1){
            r[i] = a[bi];
            prev = a[ai];
            ai++;
        }
        else {
            r[i] = a[ai++];
            i++;
            r[i] = b[bi++];
        }
        i++;
    }
}

//outra versão
void merge(int r[], int a[], int na, int b[], int nb) {
    int i, j;
    i = j = 0;
    for(int x = 0; x < na + nb; x++) {
        if(a[i] < b[j] && i < na || j == nb) r[x] = a[i++];
        else r[x] = b[j++];
    }
}


//3)
int partition(int v[], int N, int x){
    int aux[N];
    int i, j;
    int count = 0;

    //menores ou iguais a x
    for (i = 0, j = 0; i < N; i++){
        if (v[i] <= x){
            aux[j] = v[i];
            j++;
            count++;
        }
    }

    //maiores que x
    for (i = 0; i < N; i++){
        if (v[i] > x){
            aux[j] = v[i];
            j++;
        }
    }
    
    for (i = 0; i < N; i++){
        v[i] = aux[i];
    }
    return count;
}