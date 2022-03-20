/**
 * 22-03-20
 * BOJ 14267 회사 문화1
 * DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static ArrayList<Integer>[] list;
  static int[] good;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    list = new ArrayList[N+1];

    for(int i=0; i<=N; i++){
      list[i] = new ArrayList<>();
    }
    good = new int[N+1];

    st = new StringTokenizer(br.readLine());
    for(int i=1; i<=N; i++){
      int x = Integer.parseInt(st.nextToken());

      if(i != 1)
        list[x].add(i);
    }

    for(int i=0; i<M; i++){
      st = new StringTokenizer(br.readLine());

      int idx = Integer.parseInt(st.nextToken());
      int val = Integer.parseInt(st.nextToken());

      good[idx] += val;
    }

    dfs(1);

    for(int i=1; i<=N; i++){
      System.out.print(good[i] + " ");
    }
  }

  static void dfs(int x){
    for(int i=0; i<list[x].size(); i++){
      int nx = list[x].get(i);
      good[nx] += good[x];
      dfs(nx);
    }
  }
}