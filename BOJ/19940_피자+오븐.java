/**
 * 22-04-09
 * BOJ 19940 피자 오븐
 * BFS
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int T = Integer.parseInt(br.readLine());

    LinkedList<Info> q = new LinkedList<>();
    boolean[] chk = new boolean[70];
    Info[] res = new Info[70];

    q.add(new Info(0, 0, 0, 0, 0, 0));

    while(!q.isEmpty()){
      Info cur = q.poll();

      if(cur.t < 0 || cur.t > 60 || chk[cur.t]) continue;

      chk[cur.t] = true;
      res[cur.t] = cur;

      q.add(new Info(cur.t - 1, cur.ADDH, cur.ADDT, cur.MINT, cur.ADDO, cur.MINO + 1));
      q.add(new Info(cur.t + 1, cur.ADDH, cur.ADDT, cur.MINT, cur.ADDO + 1, cur.MINO));
      q.add(new Info(cur.t - 10, cur.ADDH, cur.ADDT, cur.MINT + 1, cur.ADDO, cur.MINO));
      q.add(new Info(cur.t + 10, cur.ADDH, cur.ADDT + 1, cur.MINT, cur.ADDO, cur.MINO));
      q.add(new Info(cur.t + 60, cur.ADDH + 1, cur.ADDT, cur.MINT, cur.ADDO, cur.MINO));
    }

    while(T-- > 0){
      int N = Integer.parseInt(br.readLine());

      int n = N % 60;

      System.out.println((res[n].ADDH + N/60) + " " + res[n].ADDT + " " + res[n].MINT + " " + res[n].ADDO + " " + res[n].MINO);
    }
  }
}

class Info{
  int t, ADDH, ADDT, MINT, ADDO, MINO;
  Info(int t, int ADDH, int ADDT, int MINT, int ADDO, int MINO){
    this.t = t;
    this.ADDH = ADDH;
    this.ADDT = ADDT;
    this.MINT = MINT;
    this.ADDO = ADDO;
    this.MINO = MINO;
  }
}