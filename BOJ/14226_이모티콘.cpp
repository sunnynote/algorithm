/**
 * 200904
 * BOJ 14226 이모티콘
 * BFS or DP
 * */

#include <iostream>
#include <queue>
using namespace std;

int S;
bool check[1005][1005];

struct Info
{
    int display, clipBoard, myTime;
};

void solve_BFS()
{
    queue <Info> q;
    q.push({1,0,0});

    while(!q.empty()){
        int display = q.front().display;
        int clipBoard = q.front().clipBoard;
        int myTime = q.front().myTime;
        q.pop();

        // break
        if(display==S){
            cout << myTime;
            return;
        }

        int n_display, n_clipBoard;
        int n_myTime = myTime + 1;

        // 1
        n_display = display;
        n_clipBoard = display;
        if(0<n_display && n_display<=1000)
        {
            if(!check[n_display][n_clipBoard])
            {
                q.push({n_display, n_clipBoard, n_myTime});
                check[n_display][n_clipBoard] = true;
            }
        }

        // 2
        n_display = display + clipBoard;
        n_clipBoard = clipBoard;
        if(0<n_display && n_display<=1000)
        {
            if(!check[n_display][n_clipBoard])
            {
                q.push({n_display, n_clipBoard, n_myTime});
                check[n_display][n_clipBoard] = true;
            }
        }

        // 3
        n_display = display - 1;
        n_clipBoard = clipBoard;
        if(0<n_display && n_display<=1000){
            if(!check[n_display][n_clipBoard])
            {
                q.push({n_display, n_clipBoard, n_myTime});
                check[n_display][n_clipBoard] = true;
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    solve_BFS();
    return 0;
}
