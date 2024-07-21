#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

void ConvertToBinary(const long long* from, string* to)
{
    long long num = *from;
    while(num > 0)
    {
        *to += to_string(num % 2);
        num /= 2;
    }

    // 노트와 높이를 계산하여 완전 이진트리의 노드 수 계산
    int nodes = to->length();
    int height = ceil(log2(nodes + 1));
    int totalNodes = pow(2, height) - 1;

    int dummy = totalNodes - nodes;

    while(dummy)
    {
        dummy--;
        *to += '0';
    }
    reverse(to->begin(), to->end());
}

int CheckCompleteBinary(string num)
{
    if(num.length() < 1)
    {
        return 1;
    }

    string leftTree = num.substr(0, num.length() / 2);
    string rightTree = num.substr(num.length() / 2 + 1);

    char root = num[num.length() / 2];
    char left = leftTree[leftTree.length() / 2];
    char right = rightTree[rightTree.length() / 2];

    if(root == '0' && (left == '1' || right == '1'))
    {
        return 0;
    }
    
    return CheckCompleteBinary(leftTree) && CheckCompleteBinary(rightTree);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        string longToBinary = "";
        ConvertToBinary(&numbers[i], &longToBinary);

        answer.push_back(CheckCompleteBinary(longToBinary));
    }

    return answer;
}