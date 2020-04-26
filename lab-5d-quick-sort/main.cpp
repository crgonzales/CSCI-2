#include <iostream>
#include <vector>
#include <array>

using namespace std;
void swap(vector<int>& arg, int i, int j);

void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void display(vector<int>& arg, int size);



int main() {
    const int size = 10;
    //int foo[size] = { 7, 15, 4, 20, 9, 1, 6 ,13, 17,1 };
    vector<int> foo = { 7, 15, 4, 20, 9, 1, 6 ,13, 17, 1 };
    //vector<int>bar = { 1, 4, 6, 7, 9, 13, 15, 17, 20 };
    display(foo, size);
    quickSort(foo, 0, size - 1);
    display(foo, size);

    return 0;
}

void swap(vector<int>& arg, int i, int j) {
    int t = arg[i];
    arg[i] = arg[j];
    arg[j] = t;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = (low);

    for (int j = low; j <= high; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i, low);

    cout << "\ni = " << i << endl;
    return (i);


}


void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {

        int index = partition(arr, low, high);


        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }
}

void display(vector<int>& arg, int size) {
    for (int i = 0; i < size; i++) {
        cout << arg[i] << " ";
    }
    cout << endl;
}