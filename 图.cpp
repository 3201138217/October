#include <iostream>
#include<queue>
using namespace std;

const int Maxsize = 10;
bool visited[Maxsize] = { false };
class MGraph
{
public:
	MGraph(int a[], int n, int e);//nΪ��������eΪ����
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
	for (int i = 0; i < vertexNum; i++)//���ж����ϵ��0
	{
		for (int j = 0; j < vertexNum; j++)
		{
			arc[i][j] = 0;
		}
	}
	for (int k = 0; k < arcNum; k++)
	{
		cout << "���������������������ı��" << endl;
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
	queue<int> Q;//����

	cout << vertex[v];

	 visited1[v] = 1;
	Q.push(v);//���
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
	cout << "�����붥�����" << endl;	cin >> n;	

	cout << "������ߵ�����" << endl;	cin >> e;

	
	MGraph* T;
	T = new MGraph(a,n,e);

	cout << "������ȱ������"; T->BFSTraverse(a[0]);cout << endl;
	cout << "������ȱ������"; T->DFSTraverse(a[0]);cout << endl;

	delete T;
	system("pause");
	return 0;
}