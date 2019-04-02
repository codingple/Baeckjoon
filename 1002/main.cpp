#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int ts=0; ts<T; ts++){
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double D = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

        // D = 0
        if (D == 0){
            // equal circle
            if ( r1 == r2 )
                cout << -1 << endl;
            // never
            else if ( r1 != r2 )
                cout << 0 << endl;
            else
                cout << "ERROR" << endl;
        }

        // D > 0
        else if ( D > 0 ){
            // too far
            if ( D > r1+r2 )
                cout << 0 << endl;
            // adjacent
            else if ( D == r1+r2 )
                cout << 1 << endl;
            // close enough
            else if ( D < r1+r2){
                // inner adjacent
                if ( abs(r1-r2) == D )
                    cout << 1 << endl;
                // 2 of adjacent
                else if ( abs(r1-r2) < D )
                    cout << 2 << endl;
                // inner circle
                else if ( abs(r1-r2) > D )
                    cout << 0 << endl;
                else
                    cout << "ERROR" << endl;
            }
            else
                cout << "ERROR" << endl;
        }

        else
            cout << "ERROR" << endl;\
    }
    return 0;
}
