#include "hesh.h"

string  hesh_cell:: get_type_leks() {
	return t.first;
}
string hesh_cell::get_leks() {
	return t.second;
}
 ostream& operator << (ostream& os, hesh_cell& cell) {
	os << cell.get_type_leks() << ' ' << cell.get_leks() << '\n';
	return os;
}
 bool operator ==(const hesh_cell& c1, const hesh_cell& c2) {
	 if (c1.t.first == c2.t.first && c1.t.second == c2.t.second)
		 return true;
	 return false;
 }

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
 void	hesh::print(string out){
	 int count = 0;
	 ofstream fout(out);
	 for (int i = 0; i < SIZE_MATRIX_HESH; i++) {
		 count += size_cell[i];		 
		 l[i].print(fout, count);
	 }
 }
 
 bool hesh::find(int number, hesh_cell cell) {
	 return l[number].find(cell);
 }