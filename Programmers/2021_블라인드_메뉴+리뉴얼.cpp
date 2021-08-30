#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

bool chk[10];
string tmp;
map <string, int> mp;
int mx[12];

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void menu_dfs(string str, int idx, int cnt, int N){
    if(cnt>1 && cnt<=N){
        if(mp.find(tmp)!=mp.end()) mp[tmp]++;
        else mp.insert({tmp, 1});
    }
    if(cnt==N) return;

    for(int i=idx; i<N; i++){

        if(chk[i]) continue;
        tmp.push_back(str[i]);
        chk[i] = true;

        menu_dfs(str, i, cnt+1, N);

        chk[i] = false;
        tmp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    int len = orders.size();

    for(int i=0; i<orders.size(); i++){
        string str = orders[i];
        sort(str.begin(), str.end());
        menu_dfs(str, 0, 0, str.length());
    }

    // 정렬하기 위해 v로..
    vector <pair<string, int> > v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), cmp); // 내림차순 정렬

    memset(mx, 0, sizeof(mx)); 

    for(int i=0; i<v.size(); i++){
        if(v[i].second >=2){
            for(int j=0; j<course.size(); j++){
                if(course[j]==(v[i].first).size()){
                    // 최대가 여러개면, 모두 추가.
                    if(mx[course[j]]==0 || mx[course[j]]==v[i].second){
                        mx[course[j]] = v[i].second;
                        answer.push_back(v[i].first);
                    }
                    else break;
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}