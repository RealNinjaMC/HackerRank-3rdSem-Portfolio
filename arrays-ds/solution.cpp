#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> reverseArray(const vector<int>& a) {
    return vector<int>(a.rbegin(),a.rend());
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(reverseArray({1,4,3,2}) == vector<int>({2,3,4,1}), "sample reversal");
    expect(reverseArray({7}) == vector<int>({7}), "single element");
    expect(reverseArray({1,2,3}) == vector<int>({3,2,1}), "odd length");
    cout << "PASS Arrays - DS: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; vector<int> a(n);
    for (int& value : a) cin >> value;
    vector<int> result = reverseArray(a);
    for (int i=0; i<n; ++i) cout << (i ? " " : "") << result[i];
    cout << '\n';
    return 0;
}
#endif
