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
	MNOZINA *mnoz1;
	int i;
	
	mnoz1 = kostrukt_mnoz();
	mnoz->size = mnoz->size + 1;
	for(i=0; i<mnoz->size; i++){
		mnoz->data[i] = mnoz->data[i];
	}
	mnoz1->data[mnoz->size - 1] = a;
	*mnoz = *mnoz1;
	return;
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
	
	for(i=0; i < mnoz->size; i++){
		printf("%d ", mnoz->data[i]);
	}
}

int main() {

	return 0;
}