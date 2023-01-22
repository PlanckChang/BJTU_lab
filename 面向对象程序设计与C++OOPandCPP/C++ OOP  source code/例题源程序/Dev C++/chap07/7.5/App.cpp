#include "App.h"

int CApp::run()
{
	double len, w;
	CPlaygraph * p = NULL, *old;
	CPlayground ground;  //使用默认的形参值构造对象
	while (true)
	{
		bool correct = false;
		while (!correct)
		{
			cout << "请输入运动场的类型：1 足球场；2 滑冰场" << endl;
			int choice = 0;
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "请输入足球场的长和宽：";
				cin >> len >> w;
				p = new CRectgraph(len, w);		//构造一个CRectgraph对象
				old = ground.attach_graph(p);	//关联p所指对象
				delete old;		//回收之前所用对象占用的空间
				correct = true;
				break;
			case 2:
				cout << "请输入滑冰场的半径：";
				cin >> len;
				p = new CCirclegraph(len);		//构造一个CCirclegraph对象
				old = ground.attach_graph(p);	//关联p所指对象
				delete old;		//回收之前所用对象占用的空间
				correct = true;
				break;
			default:
				cout << "非法的选择，请重新选择..." << endl;
				cin.clear();
				cin.ignore();
			}
		}
		cout << "造价是：" << ground.compute_cost() << endl;
		cout << "按 e 退出，按其他键继续..." << endl;
		if (_getch() == 'e')
			break;
	}

	return 0;
}
