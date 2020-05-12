#include <iostream>
#include <vector>
using namespace std;

struct info{
    int x, y, cnt, dir;
};

int dx[5]={0,-1,1,0,0};
int dy[5]={0,0,0,-1,1};

int changeD(int x){
    if(x==1) return 2;
    else if(x==2) return 1;
    else if(x==3) return 4;
    else return 3;
}

int main(int argc, char** argv){
	int test_case, T;
	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case){
        // init
        vector <int> map[105][105];
        vector <info> v; // 군집 목록

        // input
        int N, M, K;
        cin >> N >> M >> K;
        for(int i=0; i<K; i++){
            int x, y, cnt, dir;
            cin >> x >> y >> cnt >> dir;
            v.push_back(info{x,y,cnt,dir});
        }

        for(int t=1; t<=M; t++){
            // #1 군집의 이동 + map 만들기
            for(int i=0; i<v.size(); i++){
                if(v[i].cnt==0) continue;

                v[i].x += dx[v[i].dir];
                v[i].y += dy[v[i].dir];
                map[v[i].x][v[i].y].push_back(i);
                
                if(v[i].x==0 || v[i].x==N-1 || v[i].y==0 || v[i].y==N-1){
                    v[i].cnt = v[i].cnt/2;
                    v[i].dir = changeD(v[i].dir);
                }
            }

            // #2 군집 확인
            for(int i=0; i<v.size(); i++){
                if(v[i].cnt==0) continue;

                int x = v[i].x;
                int y = v[i].y;

                if(map[x][y].size() > 1){
                    int maxIdx = 0;
                    int maxCnt = 0;
                    int sum = 0;
                    for(int j=0; j<map[x][y].size(); j++){
                        sum += v[map[x][y][j]].cnt;
                        if( maxCnt < v[map[x][y][j]].cnt ){
                            maxIdx = map[x][y][j];
                            maxCnt = v[map[x][y][j]].cnt;
                        }
                        v[map[x][y][j]].cnt = 0;
                    }
                    v[maxIdx].cnt = sum;
                }
            }

            // init
            for(int i=0; i<v.size(); i++)
                map[v[i].x][v[i].y].clear();
            
        }

        // answer
        int ans = 0;
        for(int i=0; i<v.size(); i++)
            ans += v[i].cnt;
        cout << '#' << test_case << ' ' << ans << '\n';
	}

	return 0;
}