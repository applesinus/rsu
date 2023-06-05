#include "Chapter11.h"
#include <iostream>
using namespace std;


// Task 1
namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }
    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector()
    {
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode = RECT;
    }
    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }
    Vector operator*(double n, const Vector& a)
    {
        return a * n;
    }
    ostream& operator<<(ostream& os, const Vector& v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        else
            os << "Vector object mode is invalid";
        return os;
    }
}


// Task 2
namespace VECTOR02
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = n1 * cos(n2 / Rad_to_deg);
            y = n1 * sin(n2 / Rad_to_deg);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            x = n1 * cos(n2 / Rad_to_deg);
            y = n1 * sin(n2 / Rad_to_deg);
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector()
    {
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode = RECT;
    }
    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }
    Vector operator*(double n, const Vector& a)
    {
        return a * n;
    }
    ostream& operator<<(ostream& os, const Vector& v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m, a) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")";
        else
            os << "Vector object mode is invalid";
        return os;
    }
    double Vector::magval() const
    {
        return sqrt(x * x + y * y);
    }
    double Vector::angval() const
    {
        return (x == 0.0 && y == 0.0) ? 0.0 : atan2(y, x);
    }
}


// Task 3
namespace VECTOR03
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }
    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector()
    {
    }
    void Vector::polar_mode()
    {
        mode = POL;
    }
    void Vector::rect_mode()
    {
        mode = RECT;
    }
    Vector Vector::operator+(const Vector& b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector& b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }
    Vector operator*(double n, const Vector& a)
    {
        return a * n;
    }
    ostream& operator<<(ostream& os, const Vector& v)
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
            os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        else
            os << "Vector object mode is invalid";
        return os;
    }
}


// Task 4
Time::Time()
{
    hours = minutes = 0;
}
Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}
void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}
void Time::AddHr(int h)
{
    hours += h;
}
void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}
Time operator+(const Time& t1, const Time& t2)
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time operator-(const Time& t1, const Time& t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t2.minutes + 60 * t2.hours;
    tot2 = t1.minutes + 60 * t1.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}
Time operator*(const Time& t, double mult)
{
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
ostream& operator<<(ostream& os, const Time& t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}


// Task 5
Stonewt::Stonewt(double lbs)
{
    mode = STN;
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    mode = form;
    if (mode == STN || mode == ILBS || mode == FLBS)
    {
        stone = stn;
        pds_left = lbs;
        pounds = stn * Lbs_per_stn + lbs;
    }
    else
    {
        cout << "Incorrect 3rd argument to Stonewt() --- ";
        cout << "weight set to 0\n";
        stone = pds_left = pounds = 0;
        mode = STN;
    }
}
Stonewt::Stonewt()
{
    mode = STN;
    stone = pounds = pds_left = 0;
}
Stonewt Stonewt::operator+(const Stonewt& s) const
{
    return Stonewt(pounds + s.pounds);
}
Stonewt Stonewt::operator-(const Stonewt& s) const
{
    return Stonewt(pounds - s.pounds);
}
Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n);
}
Stonewt operator*(double n, Stonewt& s)
{
    return Stonewt(s.pounds * n);
}
ostream& operator<<(ostream& os, const Stonewt& s)
{
    if (s.mode == Stonewt::STN)
        os << s.stone << " stone, " << s.pds_left << " pounds\n";
    else if (s.mode == Stonewt::ILBS)
        os << (int)s.pounds << " pounds\n";
    else if (s.mode == Stonewt::FLBS)
        os << s.pounds << " pounds\n";
    return os;
}


// Task 6
Stonewt06::Stonewt06(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
Stonewt06::Stonewt06(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt06::Stonewt06()
{
    stone = pounds = pds_left = 0;
}
void Stonewt06::show_lbs() const
{
    cout << pounds << " pounds\n";
}
void Stonewt06::show_stn() const
{
    cout << stone << " stones, " << pds_left << " pounds\n";
}
bool operator>(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds > s2.pounds;
}
bool operator<(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds < s2.pounds;
}
bool operator>=(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds >= s2.pounds;
}
bool operator<=(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds <= s2.pounds;
}
bool operator==(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds == s2.pounds;
}
bool operator!=(const Stonewt06& s1, const Stonewt06& s2)
{
    return s1.pounds != s2.pounds;
}


// Task 7
Complex::Complex()
{
    cA = cB = 0;
}
Complex::Complex(double r, double i)
{
    cA = r;
    cB = i;
}
Complex Complex::operator+(const Complex& c) const
{
    return Complex(cA + c.cA, cB + c.cB);
}
Complex Complex::operator-(const Complex& c) const
{
    return Complex(cA - c.cA, cB - c.cB);
}
Complex Complex::operator*(const Complex& c) const
{
    return Complex((cA * c.cA - cB * c.cB), (cA * c.cB + cB * c.cA));
}
Complex Complex::operator~() const
{
    return Complex(cA, -cB);
}
Complex Complex::operator*(double n) const
{
    return Complex(cA * n, cB * n);
}
Complex operator*(double n, const Complex& c)
{
    return c * n;
}
ostream& operator<<(ostream& os, const Complex& c)
{
    os << "(" << c.cA << ", " << c.cB << "i)";
    return os;
}
istream& operator>>(istream& is, Complex& c)
{
    cout << "real: ";
    if (is >> c.cA)
    {
        cout << "imaginary: ";
        is >> c.cB;
    }
    return is;
}