/**
 * 23-11-01
 * BOJ 11507 카드셋트
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String s = br.readLine();

    int[][] arr = new int[4][14];

    for(int i=0; i<s.length(); i+=3){
      char c = s.charAt(i);
      int n1 = s.charAt(i+1) - '0';
      int n2 = s.charAt(i+2) - '0';

      int n = n1 * 10 + n2;

      if(c == 'P') arr[0][n]++;
      if(c == 'K') arr[1][n]++;
      if(c == 'H') arr[2][n]++;
      if(c == 'T') arr[3][n]++;
    }

    boolean f = false;
    int[] ans = {13, 13, 13, 13};

    for(int i=0; i<4; i++){
      for(int j=1; j<=13; j++){
        if(arr[i][j] > 1){
          f = true;
        }
        if(arr[i][j] == 1) ans[i]--;
      }
    }

    if(f) System.out.print("GRESKA");
    else{
      System.out.print(ans[0] + " " + ans[1] + " " + ans[2] + " " + ans[3]);
    }
  }
}
