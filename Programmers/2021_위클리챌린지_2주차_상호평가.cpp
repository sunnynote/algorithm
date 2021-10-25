#include <string>
#include <vector>
using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    int N = scores.size();
    
    vector <double> res;
    
    for(int j=0; j<N; j++){
        
        double sum = 0;
        
        int mx = -1;
        int mn = 101;
        int n = N;
        
        for(int i=0; i<N; i++){
            if(i==j) continue;
            
            if(scores[i][j] > mx) mx = scores[i][j];
            if(scores[i][j] < mn) mn = scores[i][j];
            sum += scores[i][j];
        }
        
        if(scores[j][j] > mx || scores[j][j] < mn) n--;
        else sum += scores[j][j];
        
        res.push_back(sum/n);
    }
    
    for(int i=0; i<N; i++){
        if(res[i]>=90) answer += "A";
        else if(res[i]>=80) answer += "B";
        else if(res[i]>=70) answer += "C";
        else if(res[i]>=50) answer += "D";
        else answer += "F";
    }
    
    return answer;
}