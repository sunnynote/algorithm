/**
 * 23-05-19
 * BOJ 8871 Zadanie próbne 2
 * 각 라운드 마다 2~3회의 작업이 가능하다.
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    System.out.print( 2*(N+1) + " " + 3*(N+1) );
  }
}
