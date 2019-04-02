#include <iostream>

using namespace std;

int func1 (int x){
    return (x%3==0 && x/3 >= 1) ? x/3 : 0;
}

int func2 (int x){
    return (x%2==0 && x/2 >=1) ? x/2 : 0;
}

int func3 (int x){
    return (x-1 >= 1) ? x-1 : 0;
}

int minimum (int x, int y, int z){
    int num =0;
    int res = 0;
    int tmp[] = {x, y, z};
    int arr[3] ={0,};
    for(int i=0; i<3; i++){
        if (*(tmp+i) > 0 ){
            arr[num] = *(tmp+i);
            num++;
        }
    }
    if (num == 0)
        return 0;

    res = arr[0];

    for(int i=1; i<num; i++){
        if (res > arr[i])
            res = arr[i];
    }

    return res;
}

int go_DP (int X, int * memo){
    int tmp[] = {func1(X), func2(X), func3(X)};

    for(int i=0; i<3; i++){
        // zero
        if ( tmp[i] == 0 )
            continue;
        // memo
        else if ( *(memo+(tmp[i]-1)) != 0 )
            tmp[i] = *(memo+(tmp[i]-1));
        // contain 1
        else if ( tmp[i] == 1 ){
            *(memo+(tmp[i]-1)) = 1;
            return 1;
        }
        // go_DP
        else{
            *(memo+(tmp[i]-1)) = go_DP(tmp[i], memo) + 1;
            tmp[i] = *(memo+(tmp[i]-1));
        }
    }

    return minimum(tmp[0],tmp[1],tmp[2]);
}



int main()
{
    int X;
    cin >> X;
    int memo[X] = {0,};
    cout << go_DP(X, memo);

    return 0;
}
