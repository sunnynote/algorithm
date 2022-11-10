/**
 * @file 영어 끝말잇기
 * @author your name (you@domain.com)
 * @brief Programmers Summer/Winter Coding ~2018
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> st;
    
    bool f = true;
    int idx = -1;
    
    st.insert(words[0]);
    
    for(int i=1; i<words.size(); i++){
        string x = words[i-1];
        string nx = words[i];
        
        // 1) 3번조건
        if(x.back() != nx.front()){
            idx = i;
            f = false;
        }
        
        // 2) 4번조건
        if(st.find(nx) == st.end()){
            st.insert(nx);
        }
        else{
            idx = i;
            f = false;
        }
        
        if(!f) break;
    }
    
    if(idx == -1){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(idx % n + 1);
        answer.push_back(idx / n + 1);
    }

    return answer;
}