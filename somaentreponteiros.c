	#include <stdio.h>
	
	
	int main(){
	int soma, *x,*z, c, b;
	printf("digite a soma 2 valores para fazer a soma entre ponteiros: \n");
	scanf("%d", &b);
	scanf("%d", &c);
	x = &b;
	z = &c;
	soma = *z+*x;
	
	printf("a soma é: %d", soma);
	return 0; }
