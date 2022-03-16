/**
 * 22-03-16
 * BOJ 1715 카드 정렬하기
 * 우선순위 큐
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class test2 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    PriorityQueue<Integer> q = new PriorityQueue<>();

    for(int i=0; i<N; i++){
      q.add(Integer.parseInt(br.readLine()));
    }

    int ans = 0;
    while(!q.isEmpty()){
      int x = q.poll();

      if(!q.isEmpty()) {
        int y = q.poll();
        ans += (x + y);
        q.add(x + y);
      }
    }

    System.out.println(ans);
  }
}