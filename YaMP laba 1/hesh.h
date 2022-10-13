#ifndef _HESH_H_
#define _HESH_H_
#include <iostream>
#include <string> 
#include "list.h"
#define SIZE_MATRIX_HESH 10003
#define   BASIS_OF_DEGREE 521
using namespace std;

class hesh_cell {
private:
	pair<string, string > t;
public:
	hesh_cell( string s1,string s2) {
		t.first = s1;
		t.second = s2;
	}
	string  get_type_leks();
	string  get_leks();
	friend ostream& operator << (ostream& os, hesh_cell& cell);
	friend bool operator ==(const hesh_cell& c1, const hesh_cell& c2);
};

class hesh {
private:
	list<hesh_cell> l[SIZE_MATRIX_HESH];
	int size_cell[SIZE_MATRIX_HESH];
	int hesh_func(string s);	
public:
	hesh() {
		for (int i = 0; i < SIZE_MATRIX_HESH; i++)
			size_cell[i] = 1;
	}
	void add(hesh_cell cell);
	void print(string out);	
	bool find(int number, hesh_cell cell);
};

#endif // _HESH_H_