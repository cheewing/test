//
//  main.cpp
//  test
//
//  Created by cheewing on 14-9-16.
//  Copyright (c) 2014年 cheewing. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Sort.h"

using namespace std;


struct node
{
    int lon;
    int lat;
    int value;
};



//冒泡排序
//7 4 2 3 1 5
//first:    1 7 4 2 3 5
//second:   1 2 7 4 3 5
//third:    1 2 3 7 4 5
//forth:    1 2 3 4 7 5
//fifth:    1 2 3 4 5 7


//first
/*
 1:     7 4 2 3 1 5
 2:     7 4 2 1 3 5
 3:     7 4 1 2 3 5
 4:     7 1 4 2 3 5
 5:     1 7 4 2 3 5
 */
/*冒泡排序伪代码
 *
    for i <- 1 to n - 1
        for j <- n to i
            if A[j] < A[j-1]
                then Swap(A[j], A[j-1]);
 
 *
 */
//output the array
void output(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int array[], int n)
{
    int i = 0;
    int j = 0;
    
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (array[j] < array[j-1]) {
                Swap(array[j], array[j - 1]);
            }
        }
        //output(array, n);
    }
}

//rand array
void randarray(int array[], int n)
{
    for (int i = 0; i < n; i++) {
        array[i] = rand() % n;
    }
}


//字符串移位
//暴力解法
//移动末尾移位到头部
void Shiftone(char *array, int n)
{
    char temp = array[n - 1];
    
    for (int i = n-1; i > 0; --i) {
        array[i] = array[i - 1];
    }
    
    array[0] = temp;
}

//暴力解法版本
void ShiftArray(char *array, int n, int k)
{
    k = k % n;
    
    for (int i = 0; i < k; ++i) {
        Shiftone(array, n);
    }
}


//移位版本
void shiftall(char *array, int left, int right)
{
    while (left < right) {
        char temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        
        left++;
        right--;
    }
}

//
void shift(char *array, int n, int k)
{
    k = k % n;
    shiftall(array, 0, k - 1);
    shiftall(array, k, n - 1);
    shiftall(array, 0, n - 1);
    
}


//链表移位
void shiftlist()
{
    
}

#define square(x) (x * x)

//test macro
void testmacro()
{
    int c = square(5 + 5);
    
    cout << c << endl;
}


class Base
{
public:
    void func()
    {
        cout << "Base::func() " << endl;
    }
    
};

class Derive : public Base
{
public:
    void func()
    {
        cout << "Derive::func() " << endl;
    }
};

#include <string.h>


int main_ss()
{

    // insert code here...
    char *filename = "out_rs0067-f3d";
    char *strm = "%mcarats-0.8";
    char *strc = "# irdc, imom :    1   1\n";
    char *strd = "# irdc, imom :    1   2\n";
    float fdata;
    
    
    //read file data
    FILE *fp;
    if ((fp = fopen("/Users/cheewing/Desktop/test/test/out_rs0067-f3d", "r")) == NULL) {
        cout << "file open error" << endl;
        return -1;
    }
 
    char str[80];
    while (fgets(str, 80, fp), strcmp(str, strc) != 0) {    //find the correct line
    }
    
    long position = ftell(fp);
    
    char delim[64] = {0};
    char temp[64];
    char temp1[64];
    char *strnum = "0.3998102";

    fgets(str, 80, fp);
    
    sscanf(str, "%s %s %s", delim, temp, temp1);    //string流取数据
    
    fdata = atof(str);
    
    
    cout << fdata << endl;
    
    fclose(fp);
    
    
    //write file data
    if ((fp = fopen("/Users/cheewing/Desktop/test/test/out_rs0067-f3d", "w")) == NULL) {
        cout << "file open error" << endl;
        return -1;
    }
    
    fseek(fp, position, SEEK_SET);
    
    //fgets(str, 80, fp);
    //fdata = 0.456;
    
    //fputs(strnum, fp);
    fwrite(str, 1, sizeof(str), fp);
    
    fclose(fp);
    return 0;
}

