#include <iostream>
#include <queue>

using namespace std;

short node[1000][10000];
short len[1000] = {0,};
short searched_DFS[1000];
short searched_BFS[1000];
short d_len = 0;
short b_len = 0;
queue<short> bqueue;

void insrt (short node1, short node2){
    // node1 first
    int i=0;
    for (; i<len[node1-1]; i++){
        if ( node[node1-1][i] > node2 )
            break;
    }
    for (int j=len[node1-1]-1; i<=j; j--)
        node[node1-1][j+1] = node[node1-1][j];
    node[node1-1][i] = node2;
    len[node1-1]++;

    // node2
    i=0;
    for (; i<len[node2-1]; i++){
        if ( node[node2-1][i] > node1 )
            break;
    }
    for (int j=len[node2-1]-1; i<=j; j--)
        node[node2-1][j+1] = node[node2-1][j];
    node[node2-1][i] = node1;
    len[node2-1]++;
}

short notSearched_DFS (short node){
    for(int i=0; i<d_len; i++){
        if ( searched_DFS[i] == node )
            return 0;
    }
    return 1;
}

short notSearched_BFS (short node){
    for(int i=0; i<b_len; i++){
        if ( searched_BFS[i] == node )
            return 0;
    }
    return 1;
}

void search_DFS(short V){
    if (notSearched_DFS(V)){
        cout << V << " ";
        searched_DFS[d_len++] = V;
        for(int i=0; i<len[V-1]; i++){
            search_DFS(node[V-1][i]);
        }
    }
}

void search_BFS(){
    while (!bqueue.empty()){
        short V = bqueue.front();
        bqueue.pop();
        if (notSearched_BFS(V)){
            cout << V << " ";
            searched_BFS[b_len++] = V;
            for(int i=0; i<len[V-1]; i++){
                bqueue.push(node[V-1][i]);
            }
        }
    }
}

int main()
{
    short N, M, V;
    cin >> N >> M >> V;
    for(int i=0; i<M; i++){
        short tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        insrt(tmp1, tmp2);
    }
    search_DFS(V);
    cout << endl;
    bqueue.push(V);
    search_BFS();
}
