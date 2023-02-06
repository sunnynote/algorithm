/**
 * 23-02-06
 * BOJ 5525 IOIOI
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    int M = Integer.parseInt(br.readLine());
    String s = br.readLine();

    int answer = 0;

    for(int i=0; i<M; i++){
      if(s.charAt(i) == 'I'){
        int cnt = 0;

        while(true){
          if(i + 2 >= M) break;
          if(s.charAt(i+1) == 'O' && s.charAt(i+2) == 'I'){
            cnt++;
            i += 2;

            if(cnt == N){
              cnt--;
              answer++;
            }
          }
          else break;
        }
      }
    }

    System.out.print(answer);
  }
}
