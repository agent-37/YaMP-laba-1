#include "lexical_analysis.h"
#include <iostream>
#include <string> 
const string variable = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", number = "0123456789", signs = ",+-()=";
string  hesh_cell::get_type_leks() {
	return t.first;
}
string hesh_cell::get_leks() {
	return t.second;
}
bool  hesh_cell::get_b_hesh() {
	return b_hesh;
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
	t0(s1, 0,0);
}

void hesh_cell::delete_sign(string &s1, int i){
	s1 = s1.substr(0, i) + s1.substr(i+1,s1.size());
}

void  hesh_cell::t0(string s1, int i, bool bad_hesh){
	if (signs.find(s1[i]) == -1 && number.find(s1[i]) == -1 && variable.find(s1[i]) == -1) {
		delete_sign(s1, i);
		bad_hesh = 1;
		t0(s1, i, bad_hesh);
		return;
	}
	if (signs.find(s1[i]) != -1) {
		sign(s1, i + 1, bad_hesh);
		return;
	}
	if (number.find(s1[i]) != -1) {
		num(s1, i + 1, bad_hesh);
		return;
	}
	if (s1[i] == 'P') {
		t1(s1, i + 1, bad_hesh);
		return;
	}
	if (s1[i] == 'T') {
		t7(s1, i + 1, bad_hesh);
		return;
	}
	if (s1[i] == 'D') {
		t8(s1, i + 1, bad_hesh);
		return;
	}
	if (s1[i] == 'E') {
		t9(s1, i + 1, bad_hesh);
		return;
	}
	if (s1[i] == 'F') {
		t11(s1, i + 1, bad_hesh);
		return;
	}

	var(s1, i + 1, bad_hesh);

}
void  hesh_cell::t1(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t1(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'R')
			t2(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t2(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t2(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'O')
			t3(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t3(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t3(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'G')
			t4(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t4(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t4(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'R')
			t5(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t5(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t5(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'A')
			t6(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t6(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t6(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'M')
			dv(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t7(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t7(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'O')
			dv(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t8(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t8(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'O')
			dv(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t9(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t9(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'N')
			t10(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t10(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t10(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'D')
			dv(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t11(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t11(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'O')
			t12(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}
}
void  hesh_cell::t12(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		var(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) == -1)
	{
		delete_sign(s1, i);
		bad_hesh = 1;
		t12(s1, i, bad_hesh);
	}
	else {
		if (s1[i] == 'R')
			dv(s1, i + 1, bad_hesh);
		else
			var(s1, i + 1, bad_hesh);
	}

}
void  hesh_cell::dv(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		data(s1, i, bad_hesh);
		return;
	}
	if (variable.find(s1[i]) != -1)
		var(s1, i + 1, bad_hesh);
	else {
		delete_sign(s1, i);
		bad_hesh = 1;
		dv(s1, i, bad_hesh);
	}
}
void  hesh_cell::var(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		t.first = "var";
		t.second = s1;
		b_hesh = bad_hesh;
		return;
	}
	if (variable.find(s1[i]) != -1)
		var(s1, i + 1, bad_hesh);
	else {
		delete_sign(s1, i);
		bad_hesh = 1;
		var(s1, i, bad_hesh);
	}

}
void  hesh_cell::data(string s1, int i, bool bad_hesh){
	t.first = "data";
	t.second = s1;
	b_hesh = bad_hesh;
}
void  hesh_cell::num(string s1, int i, bool bad_hesh){
	if (s1.size() == i) {
		t.first = "number";
		t.second = s1;
		b_hesh = bad_hesh;
		return;
	}
	if (number.find(s1[i]) != -1) 
		num(s1, i + 1, bad_hesh);	
	else {
		delete_sign(s1, i);
		bad_hesh = 1;
		num(s1, i , bad_hesh);
	}
}
void  hesh_cell::sign(string s1, int i, bool bad_hesh) {
	if (s1.size() == i) {
		t.first = "sign";
		t.second = s1;
		b_hesh = bad_hesh;
	}
	delete_sign(s1, i);
	bad_hesh = 1;

	sign(s1, i, bad_hesh);
}
