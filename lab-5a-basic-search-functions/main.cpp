#include <iostream>
#include <list>
#include <iterator>
#include <exception>
using namespace std;


void displayList(list<int>& arg);
void generateRandNumbers(int randNumbers[], int size);

list<int>::iterator searchListBinary(list<int>& arg, int target);
list<int>::iterator searchListLinear(list<int>& arg, int target);


                                        
int main(){
	
	const int size = 100;
	int myints[size] = { 0 };
	generateRandNumbers(myints, size);
	list<int> mylist(myints, myints + 100);
	list<int>::iterator itr = mylist.begin();
	cout << "hi" << endl;

	displayList(mylist);
	mylist.sort();

	displayList(mylist);


		//list<int> listOfInts({ 1, 4, 6, 7, 9, 13, 15, 17, 20 });
	//list<int>::iterator itr = searchListBinary(listOfInts, 4356548);
	//if (itr == listOfInts.end())
	itr = searchListBinary(mylist, 230054);
	if (itr==mylist.end())
		cout << "Item not found!!" << endl;
	else
		cout << *itr << " found !!" << endl;

	itr = searchListLinear(mylist, 42);

	if (itr == mylist.end())
		cout << "Item not found!!" << endl;
	else
		cout << *itr << " found !!" << endl;


	
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
		std::cout << ' ' << *it;

	std::cout << '\n';
}
