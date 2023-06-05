#include "Chapter12.h"
#include <iostream>
using namespace std;



// Task 1

Cow::Cow() : name("\0"), hobby(nullptr), weight(0) {
}
Cow::Cow(const char* nm, const char* ho, double wt) : weight(wt) {
	int i = 0;
	for (; i < 19 and '\0' != *(nm + i); ++i)
		name[i] = *(nm + i);
	name[i] = '\0';

	int len = strlen(ho);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, ho);

}
Cow::Cow(const Cow& c) : weight(c.weight) {
	strcpy_s(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
}
Cow::~Cow() {
	delete[] hobby;
	hobby = nullptr;
}
Cow& Cow::operator=(const Cow& c) {
	if (this == &c)
		return *this;
	delete[] hobby;
	strcpy_s(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char[len + 1];
	strcpy_s(hobby, len + 1, c.hobby);
	weight = c.weight;
	return *this;
}
void Cow::ShowCow() const {
	cout << "\nName: " << name << ", hobby: " << hobby << ", weight: " << weight << endl;
}
ostream& operator<<(ostream& os, const Cow& c) {
	if (c.hobby)
		os << "\nName: " << c.name << ", hobby: " << c.hobby << ", weight: " << c.weight << endl;
	else
		os << "\nName: " << c.name << ", no hobby, weight: " << c.weight << endl;
	return os;
}



// Task 2

int String::num_strings = 0;
int String::HowMany()
{
	return num_strings;
}
String::String(const char* s)
{
	len = strlen(s);          
	str = new char[len + 1];      
	strcpy_s(str, len+1, s);          
	num_strings++;               
}
String::String()                  
{
	len = 4;
	str = new char[1];
	str[0] = '\0';               
	num_strings++;
}
String::String(const String& st)
{
	num_strings++;             
	len = st.len;             
	str = new char[len + 1]; 
	strcpy_s(str, len+1, st.str);
}
String::~String()                   
{
	--num_strings;              
	delete[] str;         
}
String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len+1, st.str);
	return *this;
}
String& String::operator=(const char* s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len+1, s);
	return *this;
}
char& String::operator[](int i)
{
	return str[i];
}
const char& String::operator[](int i) const
{
	return str[i];
}
bool operator<(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2)
{
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}
String String::operator+(const String& second) const {
	int Len = strlen(str) + strlen(second.str);
	char* Str = new char[Len + 1]; 
	strcpy_s(Str, Len + 1, str);
	strcat_s(Str, Len + 1, second.str);
	Str[Len] = '\0';
	String Buf(Str);
	delete[]Str;
	return Buf;
}
String String::operator+(const char* second) const {
	int Len = strlen(str) + strlen(second);
	char* Str = new char[Len + 1]; 
	strcpy_s(Str, Len + 1, str);
	strcat_s(Str, Len + 1, second);
	Str[Len] = '\0';
	String Buf(Str);
	delete[]Str;
	return Buf;
}
void String::stringlow() { 
	for (int i = 0; i < len; ++i)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
}
void String::stringup() { 
	for (int i = 0; i < len; ++i)
		if (islower(str[i]))
			str[i] = toupper(str[i]);
}
int String::has(char ch)const { 
	int num = 0;
	for (int i = 0; i < len; ++i)
		if (ch == (str[i]))
			++num;
	return num;
}
String operator+(const char* second, const String& Strin) {
	int Len = strlen(Strin.str) + strlen(second);
	char* Str = new char[Len + 1]; 
	strcpy_s(Str, Len+1, second);
	strcat_s(Str, Len + 1, Strin.str);
	Str[Len] = '\0';
	String Buf(Str);
	delete[]Str;
	return Buf;
}



// Task 3

Stock::Stock() 
{
	company = nullptr;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const string& co, long n, double pr)
{
	int len = sizeof co;
	company = new char[len + 1];
	int i = 0;
	for (; i < len and '\0' != co[i]; ++i)
		company[i] = co[i];
	company[i] = '\0';
	if (n < 0)
	{
		cout << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
Stock::~Stock()    
{
	if (company) { 
		delete[]company;
		company = nullptr;
	}
}
void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares purchased can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
void Stock::show() const
{
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);
	if (company) {
		cout << "Company: " << company
			<< "  Shares: " << shares << '\n';
		cout << "  Share Price: $" << share_val;
		cout.precision(2);
		cout << "  Total Worth: $" << total_val << '\n';
	}
	else {
		cout << "Company: noname,  Shares: " << shares << '\n';
		cout << "  Share Price: $" << share_val;
		cout.precision(2);
		cout << "  Total Worth: $" << total_val << '\n';
	}
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}
ostream& operator<<(ostream& os, const Stock& s) {
	ios_base::fmtflags orig =
		os.setf(ios_base::fixed, ios_base::floatfield);
	streamsize prec = cout.precision(3);
	if (s.company) {
		os << "Company: " << s.company
			<< "  Shares: " << s.shares << '\n'
			<< "  Share Price: $" << s.share_val;
		os.precision(2);
		os << "  Total Worth: $" << s.total_val << '\n';
	}
	else {
		os << "Company: noname,  Shares: " << s.shares << '\n' <<
			"  Share Price: $" << s.share_val;
		os.precision(2);
		os << "  Total Worth: $" << s.total_val << '\n';
	}
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}



// Task 4

Stack12::Stack12(int n) : size(n), top(0)
{
	if (size)
		pitems = new Item12[n];
	else
		pitems = nullptr;
}
Stack12::Stack12(const Stack12& st) : size(st.size), top(st.top) {
	if (size) {
		pitems = new Item12[size];
		for (int i = 0; i < size; ++i)
			pitems[i] = st.pitems[i];
	}
	else
		pitems = nullptr;
}
Stack12::~Stack12() { 
	delete[]pitems;
	pitems = nullptr;
}
bool Stack12::isempty() const
{
	return top == 0;
}
bool Stack12::isfull() const
{
	return top == MAX;
}
bool Stack12::push(const Item12& item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}
bool Stack12::pop(Item12& item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}
Stack12& Stack12::operator=(const Stack12& st) {
	if (this == &st)
		return *this;
	delete[] pitems;
	size = st.size;
	top = st.top;
	if (size) {
		pitems = new Item12[size];
		for (int i = 0; i < size; ++i)
			pitems[i] = st.pitems[i];
	}
	else
		pitems = nullptr;
	return *this;
}



// Task 5

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;  
	items = 0;
}
Queue::~Queue()
{
	Node* temp;
	while (front != NULL)  
	{
		temp = front;     
		front = front->next;
		delete temp;
	}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}
int Queue::queuecount() const
{
	return items;
}
bool Queue::enqueue(const Item122& item)
{
	if (isfull())
		return false;
	Node* add = new Node; 
	add->item = item;  
	add->next = NULL;   
	items++;
	if (front == NULL) 
		front = add;   
	else
		rear->next = add; 
	rear = add;      
	return true;
}
bool Queue::dequeue(Item122& item)
{
	if (front == NULL)
		return false;
	item = front->item;  
	items--;
	Node* temp = front; 
	front = front->next; 
	delete temp;      
	if (items == 0)
		rear = NULL;
	return true;
}
void Customer12::set(long when)
{
	processtime = rand() % 3 + 1;
	arrive = when;
}