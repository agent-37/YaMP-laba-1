#include <iostream>
#include <string>
#include "hesh.h"
using namespace std;
int main() {
	string s1,s2;
	int n;
	cin >> n;
	hesh h;
	for (int i = 0; i < n; i++) {
		cin >> s1;
		s2 = s1;
		hesh_cell t1(s1);
		if (t1.get_b_hesh() == 0) 
			h.add(t1);		
	}
	h.print("out.txt");
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