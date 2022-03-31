/**
 * @file 9252.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 9252 LCS 2 / DP
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d[1010][1010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string s1, s2;
    cin >> s1 >> s2;
    
    int l1 = s1.length();
    int l2 = s2.length();

    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    string s = "";

    while(d[l1][l2] != 0){
        if(d[l1][l2] == d[l1-1][l2]){
            l1--;
        }
        else if(d[l1][l2] == d[l1][l2-1]){
            l2--;
        }
        else{
            s += s1[l1-1];
            l1--; l2--;
        }
    }

    reverse(s.begin(), s.end());
    
    if(d[s1.length()][s2.length()] != 0){
        cout << d[s1.length()][s2.length()] << '\n';
        cout << s;
    }
    else{
        cout << 0;
    }
    return 0;
}