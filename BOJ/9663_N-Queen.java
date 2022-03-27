/**
 * 22-03-27
 * BOJ 9663 N-Queen
 * DFS
 */

import java.util.Scanner;

public class test3 {
  static int N, ans = 0;
  static boolean[] chk1 = new boolean[15];
  static boolean[] chk2 = new boolean[30];
  static boolean[] chk3 = new boolean[30];

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();

    dfs(0);
    System.out.println(ans);
  }

  static void dfs(int cnt){
    if(cnt==N){
      ans++;
      return;
    }

    for(int i=0; i<N; i++){
      if(!chk1[i] && !chk2[i + cnt] && !chk3[i - cnt + N - 1]){
        chk1[i] = true;
        chk2[i + cnt] = true;
        chk3[i - cnt + N - 1] = true;
        dfs(cnt + 1);
        chk1[i] = false;
        chk2[i + cnt] = false;
        chk3[i - cnt + N - 1] = false;
      }
    }
  }
}