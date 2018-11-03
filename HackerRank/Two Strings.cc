#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    vector<char> checked;
    int check = 0;
    int yes = 0;
    string out;
    for (char& c: s1) {
        for (auto v: checked) {
            if (c == v) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            for (char& d: s2) {
                if (c == d) {
                    yes = 1;
                    break;
                }
            }
            checked.emplace_back(c);
        }
        check = 0;
        if (yes == 1) {
            break;
        }
    }
    if (yes == 1) {
        out = "YES";
    } else {
        out = "NO";
    }
    return out;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
