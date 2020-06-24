/**
 * 200624
 * BOJ 10971 외판원 순회 2
 * next_permutation
 * */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cost[12][12];
bool check[12];
int ans = 987654321;
int start = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> cost[i][j];

    vector <int> order;
    for(int i=0; i<N; i++)
        order.push_back(i);
    
    do{
        int res = 0;
        bool flag=true;

        for(int i=0; i<N-1; i++){
            if(cost[order[i]][order[i+1]]==0){
                flag=false;
                break;
            }
            res += cost[order[i]][order[i+1]];
        }

        if(!flag) continue;
        if(cost[order[N-1]][order[0]]==0) continue;

        res += cost[order[N-1]][order[0]];

        ans = min(res, ans);
    }while(next_permutation(order.begin(), order.end()));

    cout << ans;
    return 0;
}