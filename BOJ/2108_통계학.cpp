/**
 * @file 2108.cpp
 * @author your name (you@domain.com)
 * @brief BOJ 2108
 * @version 0.1
 * @date 2022-03-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[500010];
int b[8010];

int main(){
    int n;
    cin >> n;

    vector<int> v(8001, 0);

    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
        
        v[ a[i] + 4000 ]++;
    }
    
    // 1.
    int ans = round(sum/(double)n);
    if(ans==-0) ans = 0;
    cout << ans << '\n';

    // 2.
    sort(a, a+n);
    cout << a[n/2] << '\n';

    // 3.
    int max1=0, max2=0; // value
    int flag1=0, flag2=0; // idx
    for(int i=0; i<=8000; i++){
        if(v[i]==0) continue;

        if(max1 < v[i]){
            max2 = 0;
            max1 = v[i];
            flag2 = 0;
            flag1 = i-4000;
        }
        else if(max1 == v[i] && max2==0){
            max2 = v[i];
            flag2 = i-4000;
        }
    }

    if(max1 != max2) 
        cout << flag1 << '\n';
    else
        cout << flag2 << '\n';

    // 4.
    cout << a[n-1] - a[0] << '\n';

    return 0;}
