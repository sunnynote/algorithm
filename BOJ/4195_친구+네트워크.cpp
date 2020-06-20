/**
 * 200619
 * BOJ 4195 친구 네트워크
 * Union_find
 * */

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int parent[200005];
int unionSize[200005];

map <string,int> s;

int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}

void unite(int A, int B){
    A = findParent(A);
    B = findParent(B);
    
    if(A==B) return;
    if(unionSize[A] < unionSize[B]) swap(A, B);
    
    unionSize[A] += unionSize[B];
    parent[B] = A;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        
        int idx=1;

        for(int i=1; i<=200005; i++){
                parent[i] = i;
                unionSize[i] = 1;
        }

        for(int i=1; i<=N; i++){
            string s1, s2;
            cin >> s1 >> s2;
            
            if(s.count(s1)==0) s[s1] = idx++;
            if(s.count(s2)==0) s[s2] = idx++;

            unite(s[s1], s[s2]);
            cout << max(unionSize[parent[s[s1]]], unionSize[parent[s[s2]]]) << '\n';
        }
    }

    return 0;
}