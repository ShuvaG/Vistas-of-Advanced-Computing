// Exam 1 - Question 5
#include <iostream>
#include <string>
using namespace std;

class Shapes {
public:
	int num_of_sides;
	Shapes() {} // Prototype
	~Shapes() // Destructor
	{
		cout << "Object is being deleted." << endl;
	}
	void disp_sides()
	{
		cout << "The number of sides is" << num_of_sides << endl;
	}
};
class Triangle : public Shapes
{
public:
	int num_of_sides = 3;
	Triangle(int faces)
	{
		num_of_sides = faces;
	}
	void disp_sides()
	{
		cout << "The number of sides is " << num_of_sides << endl;
	}
	void disp_name()
	{
		cout << "This is a triangle." << endl;
	}
};
class Rectangle : public Shapes
{
public:
	int num_of_sides = 4;
	Rectangle(int faces)
	{
		num_of_sides = faces;
	}
	void disp_name()
	{
		cout << "This is a rectangle." << endl;
	}
	void disp_sides()
	{
		cout << "The number of sides is " << num_of_sides << endl;
	}
};
class Pentagon : public Shapes
{
public:
	int num_of_sides=5;
	Pentagon(int faces)
	{
		num_of_sides = faces;
	}
	void disp_name()
	{
		cout << "This is a pentagon." << endl;
	}
	void disp_sides()
	{
		cout << "The number of sides is " << num_of_sides << endl;
	}
};

int main()
{
	Triangle tri(3);
	Rectangle rect(4);
	Pentagon pent(5);

	tri.disp_name();tri.disp_sides();
	rect.disp_name();rect.disp_sides();
	pent.disp_name();pent.disp_sides();

	system("PAUSE");
	return 0;
}
