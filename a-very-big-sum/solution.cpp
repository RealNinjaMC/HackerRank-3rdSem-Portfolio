#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

long long aVeryBigSum(const vector<long long>& ar) {
    long long total = 0;
    for (long long value : ar) total += value;
    return total;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}
int main() {

    expect(aVeryBigSum({1000000001,1000000002,1000000003,1000000004,1000000005}) == 5000000015LL, "sample beyond int range");
    expect(aVeryBigSum({1000000000}) == 1000000000LL, "one large value");
    expect(aVeryBigSum({0,0}) == 0, "zeroes");
    cout << "PASS A Very Big Sum: 3 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; vector<long long> ar(n);
    for (long long& value : ar) cin >> value;
    cout << aVeryBigSum(ar) << '\n';
    return 0;
}
#endif
