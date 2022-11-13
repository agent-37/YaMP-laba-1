#include <iostream>
#include <fstream>
#include <string>
#include "hesh.h"
#include "sin_analis.h"
using namespace std;
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s1;
	hesh h;		
	sin_analis s_analis;
	while (fin >> s1) {
		hesh_cell t1(s1);
		if (t1.get_b_hesh() == 0) {
			h.add(t1);
			//cout << "+++++++++++++++++++++++++++++++++\n";
			 s_analis.step_anlis(t1);// << ' ' << t1.get_type_leks() << ' ' << t1.get_leks() << '\n';
		}
		else
			fout <<"Find bad lexem "<<s1<<'\n';
	}
	s_analis.write_tree(fout);
	//h.print(fout);
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