#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

long long arrayManipulation(int n, const vector<vector<int>>& queries) {
    vector<long long> difference(n+2,0);
    for (const auto& query : queries) {
        difference[query[0]] += query[2];
        difference[query[1]+1] -= query[2];
    }
    long long current = 0;
    long long best = 0;
    for (int i=1; i<=n; ++i) {
        current += difference[i];
        best = max(best,current);
    }
    return best;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(arrayManipulation(5,{{1,2,100},{2,5,100},{3,4,100}}) == 200, "overlapping sample ranges");
    expect(arrayManipulation(1,{{1,1,1000000000},{1,1,1000000000},{1,1,1000000000}}) == 3000000000LL, "64-bit total");
    expect(arrayManipulation(10,{{1,5,3},{4,8,7},{6,9,1}}) == 10, "range ending at boundary");
    cout << "PASS Array Manipulation: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m; vector<vector<int>> queries(m,vector<int>(3));
    for (auto& query : queries) cin >> query[0] >> query[1] >> query[2];
    cout << arrayManipulation(n,queries) << '\n';
    return 0;
}
#endif
