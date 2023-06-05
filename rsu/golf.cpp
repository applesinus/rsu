#include "golf.h"
#include <iostream>
#include <cstring>
using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
    strcpy_s(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    cout << "Enter full name: ";
    char tmp[Len];
    cin.getline(tmp, Len);
    if (tmp[0] == '\0')
    {
        cin.clear();
        return 0;
    }
    strcpy_s(g.fullname, tmp);
    cout << "Enter handicap: ";
    (cin >> g.handicap).get();
    return 1;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    cout << "Name: " << g.fullname
        << "\nhandicap: " << g.handicap << endl;
}