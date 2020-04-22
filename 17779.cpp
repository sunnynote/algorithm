#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
int people[25][25];
int field_people[7];
int field_num[25][25];

int ans;

int func(int x, int y, int d1, int d2){
    // field 5
    for(int i=0; i<=d1; i++){
        for(int j=y-i; j<=y; j++) //5-1
            field_num[ x+i ][j]=5;

        for(int j=y+d2-d1; j<=y+d2-i; j++)// 5-3
            field_num[x+d2+i][j]=5;
    }

    for(int i=0; i<=d2; i++){
        for(int j=y; j<=y+i; j++) // 5-2
            field_num[ x+i ][j]=5;

        for(int j=y-d1+i; j<=y+d2-d1; j++)
            field_num[x+d1+i][j]=5;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(field_num[i][j]==5) continue;

            if(i<x+d1 && j<=y) field_num[i][j]=1;
            else if(i<=x+d2 && y<j) field_num[i][j]=2;
            else if(x+d1<=i && j<y-d1+d2) field_num[i][j]=3;
            else if(x+d2<i && y-d1+d2<=j) field_num[i][j]=4;
            else field_num[i][j]=5;
        }
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            field_people[field_num[i][j]] += people[i][j];

    sort(field_people, field_people+5+1);

    return field_people[5]-field_people[1];
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> people[i][j];

    ans = INF;
    for(int i=1; i<N; i++)
        for(int j=1; j<N; j++)
            for(int d1=1; d1<=N; d1++)
                for(int d2=1; d2<=N; d2++){
                    if(1<=j-d1 && j+d2<=N && i+d1+d2<=N){
                        memset(field_people, 0, sizeof(field_people));
                        memset(field_num, 0, sizeof(field_num));
                        ans = min(ans, func(i,j,d1,d2));
                    }
                }
        
    cout << ans;
    return 0;
}