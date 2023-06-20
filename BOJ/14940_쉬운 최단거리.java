/**
 * 23-06-20
 * BOJ 14940 쉬운 최단거리
 */

import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class ㄴ {
  static int N, M;
  static int[][] maze;
  static int[][] chk;
  static int[] dx = {-1,1,0,0};
  static int[] dy = {0,0,-1,1};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    maze = new int[N][M];
    int x = -1, y = -1;

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<M; j++){
        maze[i][j] = Integer.parseInt(st.nextToken());

        if(maze[i][j] == 2){
          x = i;
          y = j;

          maze[i][j] = 0;
        }
      }
    }

    func(x, y);


    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        System.out.print(chk[i][j] + " ");
      }
      System.out.println();
    }
  }

  public static void func(int x, int y){
    chk = new int[N][M];

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        chk[i][j] = -1;
        if(maze[i][j] == 0) chk[i][j] = 0;
      }
    }

    chk[x][y] = 0;

    Queue<Point> q = new LinkedList<>();
    q.add(new Point(x, y));

    while(!q.isEmpty()){
      Point p = q.poll();

      for(int i=0; i<4; i++){
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];

        if(0 <= nx && nx < N && 0 <= ny && ny < M){
          if(maze[nx][ny] == 1 && chk[nx][ny] == -1){
            q.add(new Point(nx, ny));
            chk[nx][ny] = chk[p.x][p.y] + 1;
          }
        }
      }
    }
  }
}
