/**
 * 22-03-27
 * BOJ 2178 미로 탐색
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());

    int[][] arr = new int[N][M];
    int[][] chk = new int[N][M];

    int[] dx = {0, 0, -1, 1};
    int[] dy = {-1, 1, 0, 0};

    for(int i=0; i<N; i++){
      char[] s = br.readLine().toCharArray();

      for(int j=0; j<M; j++){
        arr[i][j] = s[j] - '0';
      }
    }

    LinkedList<Info> q = new LinkedList<>();
    q.add(new Info(0, 0));
    chk[0][0] = 1;

    while(!q.isEmpty()){
      int x = q.peek().x;
      int y = q.poll().y;

      if(x==N-1 && y==M-1) break;

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<=nx && nx<N && 0<=ny && ny<M){
          if(arr[nx][ny]==1 && chk[nx][ny]==0){
            q.add(new Info(nx, ny));
            chk[nx][ny] = chk[x][y] + 1;
          }
        }
      }
    }

    System.out.println(chk[N-1][M-1]);
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}