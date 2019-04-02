#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

typedef struct state{
    int i;
    int j;
}state;

int A[50][50];
int chk[50][50];
int N, L, R;
// left, right, up, down
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

int inRange(int i, int j){
    if(0<=i && i<N && 0<=j && j<N)
        return 1;
    return 0;
}

int openBorder(int a, int b){
    int t = abs(a - b);
    if (L<=t && t<=R)
        return 1;
    return 0;
}

void chk_init(){
    for(int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            chk[i][j] = 1;
        }
    }
}

int haveOpenedBorder(int i, int j){
    int cnt = 0;
    for(int k=0; k<4; k++){
        int nx_i = i + dir[k][0];
        int nx_j = j + dir[k][1];
        if (inRange(nx_i, nx_j) && chk[nx_i][nx_j] && openBorder(A[i][j], A[nx_i][nx_j]))
            cnt++;
    }
    return cnt;
}

queue< queue< state> > qq;

int main()
{
    int result = 0;
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }


    do{
        chk_init();
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(chk[i][j] && haveOpenedBorder(i, j)){
                    queue<state> tq;
                    queue<state> q;
                    state first = {i, j};
                    chk[i][j] = 0;
                    tq.push(first);
                    while(!tq.empty()){
                        state crnt = tq.front();
                        q.push(crnt);
                        for(int k=0; k<4; k++){
                            int nx_i = crnt.i + dir[k][0];
                            int nx_j = crnt.j + dir[k][1];
                            if (inRange(nx_i, nx_j) && chk[nx_i][nx_j] && openBorder(A[crnt.i][crnt.j], A[nx_i][nx_j])){
                                tq.push(state{nx_i, nx_j});
                                chk[nx_i][nx_j] = 0;
                            }
                        }
                        tq.pop();
                    }
                    qq.push(q);
                }
            }
        }
        if (qq.empty())
            break;
        result++;
        while(!qq.empty()){
            queue <state> crnt = qq.front();
            int sz = crnt.size();
            int sum = 0;
            while(!crnt.empty()){
                state s = crnt.front();
                sum += A[s.i][s.j];
                crnt.pop();
            }
            int num = sum / sz;
            crnt = qq.front();
            while(!crnt.empty()){
                state s = crnt.front();
                A[s.i][s.j] = num;
                crnt.pop();
            }
            qq.pop();
        }
    }while(1);

    cout << result << endl;

}
