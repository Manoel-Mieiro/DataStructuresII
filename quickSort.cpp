#include <stdio.h>

void Quicksort(int vet[], int l, int r) {
    int pivot = vet[l + (r - l) / 2];
    /*
	Atribui-se ao pivot o �ndice do meio do array, para que
	seja mais r�pido
	
	Assim, pivot = vet[0 + (8 - 0)/2] -> vet[4] = pivot
	*/
    int left = l, right = r;
    
    while (left <= right) {
        while (vet[left] < pivot) left++;
        while (vet[right] > pivot) right--;
        if (left <= right) {
            int temp = vet[left];
            vet[left] = vet[right];
            vet[right] = temp;
            left++;
            right--;
        }
    }
    
    if (l < right) Quicksort(vet, l, right);
    if (left < r) Quicksort(vet, left, r);
}

int main() {
    int v[] = {4, 2, 8, 7, 1, 5, 3, 6};
    int length = sizeof(v) / sizeof(int);
    
    Quicksort(v, 0, length - 1);
    
    for (int i = 0; i < length; i++)
        printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}

