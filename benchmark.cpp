#define main diagonal_program_main
#include "diagonal-difference/solution.cpp"
#undef main
#define main dynamic_program_main
#include "dynamic-array/solution.cpp"
#undef main
#define main time_program_main
#include "time-conversion/solution.cpp"
#undef main
#define main triplets_program_main
#include "compare-the-triplets/solution.cpp"
#undef main
#define main sparse_program_main
#include "sparse-arrays/solution.cpp"
#undef main
#include <chrono>
#include <iomanip>

volatile long long benchmarkSink = 0;

template<class Operation>
double measure(int repetitions, Operation operation) {
    auto started = chrono::steady_clock::now();
    for (int iteration=0; iteration<repetitions; ++iteration) operation();
    return chrono::duration<double,micro>(chrono::steady_clock::now()-started).count()/repetitions;
}

int main() {
    cout << fixed << setprecision(4);
    for (int n : {500,1000}) {
        vector<vector<int>> matrix(n,vector<int>(n,1));
        cout << "Diagonal Difference," << n << ',' << measure(1000,[&](){benchmarkSink+=diagonalDifference(matrix);}) << '\n';
    }
    for (int q : {5000,10000}) {
        vector<vector<int>> queries;
        for (int i=0; i<q/2; ++i) { queries.push_back({1,0,i}); queries.push_back({2,0,0}); }
        cout << "Dynamic Array," << q << ',' << measure(50,[&](){benchmarkSink+=dynamicArray(1,queries).size();}) << '\n';
    }
    cout << "Time Conversion,10," << measure(50000,[&](){benchmarkSink+=timeConversion("07:05:45PM")[0];}) << '\n';
    vector<int> a{5,6,7},b{3,6,10};
    cout << "Compare the Triplets,3," << measure(50000,[&](){benchmarkSink+=compareTriplets(a,b)[0];}) << '\n';
    for (int n : {5000,10000}) {
        vector<string> strings,queries;
        for (int i=0; i<n; ++i) { strings.push_back("key"+to_string(i));queries.push_back("key"+to_string(i)); }
        cout << "Sparse Arrays," << n << ',' << measure(20,[&](){benchmarkSink+=matchingStrings(strings,queries).size();}) << '\n';
    }
}
