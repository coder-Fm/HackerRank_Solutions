#include <bits/stdc++.h>

using namespace std;

/*
 * 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    int n = s.length(),
        result;
    vector<int> counter(26, 0);
    vector<int> temp;
    bool valid;
    
    for (int i = 0; i < n; i++) {
        counter[s[i] - 'a']++;
    }
    for (int i = 0; i <= 26; i++) {
        if (counter[i] == 0) {
            continue;
        }
        if (i < 26) {
            counter[i]--;
        }
        temp = counter;
        sort(temp.begin(), temp.end());
        result = temp[25];
        valid = true;
        for (int j = 0; j < 26; j++) {
            if ((temp[j] != 0) && (temp[j] != result)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return "YES";
            break;
        }
        if (i < 26) {
            counter[i]++;
        }
    }
    return "NO";
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
