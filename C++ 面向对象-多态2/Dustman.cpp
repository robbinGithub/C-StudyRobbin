#include "Dustman.h"
#include <iostream>
using namespace std;
Dustman::Dustman(string name, int age) :Worker(name, age){

}

Dustman::~Dustman()
{

}
void Dustman::work()
{
	cout << "Dustman:work ɨ��" << endl;

}
void Dustman::printinfo()
{
	cout << "Dustman:printinfo" << endl;

}