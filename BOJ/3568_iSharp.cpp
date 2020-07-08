/**
 * 200707
 * BOJ 3568 iSharp
 * 구현
 * */

#include <iostream>
using namespace std; 

int main(){
    string baseStr="";
    cin >> baseStr;
    
    string str="";
    bool endFlag=false;

    while(1){
        cin >> str;

        int len = str.length();
        if(str[len-1]==';') endFlag=true;

        string var=baseStr;
        string name="";
        for(int i=len-2; i>=0; i--){
            if(str[i]=='[') var+=']';
            else if(str[i]==']') var+='[';
            else if(str[i]=='*' || str[i]=='&') var+=str[i];

            else name+=str[i];
        }

        cout << var << ' ';
        for(int i=name.length()-1; i>=0; i--) 
            cout << name[i];
        cout << ';' << '\n';

        if(endFlag) break;
    }

    return 0;
}