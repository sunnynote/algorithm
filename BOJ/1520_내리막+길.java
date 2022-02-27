/**
 * 22-02-25
 * BOJ 1520 내리막 길
 * dfs, dp
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test {
  static int N, M;
  static int[][] arr;
  static int[][] chk;
  static int[] dx = {0,1,0,-1};
  static int[] dy = {1,0,-1,0};
  static int ans = 0;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    arr = new int[N][M];
    chk = new int[N][M];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<M; j++){
        arr[i][j] = Integer.parseInt(st.nextToken());
      }
    }

    for(int i=0; i<N; i++)
      for(int j=0; j<M; j++)
        chk[i][j] = -1;

    ans = dfs(0, 0);
    System.out.println(ans);
  }

  static int dfs(int x, int y){
    if(x==N-1 && y==M-1)
      return 1;

    if(chk[x][y] > -1)
      return chk[x][y];

    chk[x][y] = 0;

    for(int i=0; i<4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(0<=nx && nx<N && 0<=ny && ny<M)
        if(arr[x][y] > arr[nx][ny])
          chk[x][y] += dfs(nx, ny);
    }
    return chk[x][y];
  }
}
