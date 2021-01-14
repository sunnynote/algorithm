/**
 * 21-01-14
 * 동적계획법
 * */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int arrA[102];
int arrB[102];
int cache[102][102];

const long long NEGINF = numeric_limits<long long>::min();

int solve(int idxA, int idxB){
    int &ret = cache[idxA+1][idxB+1];
    if(ret != -1) return ret;

    ret = 0;
    long long a = (idxA==-1? NEGINF : arrA[idxA]);
    long long b = (idxB==-1? NEGINF : arrB[idxB]);
    long long mxRes = max(a, b);

    for(int i=idxA+1; i<N; i++){
        if(mxRes < arrA[i]){
            ret = max(ret, solve(i, idxB) + 1);
        }
    }

    for(int i=idxB+1; i<M; i++){
        if(mxRes < arrB[i]){
            ret = max(ret, solve(idxA, i) + 1);
        }
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        memset(cache, -1, sizeof(cache));

        cin >> N >> M;
        for(int i=0; i<N; i++)
            cin >> arrA[i];
        for(int i=0; i<M; i++)
            cin >> arrB[i];
    
        cout << solve(-1, -1) << '\n';
    }
    
    return 0;
}