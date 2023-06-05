#ifndef Chapter12
#define Chapter12

using namespace std;
#include <cstring>
#include <iostream>


// Task 1

class Cow {
public:
	char name[20];
	char* hobby;
	double weight;
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow& c);
	~Cow();
	Cow& operator=(const Cow& c);
	void ShowCow() const;
	friend ostream& operator<<(ostream& os, const Cow&);
};



// Task 2

class String
{
private:

	int len;                // length of string
	static int num_strings; // number of objects
	static const int CINLIM = 80;  // cin input limit
public:
	char* str;             // pointer to string
	// constructors and other methods
	String(const char* s); // constructor
	String();               // default constructor
	String(const String&); // copy constructor
	~String();              // destructor
	int length() const { return len; }
	void stringlow(); // lower case letters
	void stringup(); // upper case letters
	int has(char)const; // return the number of characters in the string
	// overloaded operator methods    
	String& operator=(const String&);
	String& operator=(const char*);
	String operator+(const String&) const;
	String operator+(const char*) const;
	friend String operator+(const char* pStr, const String& Str);
	char& operator[](int i);
	const char& operator[](int i) const;
	// overloaded operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	// static function
	static int HowMany();
};



// Task 3

class Stock
{
private:
	char* company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }
public:
	Stock();
	Stock(const string& co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;
	const Stock& topval(const Stock& s) const;
	friend ostream& operator<<(ostream& os, const Stock& s);
};



// Task 4

typedef unsigned long Item12;
class Stack12
{
private:
	enum { MAX = 10 };
	Item12* pitems;
	int size;
	int top;
public:
	Stack12(int n = MAX);
	Stack12(const Stack12& st);
	~Stack12();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item12& item);

	bool pop(Item12& item);
	Stack12& operator=(const Stack12& st);
};



// Task 5 & 6

class Customer12
{
private:
	long arrive;     
	int processtime; 
public:
	Customer12() : arrive(0), processtime(0) {}
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer12 Item122;

class Queue
{
private:
	struct Node { Item122 item; struct Node* next; };
	enum { Q_SIZE = 10 };
	Node* front; 
	Node* rear; 
	int items;
	const int qsize; 
	Queue(const Queue& q) : qsize(0) { }
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item122& item);
	bool dequeue(Item122& item);
};

#endif