/**
 * SWEA 4013 특이한 자석
 * 시뮬레이션!
 * */

#include <iostream>
#include <cmath>
#include <cstring>
#include <deque>
using namespace std;

int ans;
int K;

deque <int> dq[4];
int check[4];

void rot(int num, int dir){
    if(dir==1){ // 시계 방향
        dq[num].push_front(dq[num].back());
        dq[num].pop_back();
    }
    else{ // 반시계 방향
        dq[num].push_back(dq[num].front());
        dq[num].pop_front();
    }
}

void func(int num, int dir){
    check[num] = dir;

    // rot check
    // left
    int n_dir = dir;
    for(int i=num-1; i>=0; i--){
        if(dq[i][2]!=dq[i+1][6]){
            n_dir = -n_dir;
            check[i] = n_dir;
        }
        else break;
    }
    // right
    n_dir = dir;
    for(int i=num+1; i<4; i++){
        if(dq[i-1][2]!=dq[i][6]){
            n_dir = -n_dir;
            check[i] = n_dir;
        }
        else break;
    }

    for(int i=0; i<4; i++)
        if(check[i]!=0)
            rot(i, check[i])
}

int main(int argc, char** argv){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int test_case, T;
    cin >> T;

    for(test_case=1; test_case<=T; test_case++){
        //init
        ans = 0;
        for(int i=0; i<4; i++)
            dq[i].clear();
        
        cin >> K;

        for(int i=0; i<4; i++){
            for(int j=0; j<8; j++){
                int x;
                cin >> x; 
                dq[i].push_back(x);
            }
        }

        for(int i=0; i<K; i++){
            int n, d;
            cin >> n >> d;
            func(n-1, d);
            memset(check, 0, sizeof(check));
        }

        // calc
        for(int i=0; i<4; i++)
            if(dq[i][0]==1) ans += pow(2,i);
        
        cout << '#' << test_case << ' ' << ans << '\n';
    }

    return 0;
}
