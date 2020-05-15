#include <string>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

deque <string> dq;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize==0) return cities.size()*5;
    
    for(int i=0; i<cities.size(); i++){

        string city=cities[i];
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        bool flag = false;

        for(int j=0; j<dq.size(); j++){
            if(dq[j]==city){ // hit
                flag = true;

                deque <string> ndq;
                for(int k=0; k<dq.size(); k++){
                    if(dq[k]==city) continue;
                    ndq.push_back(dq[k]);
                }
                ndq.push_back(dq[j]);

                dq.clear();
                dq = ndq;
                answer += 1;

                break;
            }
        }

        // miss
        if(!flag){
            if(dq.size()==cacheSize)
                dq.pop_front();
            dq.push_back(city);
            answer += 5;
        }   
    }
    
    return answer;
}