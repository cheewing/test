//
//  Sort.h
//  test
//
//  Created by cheewing on 14-9-19.
//  Copyright (c) 2014年 cheewing. All rights reserved.
//

#ifndef test_Sort_h
#define test_Sort_h

//插入排序
void InsertSort(int *array, int n)
{
    
}


//选择排序
void SelectSort(int *array, int n)
{
    
}

//快速排序
int Partition(int *array, int left, int right)
{
    int i = left;
    int j = left - 1;
    int pivot = array[right];
    
    while (i < right) {
        if (array[i] < pivot) {
            ++j;
            
            //swap i and j
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
        
        ++i;
    }
    
    array[right] = array[j + 1];
    array[j + 1] = pivot;
    
    return j + 1;
}

void QuickSort(int *array, int left, int right)
{
    if (left < right) {
        int mid = Partition(array, left, right);
        QuickSort(array, left, mid - 1);
        QuickSort(array, mid + 1, right);
    }
}

void QuickSort(int *array, int n)
{
    int left = 0;
    int right = n - 1;
    
    QuickSort(array, left, right);
}


//merge sort
void merge(int *array, int left, int mid, int right)
{
    int leftlen = mid - left + 1;
    int rightlen = right - mid;
    
    int *leftarr = new int[leftlen];
    int *rightarr = new int[rightlen];
    
    int i = 0;
    int j = 0;
    
    for (i = 0; i < leftlen; i++) {
        leftarr[i] = array[i];
    }
    
    for (j = 0; j < rightlen; j++) {
        rightarr[j] = array[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    int k = 0;
    
    while (i < leftlen && j < rightlen) {
        while (leftarr[i] <= rightarr[j]) {
            array[k++] = leftarr[i++];
        }
        
        while (rightarr[j] < leftarr[i]) {
            array[k++] = rightarr[j++];
        }
    }
    
    while (i < leftlen) {
        array[k++] = leftarr[i++];
    }
    
    while (j < rightlen) {
        array[k++] = rightarr[j++];
    }
    
    delete []leftarr;
    delete []rightarr;
}


void MergeSort(int *array, int left, int right)
{
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(array, left, mid);
        MergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void MergeSort(int *array, int n)
{
    int left = 0;
    int right = n - 1;
    MergeSort(array, left, right);
}


#endif
