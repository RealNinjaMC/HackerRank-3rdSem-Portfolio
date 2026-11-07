#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string timeConversion(string s) {
    int hour = ((s[0]-'0')*10 + s[1]-'0') % 12;
    if (s[8] == 'P') hour += 12;
    s[0] = static_cast<char>('0' + hour/10);
    s[1] = static_cast<char>('0' + hour%10);
    return s.substr(0,8);
}

#ifdef LOCAL_TEST
void expect(bool condition, const string& label) {
    if (!condition) { cerr << "FAIL: " << label << "\n"; exit(1); }
}

int main() {

    expect(timeConversion("07:05:45PM") == "19:05:45", "PM conversion");
    expect(timeConversion("12:00:00AM") == "00:00:00", "midnight");
    expect(timeConversion("12:00:00PM") == "12:00:00", "noon");
    expect(timeConversion("01:02:03AM") == "01:02:03", "AM preserves leading zero");
    expect(timeConversion("11:59:59PM") == "23:59:59", "last second of day");
    cout << "PASS Time Conversion: 5 checks\n";
    return 0;
}
#else
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    cout << timeConversion(s) << '\n';
    return 0;
}
#endif
