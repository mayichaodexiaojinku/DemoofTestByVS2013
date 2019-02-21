#include"BSTree.h"
BSTreeNode* BuyBSTreeNode(BSDataType data)
{
	BSTreeNode* pNewNode = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	pNewNode->_data = data;
	pNewNode->_left = NULL;
	pNewNode->_right = NULL;
	return pNewNode;
}
void InitBSTreeNode(BSTreeNode** pRoot)
{
	assert(pRoot);
	*pRoot = NULL;
}
BSTreeNode* InsertBSTreeNode(BSTreeNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	while (*pRoot)
	{
		if ((*pRoot)->_data == data)
			break;
		else if ((*pRoot)->_data < data)
		{
			*pRoot = (*pRoot)->_right;
		}
		else
		{
			*pRoot = (*pRoot)->_left;
		}
	}
		return  *pRoot = BuyBSTreeNode(data);

}
void DeleteBSTreeNode(BSTreeNode** pRoot, BSDataType data)
{
	assert(pRoot);
	BSTreeNode* parent = *pRoot;
	BSTreeNode* cur = *pRoot;
	if (NULL == *pRoot)
	{
		return;
	}
	while (cur)
	{

		if (cur->_data == data)
			break;
		else if (cur->_data < data)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			parent = cur;
			cur = cur->_left;
		}

    }
	if (NULL==cur->_left)
	{
		if (cur == *pRoot)
		{
			*pRoot = cur->_right;
		}
		else
		{
			if (parent->_left == cur)
			{
				parent->_left = cur->_right;
			}
			else
			{
				parent->_right = cur->_right;
			}
		}
	}
	else if (NULL == cur->_right)
	{
		if (cur == *pRoot)
		{
			*pRoot = cur->_left;
		}
		else
		{
			if (parent->_left == cur)
			{
				parent->_left = cur->_left;
			}
			else
			{
				parent->_right = cur->_left;
			}
		}
	}
	else
	{
		BSTreeNode* pInorderNode = cur->_right;
		while (pInorderNode->_left)
		{
			pInorderNode = pInorderNode->_left;
		}
		cur->_data = pInorderNode->_data;
		if (parent->_left == pInorderNode)
		{
			parent->_left = pInorderNode->_right;
		}
		else
		{
			parent->_right = pInorderNode->_right;
		}
		cur = pInorderNode;
	}
	free(cur);
	return;
}
void Swap(BSTreeNode* pDelNode, BSTreeNode* InorderNode)
{
	assert(pDelNode&&InorderNode);
	BSTreeNode temp = *pDelNode;
	*pDelNode = *InorderNode;
	*InorderNode = temp;
}
BSTreeNode* FindBSTreeNode(BSTreeNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		return NULL;
	}
	while (*pRoot)
	{
		if ((*pRoot)->_data == data)
			return *pRoot;
		else if ((*pRoot)->_data < data)
			*pRoot = (*pRoot)->_right;
		else 
			*pRoot = (*pRoot)->_left;
	}
	return NULL;
}
void DestroyBSTreeNode(BSTreeNode** pRoot);
void InsertBSTreeNodeNor(BSTreeNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		*pRoot = BuyBSTreeNode(data);
		return;
	}
	else
	{
		if (data == (*pRoot)->_data)
			return;
		else if (data < (*pRoot)->_data)
			return  InsertBSTreeNodeNor(&(*pRoot)->_left,data);
		else if (data > (*pRoot)->_data)
			return  InsertBSTreeNodeNor(&(*pRoot)->_right, data);
	}
}
void DeleteBSTreeNodeNor(BSTreeNode** pRoot, BSDataType data)
{
	assert(pRoot);
	if (NULL == *pRoot)
	{
		return;
	}
	if (data < (*pRoot)->_data)
		return  DeleteBSTreeNodeNor(&(*pRoot)->_left, data);
	if (data >(*pRoot)->_data)
		return  DeleteBSTreeNodeNor(&(*pRoot)->_right, data);
	else
	{
		BSTreeNode* pDelNode = *pRoot;
		if (NULL == pDelNode->_left)
		{
			*pRoot = pDelNode->_right;
			free(pDelNode);
			return;
		}
		else if (NULL == pDelNode->_right)
		{
			*pRoot = pDelNode->_left;
			free(pDelNode);
			return;
		}
		else
		{
			BSTreeNode* pInorderNode = pDelNode->_right;
			while (pInorderNode->_left)
			{
				pInorderNode = pInorderNode->_left;
			}
			pDelNode->_data = pInorderNode->_data;
			return DeleteBSTreeNodeNor(&(*pRoot)->_right, pDelNode->_data);
		}
	}
}