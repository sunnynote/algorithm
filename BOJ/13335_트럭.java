/**
 * 23-06-26
 * BOJ 13335 트럭
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    int W = Integer.parseInt(st.nextToken());
    int L = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());

    Queue<Integer> truck = new LinkedList<>();

    for (int i=0; i<N; i++) {
      truck.add(Integer.parseInt(st.nextToken()));
    } // input end

    int cur = 0;
    int ans = 0;

    Queue<Integer> q = new LinkedList<>();

    for(int i=0; i<W; i++){
      q.add(0);
    }

    while (!q.isEmpty()) {
      ans++;
      cur -= q.poll();

      if(!truck.isEmpty()){
        if(cur + truck.peek() <= L){
          cur += truck.peek();
          q.add(truck.poll());
        }
        else{
          q.add(0);
        }
      }
    }

    System.out.print(ans);
  }
}
