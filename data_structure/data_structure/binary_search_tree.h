#pragma once

#include<vector>
#include"common.h"

using namespace std;

template<class T>
struct tree_node
{
	T key;
	tree_node<T>* left;
	tree_node<T>* right;
	tree_node<T>* parent;
	tree_node(T k, tree_node<T>* left_ = nullptr, tree_node<T>* right_ = nullptr, tree_node<T>* parent_=nullptr) :key(k), left(left_), right(right_),parent(parent_) {}
};

template<class T>
class BST
{
public:
	BST() { root = nullptr; }

	int depth(tree_node<T>* p);

	void inorder_print(tree_node<T>* p);
	void preorder_print(tree_node<T>* p);
	void postorder_print(tree_node<T>* p);
	void inorder2_print(tree_node<T>* p);
	void preorder2_print(tree_node<T>* p);
	void preorder3_print(tree_node<T>* p);
	void postorder2_print(tree_node<T>* p);
	void levelorder2_print(tree_node<T>* p);
	void levelorder_print(tree_node<T>* p);

	void delete_data(tree_node<T>* p);
	tree_node<T>* search(T k);
	tree_node<T>* min(tree_node<T>* p);
	tree_node<T>* max(tree_node<T>* p);
	tree_node<T>* successor(tree_node<T>* p);
	tree_node<T>* predecessor(tree_node<T>* p);
	void insert(T k);
	void dele(T k);
	tree_node<T>* get_root() { return root; };

private:
	tree_node<T>* root;
};

template<class T>
int BST<T>::depth(tree_node<T>* p)
{
	if (!root)
		return 0;
	int left_depth = count_depth(root->left);
	int right_depth = count_depth(root->right);
	if (left_depth > right_depth)
		return left_depth + 1;
	else
		return right_depth + 1;
}

template<class T>
void BST<T>::inorder_print(tree_node<T>* p)
{
	if (p)
	{
		inorder_print(p->left);
		printf("%d  ", p->key);
		inorder_print(p->right);
	}
}

template<class T>
void BST<T>::preorder_print(tree_node<T>* p)
{
	if (p)
	{
		printf("%d  ", p->key);
		preorder_print(p->left);
		preorder_print(p->right);
	}
}

template<class T>
void BST<T>::postorder_print(tree_node<T>* p)
{
	if (p)
	{
		postorder_print(p->left);
		postorder_print(p->right);
		printf("%d  ", p->key);
	}
}

template<class T>
void BST<T>::inorder2_print(tree_node<T>* p)
{
	Stack<tree_node<T>*> s(10);
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		tree_node<T>* temp = s.pop();
		printf("%d  ", temp->key);
		p = temp->right;
	}
	printf("\n");
}

template<class T>
void BST<T>::preorder2_print(tree_node<T>* p)
{
	Stack<tree_node<T>*> s(10);
	s.push(p);
	while ( !s.empty())
	{
		tree_node<T>* temp = s.pop();
		printf("%d  ", temp->key);
		if (temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
	printf("\n");
}

template<class T>
void BST<T>::preorder3_print(tree_node<T>* p)
{
	Stack<tree_node<T>*> s(10);

	while (p || !s.empty())
	{
		while (p)
		{
			printf("%d  ", p->key);
			s.push(p);
			p = p->left;
		}
		tree_node<T>* temp = s.pop();

		p = temp->right;
	}
	printf("\n");
}

template<class T>
void BST<T>::postorder2_print(tree_node<T>* p)
{
	Stack<tree_node<T>*> stack(10);
	tree_node<T>* last_visit = nullptr;
	while (p || !stack.empty())
	{
		while (p)
		{
			stack.push(p);
			p = p->left;
		}
		tree_node<T>* temp = stack.get_top();
		if (!temp->right || last_visit == temp->right)
		{
			stack.pop();
			printf("%d  ", temp->key);
			last_visit = temp;
		}
		else
			p = temp->right;	
	}
	printf("\n");
}

template<class T>
void BST<T>::levelorder2_print(tree_node<T>* p)
{
	Queue< tree_node<T>*> q;
	q.enqueue(p);
	while (!q.empty())
	{
		tree_node<T>* temp = q.dequeue();
		printf("%d  ", temp->key);
		if (temp->left)
			q.enqueue(temp->left);
		if (temp->right)
			q.enqueue(temp->right);
	}
}

template<class T>
void BST<T>::levelorder_print(tree_node<T>* p)
{
	int n = depth(root);
	for (int i = 1; i <= n; i++)
	{
		level_order(root, i);
	}
	return root;
}

template<class T>
void levelorder(tree_node<T>* p, int n)
{
	if (!p)
		return;
	if (n == 1)
	{
		printf("%d", p->key);
		return;
	}

	level_order(p->left, n - 1);
	level_order(p->right, n - 1);
	return;
}

template<class T>
void BST<T>::delete_data(tree_node<T>* p)
{
	if (p)
	{
		delete_data(p->left);
		printf("%d  ", p->key);
		delete_data(p->right);
	}
}

template<class T>
tree_node<T>* BST<T>::search(T k)
{
	tree_node<T>* p = root;
	while (p && k != p->key)
	{
		if (k < p->key)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}

template<class T>
tree_node<T>* BST<T>::min(tree_node<T>* p)
{
	tree_node<T>* temp = p;
	while (p)
		p = p->left;
	return p;
}

template<class T>
tree_node<T>* BST<T>::max(tree_node<T>* p)
{
	tree_node<T>* temp = p;
	while (p)
		p = p->right;
	return p;
}

template<class T>
tree_node<T>* BST<T>::successor(tree_node<T>* p)
{
	if (p->right)
		return min(p->right);

	tree_node<T>* y = p->parent;
	while (y && p == y->right)
	{
		p = y;
		y = y->parent;
	}
	return y;
}

template<class T>
tree_node<T>* BST<T>::predecessor(tree_node<T>* p)
{
	if (p->left)
		return max(p->left);

	tree_node<T>* y = p->parent;
	while (y && p == y->left)
	{
		p = y;
		y = y->parent;
	}
	return y;
}

template<class T>
void BST<T>::insert(T k)
{
	tree_node<T>* y = nullptr;
	tree_node<T>* x = root;
	while (x)
	{
		y = x;
		if (k < x->key)
			x = x->left;
		else
			x = x->right;
	}
	tree_node<T>* z = new tree_node<T>(k,nullptr,nullptr,y);
	if (y == nullptr)
		root = z;
	else if (k < y->key)
		y->left = z;
	else
		y->right = z;

}

template<class T>
void BST<T>::dele(T k)
{
	tree_node<T>* p = search(k);
	if (!p->left && !p->right)
	{
		delete p;
		p = nullptr;
	}
	else if(p->left)
	{
		tree_node<T>* left_max = max(p->left);
		p->key = left_max->key;
		delete left_max;
		left_max = nullptr;
	}
	else
	{
		p->parent->right = p->right;
		delete p;
		p = nullptr;
	}
}