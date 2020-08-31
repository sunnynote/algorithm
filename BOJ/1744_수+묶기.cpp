/**
 * 200801
 * BOJ 1744 수 묶기
 * 그리디
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arrP, arrM, arrOne, arrZero;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;

        if(x>1) arrP.push_back(x);
        else if(x<0) arrM.push_back(x);
        else if(x==1) arrOne.push_back(x);
        else if(x==0) arrZero.push_back(x);
    }

    sort(arrP.begin(), arrP.end());
    sort(arrM.begin(), arrM.end());
    
    int ans = 0;

    int len = arrP.size();
    for(int i=0; i<len; i+=2){
        if(i==0 && len%2==1) {
            ans += arrP[i];
            i+=1;
        }
        ans += arrP[i]*arrP[i+1];
    }

    len = arrM.size();
    if(len%2==0){
        for(int i=0; i<len; i+=2)
            ans += arrM[i]*arrM[i+1];
    }
    else{
        if(arrZero.size()>0){
            for(int i=0; i<len-1; i+=2){
                if(i==len-1) break;
                ans += arrM[i]*arrM[i+1];
            }
        }
        else{
            for(int i=0; i<len; i+=2){
                if(i==len-1){
                    ans += arrM[i];
                    break;
                }
                ans += arrM[i]*arrM[i+1];
            }
        }
    }

    len = arrOne.size();
    ans += len;

    cout << ans << '\n';
    return 0;
}