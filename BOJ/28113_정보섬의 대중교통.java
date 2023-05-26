/**
 * 23-05-26
 * BOJ 28113 정보섬의 대중교통
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int A = Integer.parseInt(st.nextToken());
    int B = Integer.parseInt(st.nextToken());

    if(A < B) System.out.println("Bus");
    else if(A > B) System.out.println("Subway");
    else System.out.println("Anything");
  }
}