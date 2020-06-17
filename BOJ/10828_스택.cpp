/**
 * 200618
 * BOJ 10828 스택
 * STL을 사용하지 않고 C++ 언어로 구현한 스택
 * */

#include <iostream>
#include <string>
#define MAX 10000
using namespace std;

int st[10001];
int topIdx;

void stackInit(){
    topIdx = -1;
}

int isEmpty(){
    if(topIdx == -1) return 1;
    return 0;
}

void push(int x){
    st[++topIdx] = x;
}

int pop(){
    if(isEmpty()) return -1;
    return st[topIdx--];
}

int peek(){
    if(isEmpty()) return -1;
    return st[topIdx];
}

int size(){
    return topIdx+1;
}

int main(){
    int N;
    cin >> N;
    
    stackInit();

    while(N--){
        string s;
        cin >> s;

        if(s=="push"){
            int x;
            cin >> x;
            push(x);
        }
        else if(s=="pop"){
            cout << pop() << '\n';
        }
        else if(s=="size"){
            cout << size() << '\n';
        }
        else if(s=="empty"){
            cout << isEmpty() << '\n';
        }
        else if(s=="top"){
            cout << peek() << '\n';
        }
    }
    return 0;
}