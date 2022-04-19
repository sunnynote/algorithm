/**
 * 22-04-19
 * BOJ 1303 전쟁 - 전투
 * BFS
 */

import java.io.*;
import java.util.*;

public class test6 {
  static int N, M;
  static char[][] map;
  static boolean[][] chk;
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, -1, 1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    M = Integer.parseInt(st.nextToken());
    N = Integer.parseInt(st.nextToken());

    map = new char[N][M];
    chk = new boolean[N][M];

    for(int i=0; i<N; i++){
      String s = br.readLine();
      for(int j=0; j<M; j++){
        map[i][j] = s.charAt(j);
      }
    }

    int ansW = 0, ansB = 0;

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(chk[i][j]) continue;
        if(map[i][j] == 'W') ansW += bfs(i, j);
        if(map[i][j] == 'B') ansB += bfs(i, j);
      }
    }

    System.out.println(ansW + " " + ansB);
  }

  static int bfs(int a, int b){
    LinkedList<Info> q = new LinkedList<>();

    q.add(new Info(a, b));
    chk[a][b] = true;
    int cnt = 1;

    while(!q.isEmpty()){
      int x = q.peek().x;
      int y = q.poll().y;

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || N <= nx || 0 > ny || M <= ny) continue;
        if(map[a][b] != map[nx][ny] || chk[nx][ny]) continue;

        chk[nx][ny] = true;
        q.add(new Info(nx, ny));
        cnt++;
      }
    }

    return cnt * cnt;
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}