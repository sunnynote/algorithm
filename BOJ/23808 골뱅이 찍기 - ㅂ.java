/**
 * 23-10-10
 * BOJ 23808 골뱅이 찍기 - ㅂ
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());

    for(int i=0; i<N*2; i++){
      for(int j=0; j<N; j++){
        System.out.print("@");
      }
      for(int j=0; j<N*3; j++){
        System.out.print(" ");
      }
      for(int j=0; j<N; j++){
        System.out.print("@");
      }
      System.out.println();
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<N*5; j++){
        System.out.print("@");
      }
      System.out.println();
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        System.out.print("@");
      }
      for(int j=0; j<N*3; j++){
        System.out.print(" ");
      }
      for(int j=0; j<N; j++){
        System.out.print("@");
      }
      System.out.println();
    }

    for(int i=0; i<N; i++){
      for(int j=0; j<N*5; j++){
        System.out.print("@");
      }
      System.out.println();
    }
  }
}
