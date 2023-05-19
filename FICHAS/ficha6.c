//FICHA 6 - BUFFERS
#include <stdlib.h>

#define Max 1000

//1)
typedef struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

//a)
void SinitStack (SStack s){
    s->sp = 0;
}

//b)
int SisEmpty (SStack s){
    return s->sp == 0;
}

//c)
int Spush (SStack s, int x){
    if(s->sp > (Max-1)) return 1;
    s->values[s->sp] = x;
    s->sp++;
    return 0;
}

//d)
int Spop (SStack s, int *x){
    if(SisEmpty(s)) return 1;
    *x = s->values[s->sp];
    s->sp--;
    return 0;
}

//e)
int Stop (SStack s, int *x){ //igual ao pop mas n remove nada
    if(SisEmpty(s)) return 1;
    *x = s->values[s->sp];
    return 0;
}


//EXERCICIO 2

typedef struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

//a)
void SinitQueue (SQueue q){
    q->front = 0;
    q->length = 0;
}

//b)
int SisEmptyQ (SQueue q){
    return q->length == 0;
}

//c)
int Senqueue (SQueue q, int x){
    if(q->front+q->length > Max) return 1;
    q->values[q->front+q->length] = x;
    q->length += 1;
}

//d)
int Sdequeue (SQueue q, int *x){
    if (SisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    q->length -= 1;
    q->front += 1;
    return 0;
}

//e)
int Sfront (SQueue q, int *x){
     if (SisEmptyQ(q)) return 1;
    *x = q->values[q->front];
    return 0;
}
