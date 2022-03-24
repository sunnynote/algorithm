/**
 * 22-03-24
 * BOJ 2877 4와 7
 * 구현
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class test3 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    N++;

    ArrayList<Integer> list = new ArrayList<>();

    while(N > 0){
      if(N % 2 == 0)
        list.add(4);
      else
        list.add(7);

      N /= 2;
    }

    StringBuilder sb = new StringBuilder();

    for(int i=0; i<list.size()-1; i++){
      sb.append(list.get(i));
    }

    System.out.println(sb.reverse());
  }
}