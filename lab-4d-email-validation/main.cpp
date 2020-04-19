//Carlos Gonzales
//Lab 4d

#include <string>
#include <map>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

bool isEmailValid(string email);

int main() {
	while (true) {
		cout << "Please choose an option from the menu below." << endl;

		cout << "1. Validate e-mail" << endl;

		cout << "2. Exit" << endl;
		cout << "option: ";
		int opt;

		cin >> opt;
		cout << endl;

		if (opt == 1) {
			cout << "Enter a valid email: ";
			string email = "";
			cin.ignore();
			getline(cin, email);
			cout << endl;
			try {
				isEmailValid(email);
				cout << "Valid email!!\n" << endl;
			}
			catch (exception e) {
				cout << "Error Message: " << e.what() << endl<< endl;
			}
		}
		if (opt == 2) {

			cout << "Exiting. . ." << endl;

			break;

		}
	}
	return (0);
}

bool isEmailValid(string email) {
	
	list<string> validEmailExtensions = { "@gmail.com", "@aol.com", "@cos.edu", "@giant.cos.edu" };
	size_t charFound = email.find_first_of("@");
	if (charFound == string::npos) {
		throw exception("@ not found!!!");
	}

	for (list<string>::const_iterator iterator = validEmailExtensions.begin(), end = validEmailExtensions.end(); iterator != end; ++iterator) {
		std::size_t found = email.find(*iterator);
		if (found != string::npos)
			return true;
	}
	return false;
}