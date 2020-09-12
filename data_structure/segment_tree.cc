#include <stdio.h>

using namespace std;

void BuildTree(int a[],int tree[],int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=a[start];
        return;
    }
    int mid = (start + end) / 2;
    int left_node  = node * 2 + 1;
    int right_node = node * 2 + 2;

    BuildTree(a,tree,left_node,start,mid);
    BuildTree(a,tree,right_node,mid+1,end);
    tree[node] = tree[left_node] + tree[right_node];
}

void update(int a[],int tree[],int node,int start,int end,int index,int val)
{
    if(index > end || index < start)
        return;
    if(start==end)
    {
        a[start]=val;
        tree[node]=val;
        return;
    }
    int mid = (start + end) / 2;
    int left_node  = node * 2 + 1;
    int right_node = node * 2 + 2;

    if(index>mid)
        update(a,tree,right_node,mid+1,end,index,val);
    else
        update(a,tree,left_node,start,mid,index,val);
    tree[node] = tree[left_node] + tree[right_node];
}

int query(int a[],int tree[],int node,int start,int end,int L,int R)
{
    if(L > end || R < start)
        return 0;
    if(L<=start && R>=end)
        return tree[node];
    int mid = (start + end) / 2;
    int left_node  = node * 2 + 1;
    int right_node = node * 2 + 2;
    int left_sum  = query(a,tree,left_node,start,mid,L,R);
    int right_sum = query(a,tree,right_node,mid+1,end,L,R);
    return left_sum + right_sum;
}

int main()
{
    int a[]={1,3,5,7,9,11};
    int tree[1000]={0};
    BuildTree(a,tree,0,0,5);
    update(a,tree,0,0,5,0,2);
    for(int i=0;i<=12;i++)
        printf("tree[%d] = %d\n",i,tree[i]);
    int ret=query(a,tree,0,0,5,2,3);
}