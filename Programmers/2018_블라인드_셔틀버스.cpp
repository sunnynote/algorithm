#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    priority_queue <int> pq;

    // 큐에 도착시간 넣기
    for(int i=0; i<timetable.size(); i++){
        int hour = (timetable[i][0]-'0')*10 + (timetable[i][1]-'0');
        int minutes = (timetable[i][3]-'0')*10 + (timetable[i][4]-'0');
        pq.push( -(hour*60 + minutes) );
    } cout << '\n';


    for(int i=0; i<n-1; i++){
        int startTime = 60*9 + i*t;
        int cnt = 0;

        while(!pq.empty() && cnt<m){
            if(-pq.top() <= startTime){
                pq.pop();
                cnt++;
            }
            else break;
        }
    }

    // 막차 계산
    int cnt = 0;
    int startTime = 60*9 + t*(n-1);
    while(!pq.empty() && cnt<m-1){
        if(-pq.top()<=startTime){
            pq.pop();
            cnt++;
        }
        else break;
    }

    int conTime;
    if(pq.empty() || -pq.top() > startTime)
        conTime = startTime;
    else conTime = -pq.top() - 1;

    int hour = conTime/60;
    int minutes = conTime%60;

    answer += hour/10 + '0';
    answer += hour%10 + '0';
    answer += ':';
    answer += minutes/10 + '0';
    answer += minutes%10 + '0';

    return answer;
}

// int main(){
//     string cTestTime[] = {"08:00", "08:01", "08:02", "08:03"};
//     string cTestTime2[] = {"09:10", "09:09", "08:00"};
//     string cTestTime3[] = {"09:00", "09:00", "09:00", "09:00"};    
//     string cTestTime4[] = {"00:01", "00:01", "00:01", "00:01", "00:01"};
//     string cTestTime5[] = {"23:59"};
//     string cTestTime6[] = {"23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"};
//     vector<string> testTimeTable(cTestTime, cTestTime + (sizeof(cTestTime) / sizeof(cTestTime[0])));
//     vector<string> testTimeTable2(cTestTime2, cTestTime2 + (sizeof(cTestTime2) / sizeof(cTestTime2[0])));
//     vector<string> testTimeTable3(cTestTime3, cTestTime3 + (sizeof(cTestTime3) / sizeof(cTestTime3[0])));
//     vector<string> testTimeTable4(cTestTime4, cTestTime4 + (sizeof(cTestTime4) / sizeof(cTestTime4[0])));
//     vector<string> testTimeTable5(cTestTime5, cTestTime5 + (sizeof(cTestTime5) / sizeof(cTestTime5[0])));
//     vector<string> testTimeTable6(cTestTime6, cTestTime6 + (sizeof(cTestTime6) / sizeof(cTestTime6[0])));

//     cout << "con time : " << solution(1, 1, 5, testTimeTable) << endl;
//     // cout << "con time : " << solution(2, 10, 2, testTimeTable2) << endl;
//     // cout << "con time : " << solution(2, 1, 2, testTimeTable3) << endl;
//     // cout << "con time : " << solution(1, 1, 5, testTimeTable4) << endl;
//     // cout << "con time : " << solution(1, 1, 1, testTimeTable5) << endl;
//     // cout << "con time : " << solution(10, 60, 45, testTimeTable6) << endl;
// }