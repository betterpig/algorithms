#pragma once
#include<iostream>
#include<math.h>

struct node
{
	int value;
	node* next;
	node(int x=0,node* p=nullptr) :value(x), next(p) {}
};

void print_array(int* a, int size);
void print_list(node* head);

void insertion_sort(int *a, int size);
void insertion_sort2(node** head);
void merge_sort(int *a, int size);
void bubble_sort(int *a, int size);
void select_sort(int *a, int size);
void quick_sort(int *a, int size);
void counting_sort(int* a, int size);
void bucket_sort(int* a, int size);
void radix_sort(int* a, int size);
void shell_sort(int* a, int size);
void heap_sort(int* a, int size);
