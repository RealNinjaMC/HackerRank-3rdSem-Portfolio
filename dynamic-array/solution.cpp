#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> dynamicArray(int n, const vector<vector<int>>& queries) {
    vector<vector<int>> sequences(n);
    vector<int> answers;
    int lastAnswer = 0;
    for (const auto& query : queries) {
        int index = (query[1] ^ lastAnswer) % n;
        if (query[0] == 1) {
            sequences[index].push_back(query[2]);
        } else {
            lastAnswer = sequences[index][query[2] % sequences[index].size()];
            answers.push_back(lastAnswer);
        }
    }
    return answers;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}

int main() {

    expect(dynamicArray(2,{{1,0,5},{1,1,7},{1,0,3},{2,1,0},{2,1,1}}) == vector<int>({7,3}), "sample and XOR state changes");
    expect(dynamicArray(1,{{1,0,9},{2,0,0},{2,7,5}}) == vector<int>({9,9}), "one sequence and modulo");
    expect(dynamicArray(2,{{1,0,5},{1,1,7}}).empty(), "append only");
    expect(dynamicArray(2,{{1,0,0},{1,1,8},{2,0,10},{2,1,0}}) == vector<int>({0,8}), "zero answer preserves XOR state");
    cout << "PASS Dynamic Array: 4 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<vector<int>> queries(q, vector<int>(3));
    for (auto& query : queries) cin >> query[0] >> query[1] >> query[2];
    for (int answer : dynamicArray(n,queries)) cout << answer << '\n';
    return 0;
}
#endif
