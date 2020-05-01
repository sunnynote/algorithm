#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
int map[105][105];
int ans=0;

vector <pair<int,int> > wormHole[11];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int play(int x, int y, int d){

    int nx = x;
    int ny = y;
    int res = 0; // 점수

    while(1){
        nx += dx[d];
        ny += dy[d];
        
        // 종료 조건 1 = 시작점
        if(nx==x && ny==y) break;
        // 종료 조건 2 = 블랙홀
        if(map[nx][ny]==-1) break;
        

        if(!(0<=nx && nx<N && 0<=ny && ny<N)){
            res++;
            if(d==0) d=1;
            else if(d==1) d=0;
            else if(d==2) d=3;
            else d=2;
            continue;
        }

        if(map[nx][ny]==0) continue;
        if(map[nx][ny]==1){
            res++;
            if(d==0) d=1;
            else if(d==1) d=2;
            else if(d==2) d=3;
            else if(d==3) d=0;
            continue;
        }
        else if(map[nx][ny]==2){
            res++;
            if(d==0) d=1;
            else if(d==1) d=3;
            else if(d==2) d=0;
            else if(d==3) d=2;
            continue;
        }
        else if(map[nx][ny]==3){
            res++;
            if(d==0) d=3;
            else if(d==1) d=0;
            else if(d==2) d=1;
            else if(d==3) d=2;
            continue;
        }
        else if(map[nx][ny]==4){
            res++;
            if(d==0) d=2;
            else if(d==1) d=0;
            else if(d==2) d=3;
            else if(d==3) d=1;
            continue;
        }
        else if(map[nx][ny]==5){
            res++;
            if(d==0) d=1;
            else if(d==1) d=0;
            else if(d==2) d=3;
            else if(d==3) d=2;
            continue;
        }
        else if(6<=map[nx][ny] && map[nx][ny]<=10){
            int holeNum = map[nx][ny];

            if(wormHole[holeNum][0].first==nx && wormHole[holeNum][0].second==ny){
                nx = wormHole[holeNum][1].first;
                ny = wormHole[holeNum][1].second;
            }
            else{
                nx = wormHole[holeNum][0].first;
                ny = wormHole[holeNum][0].second;
            }
            continue;
        }
                    



    }

    return res;
}

int main(){
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N;

        // init
        ans = 0;
        memset(map, 0, sizeof(map));
        for(int i=6; i<=10; i++)
            wormHole[i].clear();

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];

                if(6<=map[i][j] && map[i][j]<=10){
                    wormHole[map[i][j]].push_back(make_pair(i,j));
                }
            }
        }

        // for(int i=6; i<=10; i++){
        //     for(int j=0; j<wormHole[i].size(); j++){
        //         cout << wormHole[i][j].first << ' ' << wormHole[i][j].second << '\n';
        //     }
        // }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(map[i][j]==0){

                    for(int k=0; k<4; k++)
                        ans = max(ans, play(i, j, k));
                        cout << ans << ' ';
                    
                }
            }
        }

        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}