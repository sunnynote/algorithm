#include <iostream>
using namespace std;

int A, B, N, M;
int map[102][102];

struct Info{
    int x, y, d;
};
Info arr[102];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> B >> A >> N >> M;

    int x, y;
    char c;
    for(int i=1; i<=N; i++){
        cin >> y >> x >> c;

        arr[i].x = A-x+1;
        arr[i].y = y;

        if(c=='E') arr[i].d = 0;
        else if(c=='S') arr[i].d = 1;
        else if(c=='W') arr[i].d = 2;
        else arr[i].d = 3;

        map[arr[i].x][arr[i].y] = i;
    }
    
    int num, cnt;
    char cmd;

    for(int i=0; i<M; i++){
        cin >> num >> cmd >> cnt;

        int d = arr[num].d;

        if(cmd=='L'){
            cnt %= 4;
            arr[num].d = (d + (4 - cnt)) % 4;
        }
        else if(cmd=='R'){
            arr[num].d = (d + cnt) % 4;
        }
        else { // F : 전진
            for(int j=1; j<=cnt; j++){
                int nx = arr[num].x + dx[arr[num].d];
                int ny = arr[num].y + dy[arr[num].d];          
    
                // error 1
                if(!(0<nx && nx<=A && 0<ny && ny<=B)){ 
                    cout << "Robot " << num << " crashes into the wall";
                    return 0;
                }
                
                // error 2
                if(map[nx][ny]!=0){
                    cout << "Robot " << num << " crashes into robot " << map[nx][ny];
                    return 0;
                }
                
                // 충돌이 없으면, 로봇 위치 변경
                map[arr[num].x][arr[num].y] = 0;
                arr[num].x = nx;
                arr[num].y = ny;
                map[nx][ny] = num;
            }
        }
    }
    cout << "OK";
    return 0;
}