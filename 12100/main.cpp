# include <iostream>

using namespace std;
typedef struct state{
    unsigned int cnt;
    unsigned int max;
    unsigned int map[20][20];
}state;

void display (unsigned int N, state s){
    cout << "cnt : " << s.cnt << endl;
    for(unsigned int i=0; i<N; i++){
        for(unsigned int j=0; j<N; j++){
            cout << s.map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

unsigned int go(state st, unsigned int N);
void mov(state * s, unsigned int N, unsigned int k);
void mov2(state * s, unsigned int N, unsigned int k);

unsigned int go(state st, unsigned int N){
    unsigned int result = st.max;
    st.cnt++;
    // last
    if (st.cnt>6)
        return 0;
    unsigned int res = -1;
    // left
    state tmp = st;
    mov(&tmp, N, 0);
    //display(N, tmp);
    res = go(tmp, N);
    result = (result < res)? res : result;
    // right
    tmp = st;
    mov(&tmp, N, 1);
    //display(N, tmp);
    res = go(tmp, N);
    result = (result < res)? res : result;
    // down
    tmp = st;
    mov2(&tmp, N, 2);
    //display(N, tmp);
    res = go(tmp, N);
    result = (result < res)? res : result;
    // up
    tmp = st;
    mov2(&tmp, N, 3);
    //display(N, tmp);
    res = go(tmp, N);
    result = (result < res)? res : result;

    return result;
}

int dir[4][5];

void declare_dir(unsigned int N){
    int tmp[4][5] = {
            // left
            {0, N, 1, 0, -1},
            // right
            {N-1, -1, -1, 0, 1},
            // down
            {N-1, -1, -1, 1, 0},
            // up
            {0, N, 1, -1, 0}
    };
    for(unsigned int i=0; i<4; i++){
        for(unsigned int j=0; j<5; j++){
            dir[i][j] = tmp[i][j];
        }
    }
}

void mov2(state * s, unsigned int N, unsigned int k){
    unsigned int row = dir[k][0];
    unsigned int col = dir[k][0];
    unsigned int idx = 0;
    // dir[k]
    for(unsigned int j=dir[k][0]; j!=dir[k][1]; j+=dir[k][2]){
        row = dir[k][0] - (idx * (dir[k][3]));
        col = dir[k][0] - (idx * (dir[k][4]));
        unsigned int chk = 1;
        for(unsigned int i=dir[k][0]; i!=dir[k][1]; i+=dir[k][2]){
            if ( s->map[i][j] != 0 ){
                // not first move
                if ( row != dir[k][0] - (idx * (dir[k][3])) || col != dir[k][0] - (idx * (dir[k][4]))  ){
                    // same num
                    if ( s->map[col + (dir[k][3])][row + (dir[k][4])] == s->map[i][j] ){
                        // just merge
                        if (chk){
                            // merged
                            s->map[col + (dir[k][3])][row + (dir[k][4])] *= 2;
                            // removed
                            s->map[i][j] = 0;
                            // check merged num is the max
                            if ( s->max < s->map[col + (dir[k][3])][row + (dir[k][4])] )
                                s->max = s->map[col + (dir[k][3])][row + (dir[k][4])];
                            chk = 0;
                            continue;
                        }
                    }
                }

                // same position
                if ( j == row && i == col ){
                    col -= (dir[k][3]);
                    row -= (dir[k][4]);
                    continue;
                }

                // Or just move
                s->map[col][row] = s->map[i][j];
                s->map[i][j] = 0;
                col -= (dir[k][3]);
                row -= (dir[k][4]);
                chk = 1;
            }
        }
        idx++;
    }

}

void mov(state * s, unsigned int N, unsigned int k){
    unsigned int row = dir[k][0];
    unsigned int col = dir[k][0];
    unsigned int idx = 0;
    // dir[k]
    for(unsigned int i=dir[k][0]; i!=dir[k][1]; i+=dir[k][2]){
        row = dir[k][0] - (idx * (dir[k][3]));
        col = dir[k][0] - (idx * (dir[k][4]));
        unsigned int chk = 1;
        for(unsigned int j=dir[k][0]; j!=dir[k][1]; j+=dir[k][2]){
            if ( s->map[i][j] != 0 ){
                // not first move
                if ( row != dir[k][0] - (idx * (dir[k][3])) || col != dir[k][0] - (idx * (dir[k][4]))  ){
                    // same num
                    if ( s->map[col + (dir[k][3])][row + (dir[k][4])] == s->map[i][j] ){
                        // just merge
                        if (chk){
                            // merged
                            s->map[col + (dir[k][3])][row + (dir[k][4])] *= 2;
                            // removed
                            s->map[i][j] = 0;
                            // check merged num is the max
                            if ( s->max < s->map[col + (dir[k][3])][row + (dir[k][4])] )
                                s->max = s->map[col + (dir[k][3])][row + (dir[k][4])];
                            chk = (chk+1) % 2;
                            continue;
                        }
                    }
                }

                // same position
                if ( j == row && i == col ){
                    col -= (dir[k][3]);
                    row -= (dir[k][4]);
                    continue;
                }

                // Or just move
                s->map[col][row] = s->map[i][j];
                s->map[i][j] = 0;
                col -= (dir[k][3]);
                row -= (dir[k][4]);
                chk = 1;
            }
        }
        idx++;
    }

}

int main (void){
    unsigned int N;
    cin >> N;
    declare_dir(N);
    state init;
    init.cnt=0;
    init.max=0;
    // fill num unsigned into allCase
    for (unsigned int i=0; i<N; i++){
        for(unsigned int j=0; j<N; j++){
            unsigned int tmp;
            cin >> tmp;
            init.map[i][j] = tmp;
            init.max = (init.max < tmp)? tmp : init.max;
        }
    }

    cout << go(init, N) << endl;
    return 0;
}
