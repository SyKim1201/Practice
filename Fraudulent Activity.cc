#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int count = 0;
    int next = 0;
    int pos = 0;
    vector<pair<int, int>> checks;
    for (int i = 0; i < d; i++) {
        pair<int, int> temp(expenditure[i], i);
        checks.emplace_back(temp);
        for (int j = checks.size() - 2; j >= 0 ; j--) {
            if (temp.first < checks[j].first) {
                if (checks[j].second == next) {
                    pos = j + 1;
                }
                pair<int, int> temp2(checks[j + 1].first, checks[j + 1].second);
                checks[j + 1] = checks[j];
                checks[j] = temp2;
            } else {
                if (checks[j].second == next) {
                    pos = j;
                }
            }
        }
    }
    for (int i = d; i < expenditure.size(); i++) {
        float med;
        if (d % 2 == 0) {
            med = (checks[ceil(d/2)].first + checks[floor(d/2)].first) / 2;
        } else {
            med = checks[d/2].first;
        }
        if (expenditure[i] >= (2 * med)) {
            count++;        
        }
        pair<int, int> temp(expenditure[i], i);
        checks.erase(checks.begin() + pos);
        checks.emplace_back(temp);
        next++;
        for (int j = checks.size() - 2; j >= 0 ; j--) {
            if (temp.first < checks[j].first) {
                if (checks[j].second == next) {
                    pos = j + 1;
                }
                pair<int, int> temp2(checks[j + 1].first, checks[j + 1].second);
                checks[j + 1] = checks[j];
                checks[j] = temp2;
            } else {
                if (checks[j].second == next) {
                    pos = j;
                }
            }
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
