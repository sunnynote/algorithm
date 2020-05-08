/**
 * BOJ 2933 미네랄
 * BFS + 시뮬레이션
 * 클러스터를 아래로 내리는 과정이 point
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
char map[105][105];
bool check[105][105];
int num[105];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

void bfs(int x, int y){
    queue <pair<int,int> > q;
    check[x][y]=true;
    q.push(make_pair(x,y));

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0<nx && nx<=N && 0<=ny && ny<M){
                if(map[nx][ny]=='x' && check[nx][ny]==0){
                    q.push(make_pair(nx,ny));
                    check[nx][ny]=true;
                }
            }

        }
    }
}


void func(int len, int seq){
    int h = len; // 현재 가진 막대기 높이

    // step 1 미네랄 파괴
    if(seq%2==1){ // dir:left
        for(int j=0; j<M; j++){
            if(map[N-h+1][j]=='x'){
                map[N-h+1][j]='.';
                break;
            }
        }
    }
    else{ // dir:right
        for(int j=M-1; j>=0; j--){
            if(map[N-h+1][j]=='x'){
                map[N-h+1][j]='.';
                break;
            }
        }
    }


    // step 2 안정적인 미네랄 만들기
    memset(check, 0, sizeof(check));

    // 바닥에 붙은거 체크
    for(int j=0; j<M; j++)
        if(map[N][j]=='x' && check[N][j]==false)
            bfs(N, j);

    // down
    int down = N;
    for(int j=0; j<M; j++){

        for(int i=N; i>=1; i--){
            if(map[i][j]=='x' && check[i][j]==false){
                int down_tmp = N-i;

                for(int k=i+1; k<=N; k++){
                    if(check[k][j]==true){
                        down_tmp = k-i-1;
                        break;
                    }
                }
                if(down>down_tmp) down = down_tmp;
            }
        }
    }

    for(int j=0; j<M; j++){
        for(int i=N; i>=1; i--){

            if(i+down <= N && down!=0){
                if(map[i][j]=='x' && check[i][j]==false){
                    map[i+down][j] = map[i][j];
                    map[i][j]='.';
                }
            }

        }
    }
}

int main(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=0; j<M; j++){
            map[i][j] = s[j];
        }
    }

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int len;
        cin >> len;
        func(len, i);
    }

    for(int i=1; i<=N; i++){
        for(int j=0; j<M; j++){
            cout << map[i][j];
        } cout << '\n';
    }
    return 0;
}
