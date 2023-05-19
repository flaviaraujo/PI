//FICHA 7 - LISTAS
#include <stdio.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

//1)
void libertaLista (Palavras l){
    Palavras atual = l;
    while (atual != NULL){
        Palavras prox = atual->prox;
        free(atual->palavra);
        free(atual);
        atual = prox;
    }

}

//2)
int quantasP (Palavras l){
    Palavras atual = l;
    int count = 0;

    while (atual != NULL){
        Palavras prox = atual->prox;
        count += atual->ocorr;
        atual = prox;
    }
    return count;
}

//3)
void listaPal (Palavras l){
    Palavras atual = l;

    while (atual != NULL){
        Palavras prox = atual->prox;
        printf("Palavra: %s Ocorrências: %d\n", atual->palavra, atual->ocorr);
        atual = prox;
    }

}

//4)
char * ultima (Palavras l){
    Palavras atual = l;
    while (atual->prox != NULL){
        Palavras prox = atual->prox;
        atual = prox;
    }
    return atual->palavra;
}

//5)
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras atual;
    atual->prox = l;
    atual->palavra = p;
    atual->ocorr = 1;
    return atual;
}

//6)
Palavras acrescentaFim (Palavras l, char *p){
    // Cria uma nova célula
    Palavras nova = (Palavras) malloc(sizeof(struct celula));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = NULL;

    if (l == NULL) {
        // Se a lista estiver vazia, a nova célula será o primeiro elemento
        l = nova;
    } else {
        // Percorre até o final da lista
        Palavras atual = l;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        
        // Atualiza o próximo da última célula para apontar para a nova célula
        atual->prox = nova;
    }

    return l;
}


//7)
Palavras acrescenta (Palavras l, char *p){
    Palavras atual = l;

    while(atual != NULL){
        if(strcmp(atual->palavra, p) == 0){
            atual->ocorr += 1;
            return l;
        }
    }
    acrescentaInicio(l, *p);
    return l;
}


//8)
struct celula * maisFreq (Palavras l){
    int Mocorr = 0;
    Palavras maisocorrida;
    Palavras atual = l;

    while (atual != NULL){
        if(atual->ocorr > Mocorr){
            Mocorr = atual->ocorr;
            maisocorrida = atual;
        }
    }
    return maisocorrida;
}
