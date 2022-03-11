/**
 * 22-03-11
 * BOJ 9205 맥주 마시면서 걸어가기
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class test2 {
  static int N;
  static int house_x, house_y;
  static int target_x, target_y;
  static int[][] conv;
  static boolean[] chk;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());
    for(int tc=1; tc<=T; tc++){

      N = Integer.parseInt(br.readLine());
      conv = new int[N][2];
      chk = new boolean[N];

      st = new StringTokenizer(br.readLine());
      house_x = Integer.parseInt(st.nextToken());
      house_y = Integer.parseInt(st.nextToken());

      for(int i=0; i<N; i++) {
        st = new StringTokenizer(br.readLine());
        conv[i][0] = Integer.parseInt(st.nextToken());
        conv[i][1] = Integer.parseInt(st.nextToken());
      }

      st = new StringTokenizer(br.readLine());
      target_x = Integer.parseInt(st.nextToken());
      target_y = Integer.parseInt(st.nextToken());

      System.out.println(bfs() ? "happy" : "sad");
    }
  }

  static boolean bfs(){
    LinkedList<Info> q = new LinkedList<>();
    q.add(new Info(house_x, house_y));

    while(!q.isEmpty()){
      int x = q.peek().x;
      int y = q.poll().y;

      if(Math.abs(target_x - x) + Math.abs(target_y - y) <= 1000){
        return true;
      }

      for(int i=0; i<N; i++){
        if(chk[i]) continue;

        int nx = conv[i][0];
        int ny = conv[i][1];

        if(Math.abs(nx - x) + Math.abs(ny - y) <= 1000){
          q.add(new Info(nx, ny));
          chk[i] = true;
        }
      }
    }

    return false;
  }
}
class Info{
  int x, y;
  Info(int x, int y){
    this.x = x;
    this.y = y;
  }
}