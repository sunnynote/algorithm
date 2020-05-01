#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Battery{
    int x; int y; int c; int p;
    Battery(){};
    Battery(int _x, int _y, int _c, int _p){
        x=_x; y=_y; c=_c; p=_p;
    }
};
vector <Battery> Bty_info;

int M, A;
int ans;
int a[105];
int b[105];
int N=10;

int dx[5]={0,-1,0,1,0};
int dy[5]={0,0,1,0,-1};

int func(){
    // 초기 좌표
    int ax=1, ay=1;
    int bx=10, by=10;
    int sumA=0, sumB=0;

    for(int t=0; t<=M; t++){
        vector <int> availNumA, availNumB;
        for(int i=0; i<Bty_info.size(); i++){
            // A, B 현재 좌표에서 '이용 가능 BC' 벡터에 넣기 
            if(abs(ax-Bty_info[i].x)+abs(ay-Bty_info[i].y) <= Bty_info[i].c)
                availNumA.push_back(i);
            
            if(abs(bx-Bty_info[i].x)+abs(by-Bty_info[i].y) <= Bty_info[i].c)
                availNumB.push_back(i);
        }

        int tmpSum = 0;
        int addA = 0;
        int addB = 0;

        // A만 충전
        if(availNumA.size()>=1 && availNumB.size()==0){
            for(int i=0; i<availNumA.size(); i++){
                int chargeA = Bty_info[availNumA[i]].p;
                
                // 가장 큰 충전량으로 충전
                if(tmpSum < chargeA){ 
                    tmpSum = chargeA; 
                    addA = chargeA; 
                }
            }
        }
        // // B만 충전
        else if(availNumA.size()==0 && availNumB.size()>=1){
            for(int i=0; i<availNumB.size(); i++){
                int chargeB = Bty_info[availNumB[i]].p;

                if(tmpSum<chargeB){
                    tmpSum = chargeB;
                    addB = chargeB;
                }
            }
        }
        // A, B 둘다 충전
        else{
            for(int i=0; i<availNumA.size(); i++){
                for(int j=0; j<availNumB.size(); j++){
                    int chargeA = Bty_info[availNumA[i]].p;
                    int chargeB = Bty_info[availNumB[j]].p;

                    // 한 BC에 둘다 접속시
                    if(availNumA[i]==availNumB[j]){
                        chargeA /=2;
                        chargeB /=2;
                    }

                    if(tmpSum < chargeA+chargeB){
                        tmpSum = chargeA+chargeB;
                        addA = chargeA;
                        addB = chargeB;
                    }
                }
            }
        }
        // 다음칸으로 이동 
        ax+=dx[a[t+1]]; ay+=dy[a[t+1]];
        bx+=dx[b[t+1]]; by+=dy[b[t+1]];

        sumA += addA;
        sumB += addB;
    }
    return sumA + sumB;
}

int main(){
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        //init
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        Bty_info.clear();

        cin >> M >> A;

        for(int i=1; i<=M; i++) cin >> a[i];
        for(int i=1; i<=M; i++) cin >> b[i];

        for(int i=1; i<=A; i++){
            int X, Y, C, P;
            cin >> Y >> X >> C >> P;
            Bty_info.push_back(Battery(X,Y,C,P));
        }

        cout << "#" << test_case << ' ' << func() << '\n';
    }
}