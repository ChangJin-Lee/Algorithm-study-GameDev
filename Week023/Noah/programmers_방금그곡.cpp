#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int getTime(string start, string end){
    int start_hour, end_hour, start_min, end_min;
    
    start_hour = (start[0] - '0') * 10 + (start[1] - '0');
    start_min = (start[3] - '0') * 10 + (start[4] - '0');
    
    end_hour = (end[0] - '0') * 10 + (end[1] - '0');
    end_min = (end[3] - '0') * 10 + (end[4] - '0');
    
    cout << (end_hour * 60 + end_min) - (start_hour * 60 + start_min) << " ";
    
    return (end_hour * 60 + end_min) - (start_hour * 60 + start_min);
}

string convertSharp(string music){
    string converted = "";
    
    for(int i = 0 ; i < music.length(); ++i){
        if(music[i + 1] == '#'){
            converted += tolower(music[i]);
            i++;
        }else{
            converted += music[i];
        }
    }
    
    return converted;
}

string solution(string m, vector<string> musicinfos) {
    m = convertSharp(m);
    string answer = "(None)";
    int maxPlayTime = 0;
    
    for(auto music : musicinfos){
        vector<string> temp;
        int playTime = 0;
        string str = "", title = "";
        
        // 문자열 split
        stringstream ss(music);
        
        while(getline(ss, str, ',')){
            temp.push_back(str);
        }
        
        // 재생시간, 제목, 멜로디
        playTime = getTime(temp[0], temp[1]);
        title = temp[2];
        temp[3] = convertSharp(temp[3]);
        
        // 실제 재생된 멜로디
        string melody = "";
        
        int mel_len = temp[3].length();
        for(int i = 0; i < playTime; ++i){
            melody += temp[3][i % mel_len];
        }
        
        if(melody.find(m) != string::npos){
            if(playTime > maxPlayTime){
                maxPlayTime = playTime;
                answer = title;
            }
        }
    }
    
    return answer;
}