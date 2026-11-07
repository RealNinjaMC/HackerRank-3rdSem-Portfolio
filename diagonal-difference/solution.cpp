#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int diagonalDifference(const vector<vector<int>>& arr) {
    int primary = 0;
    int secondary = 0;
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; ++i) {
        primary += arr[i][i];
        secondary += arr[i][n-1-i];
    }
    return abs(primary-secondary);
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}

int main() {

    expect(diagonalDifference({{11,2,4},{4,5,6},{10,8,-12}}) == 15, "sample matrix");
    expect(diagonalDifference({{7}}) == 0, "single shared diagonal entry");
    expect(diagonalDifference({{-1,2},{3,-4}}) == 10, "negative diagonal sum");
    expect(diagonalDifference({{1,2},{1,2}}) == 0, "equal sums");
    cout << "PASS Diagonal Difference: 4 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (auto& row : arr) for (int& value : row) cin >> value;
    cout << diagonalDifference(arr) << '\n';
    return 0;
}
#endif

