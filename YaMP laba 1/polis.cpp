#include "polis.h"

void polis::private_build_polis(vector<pair<hesh_cell, vector<int> > > &v) {
	
	if (v[0].second.size() != 4 || v.size()==1)
	{
		err.push_back("tree is not full");
		return;
	}
	begin(v,4 );
	descriptions(v,3 );
	operators(v, 2);
	end(v, 1);

}
void polis::begin(vector<pair<hesh_cell, vector<int> > >& v, int q) {
	name_file = v[v[q].second[0]].first.get_leks();
	ans.push_back("program");
	ans.push_back(name_file);
	ans.push_back("2");
	ans.push_back("assign");
}
void polis::descriptions(vector<pair<hesh_cell, vector<int> > >& v, int q) {
	if (v[q].second.size() == 1) 
		descr(v, v[q].second[0]);	
	else {
		descr(v, v[q].second[1]);
		descriptions(v, v[q].second[0]);
	}
}
void polis::operators(vector<pair<hesh_cell, vector<int> > >& v, int q) {
	if (v[q].second.size() == 2) {
		op(v,v[q].second[1]);
		operators(v, v[q].second[0]);
	}
	else 
		op(v, v[q].second[0]);
}
void polis::end(vector<pair<hesh_cell, vector<int> > >& v, int q) {
	if (name_file != v[v[q].second[0]].first.get_leks()) {
		err.push_back("program and end don't match");
		return;
	}
	else {
		ans.push_back("end");
		ans.push_back(name_file);
		ans.push_back("2");
		ans.push_back("assign");
	}
}
void polis::descr(vector<pair<hesh_cell, vector<int> > >& v, int q) {
	int count = 0;
	ans.push_back("INTEGER");
	varlist(v,v[q].second[0], count);
	ans.push_back(to_string(count+1));
	ans.push_back("assign");
}
void polis::varlist(vector<pair<hesh_cell, vector<int> > >& v, int q, int& count1)	 {
	count1++;
	if (v[q].second.size() == 3) {
		ans.push_back(v[v[q].second[2]].first.get_leks());
		varlist(v, v[q].second[0], count1);
		hesh_cell cell("var", v[v[q].second[2]].first.get_leks());
		var.add(cell);
	}
	else {
		ans.push_back(v[v[q].second[0]].first.get_leks());
		hesh_cell cell("var", v[v[q].second[0]].first.get_leks());
		var.add(cell);
	}
}
void polis::simple_expr(vector<pair<hesh_cell, vector<int> > >& v, int q){
	if (v[q].second.size() == 1) {
		if (v[v[q].second[0]].first.get_type_leks() == "number")
			ans.push_back(v[v[q].second[0]].first.get_leks());
		else {
			string s = v[q].first.get_leks();
			if (!var.find(var.hesh_func(v[v[q].second[0]].first.get_leks()), v[v[q].second[0]].first))
				err.push_back("undeclared variable " + v[v[q].second[0]].first.get_leks());
			ans.push_back(v[q].first.get_leks());
		}
	}
	else 
		expr(v,v[q].second[1]);
}
void polis::expr(vector<pair<hesh_cell, vector<int> > >& v, int q){
	if (v[q].second.size() == 3) {
		simple_expr(v, v[q].second[2]);
		expr(v, v[q].second[0]);
		ans.push_back(v[v[q].second[1]].first.get_leks());
	}
	else 
		simple_expr(v, v[q].second[0]);
	
}
void polis::op(vector<pair<hesh_cell, vector<int> > >& v, int q){
	
	if (v[q].second.size() == 3) {
		ans.push_back(v[v[q].second[2]].first.get_leks());
		expr(v,v[q].second[0]);	
		ans.push_back(v[v[q].second[1]].first.get_leks());
	}
	else {
		string m1 = "m" + to_string(count + 1), m2 = "m" + to_string(count + 2);
		count += 2;

		if (!var.find(var.hesh_func(v[v[q].second[6]].first.get_leks()), v[v[q].second[6]].first))
			err.push_back("undeclared variable " + v[v[q].second[6]].first.get_leks());


		ans.push_back(v[v[q].second[6]].first.get_leks());
		expr(v,v[q].second[4]);
		ans.push_back(v[v[q].second[5]].first.get_leks());
		
		ans.push_back(m1);
		ans.push_back("put_label");

		ans.push_back(v[v[q].second[6]].first.get_leks());
		expr(v, v[q].second[2]);
		ans.push_back("<");

		ans.push_back(m2);
		ans.push_back("if_false_jump_to");

		operators(v, v[q].second[0]);

		ans.push_back(v[v[q].second[6]].first.get_leks());
		ans.push_back(v[v[q].second[6]].first.get_leks());
		ans.push_back("1");
		ans.push_back("+");
		ans.push_back("=");
		ans.push_back(m1);
		ans.push_back("jump_to");

		ans.push_back(m2);
		ans.push_back("put_label");

	}

}
void polis::write(ofstream& fout) {
	for (int i = 0; i < err.size(); i++)
		fout << err[i] << '\n';
	if(err.size()==0)
	for (int i = 0; i < ans.size(); i++)
		fout << ans[i] << ' ';
}