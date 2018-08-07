#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float ord;
}tpProduto;

typedef struct _nodo{
  tpProduto info;
  struct _nodo *prox;
  struct _nodo *ant;

}tpNodo;

typedef struct _lista{			
  int nItens;
  tpNodo *cabeca;
  tpNodo *cauda;

}tplista;


tplista *insere(tplista *l){
	tpNodo *N = (tpNodo *)malloc(sizeof(tpNodo));
	printf("Digite um numero: ");
	scanf("%f", &N->info.ord);
	if(l->nItens == 0){
		l->cabeca = N;
		l->cauda = N;
		l->cabeca->prox = NULL;
		l->cabeca->ant = NULL;
		l->nItens++;
	}else{
		l->cauda->prox = N;
		N->prox = NULL;
		N->ant = l->cauda;
		l->cauda = N;
		l->nItens++;
	}
	return l;	
}

tplista *inserecem(tplista *l){

	for (int i = 0; i < 100; i++){
		tpNodo *N = (tpNodo *)malloc(sizeof(tpNodo));
		N->info.ord = rand() % 100;
		if(l->nItens == 0){
			l->cabeca = N;
			l->cauda = N;
			l->cabeca->prox = NULL;
			l->cabeca->ant = NULL;
			l->nItens++;
		}else{
			l->cauda->prox = N;
			N->prox = NULL;
			N->ant = l->cauda;
			l->cauda = N;
			l->nItens++;
		}	
	}
	
	printf("100 Itens inseridos\n");
	return l;
}

tplista* exclui(tplista *l, float codigo){
	tpNodo *v;
	if(l->nItens == 0){
		printf("lista vazia !");
	}else{
		for(v = l->cabeca ; v != NULL; v = v->prox){
			if(v->info.ord == codigo){
				if(l->cabeca == v){
					l->cabeca = v->prox;
					v->ant = NULL;
					(l->nItens)--;
				}else{
					v->prox->ant = v->ant;
					v->ant->prox = v->prox;
				}
				if(v == l->cauda){
				l->cauda = l->cauda->ant;
				v->prox = NULL;
				}
			}
		}
	}	
	l->nItens--;
	free(v);
	return l;

}
void printar(tplista *l){
	tpNodo* v = l->cabeca;
		for(v = l->cabeca; v != NULL; v = v->prox){
			printf("[%.2f] ", v->info.ord);		
		}
	printf("\n");
}

void printarinv(tplista *l){
	tpNodo* v = l->cauda;
		for( ; v != NULL; v = v->ant){
			printf("[%.2f] ", v->info.ord);		
		}
	printf("\n");
}


void lista_destroi(tplista *l )
{
	tpNodo *n = l->cabeca;
	while(l->nItens != 0){
		tpNodo *r = n->prox;
			free(n);
			n = r;
			l->cabeca = n;
			l->nItens--;
	}
	free(n);
}


void *Insertion_sort(tplista *l){
	tpNodo *i = l->cabeca, *j;

	if(l->cabeca == NULL) {
		printf("\tLista não possui elementos para ordenar\n" );		
	}
	 
	else {	
		for(i = i->prox; i != NULL; i = i->prox){ //for que percorre a lista
			for(j = i->ant; j != NULL; j = j->ant){ //for que percorre a lista a partir do anterior do first
				if(i->info.ord < j->info.ord){ //compara se o codigo é maior
					if(l->nItens == 2) { //Apenas dois elementos na lista
						j->ant = i;
						i->prox = j;
						i->ant = NULL;
						j->prox = NULL;
						l->cabeca = i;
						l->cauda = j;
					}

					else if(j->ant == NULL){ //caso seja o primeiro trocando
						i->prox->ant = j;
						j->prox = i->prox;
												
						i->ant = NULL;
						i->prox = j;
						
						j->ant = i;
						l->cabeca = i;
					}
					
					else if(i->prox == NULL){ //caso seja o ultimo trocando
						j->prox = NULL;
						i->ant = j->ant;
						
						i->prox = j;
						j->ant->prox = i;
						
						j->ant = i;
						l->cauda = j;
					}

					else{ //caso seja o do meio trocando
						i->prox->ant=j;
						j->prox = i->prox;
						i->ant = j->ant;
						i->prox = j;
						j->ant->prox = i;
						j->ant = i;
					}
				}		
			}
		}
	}
	return l;
}
void Selection(tplista *l){
	tpNodo *andar, *trocar, *atual, *anteriordeatual, *proximodeatual, *anteriordeandar, *proximodeandar;
	if(l->nItens==0){
			printf("Lista vazia\n");
			return ;
    }
	for(andar = l->cabeca; andar != NULL ; andar=andar->prox){
		atual = andar;
        	printf("for principal\n");
        for(trocar = andar; trocar != NULL ; trocar=trocar->prox){
        	printf("for secundario\n");
            if(trocar->info.ord < atual->info.ord ){
            	atual = trocar;	
			}
            		
		 if(atual != andar){
		if(andar == l->cabeca && atual == l->cauda){
			printf("j");
			l->cabeca = andar->prox->ant = atual;
			l->cabeca = atual->ant->prox = andar;
			atual->prox = andar->prox;
			andar->ant = atual->ant;
			andar->prox = NULL;
			atual->ant = NULL;

		}
		else if(andar == l->cabeca && atual == l->cabeca->prox){
			printf("b");
			l->cabeca = andar->ant = atual;
			andar->prox = atual->prox;
			atual->prox = andar->prox->ant = andar;
			atual->ant = NULL;
		}
		else if(atual == l->cauda && andar==l->cauda->ant){
			printf("o");
			l->cauda = atual->prox = andar;
			atual->ant = andar->ant;
			andar->ant = andar->ant->prox = atual;
			andar->prox = NULL; 
		}
		else if(andar == l->cabeca){
			printf("d");
			anteriordeatual = atual->ant;
			proximodeatual = atual->prox;
			l->cabeca = andar->prox->ant = atual;
			atual->prox = andar->prox;
			andar->ant = anteriordeatual;
			andar->prox = proximodeatual;
			anteriordeatual->prox = andar;
			proximodeatual->ant = andar;
			atual->ant = NULL;
		}
		else if(atual == l->cauda){
			printf("g");
			anteriordeandar = andar->ant;
			proximodeandar = andar->prox;
			l->cauda = atual->ant->prox = andar;
			andar->ant = atual->ant;
			andar->prox = NULL;
			atual->ant = anteriordeandar;
			atual->prox = proximodeandar;
			anteriordeandar->prox = atual;
			proximodeandar->ant = atual;

		}
		else if(atual == andar->prox){
			printf("h");
			atual->prox->ant = andar;
			andar->ant->prox = atual;
			andar->prox = atual->prox;
			atual->ant = andar->ant;
			atual->prox = andar;
			andar->ant = atual;
			
		}
		else{
			anteriordeatual = atual->ant;
			proximodeatual  = atual->prox;
			atual->prox = andar->prox;
			atual->ant = andar->ant;
			atual->prox->ant = atual;
			atual->ant->prox = atual;
			andar->prox = proximodeatual;
			andar->ant = anteriordeatual;
			anteriordeatual->prox = andar;
			proximodeatual->ant = andar;
		}
			andar = atual;		
	} 
			
	}
}


}

int main(){

  int op, cod;


  tplista *lista = (tplista *)malloc(sizeof(lista));
  lista->cabeca = NULL;
  lista->cauda = NULL;
  lista->nItens = 0;

  do{	
		printf("(1) Para inserir um elemento na lista\n");
		printf("(2) Para excluir um elemento da lista\n");
		printf("(3) Para imprimir os elementos da lista (em ambas as ordens)\n");
		printf("(4) Para inserir de uma vez 100 elementos na lista (randomicamente)\n");
		printf("(5) Ordenar via Insertion Sort\n");
		printf("(6) Ordenar via Selection Sort\n");
		printf("(0) Para finalizar o programa\n");
		scanf("%d", &op);


    switch(op){

    case 1: //feito
		insere(lista);
	break; 

    case 2: //feito
		printf("Qual item deseja excluir: \n");
		scanf("%d", &cod);
		exclui(lista, cod);
	break;
    
    case 3:  //feito
		printar(lista);
		printf("inversa:\n");
		printarinv(lista);
	break;
		
	case 4: //feito
		lista_destroi(lista);
		inserecem(lista);
	break;

	case 5: //feito
		Insertion_sort(lista);
	break;
		
	case 6:  //feito	
		Selection(lista);
	break;
    }

  }while(op != 0);



  return 0; 
}
