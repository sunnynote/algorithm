/**
 * 23-05-09
 * BOJ 1271 엄청난 부자2
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    BigInteger N = new BigInteger(st.nextToken());
    BigInteger M = new BigInteger(st.nextToken());

    System.out.print(N.divide(M) + "\n" + N.remainder(M));
  }
}
