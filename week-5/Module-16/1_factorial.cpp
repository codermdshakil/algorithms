#include <bits/stdc++.h>
using namespace std;
// O(N)
int fact(int n){

    // basecase
    if(n==0){
        return 1;
    }

    int result = n * fact(n-1);
    return result;
}

int main(){

    int n;
    cin>>n;

    // using factorial 
    int result = fact(n);
    cout << result << endl;

    // O(N) - using loop
    // int ans = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     ans*= i;
    // }
    // cout << ans << endl;
    

    return 0;
}