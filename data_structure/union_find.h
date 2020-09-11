#pragma once
#include<math.h>

class UinonSet
{
public:
	UinonSet(int *a,int size):parent(a),size(size){}
	int find(int x);
	void union_(int x1, int x2);

private:
	int *parent;
	int size;
};

int UinonSet::find(int x)
{
	while (parent[x] >= 0)
	{
		parent[x] = parent[parent[x]];//����ѹ��
		x = parent[x];
	}
	return x;

	/*if (parent[x] < 0)	//��ȫѹ����α�ݹ飩
		return x;
	else
		return parent[x] = find(parent[x]);*/
}

void UinonSet::union_(int x1, int x2)
{
	int parent1 = find(x1);
	int parent2 = find(x2);
	//if (abs(parent[parent1]) > abs(parent[parent2]))//���߶Ⱥϲ�
	//	parent[parent2] = parent1;//�Ѹ߶�С�����ӵ��������
	//else
	//{
	//	if (abs(parent[parent1]) == abs(parent[parent2]))
	//		parent[parent2]--;//���ĸ߶�+1
	//	parent[parent1] = parent2;
	//}
	if (abs(parent[parent1]) > abs(parent[parent2]))//��Ԫ�ظ�������
	{
		parent[parent1] = parent[parent1] + parent[parent2];//Ԫ�ظ�������
		parent[parent2] = parent1;
	}
	else
	{
		parent[parent2] = parent[parent2] + parent[parent1];//Ԫ�ظ�������
		parent[parent1] = parent2;
	}
}

