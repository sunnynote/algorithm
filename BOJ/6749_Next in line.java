/**
 * 23-07-19
 * BOJ 6749 Next in line
 */

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n1 = Integer.parseInt(br.readLine());
    int n2 = Integer.parseInt(br.readLine());

    System.out.println(n2 * 2 - n1);
  }
}
