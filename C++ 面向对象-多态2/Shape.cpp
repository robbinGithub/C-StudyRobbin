#include "Shape.h"

Shape::Shape(){
	cout << "Shape()" << endl;
}
Shape::~Shape(){
	cout << "~Shape()" << endl;
}
double Shape::calcArea(){
	cout << "Shape->calArea()" << endl;
	return 0;
}