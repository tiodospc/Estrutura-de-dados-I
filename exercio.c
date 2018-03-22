#include <stdio.h>
#include <stdlib.h>

typedef struct estudante{
 char nome[50];
 char endereco[100];
 int matricula;
}tp_estudantes;


tp_estudantes *cadastrar(tp_estudantes *es, int n){
	int i;
		es = (tp_estudantes	*)malloc(sizeof(tp_estudantes));	
		
		for(i=0; i< n;i++){
		printf("Digite seu nome: ");
		scanf("%s", es->nome);
		printf("Digite o seu endereço: ");
		scanf("%s", es->endereco);
		printf("Digite suas matricula: ");
		scanf("%d", &(es->matricula));
		printf("\n");
	}
		return es;
	
}

void printa(tp_estudantes *es, int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%s\n", es->nome);
		printf("%s\n", es->endereco);
		printf("%d\n", es->matricula);
		printf("\n");
	}
}



int main(){
tp_estudantes *es;
int op, qtd_produtos;

printf("\nDigite quantos estudandtes: ");
scanf("%d", &qtd_produtos);
getchar();


do{
printf("1 - para cadastrar alunos\n");
printf("2 - para printar alunos\n");
scanf("%d", &op);
	
	switch(op){
	
		case 1: cadastrar(es, qtd_produtos);
		break;
		
		// 2: printa(es, qnt_produtos);
		//break;
	}
}while(op != 0);



return 0; }
