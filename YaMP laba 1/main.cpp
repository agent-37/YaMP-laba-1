#include <iostream>
#include "hesh.h"
using namespace std;
int main() {
	hesh h;
	string s1,s2;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		hesh_cell c(s1, s2);
		h.add(c);
	}
	h.print("output.txt");

}
/*
4
123 tr
123 tr
weq wrwer
hgsf sdgas
*/