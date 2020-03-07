#include <iostream>
#include <cmath>

using namespace std;
int n;
int b, c;
int num[1000001];
long long res; // 오버플로우 방지
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    cin >> b >> c;

    for(int i=0; i<n; i++){
        res ++;
        // 총 감독관
        if(num[i] >= b){
            num[i] -= b;
        }
        else{
            num[i] = 0;
        }

        /* 풀이 1)
        // 부 감독관
        if(num[i] % c == 0)
            res += num[i] / c;
        else{
            res += num[i] / c + 1;
        }
        */
    }

    /* 풀이 2)
    //-> 왜 틀릴까?
    //부감독관
    for(int i=0; i<n; i++){
        res += ceil((float)num[i]/(float)c);

    }
    */


    //부감독관
    for(int i=0; i<n; i++){
        res += ceil((double)num[i]/(double)c);
    }


    cout << res;
}