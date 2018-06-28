//Exam 1 - Question 3
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int fibseq(int n)
{
	if (n <= 1)
		return n;
	else
		return fibseq(n - 1) + fibseq(n - 2);
}

int main()
{
	vector <int> fibsequence(20, 0);
	int vect(20);
	list<int>::iterator it;

	cout << "The fibbonaci sequence (first 20 terms) is: " << endl;

	for (int i = 0; i < 20; i++)
	{
		fibsequence.push_back(fibseq(i));
	}

	for (int i = 0; i < 20; i++)
	{
		cout << fibseq(i) << " ";
	}
	cout << endl;
	system("PAUSE");
	return 0;
}