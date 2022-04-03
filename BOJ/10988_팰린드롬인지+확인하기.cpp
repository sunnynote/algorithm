/**
 * @file 10988.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 10988 / 팰린드롬인지 확인하기
 * @version 0.1
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    int len = s.size();
    bool f = true;
    for(int i=0; i<len; i++){
        if(s[i] != s[len - i - 1]){
            f = false;
            break;
        }
    }

    if(f) cout << 1;
    else cout << 0;
}