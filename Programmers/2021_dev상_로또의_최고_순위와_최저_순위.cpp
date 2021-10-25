/**
 * 21-10-22
 * Programmers
 * 2021 Dev-Matching: 웹 백엔드 개발자(상반기)
 * 로또의 최고 순위와 최저 순위
 * */

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int mx = 0, mn = 0;
    int cnt = 0;
    int zero_cnt = 0;
    for(int i=0; i<6; i++){
        if(lottos[i]==0) zero_cnt++;

        for(int j=0; j<6; j++){
            if(lottos[i] == win_nums[j]){
                cnt++;
                break;
            }
        }
    }


    if(cnt==0) {
        mn = 6;
        mx = mn - zero_cnt;
        if(zero_cnt==6) mx++;
    }
    else if(cnt==6) {
        mx = 1;
        mn = 1;
    }
    else{
        mn = 6 - cnt + 1;
        mx = mn - zero_cnt;
    }

    answer.push_back(mx);
    answer.push_back(mn);

    return answer;
}