#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set> 

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    set<string> car_nums;
    map<string, vector<int>> cars;
    
    for(int i = 0; i < records.size(); ++i){
        istringstream iss(records[i]);
        string time, car, state;
        iss >> time >> car >> state;
        
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int min = (time[3] - '0') * 10 + (time[4] - '0');
        
        cars[car].push_back(hour * 60 + min);
        car_nums.insert(car);
    }
    
    for(auto nums : car_nums){
        int inout_num = cars[nums].size();
        int park_times = 0;
        
        if(inout_num % 2 == 1){
            park_times = (1439 - cars[nums][inout_num - 1]);
            inout_num -= 1;
        }
        
        for(int i = 0; i < inout_num / 2; ++i){
            park_times += (cars[nums][i * 2 + 1] - cars[nums][i * 2]);
        }
        
        if(fees[0] > park_times){
            answer.push_back(fees[1]);
        }else if((park_times - fees[0]) % fees[2] != 0){
            int total_fee = fees[1] + ((park_times - fees[0]) / fees[2] + 1) * fees[3];
            answer.push_back(total_fee);
        }else{
            int total_fee = fees[1] + ((park_times - fees[0]) / fees[2]) * fees[3];
            answer.push_back(total_fee);
        }
    }
    
    return answer;
}