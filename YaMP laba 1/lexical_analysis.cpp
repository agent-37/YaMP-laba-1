#include "lexical_analysis.h"
#include <iostream>
#include <string> 

string  hesh_cell::get_type_leks() {
	return t.first;
}
string hesh_cell::get_leks() {
	return t.second;
}

ostream& operator << (ostream& os, hesh_cell& cell) {
	os << cell.get_type_leks() << ' ' << cell.get_leks() << '\n';
	return os;
}
bool operator ==(const hesh_cell& c1, const hesh_cell& c2) {
	if (c1.t.first == c2.t.first && c1.t.second == c2.t.second)
		return true;
	return false;
}
void hesh_cell::identify(string s1) {
	t0(s1, 0);
}
//сделать цикл в number и var 
//вопрос если мы пропускаем некоторые багованные символы то в конечной строке они должны быть или мы их  с концами убираем
//сделать пропуск плохих символов, но какой пропуск?
void hesh_cell::t0(string s1, int i) {

}
void hesh_cell::t1(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'R') {
		t2(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t2(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'O') {
		t3(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t3(string s1, int i){
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'G') {
		t4(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t4(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'R') {
		t5(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t5(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'A') {
		t6(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t6(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'M') {
		dv(s1, i + 1);
		return;
	}
	var(s1);

}
void hesh_cell::t7(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'O') {
		dv(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t8(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'O') {
		dv(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t9(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'E') {
		t9(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t10(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'D') {
		dv(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t11(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if (s1[i] == 'O') {
		t11(s1, i + 1);
		return;
	}
	var(s1);
}
void hesh_cell::t12(string s1, int i) {
	if (s1.size() == i) {
		var(s1);
		return;
	}
	if(s1[i]=='R'){
		dv(s1, i + 1);
		return;
    }
	var(s1);
}
void hesh_cell::var(string s1) {
	t.first = "var";
	t.second = s1;
}
void hesh_cell::data(string s1) {
	t.first = "data";
	t.second = s1;
}
void hesh_cell::number(string s1) {
	t.first = "number";
	t.second = s1;
}
void hesh_cell::sign(string s1) {
	t.first = "sign";
	t.second = s1;
}
void hesh_cell::dv(string s1, int i) {
	if (s1.size() == i) {
		data(s1);
		return;
	}
	var(s1);
}