#ifndef _POLIS_H_
#define _POLIS_H_
#include <string>
#include <vector>
#include "hesh.h"
class polis {
private:
	string name_file;
	int count;
	vector<string> ans;
	vector <string> err;
	hesh var;
public:
	polis() {
		name_file = "";
		count = 0;
	}
	polis(vector<pair<hesh_cell, vector<int> > > v) {
		build_polis(v);
	}
	void build_polis(vector<pair<hesh_cell, vector<int> > > v) {
		private_build_polis(v);
	}
	void write(ofstream& fout);
private:
	void private_build_polis(vector<pair<hesh_cell, vector<int> > > &v);
	void begin(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void descriptions(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void operators(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void end(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void descr(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void varlist(vector<pair<hesh_cell, vector<int> > >& v, int q, int& count);
	void simple_expr(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void expr(vector<pair<hesh_cell, vector<int> > >& v, int q);
	void op(vector<pair<hesh_cell, vector<int> > >& v, int q);

};
#endif // _POLIS_H_