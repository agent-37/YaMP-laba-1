#include <iostream>
#include <fstream>
#include <string>
#include "hesh.h"
#include "sin_analis.h"
using namespace std;

bool read_s(ifstream &fin,string &s1,int &i, int &j){ 
	bool flag = 0;
	char ch;
	string s;
	while (fin.get(ch)) {
		if (ch == EOF)
			break;
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
				if (ch == ' ') 
					i++;
				else {
					i = 0;
					j++;
				}
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
	while (!fin.eof() && read_s(fin,s1,i,j)) {
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