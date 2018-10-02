#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Graph.h"
#include "Tree.h"
#include "Triangle.h"
#include "Tetragon.h"
#include "Pentagon.h"
//using namespace std;
using namespace std;
void graph_checker()
{
	cout << "You will work with Class Graph\n"; 
	bool flag = false;
	while (flag)
	{
		int x;
		cout << "What data which graph";
		cin >> x;
	}
}

int main()
{
	//-----------------------------GRAPH---------------------------
	graph_checker();
	cout << "-----------------------------POLYGON---------------------------\n";
	Triangle *A = new Triangle(1, 0, 3, 0, 2, 0);
	cout << "Triangle:\nPerimetr: " << A->perimetr() << "\nSquare: " << A->square() << "\nType: " << A->regular() << '\n';
	cout << A << '\n';
	Tetragon *B = new Tetragon(0, 0, 3, 0, 3, 4, 0, 3);
	cout << "Tetragon\nPerimetr: " << B->perimetr() << "\nSquare: " << B->square() << "\nType: " << B->regular() << '\n';
	cout << B << '\n';
	Pentagon *C = new Pentagon(0, 0, 2, 0, 2, 2, 1, 3, 0, 2);
	cout << "Pentagon\nPerimetr: " << C->perimetr() << "\nSquare: " << C->square() << "\nType: " << C->regular() << '\n';
	cout << C << '\n';
	system("pause");
}