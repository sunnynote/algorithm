/**
 * 22-03-24
 * BOJ 9019 DSLR
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

    int T = Integer.parseInt(st.nextToken());

    while(T-- > 0){
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int e = Integer.parseInt(st.nextToken());

      bfs(s, e);
    }
  }

  static void bfs(int s, int e){
    LinkedList <Info> q = new LinkedList<>();
    boolean[] chk = new boolean[10001];

    q.add(new Info(s, ""));
    chk[s] = true;

    while(!q.isEmpty()){
      int x = q.peek().num;
      String str = q.poll().s;

      if(e == x){
        System.out.println(str);
        break;
      }

      // D
      int nx = x * 2;
      if(nx > 9999){
        nx %= 10000;
      }
      if(!chk[nx]) {
        chk[nx] = true;
        q.add(new Info(nx, str + "D"));
      }

      // S
      nx = x - 1;
      if(nx < 0){
        nx = 9999;
      }
      if(!chk[nx]) {
        chk[nx] = true;
        q.add(new Info(nx, str + "S"));
      }

      // L
      nx = (x%1000) * 10 + x/1000;
      if(!chk[nx]) {
        chk[nx] = true;
        q.add(new Info(nx, str + "L"));
      }

      // R
      nx = (x%10) * 1000 + x/10;
      if(!chk[nx]) {
        chk[nx] = true;
        q.add(new Info(nx, str + "R"));
      }
    }
  }

  static class Info{
    int num;
    String s;
    Info(int num, String s){
      this.num = num;
      this.s = s;
    }
  }
}
