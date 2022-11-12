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
	sin_analis q;
	hesh_cell r("abc");
	q.step_anlis(r);
	/*while (fin >> s1) {
		hesh_cell t1(s1);
		if (t1.get_b_hesh() == 0)
			h.add(t1);
		else
			fout <<"Find bad lexem "<<s1<<'\n';
	}
	h.print(fout);*/
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