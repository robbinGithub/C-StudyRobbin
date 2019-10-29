#include "Rect.h"
#include "Circle.h"

int main1(void)
{
	Shape* shape1 = new Rect(3, 6);
    Shape* shape2 = new Circle(3);
	shape1->calcArea();
	shape2->calcArea();
	delete shape1;
	shape1 = NULL;
	delete shape2;
	shape2 = NULL;
	getchar();
	return 0;
}