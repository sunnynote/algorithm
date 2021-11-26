import java.io.*;
public class p2553 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        long val = 1;

        for(int i=1; i<=N; i++){
            val *= i;

            val %= 1000000000;
            while(true){
                if(val%10==0)
                    val/=10;
                else break;
            }
        }

        System.out.println(val%10);
    }
}