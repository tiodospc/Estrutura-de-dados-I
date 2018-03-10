#include <stdio.h>


void calcula_quadrado(int lado, float *area, float *perimetro){
	*area= lado+lado+lado+lado;
	*perimetro = *area;

}


int main(){

int x;
float a, p;
printf("digite o lado do quadrado: ");
scanf("%d", &x);
calcula_quadrado(x, &a,&p);
printf("perimetro: %.2f\n", p);
printf("area: %.2f\n", a);






return 0;}
