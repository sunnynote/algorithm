/*
SWEA 4012 요리사
모든 경우를 탐색하는 완전 탐색
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;
int N;
int map[20][20];
bool selected[20];
vector<int> foodA, foodB;

void func(){
    foodA.clear();
    foodB.clear();
    
    for(int i=1; i<=N; i++){
        if(selected[i]) foodA.push_back(i);
        else foodB.push_back(i);
    }
    
    int sumA=0;
    for(int i=0; i<foodA.size()-1; i++){
        for(int j=i+1; j<foodA.size(); j++){
            sumA += map[foodA[i]][foodA[j]];
            sumA += map[foodA[j]][foodA[i]];
        }
    }
    int sumB=0;
    for(int i=0; i<foodB.size()-1; i++){
        for(int j=i+1; j<foodB.size(); j++){
            sumB += map[foodB[i]][foodB[j]];
            sumB += map[foodB[j]][foodB[i]];
        }
    }
    
    ans = min(ans, abs(sumA-sumB));
    // cout << ans << '\n';
}

void dfs(int cnt, int idx){
    if(cnt == N/2){
        func();
        return;
    }

    for(int i=idx; i<=N; i++){
        if(selected[i]) continue;

        selected[i]=true;
        dfs(cnt+1, i+1);
        selected[i]=false;
    }
}

int main(int argc, char** argv){
    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        cin >> N;

        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                cin >> map[i][j];

        //init
        ans = 987654321;
        memset(selected, 0, sizeof(selected));
        foodA.clear();
        foodB.clear();

        dfs(0, 1); // 재료를 두 그룹으로 나눈다


        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
