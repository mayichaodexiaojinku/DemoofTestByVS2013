#include"Heap.h"
void InitHeap(Heap* hp,Pcompare compare)
{
	assert(hp);
	hp->_hp = (HPDataType*)malloc(sizeof(HPDataType));
	if (NULL == hp->_hp)
	{
		assert(0);
		return;
	}
	hp->_capacity = 10;
	hp->_size = 0;
	hp->_compare = compare;

}
void CreateHeap(Heap* hp, int* array, int size, Pcompare _compare)
{
	int root = ((size - 2) >> 1);
	assert(hp);
	hp->_hp = (HPDataType*)malloc(size*sizeof(HPDataType));
	if (0 == hp->_hp)
	{
		assert(0);
		return;
	}
	memcpy(hp->_hp, array, size*sizeof(HPDataType));
	hp->_size = size;
	hp->_capacity = 9;
	hp->_compare = _compare;
	for (; root >= 0; root--)
	{
		ADJustDown(hp,size,root);
	}
}
void ADJustDown(Heap* hp, int size,int parent)
{
	int child = (parent << 1) + 1;
	assert(hp);
	while (child < size)
	{
		if (child + 1<size&&hp->_compare(hp->_hp[child+1],hp->_hp[child]))
			  child += 1;
		if (hp->_compare(hp->_hp[parent] , hp->_hp[child]))
		{
			Swap(&(hp->_hp[parent]), &(hp->_hp[child]));
			parent = child;
			child = (parent << 1) + 1;
		}
		else
			return;
	}
}
void Swap(HPDataType* left, HPDataType* right)
{
	assert(left);
	assert(right);
	HPDataType temp = *left;
	*left = *right;
	*right = temp;
}
int EmptyHeap(Heap* hp)
{
	assert(hp);
	if (0 == hp->_size)
		return 1;
	else
		return 0;
}
HPDataType TopHeap(Heap* hp)
{
	assert(hp);
	return hp->_hp[0];
}
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
void InsertHeap(Heap* hp, HPDataType data)
{
	CheckCapacity(hp);
	hp->_hp[hp->_size++] = data;
	ADJustUp(hp, hp->_size - 1);

}
void RemoveHeap(Heap* hp)
{
	assert(hp);
	if (EmptyHeap(hp))
		return;
	Swap(&(hp->_hp[0]), &(hp->_hp[hp->_size - 1]));
	hp->_size--;
	ADJustDown(hp,hp->_size, 0);
}
void ADJustUp(Heap* hp, int child)
{
	int parent = (child >> 1) - 1;
	assert(hp);
	while (child)
	{
		if (hp->_compare(hp->_hp[parent], hp->_hp[child]))
		{
			Swap(&(hp->_hp[parent]), &(hp->_hp[child]));
			child = parent;
			parent = (child >> 1) - 1;
		}
		else
			return;
	}


}
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		int NewCapacity = (hp->_capacity << 1) + 1;
		HPDataType* pT = (HPDataType*)malloc(NewCapacity*sizeof(HPDataType));
		if (NULL == pT)
		{
			assert(0);
			return;
		}
		if (hp->_hp)
		{
			int i = 0;
			for (; i < hp->_size; ++i)
				pT[i] = hp->_hp[i];
			free(hp->_hp);
		}
		hp->_hp = pT;
		hp->_capacity = NewCapacity;
	}
}
int Less(HPDataType left, HPDataType right)
{
	return left>right;
}
int Greater(HPDataType left, HPDataType right)
{
	return left < right;
}