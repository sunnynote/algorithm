/**
 * 200614
 * BOJ 2250
 * 트리의 높이와 너비
 * 트리, DFS
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int idx = 1;
pair<int,int> nodes[10005];
int root[10005];

int mnIdx[10005];
int mxIdx[10005];

void dfs(int cur, int level){
    if(nodes[cur].first > 0){
        dfs(nodes[cur].first, level+1);
    }

    mnIdx[level]=min(mnIdx[level], idx);
    mxIdx[level]=max(mxIdx[level], idx++);

    if(nodes[cur].second > 0){
        dfs(nodes[cur].second, level+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;

    // ##input
    for(int i=0; i<N; i++){
        int parent, left, right;
        cin >> parent >> left >> right;
        
        root[parent]++;
        nodes[parent].first = left;
        nodes[parent].second = right;

        if(left!=-1) root[left]++;
        if(right!=-1) root[right]++;
    }

    // ##find root
    int findRoot;
    for(int i=1; i<=N; i++)
        if(root[i]==1) findRoot=i;

    // ##inorder DFS
    for(int i=1; i<=N; i++){
        mnIdx[i] = 987654321;
        mxIdx[i] = -1;
    }
    
    dfs(findRoot, 1);

    // ## find answer
    int ansLevel = 1;
    int ans = mxIdx[1]-mnIdx[1]+1;
    
    for(int i=2; i<N; i++){
        int res = mxIdx[i]-mnIdx[i]+1;
        if(ans<res){
            ansLevel = i;
            ans = res;
        }
    }

    cout << ansLevel << ' ' << ans;
    return 0;
}