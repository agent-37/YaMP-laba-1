#include <iostream>
#include <fstream>
#include <string>
#include "hesh.h"
using namespace std;
int main() {
	string s1;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	hesh h;		
	while (fin >> s1) {
		hesh_cell t1(s1);
		if (t1.get_b_hesh() == 0)
			h.add(t1);
		else
			fout <<"Find bad lexem "<<s1<<'\n';
	}
	h.print(fout);
}
/*

8
INTEGER
FOR
DO
END
PROGRAM
PROGRAM)
asdgsdfd
(

*/