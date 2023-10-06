/**
 * 23-10-06
 * BOJ 23037 5의 수난
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s = br.readLine();

    int res = 0;

    for(int i=0; i<s.length(); i++){
      int n = s.charAt(i) - '0';
      res += (n * n * n * n * n);
    }

    System.out.print(res);
  }
}
