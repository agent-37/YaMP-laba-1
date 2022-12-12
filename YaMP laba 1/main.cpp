#include <iostream>
#include <fstream>
#include <string>
#include "hesh.h"
#include "sin_analis.h"
#include "polis.h"
using namespace std;

bool read_s(ifstream &fin,string &s1,bool fl,int &i, int &j){ 
	bool flag = 0;
	char ch;
	string s;
	while (fin.get(ch)) {
		if (ch == EOF) {
			i++;
			break;
		}
		if (flag == 0) {
			if (ch == ' ' || ch == '\n') 
				if (ch == ' ') 
					i++;				
				else {
					i = 0;
					j++;
				}			
			else {
				i++;
				s += ch;
				flag = 1;
			}
		}
		else 
			if (ch == ' ' || ch == '\n') {	
				i++;
				if (ch == '\n') 
					fl = 1;
				break;
			}
			else {
				i++;
				s += ch;
			}
		
	}
	s1 = s;
	return flag;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string s1;
	hesh h;		
	sin_analis s_analis;
	int i = 0, j = 1;
	bool flag = 0;
	while (!fin.eof() && read_s(fin,s1,flag,i,j)) {
		hesh_cell t1(s1);
		if (t1.get_b_hesh() == 0) {
			h.add(t1);			
			if (s_analis.step_anlis(t1) == 0) {
				fout << "Found unexpected element " << i - s1.size() << ':' << j << '\n';
				return 0;
			}
		}
		else {
			fout << "Found bad lexem " << i - s1.size() << ':' << j << '\n';
			return 0;
		}
		if (flag == 1) {
			flag = 0;
			i = 0;
			j++;
		}
	}
	vector<pair<hesh_cell, vector<int> > > q12;
	s_analis.write_tree(fout,q12);
	polis po(q12);
	po.write(fout);
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