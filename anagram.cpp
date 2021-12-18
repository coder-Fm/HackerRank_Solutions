#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * 'anagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int anagram(string s) {
    int n = s.length(),
        mid = n/2;
    string S1, S2, result;
    
    if (n%2 == 0) {
        S1 = s.substr(0,mid);
        S2 = s.substr(mid, mid);
        sort(S1.begin(), S1.end());
        sort(S2.begin(), S2.end());
        set_difference(S1.begin(),S1.end(),S2.begin(), S2.end(),back_inserter(result));
        return result.length();
    } else {
        return -1;
    }
    return stoi(result);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
