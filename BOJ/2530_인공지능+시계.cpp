/**
 * @file 2530.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2530 인공지능 시계 / 수학
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int sec = 0;
    sec += A * 60 * 60;
    sec += B * 60;
    sec += C;
    sec += D;
    
    int mn, hour;

    mn = sec / 60;
    hour = mn / 60;

    sec %= 60;
    mn %= 60;
    hour %= 24;

    cout << hour << ' ' << mn << ' ' << sec << '\n';
}