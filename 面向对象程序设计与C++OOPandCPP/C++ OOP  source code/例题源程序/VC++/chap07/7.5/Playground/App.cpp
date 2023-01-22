#include "App.h"

int CApp::run()
{
	double len, w;
	CPlaygraph * p = NULL, *old;
	CPlayground ground;  //ʹ��Ĭ�ϵ��β�ֵ�������
	while (true)
	{
		bool correct = false;
		while (!correct)
		{
			cout << "�������˶��������ͣ�1 ���򳡣�2 ������" << endl;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "���������򳡵ĳ��Ϳ�";
				cin >> len >> w;
				p = new CRectgraph(len, w);		//����һ��CRectgraph����
				old = ground.attach_graph(p);	//����p��ָ����
				delete old;		//����֮ǰ���ö���ռ�õĿռ�
				correct = true;
				break;
			case 2:
				cout << "�����뻬�����İ뾶��";
				cin >> len;
				p = new CCirclegraph(len);		//����һ��CCirclegraph����
				old = ground.attach_graph(p);	//����p��ָ����
				delete old;		//����֮ǰ���ö���ռ�õĿռ�
				correct = true;
				break;
			default:
				cout << "�Ƿ���ѡ��������ѡ��..." << endl;
				cin.clear();
				cin.ignore();
			}
		}
		cout << "����ǣ�" << ground.compute_cost() << endl;
		cout << "�� e �˳���������������..." << endl;
		if (_getch() == 'e')
			break;
	}

	return 0;
}
