/**
 * 23-06-01
 * BOJ 2659 십자카드 문제
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());
    int d = Integer.parseInt(st.nextToken());

    // 입력 값의 시계수 찾기
    int val = a * 1000 + b * 100 + c * 10 + d;
    int res = clock_num(val);

    // 모든 시계수 구하기
    boolean[] chk = new boolean[10000]; // 시계수이면 t

    for(int i=1111; i<=9999; i++){
      boolean f = true;
      int cur = i;

      for(int j=0; j<4; j++){
        if(cur % 10 == 0) f = false;
        cur /= 10;
      }

      if(!f) continue;

      chk[clock_num(i)] = true;
    }

    // 몇번째인지 체크하기
    int ans = 0;
    for(int i=1111; i<=res; i++){
      if(chk[i]) ans++;
    }

    System.out.print(ans);
  }

  public static int clock_num(int n){
    int mn = n;

    for(int i=0; i<3; i++){
      int tmp = n / 1000;

      n -= tmp * 1000;
      n *= 10;
      n += tmp;

      if(mn > n) mn = n;
    }

    return mn;
  }
}
