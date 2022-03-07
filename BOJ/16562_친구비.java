/**
 * 22-03-07
 * BOJ 16562 친구비
 * Union-find
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
  static int N, M, K;
  static int[] parent;
  static int[] money;
  static boolean[] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    money = new int[N + 1];
    parent = new int[N + 1];
    chk = new boolean[N + 1];

    st = new StringTokenizer(br.readLine());
    for (int i = 1; i <= N; i++) {
      money[i] = Integer.parseInt(st.nextToken());
      parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine());
      int x = Integer.parseInt(st.nextToken());
      int y = Integer.parseInt(st.nextToken());

      if (!isSameParent(x, y)) {
        unite(x, y);
      }
    }

    for(int i=1; i<=N; i++){
      chk[findParent(i)] = true;
    }
    int ans = 0;
    int mx = 0;
    for(int i=1; i<=N; i++){
      if(parent[i] == i){
        ans += money[i];
      }
    }

    if(K < ans)
      System.out.println("Oh no");
    else
      System.out.println(ans);
  }

  static boolean isSameParent(int a, int b){
    return findParent(a)==findParent(b);
  }

  static int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x] = findParent(parent[x]);
  }

  static void unite(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a != b) {
      if(money[a] < money[b]) {
        parent[b] = a;
        money[b] = money[a];
      }
      else {
        parent[a] = b;
        money[a] = money[b];
      }
    }
  }
}