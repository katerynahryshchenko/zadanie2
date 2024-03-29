#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NO_MATCH 0
#define MATCH 1

typedef struct{
	int* data;
	int size;
}MNOZINA;

MNOZINA* konstrukt_mnoz(){
    MNOZINA* mnoz = (MNOZINA*)malloc(sizeof(MNOZINA));
    if (mnoz == NULL)
	    return NULL;
		
    mnoz->data = NULL;
    mnoz->size = 0;
    return mnoz;
}

void destruct_mnoz(MNOZINA* mnoz){
    free(mnoz->data);
    free(mnoz);
}

int pridat(MNOZINA* mnoz, int a) {
	int i;
	
	mnoz->size = mnoz->size + 1;
	int* data = (int*)malloc(mnoz->size * sizeof(int));
	if (data == NULL)
		return 0;
	
	for (i = 0; i < mnoz->size - 1; i++) 
		data[i] = mnoz->data[i];
	
	free(mnoz->data);
	data[mnoz->size - 1] = a;
	mnoz->data = data;
}

int odstranit(MNOZINA* mnoz, int a) {
	int i, j;
	
	for (i = 0; i < mnoz->size; i++)
		if (mnoz->data[i] == a)
			j = i;			
	
	mnoz->size = mnoz->size - 1;
	int* data = (int*)malloc(mnoz->size * sizeof(int));
	if (data == NULL)
		return 0;	
			
	for (i = 0; i < j; i++) 
		data[i] = mnoz->data[i];
	
	for (i = j; i < mnoz->size; i++) 
		data[i] = mnoz->data[i+1];
	
	free(mnoz->data);
	mnoz->data = data;
}

int test(MNOZINA* mnoz, int a) {
	int i;
	
	for(i = 0; i < mnoz->size; i++)
		if (mnoz->data[i] == a)
			return MATCH;
	
	return NO_MATCH;		
}

void heapify(int* arr, int n, int i) {
    int max = i, a;  
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != i) {
        a = arr[i];
        arr[i] = arr[max];
        arr[max] = a;
        heapify(arr, n, max);
    }
}

void sort(MNOZINA* mnoz) {
	int a;
	
    for (int i = mnoz->size / 2 - 1; i >= 0; i--)
        heapify(mnoz->data, mnoz->size, i);

    for (int i = mnoz->size - 1; i > 0; i--) {
        a = mnoz->data[0];
        mnoz->data[0] = mnoz->data[i];
        mnoz->data[i] = a;

        heapify(mnoz->data, i, 0);
    }
}

MNOZINA* prienik(MNOZINA* mnoz1, MNOZINA* mnoz2) {
	MNOZINA* p = konstrukt_mnoz();
	if (p == NULL)
		return NULL;
		
	int i = 0, j = 0;
	
	sort(mnoz1);
	sort(mnoz2);
	
	while (i < mnoz1->size && j < mnoz2->size) {
		
		if (mnoz1->data[i] < mnoz2->data[j])
			i++;
			
		if (mnoz1->data[i] > mnoz2->data[j])
			j++;
			
		if (mnoz1->data[i] == mnoz2->data[j]) { 
			if(pridat(p, mnoz1->data[i]) == 0)
				return NULL;
			i++;
			j++;			
		}
		
	}
	return p;
}

MNOZINA* zjednotenie(MNOZINA* mnoz1, MNOZINA* mnoz2) {
	MNOZINA* z = konstrukt_mnoz();
	if (z == NULL)
		return NULL;
	int i = 0, j = 0;
	
	sort(mnoz1);
	sort(mnoz2);
	
	while (i < mnoz1->size && j < mnoz2->size) {
		
		if (mnoz1->data[i] < mnoz2->data[j]){
			if(pridat(z, mnoz1->data[i]) == 0)
				return NULL;
			i++;
		}
			
		if (mnoz1->data[i] > mnoz2->data[j]){
			if(pridat(z, mnoz2->data[j]) == 0)
				return NULL;
			j++;
		}
			
		if (mnoz1->data[i] == mnoz2->data[j]) { 
			if(pridat(z, mnoz1->data[i]) == 0)
				return NULL;
			i++;
			j++;			
		}
	}
	
	while (i < mnoz1->size) {
		if(pridat(z, mnoz1->data[i]) == 0)
			return NULL;
		i++;
	}
		
	while (j < mnoz2->size) {
       	if(pridat(z, mnoz2->data[j]) == 0)
			return NULL;
       	j++;
   	}

	return z;
}

void vypis(MNOZINA* mnoz) {
	int i;
	
	for(i = 0; i < mnoz->size; i++)
		printf("%d ", mnoz->data[i]);
	
	puts("\n");
}

int main() {
	MNOZINA* mnoz1 = konstrukt_mnoz();
	if (mnoz1 == NULL){
		puts("chyba v allokacie pamati");
		return 0;
	};
	
	MNOZINA* mnoz2 = konstrukt_mnoz();
	if (mnoz2 == NULL){
		destruct_mnoz(mnoz1);
		puts("chyba v allokacie pamati");
		return 0;
	};
	
	pridat(mnoz1, 1);
	pridat(mnoz1, 10);
	pridat(mnoz1, 3);
	
	pridat(mnoz2, 14);
	pridat(mnoz2, 3);
	pridat(mnoz2, 5);
	
	printf("Mnozina 1: ");
	vypis(mnoz1);
	printf("Mnozina 2: ");
	vypis(mnoz2);
	
	//int result = test( mnoz1, 3);
	//if(result == 1)
	//	puts("Mnozina obsahuje ten prvok");
	//else
	//	puts("Mnozina neobsahuje ten prvok");
	
	MNOZINA* pr = prienik(mnoz1, mnoz2);
	if (pr == NULL){
		destruct_mnoz(mnoz1);
		destruct_mnoz(mnoz2);
		puts("chyba v allokacie pamati");
		return 0;
	};
	printf("Prienik mnozin 1 a 2 je: ");
	vypis(pr);
	
	MNOZINA* zj = zjednotenie(mnoz1, mnoz2);
		if (zj == NULL){
		destruct_mnoz(mnoz1);
		destruct_mnoz(mnoz2);
		destruct_mnoz(zj);
		puts("chyba v allokacie pamati");
		return 0;
	};
	printf("Zjednotenie mnozin 1 a 2 je: ");
	vypis(zj);
	
	destruct_mnoz(pr);
	destruct_mnoz(zj);
	destruct_mnoz(mnoz1);
	destruct_mnoz(mnoz2);
	
	return 0;
}
