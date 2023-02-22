/**
 * 23-02-22
 * BOJ 1183 약속
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    int N = Integer.parseInt(br.readLine());
    int[] li = new int[N];

    for (int i = 0; i < N; i++) {
      st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      li[i] = b - a;
    }

    Arrays.sort(li);

    if (N % 2 == 1) System.out.println(1);
    else System.out.println(li[N / 2] - li[N / 2 - 1] + 1);
  }
}
