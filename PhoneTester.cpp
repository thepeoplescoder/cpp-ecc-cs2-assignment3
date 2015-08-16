#include <iostream>
#include <string>
#include "phone.h"
using namespace std;


void AddEntry(PhoneBook&);
void DeleteEntry(PhoneBook&);
void LookupEntry(const PhoneBook&);
void Help();

int main(){
	PhoneBook contacts;
	char choice;
	Help();
	do 
	{
		cout << "Enter command: ";
		cin >> choice;
		switch (choice) 
		{
			case 'a':
			case 'A':
				AddEntry(contacts);
				break;
			case 'd':
			case 'D':
				DeleteEntry(contacts);
				break;
			case 'h':
			case 'H':
				Help();
				break;
			case 'l':
			case 'L':
				LookupEntry(contacts);
				break;
			case 'p':
			case 'P':
				cout << "\n" << contacts;
				break;
			case 'q':
			case 'Q':
				cout << "\nExiting command block.\n";
				break;
			case 'n':
			case 'N':
				cout << "\nNumber of names in the phone book: "
					 << contacts.Size() << endl;
				break;
			default:
				cout << "Invalid command.\n";
			    break;
		}
		cout << "\n";
	}
	while (choice != 'q' && choice != 'Q');
 
	//  The next block tests the destructor
	{
		PhoneBook copy1 = contacts;  // tests copy constructor
		cout << "The copy constructor produces a list with "
			<< copy1.Size() << " elements:\n";
		cout << copy1;

		PhoneBook copy2;
		copy2 = contacts;    // tests assignment operator
		cout << "\nThe assignment operator produces a list with "
			<< copy2.Size() << " elements:\n";
		cout << copy2;

		copy2 = contacts;    // tests assignment operator again
		cout << "\nThe assignment operator produces a list with "
			<< copy2.Size() << " elements:\n";
		cout << copy2;
	}
	cout << "\nThe destructor call was apparently successful.\n";
	return 0;
}

void AddEntry(PhoneBook& pb) 
{
	string last, first, phone;
	cout << "Enter last name: ";
	cin >> last;
	cout << "Enter first name: ";
	cin >> first;
	cout << "Enter phone: ";
	cin >> phone;
	bool success = pb.Insert(last, first, phone);
	if (success) 
	{
		cout << "\nAdded to the phone book.\n";
	}
	else 
	{
		cout << "\nError: a person with this name is already in the phone book.\n";
	}
}

void DeleteEntry(PhoneBook& pb) 
{
	string last, first, phone;
	cout << "Enter last name: ";
	cin >> last;
    cout << "Enter first name: ";
	cin >> first;
	bool success = pb.Delete(last, first);
	if (success) 
	{
		cout << "\nDeleted from the phone book.\n";
	}
	else 
	{
		cout << "\nError: no one by this name in the phone book.\n";
	}
}

void LookupEntry(const PhoneBook& pb) 
{
      string last, first, phone;
	  cout << "Enter last name: ";
	  cin >> last;
      cout << "Enter first name: ";
	  cin >> first;
	  bool success = pb.Lookup(last, first, phone);
	  if (success) 
	  {
		  cout << "\nThe phone number is " << phone << ". \n";
	  } 
	  else 
	  {
		  cout << "\nError: no one by this name is in the phone book.\n";
	  }
}

void Help()  
{
	cout << "The following commands are available: \n"
		<< "   a : Add a name to the phone book. \n"
		<< "   d : Delete a name from the phone book. \n"
		<< "   h : Help -- print this list of commands. \n"
		<< "   l : Look up a phone number. \n"
		<< "   n : Report the number of names in the phone book. \n"
		<< "   p : Print the entire phone book. \n"
		<< "   q : Quit. \n";
}
