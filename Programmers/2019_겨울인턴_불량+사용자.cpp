#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set <string> st;
vector <int> v;
bool check[10];

void dfs(vector<string> banned_id, vector<string> user_id, int idx, int cnt){
    if(cnt==banned_id.size()){  
        
        bool flag = true;
        string str = "";
        for(int i=0; i<banned_id.size(); i++){
            if(banned_id[i].size() != user_id[v[i]].size()){
                flag = false;
                break;
            }
            
            for(int j=0; j<banned_id[i].size(); j++){
                if(banned_id[i][j]!='*' && banned_id[i][j] != user_id[v[i]][j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            else str += v[i];
        }
        
        if(flag) {
            sort(str.begin(), str.end());
            st.insert(str);
        }
        
        return;
    }
    
    for(int i=0; i<user_id.size(); i++){
        if(check[i]) continue;
        
        check[i] = true;
        v.push_back(i);
        dfs(banned_id, user_id, i, cnt+1);
        check[i] = false;
        v.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    dfs(banned_id, user_id, 0, 0); 
    answer = st.size();
    
    return answer;
}