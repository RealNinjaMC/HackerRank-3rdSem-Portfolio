#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> matchingStrings(const vector<string>& stringList, const vector<string>& queries) {
    unordered_map<string,int> frequencies;
    for (const string& value : stringList) ++frequencies[value];
    vector<int> answers;
    answers.reserve(queries.size());
    for (const string& query : queries) {
        auto match = frequencies.find(query);
        answers.push_back(match == frequencies.end() ? 0 : match->second);
    }
    return answers;
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}

int main() {

    expect(matchingStrings({"aba","baba","aba","xzxb"},{"aba","xzxb","ab"}) == vector<int>({2,1,0}), "duplicates and absent query");
    expect(matchingStrings({"def","de","fgh"},{"de","lmn","fgh"}) == vector<int>({1,0,1}), "exact rather than substring match");
    expect(matchingStrings({"a","a","a"},{"a","a","b"}) == vector<int>({3,3,0}), "repeated queries");
    expect(matchingStrings({"a"},{"z"}) == vector<int>({0}), "single absent query");
    cout << "PASS Sparse Arrays: 4 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<string> strings(n);
    for (string& value : strings) cin >> value;
    int q; cin >> q;
    vector<string> queries(q);
    for (string& query : queries) cin >> query;
    for (int count : matchingStrings(strings,queries)) cout << count << '\n';
    return 0;
}
#endif
