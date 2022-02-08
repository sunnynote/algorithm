/**
 * 22-02-08
 * BOJ 2436 공약수
 * 약수
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class test {
    static int x, y, a, b;
    static long mnA, mnB;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        int tmp = y/x;

        for(int i=1; i*i<=tmp; i++){
            // 약수 구하기
            if(tmp%i==0){
                a = i;
                b = tmp/i;

               // 서로소 판별
                boolean f = true;
                int cnt = 0;

                for(int j=1; j<=a; j++){
                    if(a%j==0 && b%j==0)
                        cnt++;

                    // 약수 2개 이상이면 X
                    if (cnt>=2) {
                        f = false;
                        break;
                    }
                }

                if(f){
                    mnA = a * x;
                    mnB = b * x;
                }
            }
        }

        System.out.println(mnA + " " + mnB);
    }
}