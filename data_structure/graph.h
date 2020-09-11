#pragma once
#include"common.h"

class Graph
{
private:
	int vertex_num;
	int edges_num;
	vector<vector<int>> matrix;
	vector<node<int>*> table;
	vector<int> half_matrix;
	vector<int> indegree;
	

public:
	Graph(int n, vector<vector<int>> edges);
	vector<int> topo_sort();
	vector<int> BFS();
	vector<int> DFS();
	void dfs(int i,vector<int> &result, vector<bool> &visited);
};

Graph::Graph(int n, vector<vector<int>> edges) :vertex_num(n),edges_num(edges.size()), matrix(n, vector<int>(n, 0)), table(n, nullptr), half_matrix((n + 1)*n / 2), indegree(n)
{
	for (int i = 0; i < edges_num; i++)
	{
		indegree[edges[i][1]]++;

		matrix[edges[i][0]][edges[i][1]] = 1;
		matrix[edges[i][1]][edges[i][0]] = -1;

		int half_index = edges[i][0] * (edges[i][0] + 1) + edges[i][1];
		if (edges[i][0] > edges[i][1])
			half_matrix[half_index] = 1;
		else
			half_matrix[half_index] = -1;

		if (table[edges[i][0]] == nullptr)
		{
			table[edges[i][0]] = new node<int>(edges[i][1]);
		}
		else
		{
			node<int> *temp = table[edges[i][0]];
			while (temp->next)
				temp = temp->next;
			temp->next = new node<int>(edges[i][1]);
		}
	}
}

vector<int> Graph::topo_sort()
{
	vector<int> result;
	queue<int> q;
	for (int i = 0; i < vertex_num; i++)
		if (indegree[i] == 0)
			q.push(i);
	int count = 0;
	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();
		result.push_back(vertex);
		count++;
		node<int> *temp = table[vertex];
		while (temp)
		{
			int after_vertex = temp->key;
			//if(!visited[adj_vertex])  
			//	visited[adj_vertex]=true;
			if (--indegree[after_vertex] == 0)
				q.push(after_vertex);
		}
	}
	if (count != vertex_num)
		return vector<int>();
	else
		return result;

}

vector<int> Graph::BFS()
{
	vector<int> result;
	queue<int> q;
	vector<bool> visited(vertex_num,false);
	for (int i; i < vertex_num; i++)
	{
		if (visited[i])
			continue;
		visited[i] = true;
		q.push(i);
		while (!q.empty())
		{
			int vertex = q.front();
			q.pop();
			result.push_back(vertex);
			for (int j = 0; j < vertex_num; j++)
			{
				if (matrix[i][j] != 0 && !visited[j])
				{
					visited[j] = true;
					q.push(j);
				}
			}
		}
	}
	return result;
}

vector<int> Graph::DFS()
{
	vector<int> result;
	vector<bool> visited(vertex_num, false);

	for (int i = 0; i < vertex_num; i++)
	{
		if (visited[i])
			continue;
		dfs(i, result, visited);
	}
	return result;
}

void Graph::dfs(int i,vector<int> &result, vector<bool> &visited)
{
	result.push_back(i);
	visited[i] = true;

	int start = (i - 1)*i / 2;
	int halfIndex = 0;
	for (int j = 0; j < i; j++)
	{
		halfIndex = start + j;
		if (half_matrix[halfIndex] != 0 && !visited[j])
		{
			dfs(j, result, visited);
		}
	}
	return;
}