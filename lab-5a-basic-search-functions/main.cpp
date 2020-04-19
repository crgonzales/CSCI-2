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
	cout << mylist.size() << endl;
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

list<int>::iterator searchListBinary(list<int>& arg, int target) {
	int lowerBound = 0;
	int upperBound = arg.size() - 1;  // size return 10, but -1 = 9
	int midPoint = 0;
	int valueAtMidPoint = 0;


	while (lowerBound <= upperBound) {
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