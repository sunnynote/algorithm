/**
 * 21-10-27
 * Programmers
 * 2018 Summer/Winter Coding
 * 소수 만들기
 * */

#include <vector>
using namespace std;

bool chk[51];
int answer = 0;
vector <int> n;
int N;

bool is_prime(int sum){
    bool f = true;
    for(int i=2; i<sum; i++){
        if(sum%i==0) f = false;
        if(!f) break;
    }
    return f;
}

void dfs(int cnt, int idx, int sum){
    if(cnt==3){
        answer += is_prime(sum);
        return;
    }

    for(int i=idx; i<N; i++){
        if(chk[i]) continue;

        chk[i] = true;
        dfs(cnt+1, i, sum+n[i]);
        chk[i] = false;
    }
}

int solution(vector<int> nums) {
    n = nums;
    N = nums.size();

    dfs(0, 0, 0);

    return answer;
}