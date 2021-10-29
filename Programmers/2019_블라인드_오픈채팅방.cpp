/**
 * 21-10-29
 * Programmers
 * 2019 블라인드
 * Lv2 오픈채팅방
 * */
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

map <string, string> mp;

vector<string> split(string input, char c){
    vector<string> ans;

    stringstream ss(input);
    string tmp;

    while(getline(ss, tmp, c)){
        ans.push_back(tmp);
    }

    return ans;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for(int i=0; i<record.size(); i++){
        vector<string> res = split(record[i],' ');

        if(res[0]=="Enter" || res[0]=="Change"){
            if(mp.find(res[1]) != mp.end()){ // 존재하면 수정
                mp[res[1]] = res[2];
            }
            else { 
                mp.insert({res[1],res[2]});
            }
        }
    }

    for(int i=0; i<record.size(); i++){
        vector<string> res = split(record[i], ' ');

        string str = mp[res[1]];

        if(res[0]=="Enter"){
            str += "님이 들어왔습니다.";
            answer.push_back(str);
        }
        if(res[0]=="Leave"){
            str += "님이 나갔습니다.";
            answer.push_back(str);
        }
    }

    return answer;
}