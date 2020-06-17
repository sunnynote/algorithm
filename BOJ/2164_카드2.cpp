/**
 * 200618
 * BOJ 2164 카드2
 * 큐 C++언어로 직접 구현
 * */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front;
Node* rear;

void qInit(){
    front = NULL;
    rear = NULL;
}

int isEmpty(){
    if(front==NULL) return 1;
    return 0;
}

void enQueue(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(isEmpty()){   // 첫번째 노드이면
        front = newNode; // 첫번째, 끝 모두 같은 노드로
        rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

int deQueue(){
    Node* delNode = new Node();
    int retData;
    
    if(isEmpty()){
        return -1;
    }

    delNode = front;
    retData = delNode->data;
    front = front->next;

    return retData;
}

int main(){
    int N;
    cin >> N;

    qInit();

    for(int i=1; i<=N; i++)
        enQueue(i);
    
    for(int i=1; i<N; i++){
        deQueue();
        enQueue(deQueue());
    }

    cout << deQueue();
    return 0;
}