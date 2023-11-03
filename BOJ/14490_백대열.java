/**
 * 23-11-03
 * BOJ 14490 백대열
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class d {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String s = br.readLine();

    String[] arr = s.split(":");

    int n1 = Integer.parseInt(arr[0]);
    int n2 = Integer.parseInt(arr[1]);

    // 최소 공약수 구하기
    int val = gcd(n1, n2);

    System.out.print(n1 / val + ":" + n2/val);

  }

  static int gcd(int n1, int n2){
    if(n2 == 0) return n1;
    return gcd(n2, n1 % n2);
  }
}
