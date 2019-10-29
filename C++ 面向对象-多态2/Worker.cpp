#include "Worker.h"
#include <iostream>
using namespace std;
Worker::Worker(string name, int age) :Person(name)
{
	m_iAge = age;
}
Worker::~Worker(){

}
//void Worker::work(){

//}
void Worker::printinfo(){
	cout << "Worker:printinfo" << endl;
}