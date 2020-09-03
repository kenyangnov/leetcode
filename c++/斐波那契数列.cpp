#include <iostream>
#include <vector>

using namespace std;

//-----------朴素递归-------------
int fib_1(int N) {
    if (N == 1 || N == 2) {
        return 1;
    } else {
        return fib_1(N - 1) + fib_1(N - 2);
    }
}

//------------自顶向下------------
int helper(vector<int> &memo, int n) {
    // base case
    if (n == 1 || n == 2) {
        return 1;
    } else {
        if (memo[n] != 0) {
            return memo[n];
        } else {
            memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
            return memo[n];
        }
    }
}
int fib_2(int N) {
    if (N < 1) return 0;
    // 备忘录
    vector<int> memo(N + 1, 0);
    // 进行带备忘录的递归
    return helper(memo, N);
}

//---------自底向上--------------
int fib_3(int N) {
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}

//----------优化--------------
int fib_4(int N) {
    if (N == 2 || N == 1) {
        return 1;
    }
    int prev = 1, curr = 1;
    for (int i = 3; i <= N; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

int main() {
    int n;
    cin >> n;
    cout << fib_4(n);
    system("pause");
    return 0;
}