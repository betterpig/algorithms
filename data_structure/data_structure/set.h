#pragma once

class Set
{
public:
	Set(int *a,int size):parent(a),size(size){}
	int find(int x);
	void union_set(int x1, int x2);
	int find2(int x);
	void union_set2(int x1, int x2);

private:
	int *parent;
	int size;
};

int Set::find(int x)
{
	while (parent[x] >= 0)
		x = parent[x];
	return x;
}

void Set::union_set(int x1, int x2)
{
	int parent1 = find(x1);
	int parent2 = find(x2);
	if (parent1 != parent2)
		parent[parent2] = parent1;
}

int Set::find2(int x)
{
	return parent[x];
}

void Set::union_set2(int x1, int x2)
{
	int parent1 = find2(x1);
	int parent2 = find2(x2);
	if (parent1 != parent2)
	{
		if (abs(parent[parent1]) < abs(parent[parent2]))
		{
			parent[parent2] = parent[parent1] + parent[parent2];
			parent[parent1] = parent2;
			for (int i = 0; i < size; i++)
			{
				if (parent[i] == parent1)
					parent[i] = parent2;
			}
		}
		else
		{
			parent[parent1] = parent[parent1] + parent[parent2];
			parent[parent2] = parent1;
			for (int i = 0; i < size; i++)
			{
				if (parent[i] == parent2)
					parent[i] = parent1;
			}
		}
	}
}