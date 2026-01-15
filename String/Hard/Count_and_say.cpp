//Optimal
#include <string>
using namespace std;

string countAndSay(int n)
{
    string s = "1";

    while (--n)
    {
        string next = "";
        int count = 1;

        for (int i = 1; i <= s.size(); i++)
        {
            if (i < s.size() && s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                next.append(to_string(count));
                next.push_back(s[i - 1]);
                count = 1;
            }
        }

        s.swap(next);
    }

    return s;
}
