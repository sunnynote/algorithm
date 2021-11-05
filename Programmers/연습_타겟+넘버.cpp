/**
 * 21-11-05
 * Programmers
 * Lv2 타겟 넘버
 * DFS
 * */

#include <string>
#include <vector>
using namespace std;

int N;
vector <int> num;
vector <char> ch;

int ans = 0;

void dfs(int cnt, int tg){
    if(cnt==N){
        int sum = 0;
        for(int i=0; i<N; i++){
            if(ch[i]=='-') sum -= num[i];
            else sum += num[i];
        }
        if(sum==tg) ans++;
        return;
    }

    ch.push_back('-');
    dfs(cnt+1, tg);
    ch.pop_back();

    ch.push_back('+');
    dfs(cnt+1, tg);   
    ch.pop_back();
}

void dfs2(vector<int> n, int cnt, int sum, int tg){
    if(n.size()==cnt){
        if(sum==tg) answer++;
        return;
    }

    dfs(n, cnt+1, sum+n[cnt], tg);
    dfs(n, cnt+1, sum-n[cnt], tg);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    num = numbers;
    N = numbers.size();
    dfs(0, target);
    // dfs2(numbers, 0, 0, target);
    
    answer = ans;
    
    return answer;
}