#include "Test.cpp"

int main()
{
	//-----------------------------GRAPH---------------------------
	Graph<int> temp;
	check(temp);
	cout << "-----------------------------POLYGON---------------------------\n";
	Triangle *A = new Triangle(1, 0, 3, 0, 2, 0);
	cin >> A;
	cout << "Triangle:\nPerimetr: " << A->perimetr() << "\nSquare: " << A->square() << "\nType: " << A->regular() << '\n';
	cout << A << '\n';
	Tetragon *B = new Tetragon(0, 0, 3, 0, 3, 4, 0, 3);
	cin >> B;
	cout << "Tetragon\nPerimetr: " << B->perimetr() << "\nSquare: " << B->square() << "\nType: " << B->regular() << '\n';
	cout << B << '\n';
	Pentagon *C = new Pentagon(0, 0, 2, 0, 2, 2, 1, 3, 0, 2);
	cin >> C;
	cout << "Pentagon\nPerimetr: " << C->perimetr() << "\nSquare: " << C->square() << "\nType: " << C->regular() << '\n';
	cout << C << '\n';
	system("pause");
}