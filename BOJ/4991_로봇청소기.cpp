#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
char map[25][25];
int check[25][25];

int num[25][25]; // 먼지 번호
int dist[12][12]; // 먼지 사이의 거리
vector < pair<pair<int,int>,int> > dirty;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int cnt; // 먼지 갯수
bool complete_flag;

bool cmp(pair<pair<int,int>,int> A, pair<pair<int,int>,int> B){
    return A.first.first < B.first.first;
}
void bfs(int x, int y, int idx){
    memset(check, -1, sizeof(check));
    queue <pair<pair<int,int>,int> > q;
    q.push(make_pair( make_pair(x,y),idx));
    check[x][y]=0;

    while(!q.empty()){
        x = q.front().first.first;
        y = q.front().first.second;
        idx = q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0<=nx && nx<N && 0<=ny && ny<M){
                if(map[nx][ny]!='x' && check[nx][ny]==-1){
                    q.push(make_pair(make_pair(nx,ny),idx));
                    check[nx][ny] = check[x][y]+1;

                    if(num[nx][ny]>idx){
                        dist[idx][num[nx][ny]] = check[nx][ny];
                        dist[num[nx][ny]][idx] = check[nx][ny];
                    }
                }
            }
        }
    }
}

int main(){
    while(1){
        cin >> M >> N;
        if(N==0 && M==0) break;

        //init
        memset(map, 0, sizeof(map));
        memset(num, -1, sizeof(num));
        memset(dist, 0, sizeof(dist));
        cnt=0;
        dirty.clear();
        complete_flag=false;
        
        for(int i=0; i<N; i++){
            string s;
            cin >> s;
            for(int j=0; j<M; j++){
                map[i][j] = s[j];

                if(map[i][j]=='o') {
                    num[i][j] = 0;
                    dirty.push_back(make_pair( make_pair(0,i),j));
                }
                if(map[i][j]=='*'){
                    cnt++;
                    num[i][j]=cnt;
                    dirty.push_back(make_pair(make_pair(cnt,i),j));
                }
            }
        }

        sort(dirty.begin(), dirty.end(), cmp);

        // 각 먼지 사이의 거리를 구해서 dist에 저장. dist[start][end]
        for(int i=0; i<dirty.size(); i++){
            int a = dirty[i].first.first;
            int b = dirty[i].first.second;
            int c = dirty[i].second;
            bfs(b,c, a); // x, y, idx            
        }


        vector <int> order;
        for(int i=0; i<=cnt; i++)
            order.push_back(i);            

        int min_ans = 987654321;
        bool flag=true;
        do{
            if(cnt==0 || !flag) break;

            int cur=dist[0][order[1]];
            for(int i=1; i<cnt; i++){
                int from = dirty[order[i]].first.first;
                int to = dirty[order[i+1]].first.first;

                if(dist[from][to]==0) {
                    flag = false; break;
                }
                cur += dist[from][to];
            }

            if(min_ans > cur) min_ans = cur;
        } while(next_permutation(order.begin()+1, order.end()));

        if(!flag) cout << -1 << '\n';
        else cout << min_ans << '\n';
    }
    return 0;
}