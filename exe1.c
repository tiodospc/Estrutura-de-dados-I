#include <stdio.h>
#include <stdlib.h>

int* uniao(int *v1, int n1, int *v2, int n2){
	int *v3 = (int *)malloc(sizeof(int));
	*v3 = *v1+*v2;
	int i;
	for(i = 0; i < n1+n2; i++){
		printf("[%d] ", v3);
	}
	//*v3 = v1[n1]+v2[n2];
	return v3;
}

int main(){
int nn1, nn2;
int vv1[nn1], vv2[nn2], i, *rt;

printf("Digite o numeros elementos do vetor v1: ");
scanf("%d", &nn1);
	for(i = 0 ; i < nn1; i++){
		scanf("%d", vv1[i]);
	}
	
printf("Digite o numeros elementos do vetor v1: ");
scanf("%d", &nn2);
	for(i = 0 ; i < nn2; i++){
		scanf("%d", vv2[i]);
	}
	
*rt = *uniao(vv1, nn1, vv2, nn2);

	
	
return 0;}
