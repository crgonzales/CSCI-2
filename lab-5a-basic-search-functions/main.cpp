#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<int>::iterator searchListLinear(list<int>& arg, int target);
list<int>::iterator searchListBinary(list<int>& arg, int target);
void generateRandNumbers(int randNumbers[], int size);
int main(){
	const int size = 100;
	int myints[size] = {0};
	int search = 0, found=0;

		
	generateRandNumbers(myints,size);
	std::list<int> mylist(myints, myints+100);
	list<int>::iterator itr = mylist.begin();
	std::cout << "my list contains:";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';


	mylist.sort();

	std::cout << "my sorted list contains:";
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	cout << endl;
	cout << *mylist.begin()<< endl;
	cout << "Please enter an integer to search for: ";
    cin >> search;
	itr = searchListBinary(mylist, search);

	cout << endl << "Binary Search result: " << *itr << endl;
	cout << endl << "BINARY SEARCH" << endl;
	if (search == *itr) {
		cout << *itr << " found!!!@@@ " << endl;

	}
	else
		cout << "item not found!!!@@@" << endl;
	/*
	itr = searchListLinear(mylist, search);
	cout << endl << "Linear Search result: " << *itr << endl;
	cout << endl << "LINEAR SEARCH" << endl;
	if (search == *itr) {
		cout << *itr << " found!!!@@@ " << endl;

	}
	else
		cout << "item not found!!!@@@" << endl;
	*/
	return (0);
}


list<int>::iterator searchListLinear(list<int>& arg, int target){
	for (list<int>::iterator itr = arg.begin(); itr != arg.end(); ++itr) {
		if (target == *itr) {
			return itr;
		}
	}
	return arg.begin();
}

list<int>::iterator searchListBinary(list<int>& arg, int target){
	list<int>::iterator itr = arg.begin();
	if (arg.size() == 1)
		return itr;
	else {
		int mid = arg.size() / 2;
		cout << endl << "mid= " << mid << endl;
		advance(itr, mid);
		if (target == *itr)
			return itr;
		else if (target < *itr) {
			arg.resize(mid - 1);
			return(searchListBinary(arg, target));
		}

		else {
			for (int i = 1; i < mid + 1; i++) {
				cout << *arg.begin();
				arg.pop_front();
				cout << endl;
			}
			return(searchListBinary(arg, target));
		}

	}
	
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