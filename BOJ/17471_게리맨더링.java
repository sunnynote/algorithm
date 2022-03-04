/**
 * 22-03-04
 * BOJ 17141
 * BFS, DFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test {
  static int N;
  static int[] people = new int[11];
  static int tot = 0;
  static boolean[][] adj = new boolean[11][11];
  static int ans = Integer.MAX_VALUE;
  static boolean[] is_used = new boolean[11];
  static boolean[] chk = new boolean[11];

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    for(int i=1; i<=N; i++){
      people[i] = Integer.parseInt(st.nextToken());
      tot += people[i];
    }

    for(int i=1; i<=N; i++){
      st = new StringTokenizer(br.readLine());
      int num = Integer.parseInt(st.nextToken());

      for(int j=0; j<num; j++){
        int x = Integer.parseInt(st.nextToken());
        adj[i][x] = true;
        adj[x][i] = true;
      }
    }

    dfs(0, 1);

    if(ans==Integer.MAX_VALUE) System.out.println(-1);
    else System.out.println(ans);
  }

  static void dfs(int cnt, int idx){
    if(cnt >= 1){
      if(cnt >= N)
        return;

      ArrayList<Integer> A = new ArrayList<>();
      ArrayList<Integer> B = new ArrayList<>();
      for(int i=1; i<=N; i++){
        if(is_used[i]) A.add(i);
        else B.add(i);
      }

      if(bfs(A, true) && bfs(B, false)){
        int A_num = 0;
        int B_num = 0;
        int diff;

        for(int i=1; i<=N; i++){
          if(is_used[i]) A_num += people[i];
          else B_num += people[i];
        }

        diff = Math.abs(A_num - B_num);
        ans = Math.min(ans, diff);
      }
    }

    for(int i=idx; i<=N; i++){
      if(is_used[i]) continue;
      is_used[i] = true;
      dfs(cnt+1, idx+1);
      is_used[i] = false;
    }
  }

  static boolean bfs(ArrayList<Integer> v, boolean TF){
    for(int i=0; i<11; i++){
      chk[i] = false;
    }

    LinkedList<Integer> q = new LinkedList<>();
    q.add(v.get(0));
    chk[v.get(0)] = true;
    int cnt = 1;

    while(!q.isEmpty()){
      int x = q.poll();

      for(int i=1; i<=N; i++){
        if(adj[x][i] == true && is_used[i]==TF && !chk[i]){
          chk[i] = true;
          q.add(i);
          cnt++;
        }
      }
    }

    if(v.size()==cnt) return true;
    return false;
  }
}