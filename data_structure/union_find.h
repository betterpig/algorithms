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
		parent[x] = parent[parent[x]];//隔代压缩
		x = parent[x];
	}
	return x;

	/*if (parent[x] < 0)	//完全压缩（伪递归）
		return x;
	else
		return parent[x] = find(parent[x]);*/
}

void UinonSet::union_(int x1, int x2)
{
	int parent1 = find(x1);
	int parent2 = find(x2);
	//if (abs(parent[parent1]) > abs(parent[parent2]))//按高度合并
	//	parent[parent2] = parent1;//把高度小的树接到大的树上
	//else
	//{
	//	if (abs(parent[parent1]) == abs(parent[parent2]))
	//		parent[parent2]--;//树的高度+1
	//	parent[parent1] = parent2;
	//}
	if (abs(parent[parent1]) > abs(parent[parent2]))//按元素个数更新
	{
		parent[parent1] = parent[parent1] + parent[parent2];//元素个数更新
		parent[parent2] = parent1;
	}
	else
	{
		parent[parent2] = parent[parent2] + parent[parent1];//元素个数更新
		parent[parent1] = parent2;
	}
}

