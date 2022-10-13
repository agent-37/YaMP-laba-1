#ifndef _HESH_H_
#define _HESH_H_
#include <iostream>
#include <string> 
#include "list.h"
#define SIZE_MATRIX_HESH 1000003
#define   BASIS_OF_DEGREE 521

using namespace std;
class hesh {
private:
	list<pair<string, string>> l[SIZE_MATRIX_HESH];
public:
	void add();
	void print();
private:
	void find();
	int hesh_func(string s);

	
};

#endif // _HESH_H_