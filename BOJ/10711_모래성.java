/**
 * 22-04-27
 * BOJ 10711 모래성
 * BFS
 */

import java.io.*;
import java.util.*;

public class test6 {
  static int N, M, ans = 0;
  static int[][] arr, adj;
  static boolean[][] chk;
  static int[] dx = {0,0,1,-1, -1,-1,1,1};
  static int[] dy = {-1,1,0,0, -1,1,-1,1};

  static LinkedList<Info> q, nq;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    arr = new int[N+1][M+1];
    adj = new int[N+1][M+1];
    chk = new boolean[N+1][M+1];
    q = new LinkedList<>();
    nq = new LinkedList<>();

    for(int i=0; i<N; i++){
      String s = br.readLine();

      for(int j=0; j<M; j++){
        if(s.charAt(j) == '.') {
          arr[i][j] = 0;
          chk[i][j] = true;
          q.add(new Info(i, j));
        }
        else{
          arr[i][j] = s.charAt(j) - '0';
        }
      }
    }

    System.out.println(bfs());
  }

  static int bfs(){
    while(!q.isEmpty()) {
      int x = q.peek().x;
      int y = q.poll().y;

      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= N || 0 > ny || ny >= M) continue;
        if (chk[nx][ny]) continue;

        if (arr[nx][ny] != 0) {
          adj[nx][ny] += 1;
        }
        if (adj[nx][ny] >= arr[nx][ny]) {
          nq.add(new Info(nx, ny));
          chk[nx][ny] = true;
        }
      }

      if (q.isEmpty()) {
        ans++;
        while (!nq.isEmpty()) {
          q.add(nq.poll());
        }
      }
    }

    return ans - 1;
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}