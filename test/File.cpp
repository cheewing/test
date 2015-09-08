//
//  File.cpp
//  test
//
//  Created by cheewing on 14-10-13.
//  Copyright (c) 2014年 cheewing. All rights reserved.
//


#include <iostream>
#include <fstream>
using namespace std;

void ReplaceBlank(char *str, int len)
{
    int i = 0;
    int j = 0;
    int newlen = len;
    
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            ++i;
        }
        else{
            for (j = newlen+2; j > i+2; --j) {
                str[j] = str[j-2];
            }
            str[i] = '%';
            str[i+1] = '2';
            str[i+2] = '0';
            
            newlen += 2;
        }
    }
}

void BlankReplace(char *str, int len)
{
    int newlen = 0;
    int p1= 0;
    int p2 = 0;
    int i = 0;
    int num = 0;
    
    //遍历一遍找空格数
    while (str[i++] != '\0')
    {
        if (str[i] == ' ') {
            num++;
        }
    }
    
    //替换
    newlen = len + num * 2;
    p1 = len;
    p2 = newlen;
    
    while (p1 >= 0) {
        if (str[p1] != ' ') {
            str[p2--] = str[p1--];
        }
        else{
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
            p1--;
        }
    }
}

int NumberOfOne(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (n & flag) {
            count++;
        }
        flag = flag << 1;
    }
    return count;
}

static char *mystruct[] =
{
    "ab",
    "abc",
    "abcd"
};

int main()
{
    int n = 0xF0000000;
    cout << sizeof(mystruct) / sizeof(mystruct[0]) << endl;
    
    return 0;
}



int main_test()
{
    char *filename = "/Users/cheewing/Desktop/test/test/out_rs0067-f3d";    //file name
    char buffer[80];   //file data;
    
    cout << "hello" << endl;
    ifstream infile(filename);
    
    if (! infile.is_open())
    {
        cout << "Error opening file";
        exit (1);
    }
    
    while (! infile.eof() ) {
        infile.getline (buffer,100);
        //cout << buffer << endl;
    }
    
    ofstream outfile(filename);
    outfile << "This is a Line\n";
    
    cout << "world" << endl;
    return 0;
}