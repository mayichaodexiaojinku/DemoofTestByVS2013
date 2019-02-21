#pragma once 
#include<stdio.h>
#include"Stack.h"
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void Swap(int* left, int* right);
void InsertSort(int* arr, int size);//��������
void ShellSort(int* arr, int size);//ϣ������
void SelectSort(int* arr, int size);//ѡ������
void HeapSort(int* arr, int size);//������
void BubbleSort(int* arr, int size);//ð������
void PrintSort(int *arr,int size);
void HeapAdjust(int* arr, int size, int parent);
void QuickSort(int* arr, int left, int right);//����
int Partion1(int* arr, int left, int right);//hoare�汾
int Partion2(int* arr, int left, int right);//�ڿӷ�
int Partion3(int* arr, int left, int right);//ǰ��ָ��
int GetMiddleIndex(int* arr, int left, int right);//����ȡ�з�
void QuickSortNor(int* arr, int size);//���ŵķǵݹ鷽��
void MergeSort(int* arr, int size);//�鲢����
void MergeSortNor(int* arr, int size);//�鲢�ķǵݹ�
void _MergeSort(int* arr, int left, int right, int* temp);
void MegerData(int* arr, int  left, int mid, int  right, int* temp);