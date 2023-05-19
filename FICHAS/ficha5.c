//FICHA 5 - STRUCTS E ORDENAÇÕES

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


//1)
int nota(Aluno a) {
    int i, total=0;
    
    for (i=0; i<6; i++){
        total = a.miniT[i]*10;
    }

    total /= 6;
    total *= 0.2;
    total += a.teste * 0.8;

    return (total<10) ? 0 : total;
}


//2)
int procuraNum (int num, Aluno t[], int N){
    for(int i = 0; i < N; i++){
        if (t[i].numero == num) return i;
    }
    return -1;
}


//3)
void swapAluno(Aluno *a, Aluno *b){
    Aluno guarda = *a;
    *a = *b;
    *b = guarda;
}

void ordenaPorNum (Aluno t[], int N){
    for (int i = 0; i < N; i++){
        for(int j = 1+i; j < N; j++){
            if (t[i].numero > t[j].numero){
                swapAluno(&(t[i]), &(t[j]));
            }
        }
    }

}


//4)
void criaIndPorNum (Aluno t [], int N, int ind[]){
   int i, a;
   Aluno temp[N];

   for (i = 0; i < N; i++){
        temp[i] = t[i]; //copia os elem de t para o temporário
   }
   ordenaPorNum(temp, N);

    for (i = 0; i < N; i++){
        for (a = 0; a < N && temp[a].numero != t[i].numero; a++); //para cada t[i], procura no temp[] o aluno com o mesmo numero numero de identificação 
        ind[i] = a; //ao encontrar, atribui esse indice ao ind[] para guardar a posição do aluno t[i] no array temp[]
        }
}


//5)
void imprimeTurma (int ind[], Aluno t[], int N){
    for (int i = 0; i < N; i++){
        Aluno a = t[ind[i]];
        printf("Nº: %d, Nome: %s, Nota: %d", a.numero, a.nome, nota(a));
    }
}


//6)
int procuraNum2 (Aluno t[], int N, int ind[], int num){
    for (int i = 0; i < N; i++){
        Aluno a = t[ind[i]];

        if(a.numero == num) return 1;
    }
    return 0;
}

//7)
int comparaNome (char *a, char *b){
    int i;

    for (i = 0; a[i] && b[i]; i++){
       if (a[i] != b[i]) return  b[i]-a[i];
    }
    if (a[i] && !b[i]) return -1;
    if (!a[i] && b[i]) return 1;

    return 0;
}

void ordenaPorNome (Aluno t[], int N){
    int i, j;
    for (i = 0; i < N; i++){
        for(int j = 1+i; j < N; j++){
            comparaNome(t[i].nome, t[j].nome);
        }
    }
}


void criaIndPorNome (Aluno t [], int N, int ind[]){
    int i, a;
    Aluno temp[N];

    for (i = 0; i < N; i++){
        temp[i] = t[i]; //copia os elem de t para o temporário
    }
    ordenaPorNome(temp, N);

    for (i = 0; i < N; i++){
        for (a = 0; a < N && temp[a].numero != t[i].numero; a++); //para cada t[i], procura no temp[] o aluno com o mesmo numero numero de identificação 
        ind[i] = a; //ao encontrar, atribui esse indice ao ind[] para guardar a posição do aluno t[i] no array temp[]
        }

}