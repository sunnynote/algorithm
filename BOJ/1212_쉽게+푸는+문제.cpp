/**
 * @file 1292.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 1292 쉽게 푸는 문제 / 구현
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;

    int cnt = 0;
    int sum = 0;
    for(int i=1; i<=100; i++){
        for(int j=1; j<=i; j++){
            cnt++;
            if(A <= cnt && cnt <= B) sum += i;
            if(cnt > B) break;
        }
        if(cnt > B) break;
    }
    cout << sum <<'\n';
}