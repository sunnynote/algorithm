#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> answer;

struct Node{
    int idx, x, y;
    struct Node *left;
    struct Node *right;
};

bool cmp(Node a, Node b){ // 내림차순 정렬
    if(a.y==b.y) return a.x < b.x;
    return a.y>b.y;
}

void insertNode(Node *curNode, Node* newNode){
    if(curNode->x > newNode->x){
        if(curNode->left == NULL)
            curNode->left = newNode;
        else
            insertNode(curNode->left, newNode);
    }
    else{
        if(curNode->right == NULL)
            curNode->right = newNode;
        else
            insertNode(curNode->right, newNode);
    }
}

void preOrder(Node *root){
    if(root==NULL) return;
    answer[0].push_back(root->idx);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    answer[1].push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int len = nodeinfo.size();
    answer.resize(2);
    vector<Node> nodes;
    
    for(int i=0; i<len; i++){
        nodes.push_back({i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    sort(nodes.begin(), nodes.end(), cmp);
    
    Node *root = &nodes[0];
    
    for(int i=1; i<len; i++){
        insertNode(root, &nodes[i]);
    }
    
    preOrder(root);
    postOrder(root);
    
    return answer;
}