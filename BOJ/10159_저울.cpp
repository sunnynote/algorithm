/**
 * 200924
 * BOJ 10159 저울
 * 플로이드
 * */

#include <iostream>
using namespace std;

bool arr[102][102];

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][k] && arr[k][j])
                    arr[i][j]=true;
            }
        }
    }

    for(int i=1; i<=N; i++){
        int cnt = 0;

        for(int j=1; j<=N; j++){
            if(i==j) continue;

            if(!arr[i][j] && !arr[j][i])
                cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}