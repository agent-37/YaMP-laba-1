#ifndef _LEXICAL_ANALYSIS_H_
#define _LEXICAL_ANALYSIS_H_
#include <iostream>
#include <string> 
#include "list.h"
class hesh_cell {
private:
	pair<string, string > t;
	//�������� �� �� ������ ������� ��� ��� ( "a123"- ������)
	bool b_hesh;
public:
	//�����������
	hesh_cell(string s1, string s2) {
		t.first = s1;
		t.second = s2;
		b_hesh = 0;
	}
	hesh_cell(string s1) {
		b_hesh = 0;
		identify(s1);
	}
	//�������
	string  get_type_leks();
	string  get_leks();
	bool  get_b_hesh();
	//��������������� ���������� ������ � ���������
	friend ostream& operator << (ostream& os, hesh_cell& cell);
	friend bool operator ==(const hesh_cell& c1, const hesh_cell& c2);
	void identify(string s1);
private:
	void t0(string s1, int i, bool &bad_hesh);
	void t1(string s1, int i, bool &bad_hesh);
	void t2(string s1, int i, bool &bad_hesh);
	void t3(string s1, int i, bool &bad_hesh);
	void t4(string s1, int i, bool &bad_hesh);
	void t5(string s1, int i, bool &bad_hesh);
	void t6(string s1, int i, bool &bad_hesh);
	void t7(string s1, int i, bool &bad_hesh);
	void t8(string s1, int i, bool &bad_hesh);
	void t9(string s1, int i, bool &bad_hesh);
	void t10(string s1, int i, bool &bad_hesh);
	void t11(string s1, int i, bool &bad_hesh);
	void t12(string s1, int i, bool &bad_hesh);
	void t13(string s1, int i, bool &bad_hesh);
	void t14(string s1, int i, bool &bad_hesh);
	void t15(string s1, int i, bool &bad_hesh);
	void t16(string s1, int i, bool &bad_hesh);
	void t17(string s1, int i, bool &bad_hesh);
	void t18(string s1, int i, bool &bad_hesh);	
	void var(string s1, int i, bool &bad_hesh);
	void data(string s1, int i, bool &bad_hesh);
	void num(string s1, int i, bool &bad_hesh);
	void sign(string s1, int i, bool &bad_hesh);
	void dv(string s1, int i, bool &bad_hesh);
	void integer(string s1, int i, bool &bad_hesh);

};

#endif // _LEXICAL_ANALYSIS_H_