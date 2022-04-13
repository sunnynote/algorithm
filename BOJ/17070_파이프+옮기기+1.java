/**
 * 22-04-13
 * BOJ 17070 파이프 옮기기 1
 * DFS
 */

import java.io.*;
import java.util.*;

public class test3 {
  static int N;
  static int[][] map;
  static int[] dx = {0, 1, 1};
  static int[] dy = {1, 0, 1};
  static int ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    N = Integer.parseInt(br.readLine());
    map = new int[N][N];

    for(int i=0; i<N; i++){
      StringTokenizer st = new StringTokenizer(br.readLine());

      for(int j=0; j<N; j++){
        map[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    solve(0, 1, 0);

    System.out.println(ans);
  }

  static void solve(int x, int y, int d){
    if(x == N - 1 && y == N - 1){
      ans++;
      return;
    }

    for(int i=0; i<3; i++){
      if((i == 0 && d == 1) || (i == 1 && d == 0)) continue;

      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
      if(map[nx][ny] == 1) continue;
      if(i == 2 && (map[x+1][y] == 1 || map[x][y+1] == 1)) continue;

      solve(nx, ny, i);
    }
  }
}