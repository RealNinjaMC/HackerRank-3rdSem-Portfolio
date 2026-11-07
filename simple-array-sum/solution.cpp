#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int simpleArraySum(const vector<int>& ar) {
    int total = 0;
    for (int value : ar) total += value;
    return total;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(simpleArraySum({1,2,3,4,10,11}) == 31, "sample sum");
    expect(simpleArraySum({7}) == 7, "one element");
    expect(simpleArraySum({0,0,0}) == 0, "all zeroes");
    cout << "PASS Simple Array Sum: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; vector<int> ar(n);
    for (int& value : ar) cin >> value;
    cout << simpleArraySum(ar) << '\n';
    return 0;
}
#endif
