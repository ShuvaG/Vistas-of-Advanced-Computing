/*// Void example (function)
#include <iostream>
#include <string>
using namespace std;

void declare(string words){
	cout << words << endl;
}
int main() {
	declare("My name is Shuva");
	return 0;
}*/
////////////////////////////////////////////////////////////////////////

// Matrix 
/*#include <iostream>
using namespace std;

const int COLUMN_SIZE = 4;

int sum(const int a[][COLUMN_SIZE], int rowSize)
{
	int total = 0;
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < COLUMN_SIZE; column++)
		{
			total += a[row][column];
		}

	}
	return total;
}
int main()
{
	int m[4][4] =
	{
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16},
	};
	cout << "Sum of the matrix" << sum(m, 4) << endl;
	int j;
	cin >> j;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////

// Swtich- allows you to jump to options

//////////////////////////////////////////////////////////////////////////////////

// Math
/*#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double c;
	c = pow(3, 2);
	cout << c << endl;
	int j;
	cin >> j;
	return 0;
}*/

////////////////////////////////////////////////////////////////////////////////////

//Adress
/*#include <iostream>
using namespace std;

int main()
{
	int var1 = 3;
	int var2 = 24;
	int var3 = 17;
	cout << &var1 << endl;
	cout << &var2 << endl;
	cout << &var3 << endl;
	int j;
	cin >> j;
	return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////

// Matrix Homework # 5

/*#include <iostream>
using namespace std;

const int columnSize = 4;
int newMatrix;

int transpose(int a[] [columnSize], int rowSize)
{
	for (int row = 0; row < rowSize; row++)
	{
		for (int column = 0; column < columnSize; column++)
		{
			newMatrix = a[column][row];
			cout << newMatrix << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}

int main() {

	int m[4][4] =
	{
		{ 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 },
	};

	cout << "Original Matrix: " << endl;

	for (int i = 0; i <= 3; i++) 
	{
		for (int j = 0; j <= 3; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Transposed Matrix: " << endl;
	cout << transpose(m, 4) << endl;

	int j;
	cin >> j;

	return 0;
}*/

//////////////////////////////////////////////////////////////////////////////////

// Sin Homework #6 

/*#include <iostream>
#include <math.h>
using namespace std;

double factorial(int factnumb)
{
	double factsequence = 1.0;

	for (int i = factnumb; i > 0; i--)
	{
		factsequence *= i;
	}
	return factsequence;
}

int main() {
	long double angle;
	int accuracy = 150;
	long double answer = 0;
	long double term = 0; 
	
	cout << "Enter an angle (in radians): " << endl;
	cin >> angle;

	for (int i = 0; i <= accuracy; i++)
	{
		term = (pow(-1, double (i))*pow(angle, 2 * double(i) + 1)) / double(factorial((2 * i + 1)));
		answer += term;
	}
	cout << "Sin(x) approximation: " << answer << endl;
	cout << "Sin(x) exact: " << sin((angle));

	int j;
	cin >> j;

	return 0;
}*/

/////////////////////////////////////////////////////////////////////////////////

// Pointers Homework #7
/*#include <iostream>
using namespace std;

int main()
{
	int *pc, c;

	c = 5;
	cout << "Adress of c (&c): " << &c << endl;
	cout << "Value of c (c): " << c << endl << endl;

	pc = &c;
	cout << "Address that pointer pc holds (pc): " << pc << endl;
	cout << "Content of the address pointer pc holds (*pc): " << *pc << endl << endl;

	c = 11;
	cout << "Address that pointer pc holds (pc): " << pc << endl;
	cout << "Content of the address pointer pc holds (*pc): " << *pc << endl << endl;

	*pc = 2;
	cout << "Adress of c (&c): " << &c << endl;
	cout << "Value of c (c): " << c << endl << endl;

	int j;
	cin >> j;

	return 0;

}*/

////////////////////////////////////////////////////////////////////////////

 // Pointers
/*#include <iostream>
using namespace std;

int main()
{
	float arr[5];
	float *ptr;

	cout << "Display address " << endl;

	for (int i = 0; i< 5; ++i)
	{
		cout << "&array[" << i << "]= " << &arr[i] << endl;
	}

	ptr = arr; // gives to ptr=arr (transfers pointer to pointer BECAUSE ARRAYS ARE POINTERS TOO)

	cout << "Display address  using pointers: " << endl;
	for (int i = 0;i < 5;++i)
	{
		cout << "ptr +" << i << "=" << ptr + 1 << endl;
	}

	*(ptr + 2) = 3.14159265;

	cout << arr[2];

	int j;
	cin >> j;

	return 0;
}*/

///////////////////////////////////////////////////////////////////////

// Pointer Exrercize #1 

/*#include <iostream>
using namespace std;

int main()
{
	int A, B, *ptrA, *ptrB;
	cout << "Enter a Value for A and B" << endl;
	cin >> A;
	cin >> B;

	ptrA = &A;
	ptrB = &B;

	cout << "The value of A: " << *ptrA << endl;
	cout << "The location of A: " << ptrA << endl << endl;
	cout << "The value of B: " << *ptrB << endl;
	cout << "The location of B: " << ptrB << endl;

	int j;
	cin >> j;

	return 0;
}*/
/////////////////////////////////////////////

// Pointer Example #2
/*#include <iostream>
using namespace std;

int main()
{
	int dataPoints, max, *ptrMax;
	cout << "Enter the number of data points in a set: " << endl;
	cin >> dataPoints;


	cout << "Enter a value for each data point: " << endl;
	int array [dataPoints];

	for (int i = 0; i < dataPoints; i++)
	{
		cin >> array[i];
	}

	for (int i = 0; i < dataPoints; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	ptrMax = &max;
	cout << "The max point is:" << *ptrMax << endl;
	cout << "The address of the max is: " << ptrMax << endl;

	return 0;
}*/

/////////////////////////////////////////////////////////////////////////////////////

//Pointer Example #3
/*#include <iostream>
using namespace std;

int main()
{
	int in, *ptrInput;

	cout << "Enter and integer: " << endl;
	cin >> in;

	ptrInput = &in;

	cout << "The input value is: " << *ptrInput << endl;

	int j;
	cin >> j;
	return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////
// Pointer Example #4
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
	string aString = "A string";
	string *ptr;
	string *ptr2;

	ptr = &aString;

	cout << aString[0] << " " << ptr << " " << aString[3] << endl;
	ptr += 2;
	cout << ptr << " " << aString[4] << " " << aString[7] << endl;

	int j;
	cin >> j;
	return 0;
}*/
//////////////////////////////////////////////////////////////////////////
// Dr. Prosperetti's Coding Assignment 

/*#include <iostream>
#include <math.h>
using namespace std;

double func(double x)
{
	double fx = exp(-x) - x;
	return fx;
}

double deriv(double x)
{
	double fx1 = -exp(-x) - 1;
	return fx1;
}

int main()
{
	const double tolerance = .00001;
	const int terms = 10;
	double x[terms];
	double finalAnswer = 0;
	x[0] = 0;

	for (int i = 0; i < terms; i++)
	{
		x[i + 1] = x[i] - func(x[i]) / deriv(x[i]);
		finalAnswer = x[i + 1];
		//cout << finalAnswer << endl;
		if (abs((x[i + 1] - x[i])) / x[i + 1] < tolerance) break;
	}

	cout << "The root is = " << finalAnswer << endl;
	int j;
	cin >> j;
	return 0;
}*/

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Container Problems
/*#include <iostream>
#include <vector> // class/library/header file
using namespace std;

int main()
{
	// vector with 10 elements, all of them the number 5
	vector<int> vect1(10, 5);

	cout << "Vector has " << vect1.size() << " elements. \n";

	int j;
	cin >> j;

	return 0;
}*/

////////////////////////////////////////////////////////////////////////////

// Container Problems
/*#include <iostream>
#include <vector> // class/library/header file
using namespace std;

int main()
{
	// vector with 10 elements, all of them the number 5
	vector<int> vect1(10, 5);

	cout << "Vector has (line 427) " << vect1.size() << " elements. \n";

	for (long index = 0; index < (long)vect1.size(); ++index)
		cout << "Element " << index << ": " << vect1.at(index) << endl; //printing specific element

	vect1.resize(7);

	cout << "Vector has (line 434) " << vect1.size() << " elements. \n";


	int j;
	cin >> j;

	return 0;
}*/
///////////////////////////////////////////////////////////////////
// Container Problems

/*#include <iostream>
#include <vector> // class/library/header file
using namespace std;

int main()
{
	vector<int> example;

	example.push_back(3);
	example.push_back(33);
	example.push_back(333);

	for (int x = 0; x < example.size(); ++x)
		cout << example[x] << " ";

	if (!example.empty()) example.clear();

	vector<int> another_vector;

	another_vector.push_back(10);
	example.push_back(10);

	if (example == another_vector) example.push_back(20);

	for (int y = 0; y < example.size(); y++)
	cout << example.at(y) << " ";


	return 0;
}*/
/////////////////////////////////////////////////////

//Containter Problems
/*#include <iostream>
#include <vector> // class/library/header file
using namespace std;

int main()
{
	int n;
	cout << "Number to initialize? ";
	cin >> n;

	// creating 2D array     |rows            |initial value     
	vector<vector<int>> grid(3, vector<int>(4, n));
	//                                      |# of columns 

	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) { // we could have a jagged row!
			cout << grid[row][col] << " " << flush;
		}
		cout << endl;
	}

	grid[1].push_back(11); //adding element to row 2

	cout << "After pushing element into row 2: " << endl;
	for (int row = 0; row < grid.size(); row++) {
		for (int col = 0; col < grid[row].size(); col++) { // we could have a jagged row!
			cout << grid[row][col] << " " << flush;
		}
		cout << endl;
	}

	int j;
	cin >> j;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////

//Container Problems
/*#include <iostream>
#include <unordered_set>
#include <array>
#include <string>
using namespace std;

int main()
{
	unordered_set<string> myset = { "yellow", "green", "blue" };
	array<string, 2>	  myarray{ "black", "white" };
	string				  mystring = "red";

	myset.insert(mystring); // copy insertion
	myset.insert(mystring + "dish"); //move insertion
	myset.insert(myarray.begin(), myarray.end()); //range insertion
	myset.insert({ "purple", "orange" }); //initializer

	cout << "myset contains: " << endl;

	for (const string &x : myset)
		cout << " " << x;
	cout << endl;
	
	int j;
	cin >> j;
	return 0;
}*/

///////////////////////////////////////////////////////

//Container Problems
/*#include <iostream>
#include <list>

using namespace std;

int main()
{
	list <int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	numbers.push_front(0); // NEW

	cout << "\nBefore inserting: " << endl;
	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) //::iterator is like a "*"
		cout << *it << endl;

	// no more iterator because it was defined in the "for loop"!

	list<int>::iterator it = numbers.begin(); //*it=0
	it++;; //goes to the next address //*it=1

	numbers.insert(it, 11223344);
	cout << "\nAfter inserting: " << endl;
	for (it = numbers.begin(); it != numbers.end(); ++it) //::iterator is like a "*"
		cout << *it << endl;

	it = numbers.begin(); // delclared in line 568
	it++;
	numbers.erase(it); // erases 11223344
	// list looks like : 0 1 2 3 


	//                                                        NOTHING AT THE END
	//                                                                |
	//                                                                V
	for (list<int>::iterator it = numbers.begin(); it != numbers.end();) {
		if (*it == 2) { numbers.insert(it, 22334455); }
		if (*it == 1) { it = numbers.erase(it); } //removes the number, keeps the address
		else { ++it; } // goes to the next address
	}

	// printing the list 
	for (it = numbers.begin(); it != numbers.end(); ++it) //::iterator is like a "*"
		cout << *it << endl;



	int j;
	cin >> j;
	return 0;
}*/

///////////////////////////////////////////////////////////////////////////

// HOMEWORK : Do the string coding (anagrapm) (simple and with <string>, do the random sized word problem (slide 19 & 20 on pt. 2)

// Slide 19  part B - simple way (without <string>)
/*#include <iostream>
using namespace std;

int main()
{
	char name[] = "martin";
	char newName[] = "martin";
	for (int i = 0; i <= 6; i++)
	{
		newName[i] = name[6 - i];
		cout << newName[i];
	}

	int j;
	cin >> j;

	return 0;
}*/

/////////////////////////////////////////////////////////

// Slide 19  part B - with <string>
/*#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name = "martin";
	string newName = "martin";
	
	for (int i = 0; i <= size(name); i++)
	{
		newName[i] = name[6 - i];
		cout << newName[i];
	}

	int j;
	cin >> j;

	return 0;
}*/

///////////////////////////////////////////////////////////////////////////////

// Slide 19 part C (anagram)

/*#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string reply1;
	string reply2;
	int counter = 0;
	cout << "Enter a word:  " << endl;
	cin >> reply1;
	cout << "Enter another word" << endl;
	cin >> reply2;



	if (size(reply1) == size(reply2))
	{
		for (int i = 0; i <= size(reply1); i++)
		{
			for (int k = 0; k <= size(reply1); ++i)
			{
				if (reply1[i] == reply2[k])
				{
					counter += 1;
				}
			}
		}
		if (counter = size(reply1))
			cout << "The two words are anagrams! " << endl;
		else
			cout << "The two words are not anagrams. " << endl;
	}
	else
		cout << "The two words are not anagrams. " << endl;
	
	int j;
	cin >> j;
	return 0;
}*/

////////////////////////////////////////////////////////////////////////////////////////

// Rand Homework Slide 20
/*#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int r, a, b, c;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";

	cout << "Random 'word' generator." << endl;
	for (a = 0;a <50 ;a++)
	{
		for (b = 0;b = rand();b++) 
		{
			r = rand();
			cout << letters[r];
		}
		cout << endl;
		
	}
	int j;
	cin >> j;
	return 0;
}*/

//////////////////////////////////////////

/*#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int r, a, b;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	puts("100 Random Numbers");
	for (a = 0;a<20;a++) {
		for (b = 0;b<rand();b++) {
			r = rand() % 26;
			cout << letters[r];
		}
		cout << " " << endl;
	}
	int j;
	cin >> j;
	return(0);
}*/

///////////////////////////

/*#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	float sum = 0;
	for (int i = 10000 ; i >= 1; i--)
	{
		sum += 1 / pow(i, 2);
		// cout << sum;
	}

	cout << sum;

	int j;
	cin >> j;

	return 0;
}*/
