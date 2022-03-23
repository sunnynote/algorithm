/**
 * 22-03-23
 * BOJ 15681 트리와 쿼리
 * 트리, DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class test3 {
  static int N, R, Q;
  static ArrayList<Integer>[] list;
  static int[] res;
  static boolean[] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());
    Q = Integer.parseInt(st.nextToken());

    res = new int[N + 1];
    chk = new boolean[N + 1];
    list = new ArrayList[N + 1];

    for(int i=0; i<=N; i++){
      list[i] = new ArrayList<>();
    }

    for(int i=0; i<N-1; i++){
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());

      list[s].add(e);
      list[e].add(s);
    }

    res[R] = dfs(R);

    for(int i=0; i<Q; i++){
      int x = Integer.parseInt(br.readLine());
      System.out.println(res[x]);
    }
  }

  static int dfs(int x){
    if(res[x] != 0) return res[x];

    chk[x] = true;

    int ret = 1;
    for(int i=0; i<list[x].size(); i++){
      int nx = list[x].get(i);

      if(chk[nx]) continue;

      ret += dfs(nx);
    }

    res[x] = ret;
    return ret;
  }
}