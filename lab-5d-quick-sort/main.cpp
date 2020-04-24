#include <iostream>
#include <vector>
#include <array>

using namespace std;
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void display(int arg[], int size);

int main() {
    const int size = 9;
	int foo[size] = { 7, 15, 4, 20, 9, 1, 6 ,13, 17 };
//    vector<int>foo = { 1, 4, 6, 7, 9, 13, 15, 17, 20 };
	display(foo,size);
    quickSort(foo,0,size-1);
	display(foo,size);

	return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++)
    {
      
        if (arr[j] < pivot)
        {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);

}
void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
       
        int index = partition(arr, low, high);

        
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

void display(int arg[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arg[i] << " ";
	}
	cout << endl;
}