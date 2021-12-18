#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nums_function.h"
#include "heap.h"
#include "sorts.h"
#include "single_linklist.h"
#include "tree.h"
#include "rbtree.h"
#include <stdbool.h>
#define length 10000
typedef struct tree_struct
{
	int member;
	struct tree_struct *left;
	struct tree_struct *right;
	struct tree_struct *parent;
}tree_linklist;
typedef struct rbtree_struct
{
	int member;
	bool color;//红黑树的颜色，0为红色，1为黑色
	struct rbtree_struct *left;
	struct rbtree_struct *right;
	struct rbtree_struct *parent;
}rbtree_linklist;
void test();
void select_sort_test();
void bubble_sort_test();
void insert_sort_test();
void heap_sort_test();
void quick_sort_test();
void merge_sort_test();
void count_sort_test();
void radix_sort_test();
void single_linklist_test();
void tree_test();
void rbtree_test();
void main()
{
	//test();
	clock_t start, finish;
	double duration;
	start = clock();
	//select_sort_test();
	//bubble_sort_test();
	//insert_sort_test();
	//heap_sort_test();
	//quick_sort_test();
	//merge_sort_test();
	//count_sort_test();
	//radix_sort_test();
	//single_linklist_test();
	//tree_test();
	rbtree_test();
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("time costing %f seconds", duration);
}
void select_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	nums_assign(nums, numslength);
	select_sort(nums,numslength);
	nums_print(nums, numslength);
}
void bubble_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	nums_assign(nums, numslength);
	bubble_sort(nums, numslength);
	nums_print(nums, numslength);
}
void insert_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	nums_assign(nums, numslength);
	insert_sort(nums, numslength);
	nums_print(nums, numslength);
}
void heap_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	nums_assign(nums, numslength);
	max_heap_build(nums, numslength);
	heap_sort(nums, numslength);
	nums_print(nums, numslength);
}
void quick_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	nums_assign(nums, numslength);
	quick_sort(nums, 0, numslength - 1);
	nums_print(nums, numslength);
}
void merge_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	int nums1[length] = {0};
	nums_assign(nums, numslength);
	merge_sort(nums, nums1, numslength);
	nums_print(nums, numslength);
}
void count_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	int nums1[length] = { -1 };
	int nums2[length] = { 0 };
	nums_assign(nums, numslength);
	count_sort(nums, nums1, nums2, numslength);
	nums_print(nums, numslength);
}
void radix_sort_test()
{
	int numslength = length;
	int nums[length] = { 0 };
	int nums1[length] = { 0 };
	nums_assign(nums, numslength);
	radix_sort(nums, nums1, numslength);
	nums_print(nums, numslength);
}
void single_linklist_test()
{
	int nums[10] = { 1,2,3,4,5,6,7,8,9,10 };
	single_linklist *head = single_linklist_create(0);
	for (int i = 0; i < 10; i++)
	{
		sigle_linklist_headinsert(head, nums[i]);
	}
	single_linklist_change(head, 11, 555);
	single_linklist_delete(head, 6);
	single_linklist_print(head);
	free(head);
	head = NULL;
}
void tree_test()
{
	int nums[11] = {15,6,18,3,7,17,20,2,4,13,9};
	tree_linklist *root=NULL;
	//p->member=nums[0];不允许指针指向不完整的类类型,Q6.
	for (int i = 0; i < 11; i++)
		tree_insert(&root,nums[i]);
	inorder_tree_walk(root);
	printf("\n");
	printf("%d\n",tree_max(root)->member);
	printf("%d\n", tree_min(root)->member);
	printf("%d\n", tree_pre(root,3)->member);
	printf("%d\n", tree_suc(root, 7)->member);
	tree_delete(&root, 15);
	inorder_tree_walk(root);
	printf("\n");
	printf("测试成功\n");
}
void rbtree_test()
{
	int nums[11] = { 2,3,4,6,7,9,13,15,17,18,20 };
	rbtree_linklist *nil = rbtree_create(-1);
	nil->color = 1;
	rbtree_linklist *root = nil;
	for (int i = 0; i < 11; i++)
		rbtree_insert(&root,nil,nums[i]);
	preorder_rbtree_walk(root,nil);
	printf("%d\t%d\n", rbtree_max(root,nil)->member, rbtree_max(root, nil)->color);
	printf("%d\t%d\n", rbtree_min(root,nil)->member, rbtree_min(root, nil)->color);
	printf("%d\t%d\n", rbtree_pre(root,nil,13)->member, rbtree_pre(root, nil, 3)->color);
	printf("%d\t%d\n", rbtree_suc(root,nil,6)->member, rbtree_suc(root, nil, 7)->color);
	rbtree_delete(&root,nil,9);
	preorder_rbtree_walk(root, nil);
	printf("\n");
	printf("测试成功\n");
}
void test()
{
	int i = 0;
	while (i<100)
	{
		if (i < 50)
		{
			int k = 0;
			i++;
			k++;
			printf("%d\t", k);
			continue;
		}
		printf("%d\n",i++);
	}
}
