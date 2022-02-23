/**
 * 22-02-23
 * BOJ 2696 중앙값 구하기
 * 우선순위 큐
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class test {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int T = Integer.parseInt(st.nextToken());
    int N;
    int[] arr;

    for(int t=0; t<T; t++){
      N = Integer.parseInt(br.readLine());
      arr = new int[N+1];
      int n = 0;

      if(N<=10) {
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
          arr[n++] = Integer.parseInt(st.nextToken());
      }
      else {
        int tmp;
        if(N%10==0) tmp = N/10;
        else tmp = N/10 + 1;
        for(int k=0; k<tmp; k++){
          st = new StringTokenizer(br.readLine());
          for(int i=0; i<10; i++){
            if(k==tmp-1 && N%10==i) break;
            arr[n++] = Integer.parseInt(st.nextToken());
          }
        }
      }

      PriorityQueue<Integer> l = new PriorityQueue<>(Collections.reverseOrder());
      PriorityQueue<Integer> r = new PriorityQueue<>();
      ArrayList<Integer> list = new ArrayList<>();

      for(int i=0; i<n; i++){
        if(l.isEmpty()) {
          l.add(arr[i]);
        }
        else if(l.peek() >= arr[i]){
          l.add(arr[i]);
        }
        else{
          r.add(arr[i]);
        }

        if(l.size() < r.size())
          l.add(r.poll());
        else if(l.size() > r.size() + 1)
          r.add(l.poll());

        if(i%2==1) continue;
        list.add(l.peek());
      }

      System.out.println(list.size());

      StringBuilder sb = new StringBuilder();
      for(int i=0; i<list.size(); i++){
        if(i!=0 && i%10==0) sb.append("\n");
        sb.append(list.get(i) + " ");
      }

      System.out.println(sb.toString());
    }
  }
}