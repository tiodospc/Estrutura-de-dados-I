

void somaa(int *soma,int *n1, int *n2){

*soma= *n1+*n2;
}


int main(){

int s,a,b;

printf("digite dois numeros: ");

scanf("%d", &a);
scanf("%d", &b);

somaa(&s,&a,&b);

printf("Resultado: %d\n", s);


return 0;}
