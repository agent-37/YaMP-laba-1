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
		help.pop();
		//если тип лексемы не соответствует, то точно пропускаем
		if (current.first.size() == 0) 
			continue;
		if (current.first[0].first.get_type_leks() != h.get_type_leks() ) 
			continue;
		else 
			if (h.get_type_leks() == "number" || h.get_type_leks() == "var") {
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
	pair<deque<pair<hesh_cell, int>>, vector<pair<hesh_cell, vector<int> > > > current;
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
				hesh_cell  q3("nonterminal", "Type"), q4("nonterminal", "VarList");
				current.first.push_front(make_pair(q4, current.second.size()));
				current.first.push_front(make_pair(q3, current.second.size() + 1));
				current.second[pos].second.push_back(current.second.size());
				current.second[pos].second.push_back(current.second.size() + 1);
				current.second.push_back(make_pair(q4, help));
				current.second.push_back(make_pair(q3, help));
				state.push(current);
				continue;
			}
			if (current.first[0].first.get_leks() == "Type") {
				int pos = current.first[0].second;
				vector<int>help;
				current.first.pop_front();
				hesh_cell  q4("Type", "INTEGER");
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

		}		
	}
	state = t;
}