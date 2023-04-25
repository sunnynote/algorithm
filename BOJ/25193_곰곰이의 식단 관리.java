/**
 * 23-04-25
 * BOJ 25193 곰곰이의 식단 관리
 */

import java.io.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    String s = br.readLine();
    char[] arr = s.toCharArray();

    int c_cnt = 0;
    int cnt = 0;
    for(int i=0; i<N; i++){
      if(arr[i] == 'C') c_cnt++;
      else cnt++;
    }

    if(c_cnt == 0) System.out.print(0);
    else if(cnt == 0) System.out.print(c_cnt);
    else if(cnt == 1) System.out.print( (c_cnt + 1) / 2);
    else if(c_cnt > cnt) System.out.print(c_cnt/(cnt+1) + (c_cnt%(cnt+1) == 0 ? 0 : 1));
    else System.out.print(1);
  }
}
