#include <iostream>
#include<queue>
using namespace std;

const int Maxsize = 10;
bool visited[Maxsize] = { false };
class MGraph
{
public:
	MGraph(int a[], int n, int e);//n为顶点数，e为边数
	~MGraph(){}
	void DFSTraverse(int v);
	void BFSTraverse(int v);
private:
	int vertex[Maxsize];
	int arc[Maxsize][Maxsize];
	int vertexNum, arcNum;
};


MGraph::MGraph(int a[], int n, int e)
{
	vertexNum = n;
	arcNum = e;
	for (int i = 0; i < vertexNum; i++)
	{
		vertex[i] = a[i];
	}
	for (int i = 0; i < vertexNum; i++)//所有顶点关系置0
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for (int k = 0; k < arcNum; k++)
	{
		cout << "请输入边依附的两个顶点的编号" << endl;
		int p, q;
		cin >> p >> q;
		arc[p][q] = 1;
		arc[q][p] = 1;
	}
	

	for (int i = 0; i < vertexNum; i++)
	{
		cout << vertex[i] << "  ";
	}
	cout << endl << endl;

	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << arc[i][j] <<" ";
		}
		cout << endl;
	}
}

int visited1[Maxsize] = { 0 };
void MGraph::BFSTraverse(int v)
{
	queue<int> Q;//对列

	cout << vertex[v];

	 visited1[v] = 1;
	Q.push(v);//入队
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();

		for (int j = 0; j < vertexNum; j++)
		{
			if (arc[v][j] == 1 && visited1[j] == 0)
			{
				cout << vertex[j];
				visited1[j] =1;
			
				Q.push(j);
			}
		}
		
	}
	
}




void MGraph::DFSTraverse(int v)
{
	cout << vertex[v] ;
	visited[v] = true;
	for (int j = 0; j < vertexNum; j++)
	{
		if (arc[v][j] == 1 && visited[j] == false)
		{
			DFSTraverse(j);
		}
	}
}


int main()
{
	int a[Maxsize] = { 0,1,2,3,4,5,6,7,8,9 }; int n; int e;
	cout << "请输入顶点个数" << endl;	cin >> n;	

	cout << "请输入边的条数" << endl;	cin >> e;

	
	MGraph* T;
	T = new MGraph(a,n,e);

	cout << "广度优先遍历结果"; T->BFSTraverse(a[0]);cout << endl;
	cout << "深度优先遍历结果"; T->DFSTraverse(a[0]);cout << endl;

	delete T;
	system("pause");
	return 0;
}