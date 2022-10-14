#ifndef _LEXICAL_ANALYSIS_H_
#define _LEXICAL_ANALYSIS_H_
#include <iostream>
#include <string> 
#include "list.h"
class hesh_cell {
private:
	pair<string, string > t;
public:
	//конструктор
	hesh_cell(string s1, string s2) {
		t.first = s1;
		t.second = s2;
	}
	hesh_cell(string s1) {
		identify(s1);
	}
	//геттеры
	string  get_type_leks();
	string  get_leks();
	//переопределение операторов вывода и равенства
	friend ostream& operator << (ostream& os, hesh_cell& cell);
	friend bool operator ==(const hesh_cell& c1, const hesh_cell& c2);
	void identify(string s1);
private:
	void t0(string s1, int i);
	void t1(string s1, int i);
	void t2(string s1, int i);
	void t3(string s1, int i);
	void t4(string s1, int i);
	void t5(string s1, int i);
	void t6(string s1, int i);
	void t7(string s1, int i);
	void t8(string s1, int i);
	void t9(string s1, int i);
	void t10(string s1, int i);
	void t11(string s1, int i);
	void t12(string s1, int i);
	void var(string s1);
	void data(string s1);
	void number(string s1);
	void sign(string s1);
	void dv(string s1, int i);
};

#endif // _L	EXICAL_ANALYSIS_H_