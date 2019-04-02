import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner (System.in);
        int N = s.nextInt();

        // N % 5 == 0
        if ( N % 5 == 0 )
            System.out.println(N/5);
        else{
            // N = 5 * x + 3 * y
            int tmp = 0;
            for (int i=1; 5*i<N; i++){
                if ( (N-(5*i))%3 == 0 )
                    tmp = i;
            }
            if (tmp != 0)
                System.out.println( tmp + (( N-(5*tmp) )/3) );
            // N % 3
            else if ( N % 3 == 0 )
                System.out.println( N/3 );
            else
                System.out.println(-1);
        }
    }
}
