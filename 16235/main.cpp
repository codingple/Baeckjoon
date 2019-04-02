#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
int A[10][10];
int C[10][10];
int die[10][10];
vector <int> tree[10][10];
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void init(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] = 5;
            sort(tree[i][j].begin(), tree[i][j].end(), greater<int>());
            die[i][j] = 0;
        }
    }
}

void spring(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (tree[i][j].empty()) continue;
            for(int k = tree[i][j].size()-1; k >= 0; k--){
                // drink
                if (tree[i][j][k] <= C[i][j] ){
                    C[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                }
                // die
                else{
                    die[i][j] += tree[i][j][k] / 2;
                    tree[i][j].erase(tree[i][j].begin()+k);
                }
            }
        }
    }
}


int inRange(int i, int j){
    if(0<=i && i<N && 0<=j && j<N)
        return 1;
    return 0;
}

void summer(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] += die[i][j];
            die[i][j] = 0;
        }
    }
}

void fall(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if (tree[i][j].empty()) continue;
            vector<int>::iterator iter;
            for(iter=tree[i][j].begin(); iter!=tree[i][j].end(); iter++){
                if (*iter!= 0 && *iter % 5 == 0){
                    for(int k=0; k<8; k++){
                        int nw_i = i+dir[k][0];
                        int nw_j = j+dir[k][1];
                        if (inRange(nw_i, nw_j))
                            tree[nw_i][nw_j].push_back(1);
                    }
                }
            }
        }
    }
}

void winter(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            C[i][j] += A[i][j];
        }
    }
}


int main(){
    int r, c, v;
    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin >> A[i][j];
    }
    for(int i=0; i<M; i++){
        cin >> r >> c >> v;
        r--; c--;
        tree[r][c].push_back(v);
    }

    init();
    for(int i=0; i<K; i++){
        spring();
        summer();
        fall();
        winter();
    }
    int result=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result += tree[i][j].size();
        }
    }

    cout << result << endl;
}
