#ifndef PHONE_H
#define PHONE_H

#include <iostream>
#include <string>
using namespace std;

struct PhoneBookItem  
{
	string lastname;
	string firstname;
	string phone;
	PhoneBookItem* next;
	PhoneBookItem(const string& l, const string& f, const string& ph);
};

class PhoneBook 
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook&);
	~PhoneBook();

	PhoneBook& operator=(const PhoneBook&);

	bool IsEmpty() const;
	int Size() const;
	bool Insert(const string& last, const string& first, const string& ph);
	bool Delete(const string& last, const string& first);
	bool Lookup(const string& last, const string& first, string& ph) const;

	friend ostream& operator<< (ostream&, const PhoneBook&);

private:
	void Clear();
	void Copy(const PhoneBook&);

	PhoneBookItem* head;   // points to head of the phone book
	int num;     // the number of entries in the phone book
};

#endif