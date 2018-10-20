#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> count(26, 0);
    string out;
    int notvalid = 0;
    for (char& c: s) {
        count[int(c) - 97]++;
    }
    for (int i = 0; i <= 26; i++) {
        if (i < 26) {
            count[i]--;
        }
        int pivot = count[0];
        for (auto c: count) {
            notvalid = 0;
            if ((c != 0) && (c != pivot)) {
                notvalid = 1;
                break;
            }
        }
        if (i < 26) {
            count[i]++;
        }
        if (notvalid == 0) {
            break;
        }
    }
    if (notvalid == 0) {
        out = "YES";
    } else {
        out = "NO";
    }
    return out;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
