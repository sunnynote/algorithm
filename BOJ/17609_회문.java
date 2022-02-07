/**
 * 22-02-07
 * BOJ 17609 회문
 * 투포인터
 * 반례 aapqbcbqpqaa, abbab
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class test {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        for(int i=0; i<N; i++){
            String s = br.readLine();

            func(s);
        }
    }

    static void func(String str){

        int l = 0;
        int r = str.length()-1;

        int cnt = 0;
        boolean left_f = true, right_f = true;

        while(l <= r){

            if(str.charAt(l)==str.charAt(r)){
                l++; r--;
            }
            else{
                cnt++;

                // left
                int left = l+1;
                int right = r;

                while(left < right){
                    if(str.charAt(left)==str.charAt(right)){
                        left++; right--;
                    }
                    else{
                        left_f = false;
                        cnt++;
                        break;
                    }
                }

                // right
                left = l;
                right = r-1;

                while (left < right){
                    if(str.charAt(left)==str.charAt(right)){
                        left++; right--;
                    }
                    else{
                        right_f = false;
                        cnt++;
                        break;
                    }
                }

                if(cnt>1) break;
            }
        }

        if(cnt==0) System.out.println(0);
        else if(cnt>1 && (left_f || right_f)) System.out.println(1);
        else System.out.println(2);
    }
}