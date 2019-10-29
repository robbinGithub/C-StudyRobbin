#include  "Flyable.h"
#include  <string>
#include  <iostream>
using namespace  std;
class Plane :public Flyable{

public:
	Plane(string code);
	virtual void takeoff();
	virtual void land(); 
	virtual void printcode();
private:
	string  m_strCode;

};