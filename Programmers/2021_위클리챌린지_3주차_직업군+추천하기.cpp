#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string arr[6][5];
int val[5];

vector <string> split(string input, char del){
    vector <string> ret;
    stringstream ss(input);
    string tmp;

    while(getline(ss, tmp, del)){
        ret.push_back(tmp);
    }

    return ret;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";

    for(int i=0; i<table.size(); i++){
        vector <string> rst = split(table[i], ' ');

        arr[0][i] = rst[0];
        for(int j=1; j<6; j++)
            arr[6-j][i] = rst[j];
    }

    for(int r=0; r<languages.size(); r++){
        string cur = languages[r];

        for(int i=0; i<5; i++)
            for(int j=1; j<=5; j++)
                if(arr[j][i]==cur) val[i] += j*preference[r];
    }

    vector <string> tmp_ans;
    int mx = -1;

    for(int i=0; i<5; i++){
        if(mx > val[i]) continue;

        if(mx < val[i]) tmp_ans.clear();

        mx = val[i];
        tmp_ans.push_back(arr[0][i]);
    }

    if(tmp_ans.size()>1) sort(tmp_ans.begin(), tmp_ans.end());

    answer += tmp_ans[0];

    return answer;
}