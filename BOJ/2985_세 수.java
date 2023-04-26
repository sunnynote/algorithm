/**
 * 23-04-26
 * BOJ 2985 세 수
 */

import java.io.*;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());

    if(a + b == c) System.out.println(a + "+" + b + "=" + c);
    else if(a - b == c) System.out.println(a + "-" + b + "=" + c);
    else if(a / b == c) System.out.println(a + "/" + b + "=" + c);
    else if(a * b == c) System.out.println(a + "*" + b + "=" + c);
    else if(a == b + c) System.out.println(a + "=" + b + "+" + c);
    else if(a == b - c) System.out.println(a + "=" + b + "-" + c);
    else if(a == b / c) System.out.println(a + "=" + b + "/" + c);
    else System.out.println(a + "=" + b + "*" + c);
  }
}
