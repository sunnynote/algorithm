#include <iostream>
#include <queue>
using namespace std;

int N, M;
char maze[55][55];
bool check[55][55][65];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int cnt = 0;

int bfs(int x, int y){
    queue <pair < pair<int,int>, pair<int,int> > > q;
    q.push(make_pair( make_pair(x,y) , make_pair(0,0) ));
    check[x][y][0] = true;

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        int cnt = q.front().second.first;
        int curKey = q.front().second.second;
        q.pop();

        if(maze[x][y]=='1') return cnt;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(!(0<nx && nx<=N && 0<ny && ny<=M)) continue;
            if(check[nx][ny][curKey]) continue;
            
            if(maze[nx][ny]=='.' || maze[nx][ny]=='1'){
                q.push(make_pair( make_pair(nx,ny), make_pair(cnt+1, curKey)));
                check[nx][ny][curKey]=true;
            }

            else if('a'<=maze[nx][ny] && maze[nx][ny]<='f'){
                int newKey = curKey | ( 1 << (maze[nx][ny]-'a'));

                q.push(make_pair( make_pair(nx,ny), make_pair(cnt+1, newKey)));
                check[nx][ny][newKey]=true;
            }

            else if('A'<=maze[nx][ny] && maze[nx][ny]<='F'){
                bool flag = curKey & ( 1 << (maze[nx][ny]-'A'));
                
                if(flag){
                    q.push(make_pair( make_pair(nx,ny), make_pair(cnt+1, curKey)));
                    check[nx][ny][curKey]=true;
                }
            }
        }
    }

    return -1;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int startX, startY;
    for(int i=1; i<=N; i++){
        string s;
        cin >> s;
        for(int j=1; j<=M; j++){
            maze[i][j] = s[j-1];

            if(maze[i][j]=='0'){
                maze[i][j]='.';
                startX=i;
                startY=j;
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cout << maze[i][j];
        } cout << '\n';
    }

    int ans = bfs(startX, startY);
    cout << ans;

    return 0;
}