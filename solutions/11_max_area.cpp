/**
 * Copyright (c) 2019 Face++, Megvii. All Rights Reserved
 *
 * @File   : 11_max_area.cpp
 * @Author : heliwei@megvii.com
 * @Date   : 2019-07-28 16:39
 * @Brief  : 用暴力解法会超时，采用左右两边向中间缩的方法，并不能遍历
 *
**/

#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

int smaller(int a, int b){
    return a>b?b:a;
}

int getVolumn(vector<int> v, int i, int k){
    return abs(i - k) * smaller(v[i], v[k]);
}

int maxArea(vector<int> & height){
    int size = height.size();
    int max = 0;
    for(int i = 0, k = size - 1; k > i; ){
        int r = getVolumn(height, i, k);
        cout<<"circle=====================================";
        cout<<"i: "<<i<<endl;
        cout<<"k: "<<k<<endl;
        cout<<"r: "<<r<<endl;
        if(r > max)
            max = r;
        if(height[i] < height[k])
            i++;
        else k--;
    }
    return max;
}

int main(){
    vector<int> v{1,3,2,5,25,24,5};
    int i = maxArea(v);
    cout<<"result: "<<i<<endl;
}


/*  End of '11_max_area.cpp' */

