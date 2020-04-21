#include <iostream>
#include <list>
#include <iterator>
#include <exception>
using namespace std;


void displayList(list<int>& arg);
void generateRandNumbers(int randNumbers[], int size);

list<int>::iterator searchListBinary(list<int>& arg, int target, int& newount);
list<int>::iterator searchListLinear(list<int>& arg, int target, int& count);



int main() {
	const int size = 100;
	int myints[size] = { 0 };

	int count, newCount = 0;
	generateRandNumbers(myints, size);
	list<int> mylist(myints, myints + 100);
	list<int>::iterator itr = mylist.begin();
	cout << endl;
	displayList(mylist);
	mylist.sort();
	displayList(mylist);
	cout << endl;

	while (true) {
		int opt = 0;
		count = 0;
		cout << "Please choose an option from the menu below." << endl;
		cout << "1. Search List" << endl;
		cout << "2. Exit" << endl;
		cout << "option: ";

		cin >> opt;

		if (opt == 1) {

			for (list<int>::iterator itr = mylist.begin(); itr != mylist.end(); ++itr) {
				newCount = 0;

				itr = searchListBinary(mylist, *itr, newCount);
				count = count + newCount;

			}
			count = count / mylist.size();
			cout << endl << "BINARY SEARCH -- operations: " << count << endl;
			count = 0;


			for (list<int>::iterator itr = mylist.begin(); itr != mylist.end(); ++itr) {
				newCount = 0;

				itr = searchListLinear(mylist, *itr, newCount);
				count = count + newCount;
			}
			count = count / mylist.size();
			cout << endl << "LINEAR SEARCH -- operations: " << count << endl;
		}
		if (opt == 2) {
				cout << "Exiting. . ." << endl;
				break;

		}

	


	return (0);
	}
}


list<int>::iterator searchListLinear(list<int>& arg, int target, int& newCount) {
	newCount = 0;
	for (list<int>::iterator itr = arg.begin(); itr != arg.end(); ++itr) {
		newCount += 1;
		if (target == *itr) {
			return itr;
		}
	}
	return arg.end();
}







list<int>::iterator searchListBinary(list<int>& arg, int target, int& count) {
	int lowerBound = 0;
	int upperBound = arg.size() - 1;  // size return 10, but -1 = 9
	int midPoint = 0;
	int valueAtMidPoint = 0;
	count = 0;
	while (lowerBound <= upperBound) {
		count += 4;
		midPoint = (upperBound + lowerBound) / 2;
		list<int>::iterator it = arg.begin();
		advance(it, midPoint);
		valueAtMidPoint = *it;

		if (target < valueAtMidPoint)
			upperBound = midPoint - 1;
		else if (target > valueAtMidPoint)
			lowerBound = midPoint + 1;
		else if (target == valueAtMidPoint)
			return it;

	}

	return arg.end();
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

void displayList(list<int>& arg) {
	cout << "my list contains:";
	for (list<int>::iterator it = arg.begin(); it != arg.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}