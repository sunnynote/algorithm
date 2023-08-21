/**
 * 23-08-21
 * BOJ 9237 이장님 초대
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class ㅇ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());
    ArrayList<Integer> arr = new ArrayList<>();

    StringTokenizer st = new StringTokenizer(br.readLine());

    for(int i=0; i<N; i++){
      arr.add(Integer.parseInt(st.nextToken()));
    }

    Collections.sort(arr, Collections.reverseOrder());

    int mx = -1;
    for(int i=0; i<arr.size(); i++){
      arr.set(i, + (arr.get(i) + i + 1));
      if(mx < arr.get(i)) mx = arr.get(i);
    }

    System.out.print(mx + 1);
  }
}
