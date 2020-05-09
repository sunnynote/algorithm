#include <iostream>
#include <queue>
using namespace std;

bool check[100000];
int N, K;
int ans = 0;

void bfs(int n, int k){
  queue <pair<int, int> > q;
  q.push(make_pair(n, 0));
  check[n] = true;

  while(!q.empty()){
    int cur = q.front().first;
    int cnt = q.front().second;
    q.pop();

    if(cur==k) {
      ans = cnt;
      return;
    }

    if(2*cur < 100001 && check[2*cur]==0){
      check[2*cur]=1;
      q.push(make_pair(cur*2, cnt));
    }
    if(cur-1 >= 0 && check[cur-1]==0){
      check[cur-1]=1;
      q.push(make_pair(cur-1, cnt+1));
    }
    if(cur+1 < 100001 && check[cur+1]==0){
      check[cur+1]=1;
      q.push(make_pair(cur+1, cnt+1));
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> N >> K;
  bfs(N, K);
  cout << ans <<'\n';
  return 0;
}
