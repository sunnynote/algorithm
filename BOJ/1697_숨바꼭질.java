/**
 * 22-04-27
 * BOJ 1697 숨바꼭질
 * BFS
 */

import java.io.*;
import java.util.*;

public class test6 {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());
    int[] chk = new int[100001];

    LinkedList<Integer> q = new LinkedList<>();
    q.add(N);
    chk[N] = 0;

    while(!q.isEmpty()){
      int x = q.poll();
      System.out.println(x + " " + chk[x]);
      if(x == K){
        System.out.println(chk[x]);
        break;
      }


      if(x + 1 <= 100000 && chk[x + 1] == 0){
        q.add(x + 1);
        chk[x + 1] = chk[x] + 1;
      }
      if(0 <= x - 1 && chk[x - 1] == 0){
        q.add(x - 1);
        chk[x - 1] = chk[x] + 1;
      }
      if(2 * x <= 100000 && chk[2 * x] == 0){
        q.add(2 * x);
        chk[2 * x] = chk[x] + 1;
      }
    }
  }
}