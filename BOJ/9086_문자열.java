/**
 * 23-02-24
 * BOJ 9086 문자열
 */

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int T = Integer.parseInt(br.readLine());

    for(int t = 0; t < T; t++){
      String s = br.readLine();

      System.out.print(s.charAt(0));
      System.out.println(s.charAt(s.length() - 1));
    }
  }
}
