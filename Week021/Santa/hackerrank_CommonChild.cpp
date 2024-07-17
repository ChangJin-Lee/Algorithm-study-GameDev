#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Complete the 'commonChild' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int commonChild(string s1, string s2) {
    
    vector<vector<int>> common(s1.length()+1, vector<int>(s2.length()+1, 0));
    for(int i = 1; i <= s1.length(); ++i)
    {
        for(int j = 1; j <= s2.length(); ++j)
        {
            if(s1[i-1] == s2[j-1])
            {
                common[i][j] = common[i-1][j-1] + 1;
            }
            else
            {
                common[i][j] = max(common[i-1][j], common[i][j-1]);
            }        
        }
    }
    return common[s1.length()][s2.length()]; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
