#include <iostream>
#include <vector>
#include <array>

using namespace std;
void swap(vector<int>& arg, int i, int j);

void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void display(vector<int>& arg, int size);
void generateRandNumbers(int randNumbers[], int size);


int main() {
    const int size = 100;
    int bar[size];
    generateRandNumbers(bar, size);
    vector<int> foo(bar, bar + 100);

    //int foo[size] = { 7, 15, 4, 20, 9, 1, 6 ,13, 17,1 };
    //vector<int> foo = { 7, 15, 4, 20, 9, 1, 6 ,13, 17, 1 };
    //vector<int>bar = { 1, 4, 6, 7, 9, 13, 15, 17, 20 };


    cout << "\n unsorted list: \n"<< endl;
    display(foo, size);
    quickSort(foo, 0, size - 1);
    cout << "\n sorted list: \n" << endl;
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

   // cout << "\ni = " << i << endl;
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

void generateRandNumbers(int randNumbers[], int size)
{
    int index = 0;
    int new_num;
    for (int counter = 0; counter < size; counter++)
    {
        do {
            new_num = rand() % 1000 + 1;
            for (int i = 0; i < size; i++) {
                if (new_num == randNumbers[i]) {
                    new_num = 0;
                    break;
                }
            }
        } while (new_num == 0);
        randNumbers[index] = new_num;
        index++;
    }
}