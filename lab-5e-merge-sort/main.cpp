#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
void display(vector<int>& arg);
void swap(vector<vector<int>>& arg, int i, int j);
void mergeSort(vector<int> arg);
void merge(vector<vector<int>> &arg);
void sort(vector<vector<int>>& arg);
int main() {

	vector<int> foo = { 7, 15, 4, 20, 9, 1, 6 ,13, 17, 1 };
	//vector<int>foo = { 2 };

	vector<int> arg = foo;
	//merge sort start here
	mergeSort(foo);

	
	
	

	return 0;
}
void sort(vector<vector<int>>& arg) {
	if (arg.size() == 1)
	{
		cout << "\nSTOP\n";
	}
	else{
		for (int i = 1; i < arg.size(); i += 2) {
			for (int j=0; j< arg[i].size(); j++)
				if (arg[i][j] < arg[i - 1][j]) {

					swap(arg, i, i - 1);
				}
		}


	merge(arg);

		for (int i = 0; i < arg.size(); i++) {
			cout << "\nstep:\n";

			display(arg[i]);

		}


		cout << "\nrecursion\n";

	sort(arg);
	}
};

void mergeSort(vector<int> arg) {
	vector<vector<int>> split;
	vector<int> temp;


	//turn vector into many size 1 vectors
	for (int i = 0; i < arg.size(); i++) {
		split.push_back({ arg[i] });
	}

	//sort

	sort(split);
	

}

void merge(vector<vector<int>>& arg) {
	int size = arg.size();
	for (int i = 0; i < size/2; i++) {
		arg[i].insert(arg[i].end(),arg[i+1].begin(),arg[i+1].end());

		cout << "\nmerge" << endl;
		for (int i = 0; i < arg.size(); i++) {
			display(arg[i]);

		}
		cout << "\nerase" << endl;
		arg.erase(arg.begin() + i+1);

		for (int i = 0; i < arg.size(); i++) {
			display(arg[i]);

		}
	}

}



void display(vector<int>& arg) {
	for (int i = 0; i < arg.size(); i++) {
		cout << arg[i] << " ";
	}
	cout << endl;
}

void swap(vector<vector<int>>& arg, int i, int j) {
	vector<int> temp = arg[i] ;
	arg[i] = arg[j];
	arg[j] = temp;
}