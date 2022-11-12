#ifndef _SIN_ANALIS_H_
#define _SIN_ANALIS_H_
#include <queue>
#include <vector>
#include <deque>
#include "lexical_analysis.h"

class sin_analis {
private:
	queue<pair<deque<pair<hesh_cell,int>>,vector<pair<hesh_cell, vector<int> > > > >  state;
public:
	//����������� ������ ������� ������ 
	sin_analis();
	//�� ������� ������ ������ ��������� ��������
	int step_anlis( hesh_cell h);
private:
	//������ ������ ��������� ����������
	void mov_to_term();

};

#endif // _SIN_ANALIS_H_