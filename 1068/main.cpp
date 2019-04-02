#include <iostream>
#define maxi 49
using namespace std;

int numLeaf (int x, int all[][maxi], int * leaf){
    if ( leaf[x] != -1 )
        return leaf[x];
    else if ( all[x][0] == -1 ){
        leaf[x] = 1;
        return 1;
    }
    else{
        int sum = 0;
        for (int i=0; all[x][i]!= -1; i++)
            sum += numLeaf(all[x][i], all, leaf);
        return sum;
    }
}

int main()
{
    int N;
    int n, root;
    cin >> N;

    int AllList[N][maxi]={-1,};
    for (int i=0; i<N; i++)
        fill_n(AllList[i], maxi, -1);

    for(int i=0; i<N; i++){
        cin >> n;
        // n == root
        if (n == -1){
            root = i;
        }
        // n != root
        else{
            int j = 0;
            while ( AllList[n][j] != -1 )
                j++;
            AllList[n][j] = i;
        }
    }

    int x;
    int leaf[N];
    fill_n(leaf, N, -1);
    cin >> x;
    int parent = -1;

    for (int i=0; i<N; i++){
        for(int j=0; AllList[i][j]!=-1; j++ ){
            if (AllList[i][j] == x)
                parent = i;
        }
    }

    int X = numLeaf(x, AllList, leaf);
    int Root = numLeaf(root, AllList, leaf);

    if ( parent != -1 && X == numLeaf(parent, AllList, leaf) )
        cout << Root - X + 1 << endl;
    else
        cout << Root - X << endl;

    return 0;
}
