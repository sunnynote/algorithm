#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> map;

    string temp="";
    for(int i=1; i<s.length()-1; i++){
        if(s[i]=='{') continue;
        if(s[i]=='}' || s[i]==','){

            if(map.find(temp)!= map.end()){
                map.find(temp)->second++;
            }
            else{
                if(temp=="") continue;
                map.insert({temp, 1});
            }

            temp = "";
            continue;    
        }

        temp += s[i];
    }

    vector<pair<string, int> > v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<v.size(); i++){
        int cur = atoi(v[i].first.c_str());
        answer.push_back(cur);
    }

    return answer;
}