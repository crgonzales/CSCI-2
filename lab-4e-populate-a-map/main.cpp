#include <string>
#include <map>
#include <iostream>

using namespace std;

class Person {
private:
	string first_name;
	string last_name;

public:
	Person(string fname, string lname) {
		this->first_name = fname;
		this->last_name = lname;
	}
	string display() {
		return this->first_name;
	}
};

int main() {

	map<string, Person> per;
	Person p1("John", "Kennedy");
	per.insert(pair<string, Person>("johnkennedy@mail.com", p1));
	Person p2("Abraham", "Lincoln");
	per.insert(pair<string, Person>("abrahamlincoln@hotmail.com", p2));
	Person p3("Johnson", "lee");
	per.insert(pair<string, Person>("johnson@mail.com", p3));
	Person p4("Jason", "Borne");
	per.insert(pair<string, Person>("jasonborne@yahoo.com", p4));
	Person p5("Jake", "Sully");
	per.insert(pair<string, Person>("jakesully@outlook.com", p5));

	while (true) {

		cout << "Please choose an option from the menu below !" << endl;

		cout << "1. Add a person with email" << endl;

		cout << "2. Search for a person via email" << endl;

		cout << "3. Iterate and display all elements" << endl;

		cout << "4. Exit" << endl;

		int opt;

		cin >> opt;

		if (opt == 4) {

			cout << "Exiting. . ." << endl;

			break;

		}

		else {

			switch (opt) {

			case 1:

			{

				cout << "Enter email: " << endl;

				string eml;

				cin >> eml;

				cout << "Enter first name: " << endl;

				string fname;

				cin >> fname;

				cout << "Enter last name: " << endl;

				string lname;

				cin >> lname;

				Person p(fname, lname);

				per.insert(pair<string, Person>(eml, p));

				cout << "Person added successfully !!" << endl;

				break;

			}

			case 2:

			{

				cout << "Enter the email id: " << endl;

				string em;

				cin >> em;

				map<string, Person>::iterator it;

				for (it = per.begin(); it != per.end(); ++it) {

					if (it->first == em) {

						cout << "User Found !!" << endl;

						cout << it->first << " - " << (it->second).display() << endl;

						break;

					}

				}

				if (it == per.end()) {

					cout << "Email does not exist in database" << endl;

					cout << "Please search again. . ." << endl;

				}

				break;

			}

			case 3:

			{

				map<string, Person>::iterator itr;

				for (itr = per.begin(); itr != per.end(); ++itr) {

					cout << itr->first << " - " << (itr->second).display() << endl;

				}

				break;

			}

			default:

			{

				cout << "Enter valid option..." << endl;

			}

			}

		}

	}

}