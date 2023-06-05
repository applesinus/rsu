#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <cctype>
#include <fstream>
#include <new>
//Chapter 9
#include "golf.h"
#include "sales.h"
// Chapters 10-XX
#include "Chapter10.h"
#include "Chapter11.h"
#include "Chapter12.h"

using namespace std;

void mice() {
	cout << "Three blind mice\n";
}
void run() {
	cout << "See how they run\n";
}
double AUconvert(double le) {
	return le * 63240.0;
}
double temp(int cels) {
	return cels * 1.8f + 32;
}
void clock(int h, int m) {
	cout << "Time: " << h << ":" << m << ".\n";
	return;
}

// chapter 7
double harmonic(double x, double y)
{
	return (2.0 * x * y) / (x + y);
}
int fill_ar(int ar[], int limit)
{
	int i, temp;
	cout << "Enter maximum 10 golf games results (negative value to loop stop the input):\n";
	for (i = 0; i < limit; i++)
	{
		cout << "Value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Invalid input; input process stopped.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}
void average(int ar[], int n)
{
	double temp = 0.0;
	for (int i = 0; i < n; i++)
		temp += ar[i];
	if (n) cout << "Average result: " << temp / n << endl;
}
void show_ar(const int ar[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "Result #" << (i + 1) << ": " << ar[i] << endl;
}
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};
void show_box(const box t)
{
	cout << "Maker: " << t.maker << "\nHeight: " << t.height
		<< "\nWidth: " << t.width << "\nLength: " << t.length
		<< "\nVolume: " << t.volume << endl;
}
void volume_box(box * t)
{
	t->volume = t->height * t->width * t->length;
}
long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;
	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}
unsigned long int factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}
int Fill_array(double *ar, int n)
{
	int i;
	double temp;
	cout << "Enter up to " << n << " values (q to quit):\n";
	for (i = 0; i < n; i++)
	{
		cout << "Value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) break;
		ar[i] = temp;
	}
	return i;
}
void Reverse_array(double *ar, int n)
{
	double tmp;
	for (int j = 1, i = n - 2; j < i; --i, ++j)
	{
		tmp = ar[i];
		ar[i] = ar[j];
		ar[j] = tmp;
	}
}
void Show_array(const double *ar, int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << ar[i] << " ";
	cout << endl;
}
double *fill_array(double *begin, const double *end)
{
	using namespace std;
	double temp;
	double *pt;
	for (pt = begin; pt != end; pt++)
	{
		cout << "Enter value #" << (pt - begin) + 1 << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		*pt = temp;
	}
	return pt;
}
void show_array(const double *begin, const double *end)
{
	using namespace std;
	const double *pt;
	cout << endl;
	for (pt = begin; pt != end; pt++)
	{
		cout << "Property #" << (pt - begin) + 1 << ": $";
		cout << *pt << endl;
	}
}
void revalue(double r, double *begin, const double *end)
{
	double *pt;
	for (pt = begin; pt != end; pt++)
		*pt *= r;
}
const int Seasons = 4;
const char *Snames[Seasons] = { "Spring", "Summer", "Fall", "Winter" };
struct expenses { double value[Seasons]; };
void fillA(double *pa, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}
void showA(double da[], int n)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < n; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
void fillB(expenses *pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->value[i];
	}
}
void showB(expenses da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da.value[i] << endl;
		total += da.value[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};
int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Student #" << i + 1 << "\n Full name: ";
		if (!(cin.get(pa[i].fullname, SLEN))) return i;
		while (cin.get() != '\n') continue;
		cout << " Hobby: ";
		cin.getline(pa[i].hobby, SLEN);
		cout << " opplevel: ";
		cin >> pa[i].ooplevel;
		cin.get();
	}
	return i;
}
void display1(student st)
{
	cout << "\n Full name: " << st.fullname
		<< "\n Hobby: " << st.hobby
		<< "\n opplevel: " << st.ooplevel << endl;
}
void display2(const student *ps)
{
	cout << "\n Full name: " << ps->fullname
		<< "\n Hobby: " << ps->hobby
		<< "\n opplevel: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\n Full name: " << pa[i].fullname
			<< "\n Hobby: " << pa[i].hobby
			<< "\n opplevel: " << pa[i].ooplevel << endl;
	}
}
double add(double x, double y) { return x + y; }
double mult(double x, double y) { return x * y; }
double sub(double x, double y) { return x - y; }
void calculate(double x, double y, double(*pf[])(double, double), int n)
{
	for (int i = 0; i < n; i++)
		cout << pf[i](x, y) << endl;
}


// chapter 8

// task 1
void show81(const char *str, int n=0)
{
	static int cnt = 0;
	if (!n) cout << str << "\n";
	else
		for (int i = 0; i < cnt; i++)
			cout << str << "\n";
	cnt++;
}
//task 2
struct CandyBar82
{
	char name[20];
	double weight;
	int cal;

};
void fill82(CandyBar82 &candy, const char *str = "Millennium Munch", double w = 2.85, int c = 350) {
	strcpy_s(candy.name, str);
	candy.weight = w;
	candy.cal = c;
}
void display82(const CandyBar82 &candy)
{
	cout << "\nName:     " << candy.name
		<< "\nWeight:   " << candy.weight
		<< "\nCalories: " << candy.cal << endl;
}
// task 3
void strUpp(string &str)
{
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}
// task 4
struct stringy {
	char *str;
	int ct;
};
void set84(stringy &ps, const char *ch)
{
	int len = strlen(ch);
	char *str = new char[len + 1];
	// strcpy(str, ch);
	ps.str = str;
	ps.ct = len;
}
void show84(const stringy &ps, int n=1)
{
	for (int i = 0; i < n; i++)
		cout << ps.str << endl;
}
void show84(const char *pc, int n=1)
{
	for (int i = 0; i < n; i++)
		cout << pc << endl;
}
// task 5
template <typename T> T max5(T ar[])
{
	T max = ar[0];
	for (int i = 0; i < 5; i++)
		if (max < ar[i]) max = ar[i];
	return max;
}
// task 6
template <typename T> T maxn(T ar[], int n)
{
	T max = ar[0];
	for (int i = 0; i < n; i++)
		if (max < ar[i]) max = ar[i];
	return max;
}
template <> const char* maxn(const char* ar[], int n)
{
	const char* str = ar[0];
	for (int i = 0; i < n; i++)
		if (strlen(str) < strlen(ar[i])) str = ar[i];
	return str;
}
// task 7
template <typename T> T SumArray(T arr[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}
template <typename T> T SumArray(T *arr[], int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}
struct debts
{
	char name[50];
	double amount;
};


// chapter 9

//task 2
void strcount(const string str)
{
	using namespace std;
	static int total = 0;
	int count = str.length();
	cout << "\"" << str << "\" contains ";
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
	return;
}
//task 3
struct chaff
{
	char dross[20];
	int slag;
};


// chapter 10

// task 8
void sqr(double& y) { y *= y; }


// chapter 11

// task 5
void display(const Stonewt& st, int n)
{
	for (int i = 0; i < n; i++)
		cout << "Wow! " << st;
}


// chapter 12

// task 5
bool newcustomer(double x)
{
	return (rand() * x / RAND_MAX < 1);
}



int main()
{
	int input = 0, chapter = 0;

	cout << "Prata.\nTo stop the program enter -1 in chapter or task number.\n";
	while (chapter != -1) {
		cout << endl;
		cout << "\n\nEnter chapter number: ";
		input = 0;
		chapter = 0;
		cin >> chapter;

		switch (chapter)
		{
		case -1: // Exit message
		{
			cout << "Thanks for using my programm!\n";
			break;
		}

		case 2: // CHAPTER 2
		{
			cout << "\n============== CHAPTER 2 ==============\n\n";
			cout << "List of tasks:\n\t1. Personal info output test.\n\t2. Farlongs into yards converter.\n\t3. Function output test.\n\t4. Age in mounths calculator\n";
			cout << "\t5. Celsius into Fahrenheit converter.\n\t6. Light years into AU converter.\n\t7. Formatted clock output.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input)
			{
			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch2 task 1
			{
				cout << "Name: David Parker.\nAddress: New York, NY, USA.\n\a";
				break;
			}


			case 2: // ch2 task 2
			{
				int farlong = 0;
				cout << "Enter farlong amount: ";
				cin >> farlong;
				cout << farlong << " farlongs equals " << farlong * 220 << " yards.\n";
				break;
			}


			case 3: // ch2 task 3
			{
				mice();
				mice();
				run();
				run();
				break;
			}


			case 4: // ch2 task 4
			{
				int age = 0;
				cout << "Enter your age: ";
				cin >> age;
				cout << "Your age in months is " << age * 12 << endl;
				break;
			}


			case 5: // ch2 task 5
			{
				int celsius = 0;
				cout << "Please enter a Celsius value: ";
				cin >> celsius;
				cout << celsius << " degrees Celsius is " << temp(celsius) << " degrees Fahrenheit.\n";
				break;
			}


			case 6: // ch2 task 6
			{
				cout << "Enter the number of light years: ";
				double le = 0;
				cin >> le;
				cout << le << " light years = " << AUconvert(le) << " astronomical units.\n";
				break;
			}


			case 7: // ch2 task 7
			{
				int h = 0, m = 0;
				cout << "Enter the number of hours: ";
				cin >> h;
				cout << "Enter the number of minutes: ";
				cin >> m;
				clock(h, m);
				break;
			}


			default:
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			break;
		}

		case 3: // CHAPTER 3
		{
			cout << "\n============== CHAPTER 3 ==============\n\n";
			cout << "List of tasks:\n\t1. Inches into feet and inches converter.\n\t2. BMI calculator.\n\t3. Angle in decimal degrees.\n\t4. Seconds unparser.\n";
			cout << "\t5. World population percent.\n\t6. MPG calculator.\n\t7. LPK into MPG converter.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;


			switch (input)
			{
			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch3 task 1
			{
				cout << "Enter the number of inches:_";
				int inch=0;
				cin >> inch;
				const int coef = 12;
				cout << inch << " inches is " << inch/coef << " feet and " << inch%coef << " inches.\n";
				break;
			}


			case 2: // ch3 task 2
			{
				cout << "Enter the height in feet and inches and mass in pounds.\nNumber of feet: ";
				double inch = 0, feet = 0, pounds = 0;
				cin >> feet;
				cout << "Number of inches: ";
				cin >> inch;
				cout << "Number of pounds: ";
				cin >> pounds;

				const double feet_to_inches = 12, inches_to_meters = 0.0254, pounds_to_kg = 2.2;
				cout << "Your BMI is " << (pounds / pounds_to_kg) / ((inch + feet * feet_to_inches) * inches_to_meters * (inch + feet * feet_to_inches) * inches_to_meters) << ".\n";
				
				break;
			}


			case 3: // ch3 task 3
			{
				int deg, min, sec;
				const double minutes_in_degrees = 60.0, seconds_in_minute = 60.0;
				cout << "Enter a latitude in degrees, minutes and seconds:\nFirt, enter the degrees: ";
				cin >> deg;
				cout << "Next, enter the minutes of arc: ";
				cin >> min;
				cout << "Finally, enter the seconds of arc: ";
				cin >> sec;

				cout << deg << " degrees, " << min << " minutes, " << sec << "secundes = " << deg + (min/minutes_in_degrees) + (sec/seconds_in_minute/minutes_in_degrees) << " degrees.\n";
				break;
			}


			case 4: // ch3 task 4
			{
				long long inputSeconds = 0;
				int sec = 0, min = 0, hours = 0, days = 0;
				const int sec_in_min = 60, min_in_hour = 60, hours_in_days = 24;

				cout << "Enter the number of seconds: ";
				cin >> inputSeconds;

				sec = inputSeconds % sec_in_min;
				min = inputSeconds / sec_in_min % min_in_hour;
				hours = inputSeconds / sec_in_min / min_in_hour % hours_in_days;
				days = inputSeconds / sec_in_min / min_in_hour / hours_in_days;

				cout << inputSeconds << " seconds = " << days << " days, " << hours << " hours, " << min << " minutes " << sec << " seconds.\n";

				break;
			}


			case 5: // ch3 task 5
			{
				long long worldPopulation = 0, theUSPopulation = 0;
				cout << "Enter the worlds'd population: ";
				cin >> worldPopulation;
				cout << "Enter the population of the US: ";
				cin >> theUSPopulation;

				cout << "The population if the US is " << theUSPopulation * 100.0 / worldPopulation << "% of the world population.\n";
				break;
			}


			case 6: // ch3 task 6
			{
				int miles = 0, gallons = 0;
				cout << "Amount of miles you have driven: ";
				cin >> miles;
				cout << "Amount of gallons of gas you spent: ";
				cin >> gallons;

				cout << "Your MPG is " << miles / (gallons*1.0) << ".\n";

				break;
			}


			case 7: // ch3 task 7
			{
				double lpk = 0;
				cout << "Enter your LPK: ";
				cin >> lpk;
				cout << "Your MPG is " << 100.0 * 3.875 / lpk / 1.609 << ".\n";

				break;
			}


			default:
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			break;
		}

		case 4: // CHAPTER 4
			// не работает на моём компиляторе, хотя по идее всё правильно, ругается на strcpy
		{
			cout << "\n============== CHAPTER 4 ==============\n\n";
			cout << "List of tasks:\n\t1. Student info.\n\t2. Listing 4.4.\n\t3. Name formatter (using char array).\n\t4. Name formatter (using string).\n";
			cout << "\t5. Snack of CandyBar structure.\n\t6. Array of CandyBar.\n\t7. Pizza database.\n\t8. Pizza info using new.\n\t9. CanbyBars using new.\n";
			cout << "\t10. Runners info using array type.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;
			
			switch (input)
			{
			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch4 task 1
			{
				char firstName[20]="", lastName[20]="", grade;
				cin.clear();
				cin.ignore(10000, '\n');
				int age;

				cout << "Enter your name: ";
				cin.getline(firstName, 20);

				cout << "Enter your last name: ";
				cin.getline(lastName, 20);

				cout << "Enter the mark do you think you deserve: ";
				cin >> grade;
				grade++;

				cout << "Enter your age: ";
				cin >> age;

				cout << "Name: " << lastName << ", " << firstName << endl << "Grade: " << grade << endl << "Age: " << age;

				break;
			}

			case 2: // ch4 task 2
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string name, dessert;

				cout << "Enter your name:\n";
				getline(cin, name);

				cout << "Enter your favorite dessert:\n";
				getline(cin, dessert);

				cout << "I have some delicious " << dessert << " for you, " << name << endl;

				break;
			}

			case 3: // ch4 task 3
			{
				cin.clear();
				cin.ignore(10000, '\n');
				char firstName[20], lastName[20], name[40];
				//cin.getline(firstName, 20);


				cout << "Enter your first name: ";
				cin.getline(firstName, 20);

				cout << "Enter your last name: ";
				cin.getline(lastName, 20);

				strcpy_s(name, lastName);
				strcat_s(name, ", ");
				strcat_s(name, firstName);
				cout << "Here's the information in a single string: " << name;

				break;
			}
				
			case 4: // ch4 task 4
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string firstName, lastName, name;
				//getline(cin, firstName);

				cout << "Enter your first name: ";
				getline(cin, firstName);

				cout << "Enter your last name: ";
				getline(cin, lastName);

				name = lastName + ", " + firstName;
				cout << "Here's the information in a single string: " << name;
				break;
			}

			case 5: // ch4 task 5
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct CandyBar
				{
					char name[20];
					double weight;

					int calories;
				};

				CandyBar snack{ "Mocha Munch", 2.3, 250 };

				cout << "Name: " << snack.name << endl << "Weight: " << snack.weight << endl << "Calories: " << snack.calories << endl;

				break;
			}
			
			case 6: // ch4 task 6
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct CandyBar
				{
					char name[20];
					double weight;
					int calories;
				};
				CandyBar snacks[3]
				{
					{"Twix", 50, 500},
					{"Trix", 75, 750},
					{"Quadrix", 99, 990}
				};

				cout << "Snack 1 data\n" << "Name: " << snacks[0].name << "\tWeight: " << snacks[0].weight << "\tCalories: " << snacks[0].calories << "\n\n";

				cout << "Snack 2 data\n" << "Name: " << snacks[1].name << "\tWeight: " << snacks[1].weight << "\tCalories: " << snacks[1].calories << "\n\n";

				cout << "Snack 3 data\n" << "Name: " << snacks[2].name << "\tWeight: " << snacks[2].weight << "\tCalories: " << snacks[2].calories << "\n\n";
				
				break;
			}
			
			case 7: // ch4 task 7
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct Pizza
				{
					char company[20];
					int diameter;
					double weight;
				};

				Pizza pizza1;
				cout << "Enter the company's name: ";
				//cin.getline(pizza1.company, 20);
				cin.getline(pizza1.company, 20);

				cout << "Enter pizza diameter: ";
				cin >> pizza1.diameter;

				cout << "Enter pizza weight: ";
				cin >> pizza1.weight;
				cout << endl;

				cout << "Data:" << endl	<< "Company's Name: " << pizza1.company << endl << "Pizza diameter: " << pizza1.diameter
					<< endl << "Pizza weight: " << pizza1.weight << endl;

				break;
			}

			case 8: // ch4 task 8
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct Pizza
				{
					int diameter;
					char company[20];
					double weight;
				};

				Pizza* pizza = new Pizza;

				cout << "Enter pizza diameter: ";
				(cin >> pizza->diameter).get();

				cout << "Enter company's name: ";
				cin.getline(pizza->company, 20);

				cout << "Enter pizza weight: ";
				cin >> pizza->weight;

				cout << endl;
				cout << "Pizza diameter: " << (*pizza).diameter << endl	<< "Company's name: " << (*pizza).company << endl << "Pizza weight: " << (*pizza).weight << endl;

				break;
			}

			case 9: // ch4 task 9
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct CandyBar
				{
					string name;
					double weight;
					int calories;
				};

				CandyBar* candy = new CandyBar[3];

				candy[0].name = "Twix";
				candy[0].weight = 50;
				candy[0].calories = 500;

				candy[1].name = "Trix";
				candy[1].weight = 75;
				candy[1].calories = 750;

				candy[2].name = "Quadrix";
				candy[2].weight = 99;
				candy[2].calories = 990;

				cout << "Candy 1" << endl
					<< "Name: " << candy[0].name << "\tWeight: " << candy[0].weight << "\tCalories: " << candy[0].calories << endl << endl;

				cout << "Candy 2" << endl
					<< "Name: " << candy[1].name << "\tWeight: " << candy[1].weight << "\tCalories: " << candy[1].calories << endl << endl;

				cout << "Candy 3" << endl
					<< "Name: " << candy[2].name << "\tWeight: " << candy[2].weight << "\tCalories: " << candy[2].calories << endl;


				break;
			}
			
			case 10: // ch4 task 10
			{
				cin.clear();
				cin.ignore(10000, '\n');
				array<double, 3> results;
				double average;

				cout << "You ran 40 meters 3 times\n"
					<< "Enter the first result: ";
				cin >> results[0];

				cout << "Enter the second result: ";
				cin >> results[1];

				cout << "Enter the third result: ";
				cin >> results[2];

				average = (results[0] + results[1] + results[2]) / 3;

				cout << "\nThere are your results: " << results[0] << " sec, " << results[1] << " sec, " << results[2] << " sec\n"
					<< "Average of 3: " << average << " sec.\n";

				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}
			}

			break;

		}

		case 5: // CHAPTER 5
		{
			cout << "\n============== CHAPTER 5 ==============\n\n";
			cout << "List of tasks:\n\t1. Inbetween summ.\n\t2. 5.4 using array.\n\t3. Progressing summ.\n\t4. Dafna & Cleo.\n\t5. Selling Prata.\n";
			cout << "\t6. Selling Prata for 3 years.\n\t7. Cars database.\n\t8. Untill done.\n\t9. Untill done using strings.\n\t10. Progressing stars.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;
			
			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch5 task 1
			{
				cin.clear();
				cin.ignore(10000, '\n');
				int first, second, firstCopy, sum;

				cout << "Enter the first number: ";
				cin >> first;
				firstCopy = first;
				sum = 0;

				cout << "Enter the second number: ";
				cin >> second;

				for (firstCopy; firstCopy <= second; firstCopy++) { sum += firstCopy; }

				cout << "Sum of numbers from " << first << " to " << second << " is " << sum;

				break;
			}

			case 2: // ch5 task 2
			{
				cin.clear();
				cin.ignore(10000, '\n');
				const int ArSize = 101;

				array<long double, ArSize> factorials;
				factorials[1] = factorials[0] = (long double)1;

				for (int i = 2; i < ArSize; i++)
					factorials[i] = i * factorials[i - 1];

				for (int i = 0; i < ArSize; i++)
					cout << i << "! = " << factorials[i] << endl;

				break;
			}

			case 3: // ch5 task 3
			{
				cin.clear();
				cin.ignore(10000, '\n');
				double number, sum;
				number = 1;
				sum = 0;

				while (number != 0)
				{
					cout << "Enter a number: ";
					cin >> number;

					sum += number;
					cout << "Sum of your numbers = " << sum << endl << endl;
				}

				break;
			}

			case 4: // ch5 task 4
			{
				cin.clear();
				cin.ignore(10000, '\n');
				double Dafna, Cleo;
				int i = 1;
				Dafna = Cleo = 100;

				for (i; Cleo <= Dafna; i++)
				{
					Dafna += 10;
					Cleo *= 1.05;
					cout << "Year " << i << ": Dafna's balance = " << Dafna << "\tCleo's balance = " << Cleo << endl;
				}

				cout << "It took " << i-1 << " years for Cleo's balance became more than Dafna's.\n";

				break;
			}

			case 5: // ch5 task 5
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string Months[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
				int sales[12];
				int sum = 0;

				for (int i = 0; i < 12; i++)
				{
					cout << "Enter the number of sales in " << Months[i] << ": ";
					cin >> sales[i];
					sum += sales[i];
				}

				cout << "Books sold in the year: " << sum;

				break;
			}

			case 6: // ch5 task 6
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string Months[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

				int sales[3][12];
				int oneYearSum, sum;
				sum = 0;

				for (int i = 0; i < 3; i++)
				{
					oneYearSum = 0;
					cout << "Year " << i + 1 << ":" << endl;
					for (int j = 0; j < 12; j++)
					{
						cout << "Enter number of sales in " << Months[j] << ": ";
						cin >> sales[i][j];
						oneYearSum += sales[i][j];
					}
					sum += oneYearSum;
					cout << "Books sold in year " << i + 1 << ": " << oneYearSum << endl << endl;
				}
				cout << "Books sold in three years: " << sum;


				break;
			}

			case 7: // ch5 task 7
			{
				cin.clear();
				cin.ignore(10000, '\n');
				struct Car
				{
					char Company[30];
					int ReleaseYear;
				};
				cout << "Enter amount of cars in the catalogue: ";
				int count;
				cin >> count;

				Car *Cars = new Car[count];
				int i = 0;
				while (i < count)
				{
					cout << "\nCar #" << i + 1 << endl;

					cout << "Enter the manufacturer: ";
					cin.getline(Cars[i].Company, 30);
					cin.getline(Cars[i].Company, 30);


					cout << "Enter the year of manufacturing: ";
					cin >> Cars[i].ReleaseYear;

					i++;
				}
				cout << "\nHere's your collection:" << endl;
				for (i = 0; i < count; i++)
				{
					cout << Cars[i].ReleaseYear << ' ' << Cars[i].Company << endl;
				}

				break;
			}

			case 8: // ch5 task 8
			{
				cin.clear();
				cin.ignore(10000, '\n');
				char word[30];
				int count = 0;

				cout << "Enter the text (to stop entering, type the word \"done\")\n";
				cin >> word;

				while (strcmp(word, "done"))
				{
					cin >> word;
					++count;
				}

				cout << "You entered " << count << " words.";
				cin.clear();
				cin.ignore(10000, '\n');

				break;
			}

			case 9: // ch5 task 9
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string word;
				int count = 0;
				cout << "Enter the text (to stop entering, type the word \"done\")\n";

				cin >> word;
				while (word != "done")
				{
					cin >> word;
					count++;
				}
				cout << "You entered " << count << " words";

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 10: // ch5 task 10
			{
				cin.clear();
				cin.ignore(10000, '\n');
				int strings;
				cout << "Enter the number of lines: ";
				cin >> strings;

				for (int i = 1; i <= strings; i++)
				{

					for (int j = strings; j > i; j--)
					{
						cout << '.';
					}
					for (int k = 0; k < i; k++)
					{
						cout << '*';
					}
					cout << endl;
				}

				break;
			}



			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}
			}
			
			break;
		}

		case 6: // CHAPTER 6
		{
			cout << "\n============== CHAPTER 6 ==============\n\n";
			cout << "List of tasks:\n\t1. Formatted copypaste.\n\t2. Average charity.\n\t3. Menu.\n\t4. BOP members lists.\n\t5. Neutronian taxes.\n";
			cout << "\t6. Charity database.\n\t7. Vowels vs consonants.\n\t8. Open file.\n\t9. Charity database but it's file.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch6 task 1
			{
				cin.clear();
				cin.ignore(10000, '\n');
				string textLine;
				cout << "Enter text, type '@' to stop.\n";
				getline(cin, textLine);
				for (int i = 0; i < textLine.size(); ++i)
				{
					if (!isalnum(textLine[i])) { continue; }
					else if (isalpha(textLine[i]))
					{
						if (isupper(textLine[i])) { textLine[i] += 32; } else { textLine[i] -= 32; }
					}
					else if (isdigit(textLine[i]))
					{
						for (int j = i; j < textLine.size(); ++j) { textLine[j] = textLine[j + 1]; }
						--i;
					}
				}

				cout << textLine;

				break;
			}

			case 2: // ch6 task 2 - К сожалению, я так и не понял, как адекватно сделать проверку, является ли введённая строка даблом
				// Чисто в теории можно вводить массив чаров и проверять, состоит ли он только из цифр и максимум одной запятой
			{
				cin.clear();
				cin.ignore(10000, '\n');
				const int SIZE = 10;

				double arr[SIZE];
				double donat, sum = 0.0;
				int cnt = 0, i = 0;

				cout << "Enter donation values: ";
				for (; i < SIZE && cin >> donat; i++)
				{
					arr[i] = donat;
					sum += donat;
					if (i+1 < SIZE) cout << "Enter donation values: ";
				}
				if (i != 0)
				{
					double avr = sum / i;
					for (int j = 0; j < i; j++)
					{
						if (arr[j] > avr)
							cnt++;
					}
					cout << "Average = " << avr << "; Numbers larger than average = "
						<< cnt << endl;
				}
				else
					cout << "No donations." << endl;

				break;
			}
			
			case 3: // ch6 task 3
			{
				cin.clear();
				cin.ignore(10000, '\n');
				char ch;

				cout << "Please, enter one of the following choices:\n"
					<< "c) carnivore\t"
					<< "p) pianist\n"
					<< "t) tree\t\t"
					<< "g) game\n";

				cin >> ch;

				while (ch != 'c' and ch != 'p' and ch != 't' and ch != 'g')
				{
					cout << "Please enter a c, p, t, or g: ";
					cin >> ch;

				}

				switch (ch)
				{
				case 'c':
					cout << "A wolf is a carnivore\n";
					break;

				case 'p':
					cout << "Ludwig Van Beethoven is a pianist\n";
					break;

				case 't':
					cout << "A maple is a tree\n";
					break;

				case 'g':
					cout << "Football is a game\n";
					break;
				}

				break;
			}

			case 4: // ch6 task 4
			{
				cin.clear();
				cin.ignore(10000, '\n');
				const int strsize = 30;
				struct bop
				{
					char fullname[strsize];
					char title[strsize];
					char bopname[strsize];
					int preference;
				};

				char choice;
				bop list[6] =
				{
					{"Maxim Kryukov", "Psychologist", "Kryuksim", 2},
					{"Alexey Istomin", "Butcher", "Istoxey", 2},
					{"Klim Bundin", "Inspirer", "Bunim", 0},
					{"Kirill Palatkin", "Philosopher", "Parill", 2},
					{"Vladislav Cockut", "Owner", "Cockuslav", 1},
					{"Little Blim", "Clown", "Blittle", 0}
				};

				cout << "BOP\n"
					<< "a. Show name\t\tb. Show job\n"
					<< "c. Show nickname\td. Show preference\n"
					<< "q. Quit\n"
					<< "Enter an option: ";

				cin >> choice;

				while (choice != 'q')
				{
					if (choice == 'a')
						for (int i = 0; i < 6; ++i)
							cout << list[i].fullname << endl;
					else if (choice == 'b')
						for (int i = 0; i < 6; ++i)
							cout << list[i].title << endl;
					else if (choice == 'c')
						for (int i = 0; i < 6; ++i)
							cout << list[i].bopname << endl;
					else if (choice == 'd')
						for (int i = 0; i < 6; ++i)
						{
							if (list[i].preference == 0)
								cout << list[i].fullname << endl;
							else if (list[i].preference == 1)
								cout << list[i].title << endl;
							else if (list[i].preference == 2)
								cout << list[i].bopname << endl;
						}
					cout << "Next option: ";
					cin >> choice;
				}
				cout << "Пока!\n";

				break;
			}

			case 5: // ch6 task 5
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Enter tvarps (negative number or non-numeric for quit): ";
				int tvp;
				cin >> tvp;
				while (cin && tvp >= 0)
				{
					if (tvp <= 5000)
						cout << "tax = " << 0 << endl;
					else if (5000 < tvp && tvp <= 15000)
						cout << "tax = " << (tvp - 5000)*0.1 << endl;
					else if (15000 < tvp && tvp <= 35000)
						cout << "tax = " << 10000 * 0.1 + (tvp - 15000)*0.15 << endl;
					else if (tvp > 35000)
						cout << "tax = " << 10000 * 0.1 + 20000 * 0.15 + (tvp - 35000)*0.2 << endl;
					cout << "Next: ";
					cin >> tvp;
				}

				break;
			}
			
			case 6: // ch6 task 6
			{
				cin.clear();
				cin.ignore(10000, '\n');

				struct donors {
					string name;
					double donation;
				};


				cout << "Enter number of patrons: ";
				int mem, cnt = 0;
				(cin >> mem).get();
				donors *patron = new donors[mem];
				for (int i = 0; i < mem; i++)
				{
					cout << i + 1 << ". Name: ";
					getline(cin, patron[i].name);
					cout << "Contribution: ";
					(cin >> patron[i].donation).get();
				}
				cout << "\nGrand Patron:\n";
				for (int i = 0; i < mem; i++)
				{
					if (patron[i].donation >= 10000)
					{
						cout << patron[i].name << "\t" << patron[i].donation << endl;
						cnt++;
					}
				}
				if (cnt == 0)
					cout << " none\n";
				cout << "Patron:\n";
				if (cnt == mem)
					cout << " none\n";
				else {
					for (int i = 0; i < mem; i++)
					{
						if (patron[i].donation < 10000)
							cout << patron[i].name << "\t" << patron[i].donation << endl;
					}
				}
				delete[] patron;


				break;
			}

			case 7: // ch6 task 7
			{
				cin.clear();
				cin.ignore(10000, '\n');

				int vowels = 0, consonants = 0, others = 0;
				cout << "Enter words (q to quit):\n";
				string word;
				while (cin >> word && word != "q")
				{
					if (isalpha(word[0]))
					{
						switch (word[0])
						{
						case 'A': case 'a':	case 'E': case 'e':
						case 'I': case 'i':	case 'U': case 'u':
						case 'Y': case 'y':	case 'O': case 'o':
							vowels++; break;
						default:
							consonants++;
							break;
						}
					}
					else
						others++;
				}
				cout << vowels << " words beginning with vowels.\n"
					<< consonants << " words beginning with consonants.\n"
					<< others << " others.\n";

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 8: // ch6 task 8
			{
				cin.clear();
				cin.ignore(10000, '\n');

				const int SIZE = 60;

				ifstream inFile;
				char filename[SIZE];
				cout << "Enter the title of data file: ";
				cin.getline(filename, SIZE);
				inFile.open(filename);

				char ch;
				inFile >> ch;
				int count = 0;
				while (inFile.good())
				{
					++count;
					inFile >> ch;
				}
				cout << "Amount of characters in the file: " << count << endl;
				inFile.close();

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 9: // ch6 task 9
			{
				cin.clear();
				cin.ignore(10000, '\n');

				struct donors {
					string name;
					double donation;
				};

				const int SIZE = 60;

				ifstream inFile;
				char filename[SIZE];
				cout << "Enter the title of data file: ";
				cin.getline(filename, SIZE);
				inFile.open(filename);
		
				int mem, cnt = 0;
				(inFile >> mem).get();
				donors *patron = new donors[mem];
				for (int i = 0; i < mem; i++)
				{
					getline(inFile, patron[i].name);
					(inFile >> patron[i].donation).get();
				}
				cout << "\nGrand Patron:\n";
				for (int i = 0; i < mem; i++)
				{
					if (patron[i].donation >= 10000)
					{
						cout << patron[i].name << "\t" << patron[i].donation << endl;
						cnt++;
					}
				}
				if (cnt == 0)
					cout << " none\n";
				cout << "Patron:\n";
				if (cnt == mem)
					cout << " none\n";
				else {
					for (int i = 0; i < mem; i++)
					{
						if (patron[i].donation < 10000)
							cout << patron[i].name << "\t" << patron[i].donation << endl;
					}
				}
				delete[] patron;

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}
			}

			break;
		}

		case 7: // CHAPTER 7
		{
			cout << "\n============== CHAPTER 7 ==============\n\n";
			cout << "List of tasks:\n\t1. Harmonic pairs.\n\t2. Golf results.\n\t3. Box structure.\n\t4. Lottery odds.\n\t5. Factorial again.\n";
			cout << "\t6. Custom array.\n\t7. 7.7 with pointer.\n\t8. 7.15 without array.\n\t9. Functions for already made programm.\n\t10. Calculate().\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch7 task 1
			{
				cin.clear();
				cin.ignore(10000, '\n');

				double x, y;
				cout << "\nTo stop the task, enter zero in a pair.\nEnter pair of numbers:\n";
				while (cin >> x && x != 0 && cin >> y && y != 0) {
					cout << "Harmonic (" << x << ", " << y << ") = " << harmonic(x, y)
						<< "\n\nEnter new pair of numbers:\n";
				}

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 2: // ch7 task 2
			{
				cin.clear();
				cin.ignore(10000, '\n');

				int result[10];
				int size = fill_ar(result, 10);
				show_ar(result, size);
				average(result, size);

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 3: // ch7 task 3
			{
				cin.clear();
				cin.ignore(10000, '\n');

				box gift = { "Mosigra", 20, 20, 15, 0 };
				volume_box(&gift);
				show_box(gift);

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 4: // ch7 task 4
			{
				cin.clear();
				cin.ignore(10000, '\n');

				double total, choices, meganum, limit;
				cout << "Enter amount of choices on the game card and\n"
					<< "the number of picks allowed:\n";
				while ((cin >> total >> choices) && choices <= total)
				{
					cout << "Enter the total number of choices on the game card and\n"
						<< "the number of picks allowed for the Mega Number:\n";
					if ((cin >> limit >> meganum) && meganum <= limit);
					{
						cout << "You have one chance in " << probability(total, choices) * probability(limit, meganum) << " of winning. \n";
					}
					cout << "Next two numbers(enter \"q\" to quit): ";
				}

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 5: // ch7 task 5
			{
				cin.clear();
				cin.ignore(10000, '\n');

				cout << "Enter positive value (enter \"q\" to quit): ";
				int val;
				while (cin >> val && val >= 0)
					cout << val << "! = " << factorial(val) << "\nNext value: ";

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 6: // ch7 task 6
			{
				cin.clear();
				cin.ignore(10000, '\n');

				double arr[10];
				int size = Fill_array(arr, 10);
				Show_array(arr, size);
				Reverse_array(arr, size);
				Show_array(arr, size);

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 7: // ch7 task 7
			{
				cin.clear();
				cin.ignore(10000, '\n');

				double properties[5];
				double *pt_end = fill_array(properties, properties + 5);
				show_array(properties, pt_end);
				if ((pt_end - properties) > 0)
				{
					cout << "\nEnter revaluation factor: ";
					double factor;
					while (!(cin >> factor))
					{
						cin.clear();
						while (cin.get() != '\n')
							continue;
						cout << "Invalid input; Please enter a number: ";
					}
					revalue(factor, properties, pt_end);
					show_array(properties, pt_end);
				}
				cout << "Done.\n";

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 8: // ch7 task 8
			{
				cin.clear();
				cin.ignore(10000, '\n');

				char choice;
				cout << "This task has two different solutions, please select \"a\" or \"b\": ";
				cin >> choice;

				switch (choice)
				{
				case 'a':
				{
					cin.clear();
					cin.ignore(10000, '\n');

					double expenses[Seasons];
					fillA(expenses, Seasons);
					showA(expenses, Seasons);

					cin.clear();
					cin.ignore(10000, '\n');
					break;
				}


				case 'b':
				{
					cin.clear();
					cin.ignore(10000, '\n');

					expenses exp;
					fillB(&exp);
					showB(exp);

					cin.clear();
					cin.ignore(10000, '\n');
					break;
				}


				default:
					cout << "Invalid input.\n";
					break;
				}

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 9: // ch7 task 9
			{
				cin.clear();
				cin.ignore(10000, '\n');

				cout << "Enter class size: ";
				int class_size;
				cin >> class_size;
				while (cin.get() != '\n')
					continue;
				student * ptr_stu = new student[class_size];
				int entered = getinfo(ptr_stu, class_size);
				for (int i = 0; i < entered; i++)
				{
					display1(ptr_stu[i]);
					display2(&ptr_stu[i]);
				}
				display3(ptr_stu, entered);
				delete[] ptr_stu;

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 10: //ch7 task 10
			{
				cin.clear();
				cin.ignore(10000, '\n');

				double(*pf[3])(double, double) = { add, sub, mult };
				double x, y;
				cout << "Enter two values (q to quit): \n";
				while (cin >> x >> y)
				{
					cout << "Result (add, sub, mult): \n";
					calculate(x, y, pf, 3);
					cout << "Next values: \n";
				}

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}
			}

			break;
		}

		case 8: // CHAPTER 8
		{
			cout << "\n============== CHAPTER 8 ==============\n\n";
			cout << "List of tasks:\n\t1. Useless output.\n\t2. Candy Bars database again.\n\t3. Touper().\n\t4. Done the programm.\n";
			cout << "\t5. Max5().\n\t6. MaxN().\n\t7. 8.14 but with return.\n\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}
			
			case 1: // ch8 task 1
			{
				cin.clear();
				cin.ignore(10000, '\n');

				char str[20] = "Hello, World!";
				show81(str);
				show81(str);
				show81(str, 1);

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			
			case 2: // ch8 task 2
			{
				cin.clear();
				cin.ignore(10000, '\n');

				CandyBar82 newcandy;
				fill82(newcandy);
				display82(newcandy);
				fill82(newcandy, "Twix", 50, 100);
				display82(newcandy);

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			
			case 3: // ch8 task 3
			{
				cin.clear();
				cin.ignore(10000, '\n');

				string str;
				cout << "Enter a string (type \"q\" to quit): ";
				getline(cin, str);
				while (str != "q")
				{
					strUpp(str);
					cout << str << endl;
					cout << "Next string (type \"q\" to quit): ";
					getline(cin, str);
				}

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			
			case 4: // ch8 task 4
			{
				cin.clear();
				cin.ignore(10000, '\n');

				stringy beany;
				char testing[] = "Reality isn't what it used to be.";
				set84(beany, testing);
				show84(beany);
				show84(beany, 2);
				testing[0] = 'D';
				testing[1] = 'u';
				show84(testing);
				show84(testing, 3);
				show84("Done!");
				delete[]beany.str;

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			
			case 5: // ch8 task 5
			{
				cin.clear();
				cin.ignore(10000, '\n');

				int ar1[]{ 1, 7, 5, 11, 9 };
				double ar2[]{ 1.3, 7.5, 9.5, 5.1, 9.3 };
				cout << "ar1: " << max5(ar1) << "\nar2: " << max5(ar2) << endl;

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 6: // ch8 task 6
			{
				cin.clear();
				cin.ignore(10000, '\n');

				int ar1[6] = { 1, 7, 5, 11, 9, 3 };
				double ar2[4] = { 1.3, 7.5, 9.5, 5.1 };
				const char* ar3[5] = { "Fiat", "Honda", "Ferrari", "Volvo", "Bugatti" };
				cout << "ar1: " << maxn(ar1, 6)
					<< "\nar2: " << maxn(ar2, 4)
					<< "\nar3: " << maxn(ar3, 5) << endl;

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}

			case 7: // ch8 task 7
			{
				cin.clear();
				cin.ignore(10000, '\n');

				int things[6] = { 13, 31, 103, 301, 310, 130 };
				struct debts mr_E[3] =
				{
					{"Ima Wolfe", 2400.0},
					{"Ura Foxe", 1300.0},
					{"Iby Stout", 1800.0}
				};
				double *pd[3];
				for (int i = 0; i < 3; i++)
					pd[i] = &mr_E[i].amount;
				cout << "Total number of things:\n" << SumArray(things, 6) << "\n";
				cout << "Total sum of all debts:\n" << SumArray(pd, 3) << "\n";

				cin.clear();
				cin.ignore(10000, '\n');
				break;
			}
			
			
			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}
			}

			break;
		}

		case 9: // CHAPTER 9
		{
			cout << "\n============== CHAPTER 9 ==============\n\n";
			cout << "List of tasks:\n\t1. Golf again.\n\t2. Listing 9.9 with string.\n\t3. Struct chaff.\n\t4. Namespace SALES.\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}

			case 1: // ch9 task 1
			{
				golf ann;
				setgolf(ann, "Ann Smith", 18);
				showgolf(ann);
				handicap(ann, 20);
				showgolf(ann);
				golf arr[5];
				int playerCounter = 0;
				char none[1];
				cin.getline(none, 1);
				while (playerCounter < 5 && setgolf(arr[playerCounter]))
				{
					playerCounter++;
				}
				for (int i = 0; i < playerCounter; i++)
				{
					showgolf(arr[i]);
				}

				break;
			}

			case 2: // ch9 task 2
			{
				cin.ignore();

				string input;
				cout << "Enter a line: \n";
				while (getline(cin, input) && input != "")
				{
					strcount(input);
					cout << "Enter next line (empty line to quit):\n";
				}
				cout << "Bye\n";

				break;
			}

			case 3: // ch9 task 3
			{
				cin.ignore();

				cout << "Choose an option (1 or 2, -1 to break): ";
				int option = -1;
				cin >> option;

				while (option != -1) {
					switch (option)
					{
					case 1:
					{
						char buffer[2 * sizeof(chaff)];
						chaff* chaff1 = new (buffer) chaff[2];
						strcpy_s(chaff1[0].dross, "part1_1");
						chaff1[0].slag = 1;
						strcpy_s(chaff1[1].dross, "part1_2");
						chaff1[1].slag = 2;

						for (int i = 0; i < 2; i++) {
							cout << "Chaff.\nDross: " << chaff1[i].dross << ", Slag: " << chaff1[i].slag << endl;
						}

						break;
					}

					case 2:
					{
						chaff* chaff2 = new chaff[2];
						strcpy_s(chaff2[0].dross, "part2_1");
						chaff2[0].slag = 100;
						strcpy_s(chaff2[1].dross, "part2_2");
						chaff2[1].slag = 200;

						for (int i = 0; i < 2; i++) {
							cout << "Chaff:\nDross: " << chaff2[i].dross << ", Slag: " << chaff2[i].slag << endl;
						}
						delete[]chaff2;

						break;
					}

					default:
						break;
					}

					cout << "\nChoose an option (1 or 2. -1 to break): ";
					cin >> option;
				}

				break;
			}

			case 4: // ch9 task 4
			{
				using namespace SALES;
				cin.ignore();

				Sales sail1;
				setSales(sail1);
				showSales(sail1);
				double ar[3] = { 120.2, 302.5, 177.3 };
				Sales sail2;
				setSales(sail2, ar, 3);
				showSales(sail2);

				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			}
			break;
		}


		case 10: // CHAPTER 10
		{
			cout << "\n============== CHAPTER 10 ==============\n\n";
			cout << "List of tasks:\n\t1. Bank account.\n\t2. Class Person.\n\t3. Golf again. Again.\n\t4. Namespace SALES. Again.\n";
			cout << "\t5. Struct customer.\n\t6. Class Move.\n\t7. Plorg.\n\t8. Class List.\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}


			case 1: // ch10 task 1
			{
				cin.ignore();

				BankAccount test{ "Client", "Wallet" };
				test.show();
				test.deposit(500);
				test.show();
				test.withdraw(100);
				test.show();

				break;
			}

			case 2: // ch10 task 2
			{
				cin.ignore();

				Person one;
				Person two("Dmitry");
				Person three("Rosin", "Dmitry");
				one.Show();
				one.FormalShow();
				cout << endl;
				two.Show();
				two.FormalShow();
				cout << endl;
				three.Show();
				three.FormalShow();

				break;
			}

			case 3: // ch10 task 3
			{
				cin.ignore();

				Golf ann{ "Ann Birdfree", 24 };
				ann.showgolf();
				ann.sethandicap(30);
				ann.showgolf();
				Golf arr[3];
				int player = 0;
				while (player < 3 && arr[player].setgolf())
					player++;
				for (int i = 0; i < player; i++)
					arr[i].showgolf();

				break;
			}

			case 4: // ch10 task 4
			{
				cin.ignore();

				using namespace SALES10;

				Sales sal1;
				sal1.setSales();
				sal1.showSales();
				double ar[3] = { 120.2, 302.5, 177.3 };
				Sales sal2(ar, 3);
				sal2.showSales();

				break;
			}

			case 5: // ch10 task 5
			{
				cin.ignore();

				Stack st;
				char ch;
				double total = 0;
				customer po;
				cout << "Please enter A to add customer, P to pop last customer, or Q to quit: ";
				while (cin >> ch && toupper(ch) != 'Q')
				{
					while (cin.get() != '\n')
						continue;
					if (!isalpha(ch))
					{
						cout << '\a';
						continue;
					}

					switch (ch)
					{
					case 'A':
					case 'a':
						cout << "Enter full name: ";
						cin.get(po.fullname, 35);
						while (cin.get() != '\n') {
							continue;
						}
						cout << "Enter payment amount: ";
						cin >> po.payment;
						if (st.isfull()) {
							cout << "stack is already full\n";
						}
						else {
							st.push(po);
						}
						break;
					case 'P':
					case 'p':
						if (st.isempty()) {
							cout << "stack is already empty\n";
						}
						else {
						st.pop(po);
						cout << "Receipt #" << (total += po.payment) << " popped\n";
						}
						break;
					}
					cout << "\nPlease enter A to add customer, P to pop last customer, or Q to quit: ";
				}

				break;
			}

			case 6: // ch10 task 6
			{
				cin.ignore();

				Move subject1(7, 14);
				Move subject2(100.3, 34.7);
				subject1.showmove();
				subject2.showmove();
				Move subject3 = subject1.add(subject2);
				subject3.showmove();
				subject3.reset();
				subject3.showmove();

				break;
			}

			case 7: // ch10 task 7
			{
				cin.ignore();

				Plorg plorg1;
				plorg1.show();
				Plorg plorg2("Avatar", 37);
				plorg2.show();
				plorg2.changeCI(77);
				plorg2.show();

				break;
			}

			case 8: // ch10 task 8
			{
				cin.ignore();

				List lst;
				double tmp;
				int counter = 1;
				cout << "Enter a number #" << counter << ": ";
				while (cin >> tmp)
				{
					lst.add(tmp);
					if (lst.isfull()) break;
					counter++;
					cout << "Enter a number #" << counter << ": ";
				}
				lst.show();
				lst.visit(sqr);
				lst.show();

				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			}
			break;
		}


		case 11: // CHAPTER 11
		{
			cout << "\n============== CHAPTER 11 ==============\n\n";
			cout << "List of tasks:\n\t1. Vector 1.\n\t2. Vector 2.\n\t3. Vector 3.\n\t4. Class Time.\n";
			cout << "\t5. Stonewt 1.\n\t6. Stonewt 2.\n\t7. Complex number.\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}


			case 1: // ch11 task 1
			{
				cin.ignore();

				using namespace std;
				using VECTOR::Vector;
				ofstream fout;
				fout.open("vect_log.txt");
				srand(time(0));
				double direction;
				Vector step;
				Vector result(0.0, 0.0);
				unsigned long steps = 0;
				double target;
				double dstep;
				cout << "Enter target distance (q to quit): ";
				while (cin >> target)
				{
					cout << "Enter step length: ";
					if (!(cin >> dstep))
						break;
					fout << "Target Distance: " << target << ", "
						<< "Step Size: " << dstep << endl;
					while (result.magval() < target)
					{
						fout << steps << ": " << result << endl;
						direction = rand() % 360;
						step.reset(dstep, direction, Vector::POL);
						result = result + step;
						steps++;
					}
					fout << "After " << steps << " steps, the subject "
						"has the following location:\n" << result << endl;

					cout << "After " << steps << " steps, the subject "
						"has the following location:\n" << result << endl;
					result.polar_mode();

					fout << " or\n" << result << endl;
					fout << "Average outward distance per step = "
						<< result.magval() / steps << endl;

					cout << " or\n" << result << endl;
					cout << "Average outward distance per step = "
						<< result.magval() / steps << endl;
					steps = 0;
					result.reset(0.0, 0.0);
					cout << "Enter target distance (q to quit): ";
				}
				fout.close();
				cout << "Bye!\n";
				cin.clear();
				while (cin.get() != '\n')
					continue;

				break;
			}


			case 2: // ch11 task 2
			{
				cin.ignore();

				using VECTOR02::Vector;
				srand(time(0));
				double direction;
				Vector step;
				Vector result(0.0, 0.0);
				unsigned long steps = 0;
				double target;
				double dstep;
				cout << "Enter target distance (q to quit): ";
				while (cin >> target)
				{
					cout << "Enter step length: ";
					if (!(cin >> dstep))
						break;
					while (result.magval() < target)
					{
						direction = rand() % 360;
						step.reset(dstep, direction, Vector::POL);
						result = result + step;
						steps++;
					}
					cout << "After " << steps << " steps, the subject "
						"has the following location:\n";
					cout << result << endl;
					result.polar_mode();
					cout << " or\n" << result << endl;
					cout << "Average outward distance per step = "
						<< result.magval() / steps << endl;
					steps = 0;
					result.reset(0.0, 0.0);
					cout << "Enter target distance (q to quit): ";
				}
				cout << "Bye!\n";
				cin.clear();
				while (cin.get() != '\n')
					continue;

				break;
			}


			case 3: // ch11 task 3
			{
				cin.ignore();

				using VECTOR03::Vector;
				srand(time(0));
				double direction, target, dstep;
				Vector step;
				Vector result(0.0, 0.0);
				unsigned long steps = 0;
				unsigned long min, max, total;
				int trials;
				cout << "Enter target distance (q to quit): ";
				while (cin >> target)
				{
					cout << "Enter step length: ";
					if (!(cin >> dstep))
						break;
					cout << "Enter trials: ";
					if (!(cin >> trials))
						break;
					total = 0;
					for (int i = 0; i < trials; i++)
					{
						while (result.magval() < target)
						{
							direction = rand() % 360;
							step.reset(dstep, direction, Vector::POL);
							result = result + step;
							steps++;
						}
						total += steps;
						if (i == 0) min = max = steps;
						if (min > steps) min = steps;
						if (max < steps) max = steps;
						steps = 0;
						result.reset(0.0, 0.0);
					}
					cout << "The highest, lowest, and average number of steps for "
						<< trials << " trials:\n";
					cout << " Highest: " << max << "\n Lowest : " << min
						<< "\n Average: " << total / trials << endl;
					cout << "Enter target distance (q to quit): ";
				}
				cout << "Bye!\n";
				cin.clear();
				while (cin.get() != '\n')
					continue;

				break;
			}


			case 4: // ch11 task 4
			{
				cin.ignore();

				Time aida(3, 35);
				Time tosca(2, 48);
				Time temp;
				Time temp2;
				cout << "Aida and Tosca:\n";
				cout << aida << "; " << tosca << endl;
				temp = aida + tosca;
				cout << "Aida + Tosca: " << temp << endl;
				temp2 = aida - tosca;
				cout << "Aida - Tosca: " << temp2 << endl;
				temp = aida * 1.17;
				cout << "Aida * 1.17: " << temp << endl;
				cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

				break;
			}


			case 5: // ch11 task 5
			{
				cin.ignore();

				Stonewt incognito = 275;
				Stonewt wolfe(285.7);
				Stonewt taft(21, 8);
				cout << "The celebrity weighed " << incognito;
				cout << "The detective weighed " << wolfe;
				cout << "The President weighed " << taft;
				incognito = 276.8;
				taft = 325;
				cout << "After dinner, the celebrity weighed " << taft;
				cout << "Celebrity + Detective: " << incognito + wolfe;
				cout << "President - Detective: " << taft - wolfe;
				cout << "Detective * 5: " << wolfe * 5;
				cout << "3 * Celebrity: " << 3 * incognito;
				incognito.setStnMode();
				cout << "Celebrity Stone mode: " << incognito;
				incognito.setIntMode();
				cout << "Celebrity Int mode: " << incognito;
				incognito.setFloatMode();
				cout << "Celebrity Float mode: " << incognito;
				display(taft, 2);
				cout << "The wrestler weighed even more.\n";
				display(422, 2);
				cout << "No stone left unearned\n";

				break;
			}


			case 6: // ch11 task 6
			{
				cin.ignore();

				const int SIZE = 6;
				Stonewt06 arr[SIZE] = { 141, 275, 7 };
				Stonewt06 s11(11);
				int min, max, count;
				double pounds;
				for (int i = 3; i < SIZE; i++)
				{
					cout << "Enter pound: ";
					cin >> pounds;
					arr[i] = pounds;
				}
				min = max = count = 0;
				for (int i = 0; i < SIZE; i++)
				{
					if (arr[min] > arr[i]) min = i;
					if (arr[max] < arr[i]) max = i;
					if (arr[i] >= s11) count++;
				}
				cout << "The objects >= 11 pounds: " << count << "\n";
				cout << "Max object: ";
				arr[max].show_lbs();
				cout << "Min object: ";
				arr[min].show_lbs();

				break;
			}


			case 7: // ch11 task 7
			{
				cin.ignore();

				Complex a(3.0, 4.0);
				Complex c;
				cout << "Enter a complex number (-1, -1i to quit):\n";
				while (cin >> c)
				{
					cout << "c is " << c << '\n';
					cout << "complex cojugate is " << ~c << '\n';
					cout << "a is " << a << '\n';
					cout << "a + c is " << a + c << '\n';
					cout << "a - c is " << a - c << '\n';
					cout << "a * c is " << a * c << '\n';
					cout << "2 * c is " << 2 * c << '\n';
					cout << "Enter a complex number (-1, -1i to quit):\n";

					if (c.cA == -1 && c.cB == -1) {
						break;
					}
				}
				cout << "Done!\n";

				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			}
			break;
		}


		case 12: // CHAPTER 12
		{
			cout << "\n============== CHAPTER 12 ==============\n\n";
			cout << "List of tasks:\n\t1. Vector 1.\n\t2. Vector 2.\n\t3. Vector 3.\n\t4. Class Time.\n";
			cout << "\t5. Stonewt 1.\n\t6. Stonewt 2.\n\t7. Complex number.\n";
			cout << "=======================================\n\n";
			cout << "Enter task number: ";
			cin >> input;
			cout << endl;

			switch (input) {

			case -1:
			{
				cout << "Choose the chapter!\n";
				break;
			}


			case 1: // ch12 task 1
			{
				cin.ignore();

				Cow bob, obo("Bob", "Obo", 100), oboCopy(obo);
				cout << "\nInfo1:" << bob << "\nInfo2:" << obo << "\nInfo3:" << oboCopy << endl;
				bob = obo;
				cout << "\nInfo1:" << bob << "\nInfo2:" << obo << endl;

				break;
			}


			case 2: // ch12 task 2
			{
				cin.ignore();

				String s1(" and I am a C++ student.");
				String s2 = "Please enter your name: ";
				String s3;
				cout << s2;
				cin >> s3;
				s2 = "My name is " + s3;
				cout << s2 << ".\n";
				s2 = s2 + s1;
				s2.stringup();
				cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
					<< " 'A' characters in it.\n";
				s1 = "red"; 

				String rgb[3] = { String(s1), String("green"), String("blue") };
				cout << "Enter the name of a primary color for mixing light: ";
				String ans;
				bool success = false;
				while (cin >> ans)
				{
					ans.stringlow();
					for (int i = 0; i < 3; i++)
					{
						if (ans == rgb[i]) 
						{
							cout << "That's right!\n";
							success = true;
							break;
						}
					}
					if (success)
						break;
					else
						cout << "Try again!\n";
				}

				break;
			}


			case 3: // ch12 task 3
			{
			cin.ignore();

			Stock stocks[4] = {
				Stock("NanoSmart", 12, 20.0),
				Stock("Boffo Objects", 200, 2.0),
				Stock("Monolithic Obelisks", 130, 3.25),
				Stock("Fleep Enterprises", 60, 6.5)
				};

				cout << "Stock holdings:\n";
				int st;
				for (st = 0; st < 4; st++) {
					cout << stocks[st];
				}
				const Stock* top = &stocks[0];
				for (st = 1; st < 4; st++) {
					top = &top->topval(stocks[st]);
				}
				cout << "\nMost valuable holding:\n";
				cout << *top;

				break;
			}


			case 4: // ch12 task 4
			{
				cin.ignore();

				Stack12 st;
				char ch;
				unsigned long po;
				cout << "Please enter A to add customer, P to pop last customer, or Q to quit: ";
				while (cin >> ch && toupper(ch) != 'Q')
				{
					while (cin.get() != '\n')
						continue;
					if (!isalpha(ch))
					{
						cout << '\a';
						continue;
					}
					switch (ch)
					{
					case 'A':
					case 'a': cout << "Enter payment amount: ";
						cin >> po;
						if (st.isfull())
							cout << "stack is already full\n";
						else
							st.push(po);
						break;
					case 'P':
					case 'p': if (st.isempty())
						cout << "stack is already empty\n";
							else {
						st.pop(po);
						cout << "Receipt #" << po << " popped\n";
					}
							break;
					}
					cout << "Please enter A to add customer, P to pop last customer, or Q to quit: ";
				}

				break;
			}


			case 5: // ch12 task 5
			{
				cin.ignore();

				srand(time(0));

				cout << "Case Study: Bank of Heather Automatic Teller\n";
				cout << "Enter maximum size of queue: ";
				int qs;
				cin >> qs;

				cout << "Enter the number of simulation hours: ";
				int hours;      
				cin >> hours;

				long cyclelimit = 60 * hours;


				cout << "The average number of customers per hour: ";
				double perhour = 1;   
				double average_wait_time = 0; 
				for (; true; ++perhour) {
					Queue line(qs);     
					double min_per_cust;  
					min_per_cust = 60 / perhour;

					Item122 temp;      
					long turnaways = 0;    
					long customers = 0;  
					long served = 0;     
					long sum_line = 0;  
					int wait_time = 0;    
					long line_wait = 0;    


					for (int cycle = 0; cycle < cyclelimit; cycle++)
					{
						if (newcustomer(min_per_cust)) 
						{
							if (line.isfull())
								turnaways++;
							else
							{
								customers++;
								temp.set(cycle);
								line.enqueue(temp);
							}
						}
						if (wait_time <= 0 && !line.isempty())
						{
							line.dequeue(temp); 
							wait_time = temp.ptime();
							line_wait += cycle - temp.when();
							served++;
						}
						if (wait_time > 0)
							wait_time--;
						sum_line += line.queuecount();
					}

					average_wait_time = (double)line_wait / served;
					if (0.99 < average_wait_time and 1.99 > average_wait_time) {
						cout << "Average number of customers per hour, which leads to an average waiting time of one minute: " << perhour
							<< " persons\n";
						break;
					}
					else
						cout << "\n" << perhour << " customers per hour, waiting time: " << average_wait_time << " minutes\n";
				}

				break;
			}


			case 6: // ch12 task 6
			{
				cin.ignore();

				srand(time(0));  

				cout << "Case Study: Bank of Heather Automatic Teller\n";
				cout << "Enter maximum size of queue: ";
				int qs;
				cin >> qs;

				cout << "Enter the number of simulation hours: ";
				int hours;      
				cin >> hours;

				long cyclelimit = 60 * hours;


				cout << "The average number of customers per hour: ";
				double perhour = 1;
				double average_wait_time = 0; 
				for (; true; ++perhour) {
					Queue line(qs), line2(qs);  

					double min_per_cust; 
					min_per_cust = 60 / perhour;

					Item122 temp;           
					Item122 temp2;      
					long turnaways = 0;  
					long customers = 0;   
					long served = 0;      
					long sum_line = 0;  
					int wait_time = 0;   
					int wait_time2 = 0;   
					long line_wait = 0;     


										

					Queue* pLineNow = nullptr;
					Item122* pTempNow = nullptr;

					for (int cycle = 0; cycle < cyclelimit; cycle++)
					{
						if (line.queuecount() < line2.queuecount()) { 
							pLineNow = &line; 
							pTempNow = &temp; 
						}
						else {
							pLineNow = &line2;
							pTempNow = &temp2;
						}

						if (newcustomer(min_per_cust)) 
						{
							if (line.isfull() and line2.isfull())
								turnaways++;
							else
							{
								customers++;
								pTempNow->set(cycle); 
								pLineNow->enqueue(*pTempNow);
							}
						}

						if (wait_time <= 0 && !line.isempty()) 
						{
							line.dequeue(temp); 
							wait_time = temp.ptime(); 
							line_wait += cycle - temp.when();
							served++;
						}
						if (wait_time > 0)
							wait_time--;

						if (wait_time2 <= 0 && !line2.isempty())
						{
							line2.dequeue(temp2); 
							wait_time2 = temp2.ptime(); 
							line_wait += cycle - temp2.when();
							served++;
						}
						if (wait_time2 > 0)
							wait_time2--;

						sum_line += line.queuecount() + line2.queuecount();
					}

					average_wait_time = (double)line_wait / served;
					if (0.99 < average_wait_time and 1.99 > average_wait_time) {
						cout << "Average number of customers per hour, which leads to an average waiting time of one minute: "
							<< perhour << " persons\n";
						break;
					}
					else
						cout << "\n" << perhour << " customers per hour, waiting time: " << average_wait_time << " minutes\n";
				} 

				break;
			}


			default:
			{
				cout << "Unfortunatelly here is no such task. Yet :)\n";
				break;
			}

			}
			break;
		}



		default:
		{
			cout << "Unfortunatelly here is no such chapter. Yet :)\n";
			break;
		}

		}

		cout << "\n=======================================\n";

		
	}


	return 0;
}
