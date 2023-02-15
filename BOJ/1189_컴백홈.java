/**
 * 23-02-15
 * BOJ 1189 컴백홈
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class sd {
  static int R, C, K;
  static char[][] maze;
  static boolean[][] chk;
  static int[] dx = {0, -1, 0, 1};
  static int[] dy = {-1, 0, 1, 0};
  static int ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    maze = new char[R][C];
    chk = new boolean[R][C];

    for(int i=0; i<R; i++){
      String s = br.readLine();

      for(int j=0; j<C; j++){
        maze[i][j] = s.charAt(j);
      }
    }

    chk[R-1][0] = true;
    dfs(R-1, 0, 1);

    System.out.println(ans);
  }

  static void dfs(int x, int y, int d){
    if(x == 0 && y == C-1){
      if(d == K) ans++;
      return;
    }

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(!(0 <= nx && nx < R && 0 <= ny && ny < C)) continue;
      if(maze[nx][ny] == 'T' || chk[nx][ny]) continue;

      chk[nx][ny] = true;
      dfs(nx, ny, d+1);
      chk[nx][ny] = false;
    }
  }
}