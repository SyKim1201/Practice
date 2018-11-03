#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    map<char,int> amap;
    map<char,int> bmap;
    int out = 0;

    for (int  i = 0; i < 26; i++) {
        amap[char(97 + i)] = 0;
        bmap[char(97 + i)] = 0;
    }
    for (char &c : a) {
        amap[c]++;
    }
    for (char &c : b) {
        bmap[c]++;
    }
    for (int  i = 0; i < 26; i++) {
        int sub = amap[char(97 + i)] - bmap[char(97 + i)];
        out += abs(sub);
    }
    return out;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
