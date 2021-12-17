#include <bits/stdc++.h>

using namespace std;

/*
 * 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string hour = s.substr(0,2),
           min_sec = s.substr(2,6),
           am_pm = s.substr(8,2);
    int h = stoi(hour)+12;
    
    // 12:00:00AM - 00:00:00
    if((hour == "12") && (am_pm == "AM")) {
        hour = "00";
        s = hour + min_sec;
    }
    //09:00:00PM - 21:00:00
    else if ((stoi(hour) < 12) && (am_pm == "PM")) {
        s = to_string(h)+ min_sec;
    }
    else {
        s = hour + min_sec;
    }
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
