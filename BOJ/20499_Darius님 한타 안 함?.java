/**
 * 23-08-22
 * BOJ 20499 Darius님 한타 안 함?
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine(), "/");

    int K = Integer.parseInt(st.nextToken());
    int D = Integer.parseInt(st.nextToken());
    int A = Integer.parseInt(st.nextToken());

    if(K + A < D || D == 0) System.out.println("hasu");
    else System.out.print("gosu");
  }
}
