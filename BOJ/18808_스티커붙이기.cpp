/**
 * 18808 스티커 붙이기
 * 시뮬레이션
 * Point : 배열 회전 연산!
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int R, C;
int notebook[43][43];
int sticker[12][12];

void rotate(){
    int tmp[12][12];

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            tmp[i][j] = sticker[i][j];

    for(int i=0; i<C; i++)
        for(int j=0; j<R; j++)
            sticker[i][j] = tmp[R-j-1][i];
    
    swap(R, C);
}

bool avail(int x, int y){
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(sticker[i][j]==1 && notebook[x+i][y+j]==1) return false;

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(sticker[i][j]==1) notebook[x+i][y+j]=1;
        
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for(int k=0; k<K; k++){
        cin >> R >> C;

        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                cin >> sticker[i][j];
        

         // 스티커를 차례대로 붙여본다
        for(int r=0; r<4; r++){
            bool flag = false;

            for(int i=0; i<=N-R; i++){
                
                for(int j=0; j<=M-C; j++){

                    if(avail(i,j)){ // 붙이기 가능하면..
                        flag=true;
                        break;
                    }
                
                }
                if(flag) break;
            }

            if(flag) break;
            rotate();
        }
// cout << k << '\n';
//         for(int i=0; i<N; i++){
//             for(int j=0; j<M; j++){
//                 cout << notebook[i][j] << ' ';
//             } cout << '\n';
//         } cout << '\n';
    }


    int ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(notebook[i][j]==1) ans++;

    cout << ans;
    return 0;
}

