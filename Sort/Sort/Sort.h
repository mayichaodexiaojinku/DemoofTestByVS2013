#pragma once 
#include<stdio.h>
#include"Stack.h"
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
void Swap(int* left, int* right);
void InsertSort(int* arr, int size);//插入排序
void ShellSort(int* arr, int size);//希尔排序
void SelectSort(int* arr, int size);//选择排序
void HeapSort(int* arr, int size);//堆排序
void BubbleSort(int* arr, int size);//冒泡排序
void PrintSort(int *arr,int size);
void HeapAdjust(int* arr, int size, int parent);
void QuickSort(int* arr, int left, int right);//快排
int Partion1(int* arr, int left, int right);//hoare版本
int Partion2(int* arr, int left, int right);//挖坑法
int Partion3(int* arr, int left, int right);//前后指针
int GetMiddleIndex(int* arr, int left, int right);//三数取中法
void QuickSortNor(int* arr, int size);//快排的非递归方法
void MergeSort(int* arr, int size);//归并排序
void MergeSortNor(int* arr, int size);//归并的非递归
void _MergeSort(int* arr, int left, int right, int* temp);
void MegerData(int* arr, int  left, int mid, int  right, int* temp);