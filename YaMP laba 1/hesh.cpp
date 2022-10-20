#include "hesh.h"

 int hesh::hesh_func(string s) {
	 int res = 0;
	 for (int i = 0; i < s.size(); i++)
		 res = (res * BASIS_OF_DEGREE + (int)s[i]) % SIZE_MATRIX_HESH;
	 return res;
 }
 void hesh::add(hesh_cell cell) {
	 int number = hesh_func(cell.get_leks());
	 if (!find(number, cell)) {
		 l[number].add_back(cell);
		 size_cell[number]++;
	 }
 }
 void	hesh::print(ofstream& fout){
	 int count = 0;
	for (int i = 0; i < SIZE_MATRIX_HESH; i++) {
		 count += size_cell[i];		 
		 l[i].print(fout, count);
	}
 } 
 bool hesh::find(int number, hesh_cell cell) {
	 return l[number].find(cell);
 }