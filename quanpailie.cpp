#include<iostream>
using namespace std;
const int N = 10;
int n;


void dfs(int u, int a[], bool st[])
{
    if(u>n){
        for(int i=1; i<=n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }else{
        for(int i=1; i<=n; i++){
            if(!st[i]){
                a[u] = i;
                st[i] = true;
                dfs(u+1, a, st);
                st[i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    int nums[n];
    bool st[] = {0};
    dfs(1, nums, st);
    return 0;
}

