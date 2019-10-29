#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person {
     public:
		  Person(string name);
		  ~Person();
		  virtual void work() =  0 ; //纯虚函数不需要实现
		 // virtual void printinfo() =  0 ;
     private:
		 string m_strName;
};

#endif 