import java.io.*;

public class test3{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while(true){
            String s = br.readLine();
            if(s.equals("0")) break;

            int len = s.length();

            boolean f = true;
            for(int i=0; i<len/2; i++){
                char ch1 = s.charAt(i);
                char ch2 = s.charAt(len-i-1);
                if(ch1!=ch2){
                    f = false;
                    break;
                }
            }

            System.out.println(f ? "yes" : "no");
        }
    }
}