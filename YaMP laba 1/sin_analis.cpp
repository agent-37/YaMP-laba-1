#include "sin_analis.h"
#include <iostream>
sin_analis::sin_analis() {
	hesh_cell h("nonterminal", "root");
	deque<pair<hesh_cell, int>> l;
	l.push_back(make_pair(h,0));
	vector<pair<hesh_cell, vector<int> > > v;
	vector<int> help;
	v.push_back(make_pair(h, help));
	state.push(make_pair(l, v));
}

int sin_analis::step_anlis(hesh_cell h) {
	mov_to_term();
	queue<pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > > help = state, t;
	pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > current;
	while (help.size() != 0) {
		current = help.front();
		/*
		for (int i = 0; i < current.first.size(); i++)
			cout << current.first[i].first.get_type_leks() << ' ' << current.first[i].first.get_leks() << ' ' << current.first[i].second << '\n';
		cout << '\n';
		*/
		
		help.pop();
		//если тип лексемы не соответствует, то точно пропускаем
		if (current.first.size() == 0) 
			continue;
		if (current.first[0].first.get_type_leks() != h.get_type_leks() ) 
			continue;
		else 
			if (h.get_type_leks() == "number" || h.get_type_leks() == "var") {
				current.second[current.first[0].second].first = h;
				current.first.pop_front();
				t.push(current);
			}
			else {
				if (h.get_leks() == current.first[0].first.get_leks()) {
					current.first.pop_front();
					t.push(current);
				}
				else
					continue;
			}
	}
	if (t.size() == 0)
		return 0;
	state = t;
	return 1;
}

//делает каждое состояние терминалом
void sin_analis::mov_to_term(){
	queue<pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > >  t;
	pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > current,e1,e2;
	while (state.size() != 0) {
		current = state.front();
		state.pop();
		if (current.first.size() == 0) {
			t.push(current);
			continue;
		}
		if (current.first[0].first.get_type_leks() != "nonterminal") {
			t.push(current);
			continue;
		}
		else {
			if (current.first[0].first.get_leks() == "root") {
				int pos = current.first[0].second;
				current.first.pop_front();
				hesh_cell q1("nonterminal","Begin"), q2("nonterminal", "Descriptions"), q3("nonterminal", "Operators"), q4("nonterminal", "End");
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.first.push_front(make_pair(q2, current.second.size() + 2));
				current.first.push_front(make_pair(q1, current.second.size() + 3));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				current.second[pos].second.push_back(current.second.size() + 2);
				current.second[pos].second.push_back(current.second.size() + 3);
				vector<int>help;
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				current.second.push_back(make_pair(q2, help));
				current.second.push_back(make_pair(q1, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "Begin") {
				int pos = current.first[0].second;
				current.first.pop_front();
				hesh_cell  q3("data", "PROGRAM"), q4("var", "-");
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				vector<int>help;
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "End") {
				int pos = current.first[0].second;
				current.first.pop_front();
				hesh_cell  q3("data", "END"), q4("var", "-");
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				vector<int>help;
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "Descriptions") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q3("nonterminal", "Descr"), q4("nonterminal", "Descriptions");
				
				current.first.push_front(make_pair(q3, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q3, help));
				state.push(current);

				current.first.pop_front();
				current.second[pos].second.pop_back();
				current.second.pop_back();
				
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);

				continue;
			}
			if (current.first[0].first.get_leks() == "Operators") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q3("nonterminal", "Op"), q4("nonterminal", "Operators");

				current.first.push_front(make_pair(q3, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q3, help));
				state.push(current);

				current.first.pop_front();
				current.second[pos].second.pop_back();
				current.second.pop_back();

				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);

				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);

				continue;
			}
			if (current.first[0].first.get_leks() == "Descr") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q3("nonterminal", "type"), q4("nonterminal", "VarList");
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "type") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q4("type", "INTEGER"); 
				current.first.push_front(make_pair(q4, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q4, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "VarList") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q2("var", "-"), q3("sign", ","), q4("nonterminal", "VarList");

				current.first.push_front(make_pair(q2, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q2, help));
				state.push(current);

				current.first.pop_front();
				current.second[pos].second.pop_back();
				current.second.pop_back();

				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.first.push_front(make_pair(q2, current.second.size() + 2));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				current.second[pos].second.push_back(current.second.size() + 2);

				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				current.second.push_back(make_pair(q2, help));
				state.push(current);

				continue;
			}
			if (current.first[0].first.get_leks() == "Op") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				e1 = current;
				
				hesh_cell  q2("var", "-"), q3("sign", "="), q4("nonterminal", "Expr");
				hesh_cell  h1("data", "FOR"),h2("var", "-"),h3("sign", "="),
					h4("nonterminal", "Expr"), h5("data", "TO"), h6("nonterminal", "Expr"),
					h7("data", "DO"), h8("nonterminal", "Operators");

				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.first.push_front(make_pair(q2, current.second.size() + 2));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				current.second[pos].second.push_back(current.second.size() + 2);

				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				current.second.push_back(make_pair(q2, help));


				e1.first.push_front(make_pair(h8, e1.second.size()));
				e1.first.push_front(make_pair(h7, e1.second.size() + 1));
				e1.first.push_front(make_pair(h6, e1.second.size() + 2));
				e1.first.push_front(make_pair(h5, e1.second.size() + 3));
				e1.first.push_front(make_pair(h4, e1.second.size() + 4));
				e1.first.push_front(make_pair(h3, e1.second.size() + 5));
				e1.first.push_front(make_pair(h2, e1.second.size() + 6));
				e1.first.push_front(make_pair(h1, e1.second.size() + 7));
				e1.second[pos].second.push_back(e1.second.size());
				e1.second[pos].second.push_back(e1.second.size() + 1);
				e1.second[pos].second.push_back(e1.second.size() + 2);
				e1.second[pos].second.push_back(e1.second.size() + 3);
				e1.second[pos].second.push_back(e1.second.size() + 4);
				e1.second[pos].second.push_back(e1.second.size() + 5);
				e1.second[pos].second.push_back(e1.second.size() + 6);
				e1.second[pos].second.push_back(e1.second.size() + 7);

				e1.second.push_back(make_pair(h8, help));
				e1.second.push_back(make_pair(h7, help));
				e1.second.push_back(make_pair(h6, help));
				e1.second.push_back(make_pair(h5, help));
				e1.second.push_back(make_pair(h4, help));
				e1.second.push_back(make_pair(h3, help));
				e1.second.push_back(make_pair(h2, help));
				e1.second.push_back(make_pair(h1, help));
				state.push(current);
				state.push(e1);
				continue;
			}
			if (current.first[0].first.get_leks() == "SimpleExpr") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				e1 = current;
				e2 = current;
				hesh_cell   q4("var", "-");
				hesh_cell  t4("number", "-");
				hesh_cell  h1("sign", "("), h2("nonterminal", "Expr"), h3("sign", ")");

				current.first.push_front(make_pair(q4, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q4, help));
				
				e2.first.push_front(make_pair(t4, e2.second.size()));
				e2.second[pos].second.push_back(e2.second.size());
				e2.second.push_back(make_pair(t4, help));



				e1.first.push_front(make_pair(h3, e1.second.size()));
				e1.first.push_front(make_pair(h2, e1.second.size() + 1));
				e1.first.push_front(make_pair(h1, e1.second.size() + 2));
				e1.second[pos].second.push_back(e1.second.size());
				e1.second[pos].second.push_back(e1.second.size() + 1);
				e1.second[pos].second.push_back(e1.second.size() + 2);

				e1.second.push_back(make_pair(h3, help));
				e1.second.push_back(make_pair(h2, help));
				e1.second.push_back(make_pair(h1, help));
				state.push(current);
				state.push(e2);
				state.push(e1);
				continue;
			}
			if (current.first[0].first.get_leks() == "Expr") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				e1 = current;
				e2 = current;

				hesh_cell   q4("nonterminal", "SimpleExpr");
				hesh_cell  t1("nonterminal", "SimpleExpr"), t2("sign", "+"), t3("nonterminal", "Expr");
				hesh_cell  h1("nonterminal", "SimpleExpr"), h2("sign", "-"), h3("nonterminal", "Expr");

				current.first.push_front(make_pair(q4, current.second.size()));
				current.second[pos].second.push_back(current.second.size());
				current.second.push_back(make_pair(q4, help));

				e2.first.push_front(make_pair(t3, e2.second.size()));
				e2.first.push_front(make_pair(t2, e2.second.size() + 1));
				e2.first.push_front(make_pair(t1, e2.second.size() + 2));
				e2.second[pos].second.push_back(e2.second.size());
				e2.second[pos].second.push_back(e2.second.size() + 1);
				e2.second[pos].second.push_back(e2.second.size() + 2);

				e2.second.push_back(make_pair(t3, help));
				e2.second.push_back(make_pair(t2, help));
				e2.second.push_back(make_pair(t1, help));



				e1.first.push_front(make_pair(h3, e1.second.size()));
				e1.first.push_front(make_pair(h2, e1.second.size() + 1));
				e1.first.push_front(make_pair(h1, e1.second.size() + 2));
				e1.second[pos].second.push_back(e1.second.size());
				e1.second[pos].second.push_back(e1.second.size() + 1);
				e1.second[pos].second.push_back(e1.second.size() + 2);

				e1.second.push_back(make_pair(h3, help));
				e1.second.push_back(make_pair(h2, help));
				e1.second.push_back(make_pair(h1, help));
				state.push(current);
				state.push(e2);
				state.push(e1);
				continue;
			}
		}		
	}
	state = t;
}

void sin_analis::rek_print(ofstream& fout, vector<pair<hesh_cell, vector<int> > > vec, int i, int tab) {
	tab++;
	for (int j = 0; j < vec[i].second.size(); j++) 
		rek_print(fout,vec, vec[i].second[j], tab);
	for (int j = 0; j < tab; j++)
		fout << "                    ";
	fout << vec[i].first.get_type_leks() << '-' << vec[i].first.get_leks() << '\n';
}

//печатает дерево
void sin_analis::write_tree(ofstream& fout) {
	queue<pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > > help = state;
	pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > current;
	while (help.size() != 0) {
		if (help.front().first.size() == 0) {
			current = help.front();
			break;
		}
		help.pop();
	}
	if (help.size() == 0)
		return;
	rek_print(fout, current.second, 0, -1);
}