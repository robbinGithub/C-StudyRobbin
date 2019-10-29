#include "Circle.h"

Circle::Circle(double r){
	m_dR = r;
	cout << "Circle()" << endl;

}

Circle::~Circle(){
	cout << "~Circle()" << endl;

}
double Circle::calcArea(){
	cout << "Cirlce->calArea()" << endl;
	return m_dR *m_dR;

}