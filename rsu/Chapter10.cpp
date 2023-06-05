#include "Chapter10.h"
#include <iostream>
#include <cstring>
using namespace std;

// Task 1
BankAccount::BankAccount(const string& client, const string& num, double bal)
{
    name = client;
    acctnum = num;
    if (bal < 0)
    {
        cout << "Number of ballance can't be negative; balance set to 0.\n";
        balance = .0;
    }
    else
        balance = bal;
}
void BankAccount::show(void) const
{
    cout << "Name:   " << name << "\naccount: " << acctnum << "\nbalance: " << balance << endl << endl;
}
void BankAccount::deposit(double cash)
{
    if (cash < 0)
        cout << "Number of deposit can't be negative. "
        << "Transaction is aborted.\n";
    else
        balance += cash;
}
void BankAccount::withdraw(double cash)
{
    if (cash < 0)
        cout << "Number of withdraw can't be negative. "
        << "Transaction is aborted.\n";
    else if (cash > balance)
        cout << "You can't withdraw more than you have! "
        << "Transaction is aborted.\n";
    else
        balance -= cash;
}


// Task 2
Person::Person(const string& ln, const char* fn)
{
    lname = ln;
    strncpy_s(fname, fn, LIMIT - 1);
    fname[LIMIT - 1] = '\0';
}
void Person::Show() const
{
    cout << "Last Name: " << lname << "\nFirst Name: " << fname << endl;
}
void Person::FormalShow() const
{
    cout << "Formal name: " << fname << " " << lname << endl;
}


// Task 3
Golf::Golf(const char* name, int hc)
{
    strncpy_s(fullname, name, Len - 1);
    fullname[Len - 1] = '\0';
    handicap = hc;
}
int Golf::setgolf()
{
    char str[Len];
    int hand;
    cout << "Enter full name: ";
    cin.get(str, Len);
    if (str[0] == '\0')
    {
        cin.clear();
        return 0;
    }
    while (cin.get() != '\n')
        continue;
    cout << "Enter handicap: ";
    (cin >> hand).get();
    Golf tmp{ str, hand };
    *this = tmp;
    return 1;
}
void Golf::sethandicap(int hc)
{
    handicap = hc;
}
void Golf::showgolf() const
{
    cout << "Name: " << fullname
        << "\nhandicap: " << handicap << endl;
}


// Task 4
namespace SALES10
{
    Sales::Sales(const double ar[], int n)
    {
        double max, min, total = .0;
        for (int i = 0; i < QUARTERS; i++)
        {
            if (n > i) sales[i] = ar[i];
            else sales[i] = .0;
            total += sales[i];
        }
        max = min = sales[0];
        for (int i = 0; i < n && i < QUARTERS; i++)
        {
            if (max < sales[i]) max = sales[i];
            if (min > sales[i]) min = sales[i];
        }
        s_max = max;
        s_min = min;
        average = (n < QUARTERS) ? total / n : total / QUARTERS;
    }
    void Sales::setSales()
    {
        double arr[QUARTERS];
        for (int i = 0; i < QUARTERS; i++)
        {
            std::cout << "Enter sales #" << i + 1 << ": ";
            std::cin >> arr[i];
        }
        Sales tmp(arr, QUARTERS);
        *this = tmp;
    }
    void Sales::showSales() const
    {
        for (int i = 0; i < QUARTERS; i++)
            std::cout << "sales #" << i + 1 << ": " << sales[i] << std::endl;
        std::cout << "average: " << average << "\n"
            << "max:     " << s_max << "\n"
            << "min:     " << s_min << std::endl;
    }
}


// Task 5
bool Stack::isempty() const
{
    return top == 0;
}
bool Stack::isfull() const
{
    return top == MAX;
}
bool Stack::push(const Item& item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}
bool Stack::pop(Item& item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}


// Task 6
Move::Move(double a, double b)
{
    x = a;
    y = b;
}
void Move::showmove() const
{
    std::cout << "x = " << x << "; y = " << y << ";\n";
}
Move Move::add(const Move& m) const
{
    return Move(x + m.x, y + m.y);
}
void Move::reset(double a, double b)
{
    x = a;
    y = b;
}


// Task 7
Plorg::Plorg(const char* name, int i)
{
    strncpy_s(fullname, name, Len);
    fullname[Len - 1] = '\0';
    ci = i;
}
void Plorg::show() const
{
    std::cout << "Plorg\n name: " << fullname << "\n CI: " << ci << "\n";
}
void Plorg::changeCI(int i)
{
    ci = i;
}


// Task 8
List::List()
{
    top = 0;
}
bool List::isempty() const
{
    return top == 0;
}
bool List::isfull() const
{
    return top == MAX;
}
void List::add(const Item08& item)
{
    if (top < MAX)
        items[top++] = item;
}
void List::visit(void (*pf)(Item08&))
{
    for (int i = 0; i < top; i++)
        pf(items[i]);
}
void List::show() const
{
    if (isempty())
        std::cout << "List is empty.\n";
    else
        for (int i = 0; i < top; i++)
            std::cout << "Item #" << i + 1 << ": " << items[i] << "\n";
}