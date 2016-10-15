#include <stdio.h>
#include <stdlib.h>

#define MAX_INT  1000
#define TRUE     1
#define FALSE    0

void fill(int *, int);
void print(int *, int);
void swap(int *, int, int);
void shuffle(int *, int);
void quicksort(int *, int);
void sort(int *, int, int);
int partition(int *, int, int);
int isSorted(int *, int);

int main(void)
{
    int size = 100;
    int a[size];
    fill(a, size);
    quicksort(a, size);
    print(a, size);
    if (isSorted(a, size)) printf("sorted!\n");
    return 0;
}

void fill(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
	arr[i] = (int) rand() % MAX_INT;
}

void print(int arr[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
    printf("%d ", arr[i]);
    printf("\n");
    
}

void swap(int array[], int a, int b)
{
    int t = array[a];
    array[a] = array[b];
    array[b] = t;
}

void shuffle(int arr[], int sz)
{
    int i, r;
    for (i = 1; i < sz; i++)
    {
	r = rand() % i;
	swap(arr, r, i);
    }
}

void quicksort(int arr[], int sz)
{
    shuffle(arr, sz);
    sort(arr, 0, sz - 1);
}

void sort(int a[], int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(a, lo, hi);
    sort(a, lo, j - 1);
    sort(a, j + 1, hi);
}

int partition(int a[], int lo, int hi)
{
    int i = lo, j = hi + 1;
    while (TRUE)
    {
	while (a[++i] < a[lo])
	    if (i == hi) break;
	while (a[--j] > a[lo])
	    if (j == lo) break;
	if (i >= j) break;
	swap(a, i, j);
    }
    swap(a, lo, j);
    return j;
}

int isSorted(int a[], int sz)
{
    int i;
    for (i = 1; i < sz; i++)
        if (a[i] < a[i-1]) return FALSE;
    return TRUE;
}
