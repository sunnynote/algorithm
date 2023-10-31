/**
 * 23-10-31
 * BOJ 28431 양말 짝 맞추기
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int[] arr = new int[10];

    for(int i=0; i<5; i++){
      int n = Integer.parseInt(br.readLine());
      if(arr[n] == 0) arr[n]++;
      else arr[n]--;
    }

    for(int i=0; i<10; i++){
      if(arr[i] == 1){
        System.out.print(i);
        break;
      }
    }
  }
}
