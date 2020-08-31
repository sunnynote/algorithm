#include <iostream>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

char map[105][105];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int len=0;
    cin >> len;    

    string str;
    cin >> str;

    int cnt=0;
    int x=50, y=50;
    int dir=0;
    map[x][y]='.';
    while(cnt<len){
        char cur = str[cnt];

        if(cur=='F'){
            x += dx[dir];
            y += dy[dir];
            map[x][y]='.';
        }
        else if(cur=='L'){
            dir = (dir+3)%4;
        }
        else if(cur=='R'){
            dir = (dir+1)%4;
        }
        cnt++;
    }
    
    int stX=100, stY=100, enX=0, enY=0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(map[i][j]=='.'){
                if(stX > i) stX = i;
                if(stY > j) stY = j;
                if(enX < i) enX = i;
                if(enY < j) enY = j;
            }
        }
    }

    for(int i=stX; i<=enX; i++){
        for(int j=stY; j<=enY; j++){
            if(map[i][j]=='.') cout << '.';
            else cout << '#';
        } cout << '\n';
    }

    return 0;
}