/**
 * 22-04-06
 * BOJ 11123 양 한마리... 양 두마리...
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test1 {
  static int N, M;
  static char[][] map;
  static boolean[][] chk;
  static int ans;

  static int[] dx = {0, 0, -1, 1};
  static int[] dy = {-1, 1, 0, 0};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      st = new StringTokenizer(br.readLine());
      N = Integer.parseInt(st.nextToken());
      M = Integer.parseInt(st.nextToken());

      map = new char[N][M];
      chk = new boolean[N][M];
      ans = 0;

      for(int i=0; i<N; i++){
        String s = br.readLine();

        for(int j=0; j<M; j++){
          map[i][j] = s.charAt(j);
        }
      }

      for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
          if(map[i][j] == '#' && !chk[i][j]){
            ans++;
            bfs(i, j);
          }
        }
      }

      System.out.println(ans);
    }
  }

  static void bfs(int x, int y){
    LinkedList<Info> q = new LinkedList<>();
    chk[x][y] = true;
    q.push(new Info(x, y));

    while(!q.isEmpty()){
      x = q.peek().x;
      y = q.poll().y;

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(!(0<=nx && nx<N && 0<=ny && ny<M)) continue;
        if(map[nx][ny]=='.' || chk[nx][ny]) continue;

        q.add(new Info(nx, ny));
        chk[nx][ny] = true;
      }
    }
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}
