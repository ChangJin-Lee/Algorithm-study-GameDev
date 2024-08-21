#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
 
string EraseBlank(string s)
{
    string t = "";
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            t += s[i];
        }
    }
    return t;
}

string encryption(string s) {
    string ss = EraseBlank(s);
    vector<string> encrypts;
    int l = ss.size();
    int row = floor(sqrt(l));
    int col = ceil(sqrt(l));
    
    if(row * col < l)
    {
        row++;
    }
    
    encrypts.assign(col, "");
    
    for(int i = 0 ; i < row; i++)
    {
        for(int j = 0 ; j < col; j++)
        {
            if(i*col + j < l)
            {
                encrypts[j].push_back(ss[i*col + j]);
            }
        }
    }
    
    string encodedstring = "";
    for (size_t i = 0; i < encrypts.size(); ++i)
    {
        encodedstring += encrypts[i];
        if (i != encrypts.size() - 1)
        {
            encodedstring += ' ';
        }
    }
    
    return encodedstring;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}