#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
typedef int BSDataType;
typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	BSDataType _data;
}BSTreeNode;
void Swap(BSTreeNode* pDelNode, BSTreeNode* InorderNode);
void InitBSTreeNode(BSTreeNode** pRoot);
BSTreeNode* InsertBSTreeNode(BSTreeNode** pRoot, BSDataType data);
void DeleteBSTreeNode(BSTreeNode** pRoot, BSDataType data);
void InsertBSTreeNodeNor(BSTreeNode** pRoot, BSDataType data);
void DeleteBSTreeNodeNor(BSTreeNode** pRoot, BSDataType data);
BSTreeNode* FindBSTreeNode(BSTreeNode** pRoot);
void DestroyBSTreeNode(BSTreeNode** pRoot);