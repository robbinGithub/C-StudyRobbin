#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;
class Person {
     public:
		  Person(string name);
		  ~Person();
		  virtual void work() =  0 ; //���麯������Ҫʵ��
		 // virtual void printinfo() =  0 ;
     private:
		 string m_strName;
};

#endif 