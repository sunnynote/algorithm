/**
 * 23-11-14
 * BOJ 15719 중복된 숫자
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    StringTokenizer st = new StringTokenizer(br.readLine());

    long sum = 0;
    for(int i=0; i<N; i++){
      sum += Integer.parseInt(st.nextToken());
    }

    sum -= ((long)N * (long)(N-1)) / 2;

    System.out.print(sum);
  }
}
