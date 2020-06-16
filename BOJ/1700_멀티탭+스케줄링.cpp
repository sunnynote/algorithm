/**
 * 200616
 * BOJ 1700 멀티탭 스케줄링
 * greedy 구현
 * */

#include <iostream>
using namespace std;

int order[105]; // 입력 순서
int res[105][2]; // 각 번호당 사용 횟수, 현재 꽂혀있는지 여부

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    for(int i=1; i<=K; i++){
        int x;
        cin >> x;
        
        order[i] = x;
        res[x][0]++;
    }

    int fillMultiTap = 0;
    int ans = 0;
    for(int i=1; i<=K; i++){
        // 처음 N회는 그냥 꽂는다.
        if(fillMultiTap<N){
            res[order[i]][0]--;
            if(res[order[i]][1]==0){ // 안 꽂혀 있으면
                fillMultiTap++;
                res[order[i]][1]=1;
            }        
        }

        else{ // N회 지나면
            // 이미 꽂혀있으면 pass
            if(res[order[i]][1]==1) {
                res[order[i]][0]--;
                continue;
            }

            /** 하나 빼야하는 경우
             * case 0. 꽂혀 있는 것 중 앞으로 사용 안하는 것 있으면 제거
             * case 1. 꽂혀 있는 것들이 모두 사용 될 예정이면,  
             *      가장 나중에 사용 될 것을 제거
            */

            int removeNum=0;
            bool caseFlag=true;
            // case 0 -- 앞으로 사용하지 않는데 꽂혀있는 것 있다면
            for(int j=1; j<=K; j++){
                if( res[order[j]][0]==0 && res[order[j]][1]==1 ){
                    removeNum = order[j];
                    caseFlag=false;
                }
            }
            
            // case 1 -- 처음으로 사용되는 시점이 나중인 것 제거
            if(caseFlag){
                int tmp = 0;
                bool check[105];
                for(int i=1; i<=K; i++) check[i]=false;
                for(int j=i+1; j<=K; j++){
                    if(res[order[j]][0]>0 && res[order[j]][1]==1 && !check[order[j]]){
                        if(tmp >= N) break;

                        removeNum = order[j];
                        check[order[j]]=true;
                        tmp++;
                    }
                }
            }

            res[removeNum][1]=0; // 제거

            res[order[i]][0]--; // 꽂는다
            res[order[i]][1]=1;
            ans++;
        }
    }

    cout << ans << '\n';
}