#include <iostream>

using namespace std;

int N, H, M;

int map[30][10];

int inRange(int i, int j){
    if (0 <= i && i < H && 0 <= j && j <= N)
        return 1;
    return 0;
}

int agentReached(int j){
    int fin = j;
    for(int i=0; i<H; i++){
        if (map[i][j] == 1){
            j++;
        }
        else if (inRange (i,j-1) && map[i][j-1] )
            j--;
    }
    if ( j == fin)
        return 1;
    return 0;
}

int allSatisfied(){
    for(int i=0; i<N; i++){
        if (!agentReached(i))
            return 0;
    }
    return 1;
}

int cycle (int s){
    int i_1, j_1, i_2, j_2, i_3, j_3;
    // c >= 1
    for(i_1=0; i_1<H; i_1++){for(j_1=0; j_1<N-1; j_1++){
        if ( !map[i_1][j_1] && !map[i_1][j_1+1] && !(inRange(i_1, j_1-1) && map[i_1][j_1-1]) ){
            map[i_1][j_1] = 1;
            // c >= 2
            if (s > 1){
                for(i_2=i_1; i_2<H; i_2++){for(j_2=(i_2==i_1)? j_1+2 : 0; j_2<N-1; j_2++){
                    if ( !map[i_2][j_2] && !map[i_2][j_2+1] && !(inRange(i_2, j_2-1) && map[i_2][j_2-1]) ){
                        map[i_2][j_2] = 1;
                        // c >= 3
                        if (s > 2){
                            for(i_3=i_2; i_3<H; i_3++){for(j_3=(i_3==i_2)? j_2+2 : 0; j_3<N-1; j_3++){
                                if ( !map[i_3][j_3] && !map[i_3][j_3+1] && !(inRange(i_3, j_3-1) && map[i_3][j_3-1]) ){
                                    map[i_3][j_3] = 1;
                                    // c == 3
                                    if (allSatisfied()) return 3;
                                    map[i_3][j_3] = 0;
                                }
                            }}
                        }
                        // c == 2
                        else if (allSatisfied()) return 2;
                        map[i_2][j_2] = 0;
                    }
                }}
            }
            // c == 1
            else if (allSatisfied()) return 1;
            map[i_1][j_1] = 0;
        }
    }}
    return -1;
}

int main()
{
    int a, b;
    int result = -1;
    cin >> N >> M >> H;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }

    if (allSatisfied()) result = 0;
    else{
        for(int i=1; i<4; i++){
            result = cycle(i);
            if (result != -1) break;
        }
    }

    cout << result << endl;
    return 0;
}
