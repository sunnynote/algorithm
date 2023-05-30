/**
 * 23-05-30
 * BOJ 14215 세 막대
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    List<Integer> li = new ArrayList<>();

    for(int i=0; i<3; i++){
      li.add(Integer.parseInt(st.nextToken()));
    }

    Collections.sort(li);

    if(li.get(0) + li.get(1) > li.get(2)) {
      System.out.print(li.get(0) + li.get(1) + li.get(2));
    }
    else {
      System.out.print((li.get(0) + li.get(1)) * 2 - 1);
    }
  }
}
