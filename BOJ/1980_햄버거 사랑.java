/**
 * 23-05-12
 * BOJ 1980 햄버거 사랑
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int M = Integer.parseInt(st.nextToken());
    int T = Integer.parseInt(st.nextToken());

    // swap
    if(N > M){
      int tmp = N;
      N = M;
      M = tmp;
    }

    int coke = Integer.MAX_VALUE;
    int res = -1;

    for(int i=T/N; i>=0; i--){
      int t = T;
      t -= (N * i);

      int m = t / M;
      t -= (M * m);

      if(t == 0){
        coke = 0;
        res = (i + m);
        break;
      }
      else{
        if(coke > t){
          coke = t;
          res = (i + m);
        }
      }
    }

    System.out.println(res + " " + coke);
  }
}
