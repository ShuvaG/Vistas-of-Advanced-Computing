// Anagram Homework
/*#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string rep1, rep2;

	cout << "Entner a word: " << endl;
	cin >> rep1;
	cout << "Enter another word " << endl;
	cin >> rep2;
	if (size(rep1) == size(rep2))
	{
		sort(rep1.begin(), rep1.end());
		sort(rep2.begin(), rep2.end());

		if (rep1 == rep2)
			cout << "Theses words are anagrams!" << endl;
	}
	if (size(rep1)!= size(rep2))
		cout << "Theses words are not anagrams." << endl;

	int j;
	cin >> j;
	return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////

/*#include<iostream>
#include <string>
using namespace std;

struct Animal
{
	int age;
	string name;
	string color;
	int legCount;
};

int main()
{
	Animal gorilla;
	gorilla.age = 5;
	cout << gorilla.age;
	int j;
	cin >> j;
	return 0;
}*/

///////////////////////////////

/*#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
	int age;
	string name;
	string color;
	int legCount;
	
	//constructors (makes it a function)
	Animal() { //handles what to do when you don't give any parameters

		//cout << "Don't forget to initialize this object" << endl;

		if (name == "" || age == NULL || legCount == NULL || color == "")
			cout << "Don't forget to initialize this object" << endl;

			/*age = 999;
			name = "EMPTY";
			color = "UNFILLED";
			legCount = 999;*/

/*	}
	Animal(int a, string n, string c, int l) { // allows for the passing of arguments
		age = a;
		name = n;
		color = c;
		legCount = l;
	}
};

int main()
{
	Animal gorilla(5, "Jack", "Black", 4); //passing arguments
	Animal bird;
	bird.name = "Harry";
	gorilla.name = "Jack Jr.";
	cout << gorilla.name << endl;
	cout << bird.name << endl;
	int j;
	cin >> j;

	return 0;
}*
///////////////////////////////////////////////////

// Making a Structure that holds physics constnts
/*#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct PhysConst {
	const double e = 2.71828182846;
	const double pi = 3.14159265359;
	const double h = 6.626*pow(10, -34);
	const double c = 2.99792*pow(10, 8);
	const double echarge = 1.60217662 * pow(10, -19);
	const double g = 9.81;

}PhysConst;
int main()
{
	cout << PhysConst.pi << endl;

	int j;
	cin >> j;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////

/*#include <iostream>
#include <string>
using namespace std;

class Rectangle {
// this is private by default
	int width, height;

public: // you do need this 
	//  Constructor prototype
	Rectangle(int, int);

	/*Rectangle(int w, int h){
	  width=w;
	  height=h;
	  }*/

	/*void changeW(int a); //This is how to access width

	int area(); // prototype 
};*/
/*Rectangle::Rectangle(int w, int h) { // This is a constructor
	width = w;
	height = h;
}
int Rectangle::area() {
	return width * height;
}
void Rectangle::changeW(int w) {
	width = w;
}

int main()
{
	Rectangle rect(3, 4); // ANOTHER WAY TO DO THIS => Rectangle *rect = new Rectangle (3,4); 
	                      // BUUUUUT at the end you HAVE to put "delete rect;" at the end!
	Rectangle rect2(5, 6);

	cout << "rect area: " << rect.area() << endl // DON'T NEED COUT IN NEXT LINE B/C NO ";"!!!
	<< "rect2 area: " << rect2.area() << endl;
	

	// rect.width=22; will NOT work because "width" is private (Look back at changeW, this allows us to change/access width)
	//rect.changeW(333); this WILL work because we made the function changeW


	int j;
	cin >> j;
	return 0;

}*/
//////////////////////////////////////////////////

// DESTRUCTOR USE
/*#include <iostream>
using namespace std;

class Line {
public:
	void setLength(double len);
	double getLength(void);
	Line();
	~Line();

private:
	double length;
};

// Member function definition including constructor
Line::Line(void) {
	cout << "Object is being created" << endl;
}
Line ::~Line(void) {
	cout << "Object is being deleted" << endl;
}
void Line::setLength(double len) {
	length = len;
}
double Line::getLength(void) {
	return length;
}

// Main Function

int main()
{
	Line line;

	//set length
	line.setLength(6.0);
	cout << "Length of line : " << line.getLength() << endl;

	int j;
	cin >> j; 

	return 0;
}*/
//////////////////////////////////

// HOMEWORK (20 June 2018) : 
	//Program random word
	//Read about exception handling
	//Read about map
	//Read about recursion
	//Program Fibonacii

///////////////////////////////////

// RANDOM WORD GENERATOR HOMEWORK
/*#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int r, a, b, count=0;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	for (a = 0;a<60;a++) {
		for (b = 0;b<rand();b++) {
			r = rand() % 26;
			cout << letters[r];
			//if (count >= 49)
				//cout << " " << endl;
		}
	
	}
	int j;
	cin >> j;
	return(0);
}*/

//////////////////////////////////////////////////////////

//Fibonacci Program Homework

/*#include <iostream>
using namespace std;

int fibonacci(int n)
{
	int fib;
	if (n <= 1)
		return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int n;
	cout << "Enter how many values you want" << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
		cout << fibonacci(i) << " ";

	system("PAUSE");
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////

// IN CLASS ASSIGNMENT

/*#include <iostream>
#include <string>
using namespace std;

class Person {

public:
	string profession;
	int age;

	Person() : profession("unemployed"), age(16){} //Constructor

	void display()
	{
		cout << profession << " " << age << endl;
	}
};


class MathsTeacher: public Person {
public:

	void teachMaths()
	{
		cout << "I can teach math." << endl;
	}

};

class Footballer : public MathsTeacher {
public:
	void  playFootball()
	{
		cout << "I can play football." << endl;
	}
};

int main()
{
	MathsTeacher teacher;
	teacher.profession = "Teacher";
	teacher.age = 23;
	teacher.display();
	teacher.teachMaths();

	Footballer footballer;
	footballer.profession = "Footballer";
	footballer.age = 19;
	footballer.display();
	footballer.playFootball();

	system("PAUSE");

	return 0;
}*/

//////////////////////////////////////////////////////////////

// MYSTERY CODE

/*#include<stdlib.h>
#include<stdio.h>
void f1(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	// create temp arrays 
	int L[n1], R[n2];
	// Copy data to temp arrays L[] and R[] 
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	// ... the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	// Copy the remaining elements of L[], if there are any 
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	// Copy the remaining elements of R[], if there are any 
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
// l is for left index and r is right index of the sub-array of arr to be ... 
void f2(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;
		// ... first and second halves
		f2(arr, l, m);
		f2(arr, m + 1, r);
		f1(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is \n");
	printArray(arr, arr_size);
	f2(arr, 0, arr_size - 1);
	printf("\ New array is \n");
	printArray(arr, arr_size);
	return 0;
}*/

/////////////////////////////////////////////////////

//HOMEWORK FILL IN ?? #1

/* <iostream>
using namespace std;

// Base class Shape
class Shape {
public:
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}


protected: 
	int width;
	int height;
};

// Base class PaintCost
class PaintCost {
public:
	int getCost(int area) {
		return area * 70;
	}
};
// Derived class
class Rectangle : public Shape, public PaintCost{
public:
	int getArea() {
		return(width*height);
	}
};
int main(void) {
	Rectangle Rect;
	int area;
	Rect.setWidth(5);
	Rect.setHeight(7);

	area = Rect.getArea();

	//Print the area of the object.
	cout << "Total area: " << Rect.getArea() << endl;

	//Print the total cost of painting
	cout << "Total paint cost: $" << Rect.getCost(area) << endl;

	system("PAUSE");
	return 0;
}*/

/////////////////////////////////////////////////////////////

// HOMEWORK FILL IN ?? #2 

/*#include <iostream>
using namespace std;

class country
{
public:
	country()
	{
		cout << "\n Destructor called \n";
	}

	void setNumOfCities(int num);
	int getNumOfCities(void);

	~country()
	{
		cout << "\n Destructor called \n";
	}
private:
	int num_of_cities;
};

void country::setNumOfCities(int num)
{
	num_of_cities = num;
}

int country::getNumOfCities(void)
{
	return num_of_cities;
}

int main(void)
{
	country obj;
	int num = 5;

	num = obj.getNumOfCities();
	obj.setNumOfCities(num);
	cout << "\n Number of cities is equal " << num << endl;

	system("PAUSE");
	return 0;
}*/

///////////////////////////////////////////////////////////////

/*  WORD CLOUD (using C++ 14)
Author : YADAV SUMITKUMAR
CSE Sec-C
Reg.No : 149105478
to compile: g++ main.cpp -std=c++0x
*/

/*#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	int i, found;
	string str;
	ifstream fi("out.txt");
	ofstream fo("word_cloud.html");

	vector<string> stopwords = { ",",".",";","is","were","has","we","a","an","the","of","from","to","when","will","be","at","but","in","and" };
	vector< pair<string, int> > list;
	vector< pair<string, int> >::iterator it;

	if (!fi.is_open() || !fo.is_open()) {
		cout << "Error opening files." << endl;
		return 0;
	}

	while (fi >> str)
	{
		// Checking for stopwords
		if (find(stopwords.begin(), stopwords.end(), str) != stopwords.end()) {
			continue;
		}

		found = 0;
		// Searching if word already exists
		for (i = 0; i < list.size(); i++) {
			if (str == list[i].first) {
				found = 1;
				break;
			}
		}

		if (found == 1) {		// Increment Frequency if exists
			list[i].second = list[i].second + 1;
		}
		else {				// Add to the list if does not exists 
			list.push_back(make_pair(str, 1));
		}
	}

	fo << "<html>\n<title>Word Cloud</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n</head>\n<body>\n<div class=\"para\">\n";

	for (it = list.begin(); it != list.end(); it++) {

		if (it->second == 1) {
			fo << "<span class=\"text1\">" + it->first + "</span>\n";
		}
		else if (it->second == 2) {
			fo << "<span class=\"text2\">" + it->first + "</span>\n";
		}
		else if (it->second == 3) {
			fo << "<span class=\"text3\">" + it->first + "</span>\n";
		}
		else if (it->second == 4) {
			fo << "<span class=\"text4\">" + it->first + "</span>\n";
		}
		else if (it->second > 4) {
			fo << "<span class=\"text5\">" + it->first + "</span>\n";
		}
	}

	fo << "</div>\n</body>\n</html>";

	fi.close();
	fo.close();
	system("PAUSE");
	return 0;
}*/