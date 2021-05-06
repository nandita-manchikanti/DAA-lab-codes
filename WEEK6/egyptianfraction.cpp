// C++ program to print a fraction in Egyptian Form using Greedy Algorithm
// Every positive fraction can be represented as sum of unique unit fractions. 
//A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. 
//Such a representation is called Egyptian Fraction as it was used by ancient Egyptians.


//Greedy part is  first find the greatest possible unit fraction, then recur for the remaining part
#include <iostream>
using namespace std;

void printEgyptian(int nr, int dr)
{
	// If either numerator or denominator is 0
	if (dr == 0 || nr == 0)
		return;

	// If numerator divides denominator, then simple division
	// makes the fraction in 1/n form
	if (dr%nr == 0)
	{
		cout << "1/" << dr/nr;
		return;
	}

	// If denominator divides numerator, then the given number is not fraction
	if (nr%dr == 0)
	{
		cout << nr/dr;
		return;
	}

	// If numerator is more than denominator
	if (nr > dr)
	{
		cout << nr/dr << " + ";
		printEgyptian(nr%dr, dr);
		return;
	}

	// We reach here dr > nr and dr%nr is non-zero then we find the ceiling of dr/nr and print it as first fraction
	int n = dr/nr + 1;
	cout << "1/" << n << " + ";

	// Recur for remaining part
	printEgyptian( nr*n-dr, dr*n );

}

// Driver Program
int main()
{
	int nr;
    int dr;
    cout<<"Enter the numerator : ";
    cin>>nr;
    cout<<"Enter the denominator : ";
    cin>>dr;

	cout << "Egyptian Fraction Representation of "<< nr << "/" << dr << " is\n ";
	printEgyptian(nr, dr);
	return 0;
}
