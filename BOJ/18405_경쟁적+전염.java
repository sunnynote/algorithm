/**
 * 22-03-21
 * BOJ 18405 경쟁적 전염
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test3 {
  static int N, K, S, X, Y;
  static int[][] map;
  static int[] dx = {0,0,-1,1};
  static int[] dy = {-1,1,0,0};
  static ArrayList<Info> list = new ArrayList<>();

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());
    map = new int[N][N];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());
      for(int j=0; j<N; j++){
        map[i][j] = Integer.parseInt(st.nextToken());

        if(map[i][j] != 0){
          list.add(new Info(map[i][j], i, j, 0));
        }
      }
    }

    st = new StringTokenizer(br.readLine());
    S = Integer.parseInt(st.nextToken());
    X = Integer.parseInt(st.nextToken());
    Y = Integer.parseInt(st.nextToken());

    Collections.sort(list);
    bfs();

    System.out.println(map[X-1][Y-1]);
  }

  static void bfs(){
    LinkedList<Info> q = new LinkedList<>();

    for(int i=0; i<list.size(); i++){
      q.add(new Info(list.get(i).idx, list.get(i).x, list.get(i).y, list.get(i).t));
    }

    while(!q.isEmpty()){
      int idx = q.peek().idx;
      int x = q.peek().x;
      int y = q.peek().y;
      int t = q.poll().t;

      if(t==S) break;

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0<=nx && nx<N && 0<=ny && ny<N){
          if(map[nx][ny]==0){
            map[nx][ny] = idx;
            q.add(new Info(idx, nx, ny, t+1));
          }
        }
      }
    }
  }
}

class Info implements Comparable<Info>{
  int idx, x, y, t;
  Info(int idx, int x, int y, int t){
    this.idx = idx;
    this.x = x;
    this.y = y;
    this.t = t;
  }

  @Override
  public int compareTo(Info o){
    return idx - o.idx;
  }
}