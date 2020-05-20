/**
 * 200520
 * BOJ 1184 귀농
 * 구현 문제
 * */

#include <iostream>
#include <vector>
using namespace std;

int N;
int a[55][55];

vector <int> sum1;
vector <int> sum2;

void leftUP(int x, int y){
    int idx = 0;
    
    for(int i=x; i>=0; i--){
        int res = 0;
        int len = 0;
        int maxLen = y+1;
        
        for(int j=y; j>=0; j--){
            res += a[i][j];
            
            if(i==x) 
                sum1.push_back(res);
            else{
                sum1.push_back(res + sum1[maxLen*idx + len]);
                len++;
            }
        }

        if(i!=x) idx++;
    }
}

void rightDown(int x, int y){
    int idx = 0;

    for(int i=x+1; i<N; i++){
        int res = 0;
        int len = 0;
        int maxLen = N-y-1;

        for(int j=y+1; j<N; j++){
            res += a[i][j];
            
            if(i==x+1)
                sum2.push_back(res);
            else{
                sum2.push_back(res + sum2[maxLen*idx + len]);
                len++;
            }
        } 

        if(i!=x+1) idx++;
    }
}

void leftDown(int x, int y){
    int idx = 0;

    for(int i=x+1; i<N; i++){
        int res = 0;
        int len = 0;
        int maxLen = y+1;

        for(int j=y; j>=0; j--){
            res += a[i][j];

            if(i==x+1)
                sum1.push_back(res);
            else{
                sum1.push_back(res + sum1[maxLen*idx + len]);
                len++;
            }
        }

        if(i!=x+1) idx++;
    }
}

void rightUp(int x, int y){
    int idx = 0;

    for(int i=x; i>=0; i--){
        int res = 0;
        int len = 0;
        int maxLen = N-y-1;

        for(int j=y+1; j<N; j++){
            res += a[i][j];

            if(i==x)
                sum2.push_back(res);
            else{
                sum2.push_back(res + sum2[maxLen*idx + len]);
                len++;
            }
        }

        if(i!=x) idx++;
    }
}

void solution(){
    int ans = 0;

    // 가능한 꼭지점 모두 조사
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-1; j++){
            // init
            sum1.clear();
            sum2.clear();

            // #1. left+up -- right+down
            leftUP(i,j); // left+up에서 가능한 합을 모두 구한다
            rightDown(i,j); // right+down에서 가능한 합을 모두 구한다
            // cout << '\n';
            
            //// sum1, sum2를 돌면서 같은 것이 있으면 ans증가
            for(int q=0; q<sum1.size(); q++)
                for(int w=0; w<sum2.size(); w++)
                    if(sum1[q]==sum2[w]) ans++;

            // init
            sum1.clear();
            sum2.clear();

            // #2. left+down -- right+up
            leftDown(i,j);
            rightUp(i,j);

            for(int q=0; q<sum1.size(); q++)
                for(int w=0; w<sum2.size(); w++)
                    if(sum1[q]==sum2[w]) ans++;
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> a[i][j];

    solution();

    return 0;
}