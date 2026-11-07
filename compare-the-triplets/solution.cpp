#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> compareTriplets(const vector<int>& a, const vector<int>& b) {
    vector<int> score(2,0);
    for (int i = 0; i < 3; ++i) {
        if (a[i] > b[i]) ++score[0];
        else if (a[i] < b[i]) ++score[1];
    }
    return score;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}

int main() {

    expect(compareTriplets({5,6,7},{3,6,10}) == vector<int>({1,1}), "sample including tie");
    expect(compareTriplets({17,28,30},{99,16,8}) == vector<int>({2,1}), "second sample");
    expect(compareTriplets({1,1,1},{1,1,1}) == vector<int>({0,0}), "all ties");
    expect(compareTriplets({100,100,100},{1,1,1}) == vector<int>({3,0}), "Alice wins all");
    expect(compareTriplets({1,1,1},{100,100,100}) == vector<int>({0,3}), "Bob wins all");
    cout << "PASS Compare the Triplets: 5 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a(3), b(3);
    for (int& value : a) cin >> value;
    for (int& value : b) cin >> value;
    vector<int> answer = compareTriplets(a,b);
    cout << answer[0] << ' ' << answer[1] << '\n';
    return 0;
}
#endif
