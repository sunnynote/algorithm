/**
 * 21-08-31
 * 순위검색
 * */

#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;

bool chk[50001];
vector <string> info_mat[50001];

vector <string> split(string input, char delimiter){
    vector <string> ans;
    stringstream ss(input);
    string tmp;
    
    while(getline(ss, tmp, delimiter)){
        ans.push_back(tmp);
    }
    
    return ans;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    int info_sz = info.size();
    
    // info slice
    for(int i=0; i<info_sz; i++)
        info_mat[i] = split(info[i], ' ');

    for(int i=0; i<query.size(); i++){
        
        // query slice
        vector<string> q_split = split(query[i], ' ');
        vector<int> q_int;
        
        // and sub
        vector<string> q_mat;
        for(int j=0; j<q_split.size(); j++){
            if(q_split[j]=="and") continue;
            q_mat.push_back(q_split[j]);
        }
        
        memset(chk, 1, sizeof(chk));
        for(int j=0; j<info_sz; j++){
            
            for(int k=0; k<4; k++){
                if(q_mat[k]=="-") continue;
                if(info_mat[j][k] != q_mat[k]) {
                    chk[j] = false;
                    break;
                }
            }
            
            int q_score = stoi(q_mat[4]);
            int info_score = stoi(info_mat[j][4]);
            if(q_score>info_score) chk[j] = false;
        }
        
        int cnt = 0;
        for(int j=0; j<info_sz; j++)
            if(chk[j]) cnt++;
        
        answer.push_back(cnt);
    }
    
    return answer;
}