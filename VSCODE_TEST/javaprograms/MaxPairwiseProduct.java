import java.util.*;
import java.io.*;
public class MaxPairwiseProduct {

    static long getMaxPairwiseProduct(long [] numbers){
        long max_1=-1;
        int index_1=0;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]>max_1){
                max_1=numbers[i];
                index_1=i;
            }
                 
        }
        long max_2=-1;
        for(int i=0;i<numbers.length;i++){
            if(numbers[i]>max_2&&i!=index_1)
                max_2=numbers[i];   
        }
      //  System.out.println("index 1: "+max_1+" index 2: "+max_2);
        return max_1*max_2;
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        long n = scanner.nextLong();
        long[] numbers = new long[(int)n];
        for (int i = 0; i < n; i++) {
        numbers[i] = scanner.nextLong();
        }
        System.out.println(getMaxPairwiseProduct(numbers));
        }

        static class FastScanner {
            BufferedReader br;
            StringTokenizer st;
            FastScanner(InputStream stream) {
            try {
            br = new BufferedReader(new
            InputStreamReader(stream));
            } catch (Exception e) {
            e.printStackTrace();
            }
            }
            String next() {
            while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
} catch (IOException e) {
e.printStackTrace();
}
}
return st.nextToken();
}
long nextLong() {
return Long.parseLong(next());
}
}

                 
}