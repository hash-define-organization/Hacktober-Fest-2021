#include <bits/stdc++.h>
using namespace std;

vector<string> Subsequence(string s)
{
    if (s.size() == 0)
    {
        vector<string> temp2;
        temp2.push_back("");
        return temp2;
    }

    char a = s[0];
    string tempStr = s.substr(1, s.size());
    vector<string> temp = Subsequence(tempStr);

    vector<string> result;
    for (auto it : temp)
    {
        string var1 = a + it;
        result.push_back(var1);

        string var2 = " " + it;
        result.push_back(var2);
    }

    return result;
}

int main()
{
    string str;
    cin >> str;

    vector<string> result = Subsequence(str);

    cout << endl;
    cout << result.size() << endl;
    for (auto it : result)
    {
        cout << it << endl;
    }
    return 0;
}