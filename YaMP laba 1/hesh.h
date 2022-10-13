#ifndef _HESH_H_
#define _HESH_H_
#include <iostream>
#include <string> 
#include "list.h"
#define SIZE_MATRIX_HESH 1000003
#define   BASIS_OF_DEGREE 521
using namespace std;

class hesh_cell {
private:
	pair<string, string > t;
public:
	string  get_type_leks() {
		return t.first;
	}
	string  get_leks() {
		return t.second;
	}
	friend ostream& operator << (ostream& os,  hesh_cell& cell) {
		os << cell.get_type_leks() << ' ' << cell.get_leks()<<'\n';
		return os;
	}
};

class hesh {
private:
	list<hesh_cell> l[SIZE_MATRIX_HESH];
	int size_cell[SIZE_MATRIX_HESH];
	hesh() {
		for (int i = 0; i < SIZE_MATRIX_HESH; i++)
			size_cell[i] = 0;
	}
public:
	void add();
	void print();
private:
	void find();
	int hesh_func(string s);

	
};

#endif // _HESH_H_