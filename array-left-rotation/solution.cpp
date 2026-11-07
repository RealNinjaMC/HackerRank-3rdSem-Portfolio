#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> rotateLeft(int d, const vector<int>& arr) {
    vector<int> rotated(arr.size());
    for (size_t i=0; i<arr.size(); ++i) rotated[i] = arr[(i+d)%arr.size()];
    return rotated;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(rotateLeft(4,{1,2,3,4,5}) == vector<int>({5,1,2,3,4}), "sample rotation");
    expect(rotateLeft(0,{1,2,3}) == vector<int>({1,2,3}), "zero rotation");
    expect(rotateLeft(3,{1,2,3}) == vector<int>({1,2,3}), "full rotation");
    cout << "PASS Left Rotation: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,d; cin >> n >> d; vector<int> arr(n);
    for (int& value : arr) cin >> value;
    vector<int> result = rotateLeft(d,arr);
    for (int i=0; i<n; ++i) cout << (i ? " " : "") << result[i];
    cout << '\n';
    return 0;
}
#endif
