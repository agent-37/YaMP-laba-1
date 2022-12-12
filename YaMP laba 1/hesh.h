#ifndef _HESH_H_
#define _HESH_H_
#include <iostream>
#include <string> 
#include "list.h"
#include "lexical_analysis.h"
#define SIZE_MATRIX_HESH 10003
#define   BASIS_OF_DEGREE 521
using namespace std;


//хеш с коррелиацией 
class hesh {
private:
	list<hesh_cell> l[SIZE_MATRIX_HESH];
	int size_cell[SIZE_MATRIX_HESH];	
public:
	int hesh_func(string s);
	hesh() {
		for (int i = 0; i < SIZE_MATRIX_HESH; i++)
			size_cell[i] = 1;
	}
	//добавление в хеш
	void add(hesh_cell cell);
	//печать хеша
	void print(ofstream& fout);
	//проверяет есть ли элемент в хеше
	bool find(int number, hesh_cell cell);
};

#endif // _HESH_H_