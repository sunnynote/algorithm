/**
 * 200615
 * BOJ 2533
 * 사회망 서비스(SNS)
 * */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[1000010];
vector <int> realV[1000010];
int d[1000010][2];
bool check[1000010];

void dfs(int node){ // make graph -- 단방향
    check[node]=true;
    
    for(int i=0; i<v[node].size(); i++){
        int nextNode = v[node][i];

        if(!check[nextNode]){
            realV[node].push_back(nextNode);
            dfs(nextNode);
        }
    }
}

int earlyState(int node, bool state){
    int &ret = d[node][state];
    if(ret!=-1) return ret;

    if(state){ // 현재 얼리어답터 O -- 자식 얼리어답터 O, X
        ret = 1;
        for(int i=0; i<realV[node].size(); i++){
            int nextNode = realV[node][i];
            ret += min(earlyState(nextNode, true), earlyState(nextNode, false));
        }
    }
    else{ // 현재 얼리어답터 X -- 자식 얼리어답터 O
        ret = 0;
        for(int i=0; i<realV[node].size(); i++){
            int nextNode = realV[node][i];
            ret += earlyState(nextNode, true);
        }
    }

    return ret;
}

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N-1; i++){
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    memset(d, -1, sizeof(d));
    dfs(1); // 1번부터 시작

    cout << min( earlyState(1,true), earlyState(1,false) );
    return 0;
}
