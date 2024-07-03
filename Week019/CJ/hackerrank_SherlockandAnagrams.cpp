#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */
 
 int combination(int n, int r)
 {
     if(n == r || r == 0)
     {
         return 1;
     }
     return combination(n-1, r) + combination(n-1,r-1);
 }

int sherlockAndAnagrams(string s) {
    map<string,int> subsets;
    int answer = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 1; j <= s.size() - i; j++)
        {
            string st = s.substr(i,j);
            sort(st.begin(), st.end());
            if(subsets.find(st) == subsets.end())
            {
                subsets[st] = 1;
            }
            else 
            {
                subsets[st]++;
            }
        }
    }
    
    for(auto subset : subsets)
    {
        if(subset.second >= 2)
        {
            answer += combination(subset.second, 2);
        }
    }
    
    return answer;
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

        int result = sherlockAndAnagrams(s);

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
