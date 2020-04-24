// https://www.acmicpc.net/problem/1300
// Binaray Search(6), K번째 수
// NUMBER 1300

#include <iostream>
#include <map>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, string> sites;
    int n, m;
    cin >> n >> m;
    string address, password;
    for (int i = 0; i < n; i++) {
        cin >> address >> password;
        sites[address] = password;
    }
    for (int i = 0; i < m; i++) {
        cin >> address;
        cout << sites[address] << endl;
    }
    return 0;
}