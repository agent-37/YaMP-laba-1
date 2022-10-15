#include <iostream>
#include <string>
#include "hesh.h"
using namespace std;
int main() {
	string s1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1;
		hesh_cell t1(s1);
		cout << t1.get_b_hesh() << '\n';
	}
}
/*

8
123
adf
FOR
END
PROGRAM
PROGRAM)
)
(

*/