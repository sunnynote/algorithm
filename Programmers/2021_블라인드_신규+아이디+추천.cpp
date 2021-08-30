#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    int len = new_id.length();
    
    // 1
    for(int i=0; i<len; i++)
        if('A'<=new_id[i] && new_id[i]<='Z')
            new_id[i] += 32;
    
    // 2
    string step2 = "";
    for(int i=0; i<len; i++){
        if('a'<=new_id[i] && new_id[i]<='z')
            step2 += new_id[i];
        if('0'<=new_id[i] && new_id[i]<='9')
            step2 += new_id[i];
        if(new_id[i]=='-' || new_id[i]=='_' || new_id[i]=='.')
            step2 += new_id[i];
    }
    
    // 3
    string step3 = "";
    while(1){
        bool flag = false;
        
        string tmp = "";
        len = step2.length();
        for(int i=0; i<len; i++){
            tmp += step2[i];
            
            if(i!=len-1 && step2[i]=='.' && step2[i+1]=='.') {
                i+=1;
                flag = true;
            }
        }
        
        step2 = tmp;
        
        if(!flag) break;
    }
    
    step3 = step2;
    
    // 4
    if(step3.front()=='.') step3.erase(step3.begin());
    if(step3.back()=='.') step3.pop_back();
    string step4 = step3;
    
    // 5
    string step5 = "";
    if(step4.size()==0) step5 = "a";
    else step5 = step4;
    
    // 6
    string step6 = "";
    if(step5.length()>=16){
        for(int i=0; i<15; i++)
            step6 += step5[i];
    }
    else step6 = step5;
    
    // 6-2
    if(step6.back()=='.') step6.pop_back();
    
    // 7
    string step7 = "";
    step7 = step6;
    while(step7.size()<=2){
        step7 += step6.back();
    }
    
    answer = step7;
    
    return answer;
}