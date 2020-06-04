#include <string>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    int len = dartResult.length();
    int cur = 0;
    int preScore = 0;
    int score = 0;
    
    while(cur < len){
        
        if('0'<=dartResult[cur] && dartResult[cur]<='9') 
            score = dartResult[cur] - '0';
        if(dartResult[cur+1]=='0'){
            score = 10;
            cur+=1;
        }
        cur+=1;
            
        
        if(dartResult[cur]=='S'){
        }
        else if(dartResult[cur]=='D'){
            score = score*score;
        }
        else { // T
            score = score*score*score;
        }
        cur+=1;
        
        
        if(dartResult[cur]=='*' || dartResult[cur]=='#'){
            if(dartResult[cur]=='*'){
                if(preScore!=0) preScore *= 2;
                score*=2;
            }
            else{ // '#'
                score = -score;
            }
            cur+=1;
        }
        answer += preScore;
        preScore = score;
    }
    answer += score;
    
    return answer;
}