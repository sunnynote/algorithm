/**
 * 23-09-05
 * BOJ 28455 Union Maplestory
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    ArrayList<Integer> arr = new ArrayList<>();

    int sum = 0;
    int up = 0;
    for(int i=0; i<N; i++){
      arr.add(Integer.parseInt(br.readLine()));
    }

    if(N > 42){
      Collections.sort(arr, Collections.reverseOrder());
      N = 42;
    }

    for(int i=0; i<N; i++){
      int cur = arr.get(i);
      if(cur >= 60) up++;
      if(cur >= 100) up++;
      if(cur >= 140) up++;
      if(cur >= 200) up++;
      if(cur >= 250) up++;

      sum += cur;
    }

    System.out.println(sum + " " + up);
  }
}
