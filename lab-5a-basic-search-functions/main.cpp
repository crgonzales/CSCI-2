#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<int>::iterator searchListLinear(list<int>& arg, int target);
list<int>::iterator searchListBinary(list<int>& arg, int target);

int main(){
	int myints[] = { 75,23,65,42,13 };
	std::list<int> mylist(myints, myints + 5);

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';


	mylist.sort();

	std::cout << "mylist contains:";
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';

	cout << *searchListBinary(mylist, 76) << endl;

	if (mylist.end != 76)
		cout << "item not found!!!@@@" << endl;

	return (0);
}


/*list<int>::iterator searchListLinear(list<int>& arg, int target){
	
}*/

list<int>::iterator searchListBinary(list<int>& arg, int target){
	list<int>::iterator itr = arg.begin();
	if (arg.size() == 1)
		return itr;
	else {
		int mid = arg.size() / 2;
		advance(itr, mid);
		if (target == *itr)
			return itr;
		else if (target < *itr) {
			arg.resize(mid - 1);
			return(searchListBinary(arg, target));
		}

		else {
			for (int i = 1; i < mid + 1; i++) {
				arg.pop_front();
				return(searchListBinary(arg,target));
			}
		}

	}
	return arg.end();
}



int binarySearch(const int arr[], int first, int last, int target) {
	int index;
	if (first > last)
		index = -1;
	else {
		int mid = first + (last - first) / 2;
		if (target == arr[mid])
			index = mid;
		else if (target < arr[mid])
			index = binarySearch(arr, first, mid - 1, target);
		else
			index = binarySearch(arr, mid + 1, last, target);

	}
	return index;

}