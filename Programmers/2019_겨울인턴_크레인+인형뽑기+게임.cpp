#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    stack <int> basket;
    int N = board.size();
    
    for(int i=0; i<moves.size(); i++){
        int cur = moves[i]-1;
    
        for(int j=0; j<N; j++){
            if(board[j][cur]!=0){
                
                if(basket.size()>0 && board[j][cur]==basket.top()){
                    basket.pop();
                    answer += 2;
                }
                else{
                    basket.push(board[j][cur]);
                }
                
                board[j][cur] = 0;
                break;
            }
        }
        
    }
    
    return answer;
}