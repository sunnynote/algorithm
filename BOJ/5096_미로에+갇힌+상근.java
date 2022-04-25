/**
 * 22-04-25
 * BOJ 5096 미로에 갇힌 상근
 */

import java.io.*;
import java.util.*;

public class test6 {

  static long[] dp = {1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int T = Integer.parseInt(br.readLine());

    while(T-- > 0){
      int n = Integer.parseInt(br.readLine());

      System.out.println(dp[n]);
    }
  }
}