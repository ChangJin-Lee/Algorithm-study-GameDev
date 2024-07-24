#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */
 
 map<int, std::string> num2word = {
    {1, "one"},
    {2, "two"},
    {3, "three"},
    {4, "four"},
    {5, "five"},
    {6, "six"},
    {7, "seven"},
    {8, "eight"},
    {9, "nine"},
    {10, "ten"},
    {11, "eleven"},
    {12, "twelve"},
    {13, "thirteen"},
    {14, "fourteen"},
    {15, "quarter"},
    {16, "sixteen"},
    {17, "seventeen"},
    {18, "eighteen"},
    {19, "nineteen"},
    {20, "twenty"},
    {30, "half"}
};

string timeInWords(int h, int m) {
    
    string concate = " past ";
    if(m > 30)
    {
        h++;
        m = 60 - m;
        concate = " to ";
    }
    
    if(m == 0)
    {
        return num2word[h] + " o' clock";
    }
    else if ( m == 1)
    {
         return num2word[m] + " minute" + concate + num2word[h];
    }
    else if (m == 15 || m == 30)
    {
        return num2word[m] + concate + num2word[h];
    }
    else if(m < 20)
    {
        return num2word[m] + " minutes" + concate + num2word[h];
    }
    else
    {
        return num2word[m - m%10] + " " + num2word[m%10] + " minutes" + concate + num2word[h];
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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
