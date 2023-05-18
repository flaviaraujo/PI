//FICHA 1 

//1. ESTADO E ATRIBUIÇÕES

//1.1
//12 16

//1.2
// 0 (y não foi inicializado)

//1.3
//A 65
// B 66 2 50
// b 98

//1.4
// 100 200


//2. ESTRUTURAS DE CONTROLO

//(a)
// 3 5

//(b)
// 11 66

//(c)
// _#_#_#_#_#_#_#_#_#_#

//(d)
/*
1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111 
1111
*/

//3. PROGRAMAS INTERATIVOS

//3.1
void quadrado(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			putchar('#');
		}
		putchar('\n');
	}
}

//3.2
void xadrez(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i + j)%2) putchar('_');
				else putchar('#');
		}
		putchar('\n');
	}
}

//3.3
void tri_vertical(int n){
	for(int i = 1; i < 2 * n; i++) {
        for(int j = 1; j <= 2 * n - i; j++) {
            if(j <= i) putchar('#');
        }
        putchar('\n');
    }
}

void tri_horizontal(int n){
	for(int i = 1; i <= n; i++) {
        int j = i - 1;
        for(int k = 0; k < n - 1 - j; k++) putchar(' ');
        for(int k = 0; k < 1 + 2 * j; k++) putchar('#');
        putchar('\n');
    }
}

int main(int argc, char const *argv[])
{
    triang1(5);
    triang2(5);
    return 0;
}
