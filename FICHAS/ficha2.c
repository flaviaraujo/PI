//FICHA 2: ALGORITMOS NUMÉRICOS SOBRE INTEIROS

//1.
float multInt1 (int n, float m){
	float r = 0;
	for(int i = 0; i < n; i++){
		r += m;
	}
	return r;
}

//2.
float multInt2 (int n, float m){
	float r = 0;
	while (n > 0){
		if(n%2) r += m;
		n /= 2;
		m *= 2;
	}
}

//3.
int mdc1 (int a, int b){
	int n, m;
	if(a < b){
		n = a;
		a = b;
		b = n;
	}
	for(int i = 1; i <= b; i++){
		if(a % i == 0 && b % i == 0) m = i;
	}
	return m;
}

//4.
int mdc2 (int a, int b){
	while(a != 0 && b != 0) {
        if(a > b) a -= b;
        else if (b > a) b -= a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

//5.
int mdc3 (int a, int b){
	while(a != 0 && b != 0) {
        if(a > b) a %= b;
        else if (b > a) b %= a;
        else return a;
    }
    if(a == 0) return b;
    else return a;
}

//6.
//(a)
int fib1 (int n){
	if (n == 1 || n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}

//(b)
int fib2 (int n){
	int temp, acc1 = 1, acc2 = 1;
	for(int i = 3; i <= n; i++){
		temp = acc2;
		acc2 += acc1;
		acc1 = temp;
	}
	return acc2;
}
