#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int* data;
	int size;
}MNOZINA;

MNOZINA* konstrukt_mnoz(){
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
	for (i = 0; i < mnoz->size - 1; i++) {
		data[i] = mnoz->data[i];
	}
	free(mnoz->data);
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
	free(mnoz->data);
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

void heapify(int arr[], int n, int i) {
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

void vypis(MNOZINA* mnoz) {
	int i;
	
	for(i = 0; i < mnoz->size; i++){
		printf("%d ", mnoz->data[i]);
	}
	puts("\n");
}

int main() {
	MNOZINA* mnoz = konstrukt_mnoz();
	pridat(mnoz, 1);
	pridat(mnoz, 10);
	pridat(mnoz, 3);
	vypis(mnoz);
	odstranit(mnoz, 10);
	pridat(mnoz, 7);
	vypis(mnoz);
	destruct_mnoz(mnoz);
	return 0;
}
