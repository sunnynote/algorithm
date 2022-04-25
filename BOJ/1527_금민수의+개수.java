/**
 * 22-04-25
 * BOJ 1527 금민수의 개수
 * BF
 */

import java.io.*;
import java.util.*;

public class test6 {

  static long A, B, ans;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st =  new StringTokenizer(br.readLine());

    A = Integer.parseInt(st.nextToken());
    B = Integer.parseInt(st.nextToken());

    solve(4);
    solve(7);

    System.out.println(ans);
  }

  static void solve(long n) {
    if(n > B) return;

    if(A <= n && n <= B) ans++;

    solve(n * 10 + 4);
    solve(n * 10 + 7);
  }
}