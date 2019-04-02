#include <iostream>

using namespace std;

int num[500][500];
int N, M, result;

// right, left, up, down
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

// out of range
int inRange(int i, int j){
    return (i>=0 && i<N && j>=0 && j<M)? 1 : 0;
}

// all tetroino cases up to 13
void check(int i, int j){
    int crnt = num[i][j];

    int r1_i = i + dir[0][0];
    int r1_j = j + dir[0][1];
    int r2_i = r1_i + dir[0][0];
    int r2_j = r1_j + dir[0][1];
    int r3_i = r2_i + dir[0][0];
    int r3_j = r2_j + dir[0][1];
    int d1_i = i + dir[3][0];
    int d1_j = j + dir[3][1];
    int d2_i = d1_i + dir[3][0];
    int d2_j = d1_j + dir[3][1];
    int d3_i = d2_i + dir[3][0];
    int d3_j = d2_j + dir[3][1];
    int r1_d1_i = r1_i + dir[3][0];
    int r1_d1_j = r1_j + dir[3][1];
    int d2_r1_i = d2_i + dir[0][0];
    int d2_r1_j = d2_j + dir[0][1];
    int r2_u1_i = r2_i + dir[2][0];
    int r2_u1_j = r2_j + dir[2][1];
    int r1_u1_i = r1_i + dir[2][0];
    int r1_u1_j = r1_j + dir[2][1];
    int d1_l1_i = d1_i + dir[1][0];
    int d1_l1_j = d1_j + dir[1][1];
    int d2_l1_i = d2_i + dir[1][0];
    int d2_l1_j = d2_j + dir[1][1];
    int r2_d1_i = r2_i + dir[3][0];
    int r2_d1_j = r2_j + dir[3][1];

    int chk_r1 = inRange(r1_i, r1_j);
    int chk_r2 = inRange(r2_i, r2_j);
    int chk_r3 = inRange(r3_i, r3_j);
    int chk_d1 = inRange(d1_i, d1_j);
    int chk_d2 = inRange(d2_i, d2_j);
    int chk_d3 = inRange(d3_i, d3_j);
    int chk_r1_d1 = inRange(r1_d1_i, r1_d1_j);
    int chk_d2_r1 = inRange(d2_r1_i, d2_r1_j);
    int chk_r1_u1 = inRange(r1_u1_i, r1_u1_j);
    int chk_r2_u1 = inRange(r2_u1_i, r2_u1_j);
    int chk_d1_l1 = inRange(d1_l1_i, d1_l1_j);
    int chk_d2_l1 = inRange(d2_l1_i, d2_l1_j);
    int chk_r2_d1 = inRange(r2_d1_i, r2_d1_j);

    if (chk_r1){
        int r1 = num[r1_i][r1_j];
        if (chk_r2){
            int r2 = num[r2_i][r2_j];
            // 1
            if (chk_r3){
                int tmp = crnt+r1+r2+num[r3_i][r3_j];
                result = (tmp > result)?tmp:result;

            }
            // 5
            if (chk_r2_u1){
                int tmp = crnt+r1+r2+num[r2_u1_i][r2_u1_j];
                result = (tmp > result)?tmp:result;
            }
            // 7
            if (chk_d1){
                int tmp = crnt+r1+r2+num[d1_i][d1_j];
                result = (tmp > result)?tmp:result;
            }
            // 10
            if (chk_r1_d1){
                int tmp = crnt+r1+r2+num[r1_d1_i][r1_d1_j];
                result = (tmp > result)?tmp:result;
            }
            // 12
            if (chk_r1_u1){
                int tmp = crnt+r1+r2+num[r1_u1_i][r1_u1_j];
                result = (tmp > result)?tmp:result;
            }
            // 15
            if (chk_r2_d1){
                int tmp = crnt+r1+r2+num[r2_d1_i][r2_d1_j];
                result = (tmp > result)?tmp:result;
            }
        }
        if (chk_r1_d1){
            int r1_d1 = num[r1_d1_i][r1_d1_j];
            // 3
            if (chk_d1){
                int tmp = crnt+r1+r1_d1+num[d1_i][d1_j];
                result = (tmp > result)?tmp:result;
            }
            // 6
            if (chk_d2_r1){
                int tmp = crnt+r1+r1_d1+num[d2_r1_i][d2_r1_j];
                result = (tmp > result)?tmp:result;
            }
            // 13
            if (chk_r1_u1){
                int tmp = crnt+r1+r1_d1+num[r1_u1_i][r1_u1_j];
                result = (tmp > result)?tmp:result;
            }
            // 19
            if (chk_r2_d1){
                int tmp = crnt+r1+r1_d1+num[r2_d1_i][r2_d1_j];
                result = (tmp > result)?tmp:result;
            }
        }
        // 9
        if (chk_r1_u1 && chk_r2_u1){
            int tmp = crnt+r1+num[r2_u1_i][r2_u1_j]+num[r1_u1_i][r1_u1_j];
            result = (tmp > result)?tmp:result;
        }
        // 16
        if (chk_d1 && chk_d2){
            int tmp = crnt+r1+num[d1_i][d1_j]+num[d2_i][d2_j];
            result = (tmp > result)?tmp:result;
        }
    }

    if (chk_d1){
        int d1 = num[d1_i][d1_j];
        if(chk_d2){
            int d2 = num[d2_i][d2_j];
            // 2
            if (chk_d3){
                int tmp = crnt+d1+d2+num[d3_i][d3_j];
                result = (tmp > result)?tmp:result;
            }
            // 4
            if (chk_d2_r1){
                int tmp = crnt+d1+d2+num[d2_r1_i][d2_r1_j];
                result = (tmp > result)?tmp:result;
            }
            // 11
            if (chk_r1_d1){
                int tmp = crnt+d1+d2+num[r1_d1_i][r1_d1_j];
                result = (tmp > result)?tmp:result;
            }
            // 14
            if (chk_d2_l1){
                int tmp = crnt+d1+d2+num[d2_l1_i][d2_l1_j];
                result = (tmp > result)?tmp:result;
            }
        }
        if (chk_r1_d1){
            int r1_d1 = num[r1_d1_i][r1_d1_j];
            // 8
            if (chk_d2_r1){
                int tmp = crnt+d1+r1_d1+num[d2_r1_i][d2_r1_j];
                result = (tmp > result)?tmp:result;
            }
            // 17
            if (chk_r2_d1){
                int tmp = crnt+d1+r1_d1+num[r2_d1_i][r2_d1_j];
                result = (tmp > result)?tmp:result;
            }
        }
        // 18
        if (chk_d1_l1 && chk_d2_l1){
            int tmp = crnt+d1+num[d1_l1_i][d1_l1_j]+num[d2_l1_i][d2_l1_j];
            result = (tmp > result)?tmp:result;
        }
    }
}

int main()
{
    int tmp;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> tmp;
            num[i][j] = tmp;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            check(i, j);
        }
    }

    cout << result << endl;
}
