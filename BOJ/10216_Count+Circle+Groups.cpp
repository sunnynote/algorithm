/**
 * 20-10-02
 * BOJ 10216 Count Circle Groups
 * union-find
 * */

#include <iostream>
#include <vector>
using namespace std;

int N;
int map[5001][3];
int parent[5001];

bool calc(int x, int y){
    int xDiff = map[x][0] - map[y][0];
    int yDiff = map[x][1] - map[y][1];
    int r = map[x][2] + map[y][2];

    if( xDiff*xDiff + yDiff*yDiff <= r*r) return true;
    return false;
}

int findParent(int x){
    if(x==parent[x]) return x;
    return parent[x]=findParent(parent[x]);
}

bool isSameParent(int a, int b){
    return findParent(a)==findParent(b);
}
void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(parent[a]>parent[b]) parent[a] = b;
    else parent[b] = a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--){
        cin >> N;
        int cnt=1;
        for(int i=0; i<N; i++){
            int x, y, r;
            cin >> x >> y >> r;

            map[i][0] = x;
            map[i][1] = y;
            map[i][2] = r;
            parent[i] = i;
        } // input

        int ans = N;

        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(calc(i, j)){
                    if(!isSameParent(i,j)){
                        unite(i,j);
                        ans--;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
