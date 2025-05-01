#pragma once

#include <algorithm>
#include <map>
#include <string>
#include <vector>

float consultMax(const std::string& search_term, const std::map<std::string, std::vector<float>>& data) {
    //implement your function here
    if(data.find(search_term)!=data.end()){
        std::vector<float> vec = data.at(search_term);
        float currMax = vec.at(0);
        for (int i = 1; i < vec.size(); i++){
            if(vec.at(i) > currMax){
                currMax = vec.at(i);
            }
        }
        return currMax;
    }
    return -1;
}

std::map<std::string, float> returnMaxMap(const std::map<std::string, std::vector<float>>& in_map) {
    //implement your function here
    std::map<std::string, float> MaxMap;
    for(auto it = in_map.begin(); it != in_map.end(); it++){
        std::vector<float> vec = it->second;
        float currMax = vec.at(0);
        for (int i = 1; i < vec.size(); i++){
            if(vec.at(i) > currMax){
                currMax = vec.at(i);
            }
        }
        MaxMap[it->first] = currMax;
    }
    return MaxMap;
}