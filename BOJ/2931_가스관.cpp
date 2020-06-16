/**
 * 200615
 * BOJ 2931 가스관
 * DFS + 구현
 * */

#include <iostream>
using namespace std;

int R, C;
char map[27][27];
int sx, sy;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

// maptype 1:중간에 빈곳 , :2:M주위에 바로 빈곳
bool func(int x, int y, int mapType){
    bool nextFlag=false;
    bool dirCheck[4] = {0,0,0,0};

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(mapType==1 && map[nx][ny]=='Z')
            dirCheck[i] = true;
        if(mapType==2 && map[nx][ny]=='M')
            dirCheck[i] = true;

        if(i==0){
            if(map[nx][ny]=='|' || map[nx][ny]=='+'
                || map[nx][ny]=='1' || map[nx][ny]=='4')
                dirCheck[0]=true;
            
        }
        else if(i==1){
            if(map[nx][ny]=='|' || map[nx][ny]=='+'
                || map[nx][ny]=='2' || map[nx][ny]=='3')
                dirCheck[1]=true;
        }
        else if(i==2){
            if(map[nx][ny]=='-' || map[nx][ny]=='+'
                || map[nx][ny]=='1' || map[nx][ny]=='2')
                dirCheck[2]=true;
        }
        else if(i==3){
            if(map[nx][ny]=='-' || map[nx][ny]=='+'
                || map[nx][ny]=='3' || map[nx][ny]=='4')
                dirCheck[3]=true;
        }
    }

    char c;
    if(dirCheck[0] && dirCheck[1] && dirCheck[2] && dirCheck[3])
        c = '+';
    else if(dirCheck[2] && dirCheck[3])
        c = '-';
    else if(dirCheck[0] && dirCheck[1])
        c = '|';
    else if(dirCheck[1] && dirCheck[3])
        c = '1';
    else if(dirCheck[0] && dirCheck[3])
        c = '2';
    else if(dirCheck[0] && dirCheck[2])
        c = '3';
    else if(dirCheck[1] && dirCheck[2])
        c = '4';
    else{
        nextFlag=true;
    }

    // cout  << dirCheck[0] << ' ' << dirCheck[1] << ' ' << dirCheck[2] << ' ' << dirCheck[3] << "//" << nextFlag << '\n';
    
    if(!nextFlag) {
        cout << x << ' ' << y << ' ' << c << '\n';
        return false;
    }
    else return true; // 맞는 블럭이 없음.
}

void dfs(int x, int y, int d){
    if( !(0<x && x<=R && 0<y && y<=C) ) return;

    if(map[x][y]=='.'){
        bool nextFlag = func(x,y,1);
        if(!nextFlag) return;
    }

    int nx = x + dx[d];
    int ny = y + dy[d];

    if(d==0){
        if(map[nx][ny]=='1') d=3;
        if(map[nx][ny]=='4') d=2;
    }
    else if(d==1){
        if(map[nx][ny]=='2') d=3;
        if(map[nx][ny]=='3') d=2;
    }
    else if(d==2){
        if(map[nx][ny]=='1') d=1;
        if(map[nx][ny]=='2') d=0;
    }
    else if(d==3){
        if(map[nx][ny]=='3') d=0;
        if(map[nx][ny]=='4') d=1;
    }

    dfs(nx, ny, d);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        string s;
        cin >> s;
        for(int j=1; j<=C; j++){
            map[i][j] = s[j-1];

            if(map[i][j]=='M'){
                sx = i; sy = j;
            }
        }
    }

    bool edge=true;
    for(int i=0; i<4; i++){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(!(0<nx && nx<=R && 0<ny && ny<=C)) continue;
        
        if(map[nx][ny]!='.'){
            dfs(sx, sy, i); // x,y,d
            edge=false;
        }
    }

    // 시작점 주위가 바로 빈 곳이라면 -- 4좌표에 대해 모든 파이프를 넣어본다.
    if(edge){
        for(int i=0; i<4; i++){
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(!(0<nx && nx<=R && 0<ny && ny<=C)) continue;
    
            func(nx,ny,2);
        }
    }

    return 0;
}
