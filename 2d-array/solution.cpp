#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int hourglassSum(const vector<vector<int>>& arr) {
    int best = -63;
    for (int row=0; row<4; ++row) {
        for (int column=0; column<4; ++column) {
            int sum = arr[row][column]+arr[row][column+1]+arr[row][column+2]
                    + arr[row+1][column+1]
                    + arr[row+2][column]+arr[row+2][column+1]+arr[row+2][column+2];
            best = max(best,sum);
        }
    }
    return best;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(hourglassSum({{1,1,1,0,0,0},{0,1,0,0,0,0},{1,1,1,0,0,0},{0,0,2,4,4,0},{0,0,0,2,0,0},{0,0,1,2,4,0}}) == 19, "sample hourglasses");
    expect(hourglassSum(vector<vector<int>>(6,vector<int>(6,-9))) == -63, "all negative");
    expect(hourglassSum(vector<vector<int>>(6,vector<int>(6,1))) == 7, "uniform ones");
    cout << "PASS 2D Array - DS: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> arr(6,vector<int>(6));
    for (auto& row : arr) for (int& value : row) cin >> value;
    cout << hourglassSum(arr) << '\n';
    return 0;
}
#endif
