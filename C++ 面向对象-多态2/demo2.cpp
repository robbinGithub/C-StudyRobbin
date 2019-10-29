#include <iostream>
#include <stdlib.h>
#include "Person.h"
#include "Dustman.h"
using namespace std;

int main(void){
	//Person person("robbin");29
	Dustman dustman("robbin", 22);
	dustman.work();
	system("pause");
	return 0;

}