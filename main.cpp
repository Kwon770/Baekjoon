// https://www.acmicpc.net/problem/2156
// Dynamic Programming (10), 포도주 시식
// NUMBER 2156

#include <iostream>

using namespace std;
#define MAX 10001
int input[MAX], result[MAX];

void Solve(int n)
{
    result[1] = input[1];
    result[2] = input[2] + input[1];
    for (int i = 3; i <= n; i++)
        result[i] = max(result[i - 1], max(result[i - 2] + input[i], result[i - 3] + input[i - 1] + input[i]));
    cout << result[n] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> input[i];
    Solve(N);
    return 0;
}