#ifndef Chapter11
#define Chapter11

#include <string>
using namespace std;


// Task 1
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;

        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector& a);
        friend ostream& operator<<(ostream& os, const Vector& v);
    };
}


// Task 2
namespace VECTOR02
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
    private:
        double x;
        double y;
        Mode mode;
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const;
        double angval() const;
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector& a);
        friend ostream& operator<<(ostream& os, const Vector& v);
    };
}


// Task 3
namespace VECTOR03
{
    class Vector
    {
    public:
        enum Mode { RECT, POL };
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;

        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector& b) const;
        Vector operator-(const Vector& b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector& a);
        friend ostream& operator<<(ostream& os, const Vector& v);
    };
}


// Task 4
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    friend Time operator+(const Time& t1, const Time& t2);
    friend Time operator-(const Time& t1, const Time& t2);
    friend Time operator*(const Time& t, double n);
    friend Time operator*(double m, const Time& t) { return t * m; }
    friend ostream& operator<<(ostream& os, const Time& t);
};


// Task 5
class Stonewt
{
public:
    enum Mode { STN = 1, ILBS = 2, FLBS = 3 };
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
    Mode mode;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs, Mode form = STN);
    Stonewt();
    ~Stonewt() {};
    void setStnMode() { mode = STN; }
    void setIntMode() { mode = ILBS; }
    void setFloatMode() { mode = FLBS; }
    Stonewt operator+(const Stonewt& s) const;
    Stonewt operator-(const Stonewt& s) const;
    Stonewt operator*(double n) const;
    friend Stonewt operator*(double n, Stonewt& s);
    friend ostream& operator<<(ostream& os, const Stonewt& s);
};


// Task 6
class Stonewt06
{
private:
    enum { Lbs_per_stn = 14 };
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt06(double lbs);
    Stonewt06(int stn, double lbs);
    Stonewt06();
    ~Stonewt06() {};
    void show_lbs() const;
    void show_stn() const;
    friend bool operator>(const Stonewt06& s1, const Stonewt06& s2);
    friend bool operator<(const Stonewt06& s1, const Stonewt06& s2);
    friend bool operator>=(const Stonewt06& s1, const Stonewt06& s2);
    friend bool operator<=(const Stonewt06& s1, const Stonewt06& s2);
    friend bool operator==(const Stonewt06& s1, const Stonewt06& s2);
    friend bool operator!=(const Stonewt06& s1, const Stonewt06& s2);
};


// Task 7
class Complex
{
public:
    double cA;
    double cB;
    Complex();
    Complex(double a, double b);
    ~Complex() {}
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator~() const;
    Complex operator*(double n) const;
    Complex operator*(const Complex& c) const;
    friend Complex operator*(double n, const Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& s);
    friend istream& operator>>(istream& is, Complex& c);
};


#endif