import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 * 22-01-19
 * BOJ 5904 Moo 게임
 * 분할정복
 */

public class p5904 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int len = 3;
        int midLen = 3;

        while(N > len) {
            midLen++;
            len = len * 2 + midLen;
        }

        while(true){
            int leftLen = (len - midLen)/2;

            if(N <= leftLen){
                midLen--;
                len = leftLen;
            }
            else if(N > leftLen+midLen){
                N -= (leftLen + midLen);
                len = leftLen;
                midLen--;
            }
            else{
                N -= leftLen;
                break;
            }
        }

        if(N==1) System.out.println("m");
        else System.out.println("o");
    }
}
