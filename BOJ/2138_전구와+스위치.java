/**
 * 22-03-19
 * BOJ 2138 전구와 스위치
 * 그리디
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class test {
  static int N, answer;
  static int[][] arr;
  static int[] check;

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    arr = new int[2][N];
    check = new int[N];
    answer = Integer.MAX_VALUE;

    String input = br.readLine();
    String input2 = br.readLine();

    for (int i = 0; i < input.length(); i++) {
      arr[0][i] = input.charAt(i) - '0';
      arr[1][i] = input.charAt(i) - '0';
      check[i] = input2.charAt(i) - '0';
    }

    play(1, 0, 0);
    onoff(0, 1);
    play(1, 1, 1);

    System.out.println(answer == Integer.MAX_VALUE ? -1 : answer);
  }

  public static void onoff(int idx, int type) {
    for (int i = idx - 1; i <= idx + 1; i++) {
      if (0 <= i && i < N)
        arr[type][i] = arr[type][i] == 1 ? 0 : 1;
    }
  }

  public static void play(int idx, int type, int count) {
    if (idx == N) {
      if (arr[type][idx - 1] == check[idx - 1])
        answer = answer > count ? count : answer;
      return;
    }

    if (arr[type][idx - 1] != check[idx - 1]) {
      onoff(idx, type);
      play(idx + 1, type, count + 1);
    } else
      play(idx + 1, type, count);
  }
}