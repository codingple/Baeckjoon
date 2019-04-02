#include <iostream>
#include <cstdio>

using namespace std;

typedef struct state{
    unsigned int num;
    unsigned int div;
    unsigned int remain;
}state;

state arr[10000];
int len;
int N;
int K;

int main()
{
    long long sum = 0;
    cin >> K >> N;

    for(int i=0; i<K; i++){
        state tmp;
        scanf("%u", &tmp.num);
        sum += tmp.num;
        arr[len++] = tmp;
    }

    unsigned int crnt = sum / N;
    unsigned int cnt = 0;

    for(int i=0; i<K; i++){
        arr[i].div = arr[i].num / crnt;
        cnt += arr[i].div;
        arr[i].remain = arr[i].num % crnt;
        unsigned int tmp = (crnt - arr[i].remain) / (1+arr[i].div);
        arr[i].num = ((crnt - arr[i].remain) % (1+arr[i].div) == 0)? tmp : tmp+1;
    }

    while(cnt<N){
        unsigned int mn = arr[0].num;
        for(int i=1; i<K; i++)
            mn = (arr[i].num < mn)? arr[i].num : mn;
        crnt -= mn;
        for(int i=0; i<K; i++){
            arr[i].num -= mn;
            if ( arr[i].num == 0){
                arr[i].remain = (mn*arr[i].div+arr[i].remain) - crnt;
                arr[i].div++;
                unsigned int tmp = (crnt - arr[i].remain) / (1+arr[i].div);
                arr[i].num = ((crnt - arr[i].remain) % (1+arr[i].div) == 0)? tmp : tmp+1;
                cnt++;
            }
        }
    }

    cout << crnt << endl;

    return 0;
}
