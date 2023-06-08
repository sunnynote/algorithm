/**
 * 23-06-08
 * BOJ 5635 생일
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class s {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    int N = Integer.parseInt(st.nextToken());
    String[][] arr = new String[N][4];

    for(int i=0; i<N; i++){
      st = new StringTokenizer(br.readLine());

      arr[i][0] = st.nextToken();
      arr[i][1] = st.nextToken();
      arr[i][2] = st.nextToken();
      arr[i][3] = st.nextToken();
    }

    Arrays.sort(arr, new Comparator<String[]>() {
      @Override
      public int compare(String[] o1, String[] o2) {
        if(Integer.parseInt(o1[3]) == Integer.parseInt(o2[3])){ // year
          if(Integer.parseInt(o1[2]) == Integer.parseInt(o2[2])){ // month
            return Integer.compare(Integer.parseInt(o1[1]), Integer.parseInt(o2[1]));
          }
          return Integer.compare(Integer.parseInt(o1[2]), Integer.parseInt(o2[2]));
        }
        return Integer.compare(Integer.parseInt(o1[3]), Integer.parseInt(o2[3]));
      }
    });

    System.out.println(arr[N-1][0] + '\n' + arr[0][0]);
  }
}
