#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int* data;
	int size;
}MNOZINA;

MNOZINA* kostrukt_mnoz(){
    MNOZINA* mnoz = (MNOZINA*)malloc(sizeof(MNOZINA));
    mnoz->data = NULL;
    mnoz->size = 0;
    return mnoz;
}

void destruct_mnoz(MNOZINA* mnoz){
    free(mnoz->data);
    free(mnoz);
}

void pridat(MNOZINA* mnoz, int a) {
	int i;
	
	mnoz->size = mnoz->size + 1;
	int* data = (int*)malloc(mnoz->size * sizeof(int));
	for (i = 0; i < mnoz->size - 1 ; i++) {
		data[i] = mnoz->data[i];
	}
	data[mnoz->size - 1] = a;
	mnoz->data = data;
}

void odstranit(MNOZINA* mnoz, int a) {
	int i, j;
	
	for (i = 0; i < mnoz->size; i++){
		if (mnoz->data[i] == a)
			j = i;			
	}
	mnoz->size = mnoz->size - 1;
	int* data = (int*)malloc(mnoz->size * sizeof(int));
	for (i = 0; i < j; i++) {
		data[i] = mnoz->data[i];
	}
	for (i = j; i < mnoz->size; i++) {
		data[i] = mnoz->data[i+1];
	}
	mnoz->data = data;
}

void test(MNOZINA* mnoz, int a) {
	int i;
	
	for(i = 0; i < mnoz->size; i++){
		if (mnoz->data[i] == a){
		printf("Mnozina obsahuje prvok %d", a);
		return;
		}
	}	
	printf("Mnozina neoobsahuje prvok %d", a);
	return;		
}

void vypis(MNOZINA* mnoz) {
	int i;
	
	for(i = 0; i < mnoz->size; i++){
		printf("%d ", mnoz->data[i]);
	}
}

int main() {

	return 0;
}
