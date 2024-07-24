#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkBan(string user_id, string banned_id)
{
    // 문자열의 길이가 다르면 ban 아님 
   if(user_id.length() != banned_id.length())
   {
        return false;
   }
    
    for(int idx = 0; idx < banned_id.length(); ++idx)
    {
        // ban id랑 다르면 ban 아님
        if(user_id[idx] != banned_id[idx] && banned_id[idx] != '*')
        {
            return false;
        }
    }
    return true;
}
    
int solution(vector<string> user_id, vector<string> banned_id) {
    set<string> id_list;
    
    sort(user_id.begin(), user_id.end());
 
    // 임시 백터
    vector<string> temp;
    
    do {
        temp.clear();
        // 임시 문자열
        string banned_ids = "";
        
        // 불량 아이디 골라내기
        for (int i = 0; i < banned_id.size(); i++) {
            if (checkBan(user_id[i], banned_id[i])) {
                temp.push_back(user_id[i]);
            }
        }

        // 불량 아이디 개수 만큼 골라냈으면
        if (temp.size() == banned_id.size()) {
            // 정렬
            sort(temp.begin(), temp.end());
            // 불량 아이디로 문자열 만들기
            for (auto& t : temp) {
                banned_ids += t;
            }
            // 중복 방지를 위해 set에 넣기
            id_list.insert(banned_ids);
        }

    } while (next_permutation(user_id.begin(), user_id.end()));
    
    return id_list.size();
}   