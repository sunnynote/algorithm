/**
 * 22-02-28
 * BOJ 1389 케빈 베이컨의 6단계 법칙
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int[][] arr = new int[N+1][N+1];
    boolean[][] chk = new boolean[N+1][N+1];

    for(int i=0; i<M; i++){
      st = new StringTokenizer(br.readLine());
      int from = Integer.parseInt(st.nextToken());
      int to = Integer.parseInt(st.nextToken());

      arr[from][to] = 1;
      arr[to][from] = 1;
    }

    int mn = Integer.MAX_VALUE;
    int ans = 0;

    LinkedList<Integer> q = new LinkedList<>();

    for(int i=1; i<=N; i++){
      q.add(i);
      chk[i][i] = true;

      int tmp = 0;
      while(!q.isEmpty()){
        int x = q.poll();

        for(int j=1; j<=N; j++){
          if(!chk[i][j] && arr[x][j]==1){
            q.add(j);
            arr[i][j] = arr[i][x] + arr[x][j];
            chk[i][j] = true;
            tmp += arr[i][j];
          }
        }
      }

      if(tmp<mn){
        mn = tmp;
        ans = i;
      }
    }

    System.out.println(ans);
  }
}