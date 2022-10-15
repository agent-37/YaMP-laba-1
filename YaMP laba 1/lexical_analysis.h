#ifndef _LEXICAL_ANALYSIS_H_
#define _LEXICAL_ANALYSIS_H_
#include <iostream>
#include <string> 
#include "list.h"
class hesh_cell {
private:
	pair<string, string > t;
	//отвечает за то плохая лексема или нет ( "a123"- плохая)
	bool b_hesh;
public:
	//конструктор
	hesh_cell(string s1, string s2) {
		t.first = s1;
		t.second = s2;
		b_hesh = 0;
	}
	hesh_cell(string s1) {
		identify(s1);
	}
	//геттеры
	string  get_type_leks();
	string  get_leks();
	bool  get_b_hesh();
	//переопределение операторов вывода и равенства
	friend ostream& operator << (ostream& os, hesh_cell& cell);
	friend bool operator ==(const hesh_cell& c1, const hesh_cell& c2);
	void identify(string s1);
private:
	void t0(string s1, int i, bool bad_hesh);
	void t1(string s1, int i, bool bad_hesh);
	void t2(string s1, int i, bool bad_hesh);
	void t3(string s1, int i, bool bad_hesh);
	void t4(string s1, int i, bool bad_hesh);
	void t5(string s1, int i, bool bad_hesh);
	void t6(string s1, int i, bool bad_hesh);
	void t7(string s1, int i, bool bad_hesh);
	void t8(string s1, int i, bool bad_hesh);
	void t9(string s1, int i, bool bad_hesh);
	void t10(string s1, int i, bool bad_hesh);
	void t11(string s1, int i, bool bad_hesh);
	void t12(string s1, int i, bool bad_hesh);
	void var(string s1, int i, bool bad_hesh);
	void data(string s1, int i, bool bad_hesh);
	void num(string s1, int i, bool bad_hesh);
	void sign(string s1, int i, bool bad_hesh);
	void dv(string s1, int i, bool bad_hesh);
	void delete_sign(string &s1, int i);
};

#endif // _L	EXICAL_ANALYSIS_H_