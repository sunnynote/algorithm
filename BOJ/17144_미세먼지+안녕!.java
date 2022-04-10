/**
 * 22-04-09
 * BOJ 17144 미세먼지 안녕!
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;

public class test3 {
  static int N, M, T;
  static int[][] map, nmap, chk;
  static int[] dx = {-1, 1, 0, 0};
  static int[] dy = {0, 0, -1, 1};
  static Vector<Info> v = new Vector<>();

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    // input
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    T = Integer.parseInt(st.nextToken());

    map = new int[N][M];
    nmap = new int[N][M];
    chk = new int[N][M];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      for(int j=0; j<M; j++){
        map[i][j] = Integer.parseInt(st.nextToken());

        if(map[i][j] == -1){
          v.add(new Info(i, j));
        }
      }
    }

    while(T-- > 0){
      spread();
      clean();
    }

    int sum = 0;
    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(map[i][j] > 0){
          sum += map[i][j];
        }
      }
    }

    System.out.println(sum);

  }

  static void spread(){

    Vector<Info> trash = new Vector<>();

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        nmap[i][j] = map[i][j];
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        if(map[i][j] > 0){
          trash.add(new Info(i, j));
        }
      }
    }

    int len = trash.size();
    for(int i=0; i<len; i++){
      int x = trash.get(i).x;
      int y = trash.get(i).y;
      int need = map[x][y] / 5;
      int cnt = 0;

      for(int j=0; j<4; j++){
        int nx = x + dx[j];
        int ny = y + dy[j];

        if(0 > nx || nx >= N || 0 > ny || ny >= M) continue;
        if(map[nx][ny] == -1) continue;

        nmap[nx][ny] += need;
        cnt++;
      }

      while(cnt-- > 0){
        nmap[x][y] -= need;
      }
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
        map[i][j] = nmap[i][j];
      }
    }
  }

  static void clean(){
    int x = v.get(0).x;

    for(int i=x-1; i>0; i--){
      map[i][0] = map[i-1][0];
    }
    for(int i=0; i<M-1; i++){
      map[0][i] = map[0][i+1];
    }
    for(int i=0; i<x; i++){
      map[i][M-1] = map[i+1][M-1];
    }
    for(int i=M-1; i>1; i--){
      map[x][i] = map[x][i-1];
    }
    map[x][1]=0;

    //2nd
    x = v.get(1).x;

    for(int i=x+1; i<N-1; i++){
      map[i][0] = map[i+1][0];
    }
    for(int i=0; i<M-1; i++){
      map[N-1][i] = map[N-1][i+1];
    }
    for(int i=N-1; i>=x; i--){
      map[i][M-1] = map[i-1][M-1];
    }
    for(int i=M-1; i>1; i--){
      map[x][i] = map[x][i-1];
    }
    map[x][1]=0;
  }
}

class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}

