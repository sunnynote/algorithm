#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
char map[305][305];
int num[305][305];
bool check[305][305];
int ans;

int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={1,-1,0,-1,1,0,-1,1};

void bfs(int x, int y){
    check[x][y]=true;
    queue <pair<int,int> > q;
    q.push(make_pair(x,y));

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<N && 0<=ny && ny<N){

                if(map[nx][ny]=='.' && check[nx][ny]==0){
                    if(num[nx][ny]==0){
                        q.push(make_pair(nx,ny));
                        check[nx][ny]=1;
                    }
                    else check[nx][ny]=1;
                }
            }
        }
    }

}

// 지뢰 갯수 카운트
void numbering(int x, int y){
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<N && 0<=ny && ny<N){
            if(map[nx][ny] != '*') 
                num[nx][ny]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test_case;
    int T;
    cin >> T;
    for(test_case=1; test_case<=T; ++test_case){
        
        cin >> N;
        for(int i=0; i<N; i++){
            string s;
            cin >> s;
            for(int j=0; j<N; j++){
                map[i][j] = s[j];
            }
        } // input

        memset(check, 0, sizeof(check));
        memset(num, 0, sizeof(num));
        ans=0;

        // 지뢰 갯수 카운트
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(map[i][j]=='*')
                    numbering(i,j);

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]=='*') continue;
                if(num[i][j]==0 && check[i][j]==0){
                    bfs(i,j);
                    ans++;
                }
            }
        }

        // cout <<"1~" << ans << '\n';

        // 0과 인접하지 않은 곳 하나씩 클릭할 때 횟수 추가
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]=='*') continue;
                if(check[i][j]==false) ans++;
            }
        }

        // cout << "2~" << ans << '\n';

        cout << "#" << test_case << ' ' << ans << '\n';
    }
    return 0;
}