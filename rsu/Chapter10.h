#ifndef Chapter10
#define Chapter10

#include <string>
using namespace std;

// Task 1
class BankAccount
{
private:
    string name;
    string acctnum;
    double balance;
public:
    BankAccount(const string& client,
        const string& num, double bal = 0.0);
    void show(void) const;
    void deposit(double cash);
    void withdraw(double cash);
};


// Task 2
class Person
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    Person() { lname = ""; fname[0] = '\0'; }
    Person(const string& ln, const char* fn = "Some");
    void Show() const;
    void FormalShow() const;
};


// Task 3
class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf(const char* name = "", int hc = 0);
    int setgolf();
    void sethandicap(int hc);
    void showgolf() const;
};


// Task 4
namespace SALES10
{
    class Sales
    {
    private:
        enum { QUARTERS = 4 };
        double sales[QUARTERS]{};
        double average;
        double s_max;
        double s_min;
    public:
        Sales() { s_max = s_min = average = 0; }
        Sales(const double ar[], int n);
        void setSales();
        void showSales() const;
    };

}


// Task 5
struct customer {
    char fullname[35];
    double payment;
};
typedef customer Item;
class Stack
{
private:
    enum { MAX = 10 };
    Item items[MAX]{};
    int top;
public:
    Stack() { top = 0; }
    bool isempty() const;
    bool isfull() const;
    bool push(const Item& item);
    bool pop(Item& item);
};


// Task 6
class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    Move add(const Move& m) const;
    void reset(double a = 0, double b = 0);
};


// Task 7
class Plorg
{
private:
    static const int Len = 19;
    char fullname[Len];
    int ci;
public:
    Plorg(const char* name = "Plorga", int i = 50);
    void show() const;
    void changeCI(int i);
};


// Task 8
typedef double Item08;
class List
{
private:
    enum { MAX = 10 };
    Item08 items[MAX]{};
    int top;
public:
    List();
    bool isempty() const;
    bool isfull() const;
    void add(const Item08&);
    void show() const;
    void visit(void (*pf)(Item08&));
};

#endif
