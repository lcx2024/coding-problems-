#include<iostream>
using namespace std;
const int N = 10;  // 最大支持生成10个数的全排列
int n;             // 实际输入的数字范围(1~n)

/*
深度优先搜索函数：生成全排列
u: 当前正在填充的位置(1~n)
a[]: 存储当前排列的数组
st[]: 标记数组，st[i]表示数字i是否已被使用
*/
void dfs(int u, int a[], bool st[])
{
    if(u > n){  // 终止条件：当u超过n时，表示所有位置都已填充完毕
        for(int i = 1; i <= n; i++)  // 输出当前排列
            cout << a[i] << ' ';
        cout << endl;
        return;
    }
    
    // 尝试将数字1~n填入当前位置u
    for(int i = 1; i <= n; i++){
        if(!st[i]){  // 如果数字i尚未被使用
            a[u] = i;      // 填入数字i到位置u
            st[i] = true;  // 标记i已被使用
            dfs(u + 1);    // 递归填充下一个位置
            st[i] = false; // 回溯：撤销选择，允许后续排列使用i
        }
    }
}

int main()
{
    cin >> n;
    int nums[N + 1] = {0};  // 修正：使用固定大小数组，索引1~n有效
    bool st[N + 1] = {0};   // 修正：完整初始化标记数组
    dfs(1, nums, st);       // 从位置1开始填充
    return 0;
}
