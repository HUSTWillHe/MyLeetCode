/**
 * Copyright (c) 2019 Face++, Megvii. All Rights Reserved
 *
 * @File   : 11_max_area.cpp
 * @Author : heliwei@megvii.com
 * @Date   : 2019-07-28 16:39
 * @Brief  :
 *
**/

#include <iostream>
#include <vector>
using namespace std;

int small(int a, int b){
    return a>b? b:a;
}

int maxArea(vector<int> & height){
    int size = height.size();
    int max = 0;
    for(int i = 0; i< size; i++){
        for(int k = i + 1; k < size; k++){
            int volumn = small(height[i], height[k]) * (k - i);
            cout<<"i: "<<i<<"k: "<<k<<endl;
            cout<<"volumn"<<volumn<<endl;
            if(volumn > max)
                max = volumn;
        }
    }
    return max;
}

int main(){
    vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int i = maxArea(v);
    cout<<"result: "<<i<<endl;
}


/*  End of '11_max_area.cpp' */

