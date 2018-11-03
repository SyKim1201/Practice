#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    vector<vector<int>> arr;
    for (int i = 0; i <= s1.size(); i++) {
        vector<int> temp(s2.size() + 1, 0);
        arr.emplace_back(temp);
    }
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1] + 1;
            } else {
                arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
            }
        }
    }
    return arr[s1.size()][s2.size()];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
