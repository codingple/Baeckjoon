import java.util.*;
public class Main {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        ArrayList<Tuple> arr = new ArrayList<Tuple>(N);

        for(int i=0; i<N; i++){
            Tuple t = new Tuple(s.nextInt(), s.nextInt());
            arr.add(t);
        }

        Collections.sort(arr, Tuple.oneCompare());
        Collections.sort(arr, Tuple.twoCompare());

        int cnt = 1;
        int chk = 0;
        int crr_last = arr.get(0).two();
        for (int i=1; i<N; i++){
            int first = arr.get(i).one();
            int last = arr.get(i).two();
            if ( first >= crr_last ){
                cnt++;
                crr_last = last;
            }
        }
        System.out.println(cnt);
    }
}

class Tuple{
    private final Integer x;
    private final Integer y;
    public Tuple(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int one() { return x;}
    public int two() { return y;}

    static Comparator<Tuple> oneCompare(){
        return new Comparator<Tuple>(){
            public int compare(Tuple X, Tuple Y){
                return X.x.compareTo(Y.x);
            }
        };
    }

    static Comparator<Tuple> twoCompare(){
        return new Comparator<Tuple>(){
            public int compare(Tuple X, Tuple Y){
                return X.y.compareTo(Y.y);
            }
        };
    }
}