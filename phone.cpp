#include <iostream>
#include <string>
#include "phone.h"

using namespace std;


PhoneBookItem::PhoneBookItem(const string& l, const string& f, const string& ph) 
{
	lastname = l;
	firstname = f;
	phone = ph;
    next = NULL;
}

PhoneBook::PhoneBook() 
{
	head = NULL;
	num = 0;
}

PhoneBook::PhoneBook( const PhoneBook& pb) 
{
	head = NULL;
	num = 0;
	Copy(pb);
}

PhoneBook::~PhoneBook() 
{
	Clear();
}

PhoneBook& PhoneBook::operator=(const PhoneBook& pb) 
{
	if (this != &pb) 
	{
		Clear();
		Copy(pb);
	}
	return *this;
}

/********************** checks to see if the phonebook is empty or not **********************/
bool PhoneBook::IsEmpty() const 
{
	
	if(num == 0)
	{
		return true;
	}
	return false;
}

/********************** checks the number of elements in the phonebook **********************/
int PhoneBook::Size() const 
{
	
	return num;            // returns the number of elements
}

/******************** inserts a new name and phone number in the phonebook *******************/
bool PhoneBook::Insert(const string& last, const string& first, const string& ph)
{
	PhoneBookItem *prevItem = NULL;
	PhoneBookItem *currItem = head;
	PhoneBookItem *temp;
	string currName, nameToInsert;

	nameToInsert = last + first;

	while (currItem != NULL)
	{
		currName = currItem->lastname + currItem->firstname;	// get current name

		// this means we found the insertion point.
		if (nameToInsert < currName)
		{
			break;
		}

		// name already exists; do not add
		else if (nameToInsert == currName)
		{
			return false;
		}

		// Go to the next node.
		prevItem = currItem;
		currItem = currItem->next;
	}

	// at this point we know it's safe to create the item.
	temp = new PhoneBookItem(last, first, ph);

	if (prevItem != NULL)
	{
		prevItem->next = temp;
		temp->next = currItem;
	}
	else
	{
		temp->next = head;
		head = temp;
	}

	num++;
	return true;
}

/********************** deletes a name and number from the phonebook **********************/
bool PhoneBook::Delete(const string& last, const string& first)
{
	PhoneBookItem *currItem = this->head;
	PhoneBookItem *prevItem = NULL;

	while (currItem != NULL)                   // run through loop if the current item is not a NULL. 
	{
		if ((currItem->lastname == last) && (currItem->firstname == first))
		{
			if (prevItem == NULL)
			{
				prevItem = head;			// Keep track of the old head node.
				head = head->next;			// Set new head node
				delete prevItem;			// Delete old head node.
			}
			else
			{
				prevItem->next = currItem->next;
				delete currItem;
			}
			num--;
			return true;
		}

		prevItem = currItem;
		currItem = currItem->next;
	}

	return false;
}

/********************** reads a person's name and returns his or her phone number **********************/
bool PhoneBook::Lookup(const string& last, const string& first, string& ph) const
{
	PhoneBookItem *currItem = this->head;
	while (currItem != NULL)                             // while the current item is not equal to NULL
	{
		if ((currItem->lastname == last) && (currItem->firstname == first))       // check to see if the current item has both last and first name.
		{
			ph = currItem->phone;                        // ph has current item to phone. 
			return true;
		}
		currItem = currItem->next;
	}
	return false;

}

/********************** prints out the last name, firstname followed by phone number **********************/
ostream& operator<< (ostream& out, const PhoneBook& ph)                                // outputs the values
{
	PhoneBookItem *currItem = ph.head;                                 // ph.head is assigned to current item.
	while (currItem != NULL)
	{
		cout << currItem->lastname << ", " << currItem->firstname << ": " << currItem->phone << endl;        // prints the last name, first name, and the phone number.
		currItem = currItem->next;
	}
	return out;
}

/********************** clears the entire phonebook of entries **********************/
void PhoneBook::Clear()
{
	PhoneBookItem *currItem = head;
	while(currItem != NULL)
	{
		head = head->next;
		delete currItem;               // after creating head, delete the current item.
		currItem = head;
	}
		num = 0;                      // both head and num have to be NULL and 0.
		//head = NULL;
}

/********************** copies the name and phone number and uses the insert function to check **********************/
void PhoneBook::Copy(const PhoneBook& ph)
{
	if(!IsEmpty())
	{
		cout << "Error, internal error in private member function Copy";
		exit(1);
	}
	PhoneBookItem *currItem = ph.head;
	
	while(currItem != NULL)
	{  
		Insert(currItem->lastname, currItem->firstname, currItem->phone);         // inserts the last name, first name, and phone number.
		currItem = currItem->next;                                            // current item has to be the next current item. 
	}

}