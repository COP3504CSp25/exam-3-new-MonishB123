#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

std::map<std::string, int> loadTrafficData(const std::string& filename) {
  //implement your function here!
  std::map<std::string, int> trafficData;
  std::ifstream file(filename);
  std::string line;
  while(std::getline(file, line)){
    std::stringstream ss(line);
    std::string value;
    std::vector<std::string> row;
    while(std::getline(ss, value, ',')){
      row.push_back(value);
    }
    trafficData[row[0]] = std::stoi(row[1]);
  }
}

void updateTrafficData(const std::string& filename, std::map<std::string, int>& dataMap) {
    //implement your function here!
    std::ifstream file(filename);
    std::string line;
    while(std::getline(file, line)){
      std::stringstream ss(line);
      std::string value;
      std::vector<std::string> row;
      while(std::getline(ss, value, ',')){
        row.push_back(value);
      }
      std::string airportName = row[0];
      int numPassengers = std::stoi(row[1]);
      dataMap[airportName] = numPassengers;
    }
}