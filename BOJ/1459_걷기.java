import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ㄴ {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    long X = Long.parseLong(st.nextToken());
    long Y = Long.parseLong(st.nextToken());
    long W = Long.parseLong(st.nextToken()); // 한 블록 가는데 걸리는 시간
    long S = Long.parseLong(st.nextToken()); // 한 블록을 가로지르는 시간

    long ans = Long.MAX_VALUE;

    // case1. 수평 이동시
    if(2 * W < S){
      ans = (X + Y) * W;
    }
    else{

      // case2. 대각선 이동 시
      if((X+Y) % 2 == 0){
        ans = Math.min(ans, Math.max(X, Y)*S);
      }
      else {
        ans = Math.min(ans, (Math.max(X, Y) - 1)*S + W);
      }
    }

    ans = Math.min(ans, Math.min(X, Y)*S + Math.abs(X - Y)*W);

    System.out.println(ans);
  }
}
