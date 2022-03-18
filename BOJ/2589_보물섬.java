/**
 * 22-03-18
 * BOJ 2589 보물섬
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test {
  static int N, M;
  static int[][] map = new int[51][51];
  static int[] dx = {-1,0,1,0};
  static int[] dy = {0,1,0,-1};
  static int ans = 0;
  static int[][] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    for(int i=0; i<N; i++){
      String s = br.readLine();
      for(int j=0; j<M; j++){
        char[] c = s.toCharArray();

        if(c[j]=='W') {
          map[i][j] = 0;
        }
        else if(c[j]=='L') {
          map[i][j] = 1;
        }
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(map[i][j]==1)
          ans = Math.max(ans, bfs(i, j));
      }
    }

    System.out.println(ans);
  }

  static int bfs(int x, int y){
    LinkedList<Info> q = new LinkedList<Info>();
    chk = new int[51][51];
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        chk[i][j] = -1;
      }
    }

    q.add(new Info(x, y));
    chk[x][y] = 0;

    while(!q.isEmpty()){
      x = q.peek().x;
      y = q.poll().y;

      ans = chk[x][y];

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<=nx && nx<N && 0<=ny && ny<M){

          if(map[nx][ny]==1 && chk[nx][ny]==-1){
            q.add(new Info(nx, ny));
            chk[nx][ny] = chk[x][y] + 1;
          }
        }
      }
    }

    return ans;
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}