// BFS 양방향 탐색

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 12
using namespace std;

int N;
int check[1 << MAX*2];

int get(int state, int idx){ // idx번째 원반을 가지고 있는 기둥 번호 반환
    return (state >> (idx*2)) & 3;
}

int set(int state, int idx, int val){ // idx번째 원반을 val번째 기둥에 놓는다
    return (state & ~(3 << (idx*2))) | (val << (idx*2));
}

int sgn(int x){
    if(!x) return 0;
    
    if(x>0) return 1;
    return -1;
}

int incr(int x){
    if(x<0) return x-1;
    return x+1;
}

int bfs(int loc, int begin, int end){
    if(begin==end) return 0;

    queue<int> q;
    memset(check, 0, sizeof(check));

    q.push(begin);
    check[begin] = 1;

    q.push(end);
    check[end] = -1;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        // 기둥의 맨위에 있는 원반
        int top[4] = {-1, -1, -1, -1};
        for(int i = loc-1; i>=0; i--)
            top[get(x, i)] = i;

        // 맨위 원반을 다른 기둥으로 이동
        for(int i=0; i<4; i++){
            if(top[i] != -1){ // 맨위 원반을 찾으면

                for(int j=0; j<4; j++){
                    if(i!=j && (top[j]==-1 || top[j] > top[i])){
                        int nx = set(x, top[i], j); // 다른 기둥으로

                        // 방문하지 않았다면
                        if(check[nx] == 0){
                            check[nx] = incr(check[x]);
                            q.push(nx);
                        }

                        // 정방향, 역방향 만났다면
                        else if(sgn(check[nx]) != sgn(check[x])){
                            return abs(check[nx]) + abs(check[x]) - 1;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int TC;
    cin >> TC;
    while(TC--){
        cin >> N;

        int st = 0;
        int ed = pow(2, 2*N) - 1;

        for(int i=0; i<4; i++){
            int len;
            cin >> len;

            for(int j=0; j<len; j++){
                int num;
                cin >> num;

                st = set(st, num-1, i);
            }
        }

        cout << bfs(N, st, ed) << '\n';
    }

    return 0;
}