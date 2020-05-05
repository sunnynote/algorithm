/*
BOJ 17140
삼성 기출 시뮬레이션
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int arr[105][105];
int new_arr[105][105];
int r, c;
int num[105];

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second < b.second) return true;
    else if(a.second == b.second) return a.first < b.first;
    return false;
}

void row_func(){
    int origin_c = c;
    memset(new_arr, 0, sizeof(new_arr));

    for(int i=0; i<r; i++){
        // init
        vector <pair<int,int> > v;
        memset(num, 0, sizeof(num));

        // number count
        for(int j=0; j<c; j++)
            num[arr[i][j]]++;

        for(int j=1; j<=100; j++){
            if(num[j]==0) continue;
            v.push_back(make_pair(j, num[j]));
        }

        sort(v.begin(), v.end(), cmp);

        // 다음 행렬의 가로 크기 조정하고 arr update
        int next_c = v.size()*2;
        if(origin_c < next_c) origin_c = next_c;

        for(int j=0; j<v.size(); j++){
            new_arr[i][j*2] = v[j].first;
            new_arr[i][j*2+1] = v[j].second;
        }
    }

    r = r;
    c = origin_c;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            arr[i][j] = new_arr[i][j];
}

void col_func(){
    int origin_r = r;
    memset(new_arr, 0, sizeof(new_arr));

    for(int j=0; j<c; j++){
        //init
        vector <pair<int,int> > v;
        memset(num, 0, sizeof(num));

        for(int i=0; i<r; i++)
            num[arr[i][j]]++;

        for(int i=1; i<=100; i++){
            if(num[i]==0) continue;
            v.push_back(make_pair(i, num[i]));
        }

        sort(v.begin(), v.end(), cmp);

        int next_r = v.size()*2;
        if(origin_r < next_r) origin_r = next_r;

        for(int i=0; i<v.size(); i++){
            new_arr[i*2][j] = v[i].first;
            new_arr[i*2+1][j] = v[i].second;
        }
    }

    r = origin_r;
    c = c;
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            arr[i][j] = new_arr[i][j];
}

int main(){
    int R, C, K;
    cin >> R >> C >> K;

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> arr[i][j];
    
    int ans = 0;
    r = 3;
    c = 3;

    while(1){
        if(ans > 100) { 
            ans = -1; 
            break; 
        }
        if(arr[R-1][C-1]==K) break;

        if(r>=c) row_func();
        else col_func();

        ans++;
    }

    cout << ans;
    return 0;
}