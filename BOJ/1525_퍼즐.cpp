#include <iostream>
#include <queue>
#include <set>
#define N 3
using namespace std;

int map[4][4];
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

set <string> check;
struct info{
    string str;
    int cnt;
};

int bfs(){
    queue <info> q;

    string num="";
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            num += to_string(map[i][j]);

    q.push({num, 0});
    check.insert(num);

    while(!q.empty()){
        string str = q.front().str;
        int cnt = q.front().cnt;
        q.pop();

        if(str=="123456780") return cnt;

        int n = 0;
        int x = 0, y = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j] = str[n++]-'0';

                if(map[i][j]==0){
                    x = i; y = j;
                }
            }
        }

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            
            if(0<=nx && nx<N && 0<=ny && ny<N){
                // swap
                int a = map[nx][ny];
                int b = map[x][y];
                
                num="";
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        if(map[i][j]==a) num += to_string(b);
                        else if(map[i][j]==b) num += to_string(a);
                        else num += to_string(map[i][j]);
                    }
                }

                if(check.find(num)==check.end()){
                    q.push({num, cnt+1});
                    check.insert(num);
                }
            }
        }
    }

    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> map[i][j];

    cout << bfs();
    return 0;
}