#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int weight[33]; // 주어지는 추의 무게
int want[10]; // 무게 확인할 구슬
bool check[31][30*500+1]; // 추의 갯수, 무게

void func(int cnt, int res){ // 현재 추의 갯수, 현재 총 무게
    if(cnt>N) return;
    if(check[cnt][res]) return;

    check[cnt][res]=true; // 현재 무게

    func(cnt+1, res+weight[cnt]); // 추를 구슬 반대편에 올릴 때
    func(cnt+1, res); // 추를 올리지 않을 때
    func(cnt+1, abs(res-weight[cnt])); // 추를 구슬편에 올릴 때
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> weight[i];

    cin >> M;
    for(int i=0; i<M; i++)
        cin >> want[i];

    func(0, 0); // 모든 경우 확인
    
    for(int i=0; i<M; i++){
        if(want[i] > 30*500) // 500g추 30개 이상의 무게라면
            cout << "N ";
        else if(check[N][want[i]]==1)
            cout << "Y ";
        else
            cout << "N ";
    }
    return 0;
}