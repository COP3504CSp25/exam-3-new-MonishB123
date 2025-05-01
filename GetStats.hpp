#pragma once
#include <vector>
struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    void addHead(const int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    int* getStats() const{
        //write your function here!
        std::vector<int> vals;
        Node* curr = head;
        while(curr!=nullptr){
            vals.push_back(curr->data);
            curr = curr->next;
        }
        int* arr = new int;
        if(vals.size() ==0){
            arr[0] = 0;
            arr[1] = 0;
            arr[2] = 0;
            return arr;
        }
        int currMin = vals.at(0);
        int currMax = vals.at(0);
        int sum = vals.at(0);
        for(int i = 1; i < vals.size(); i++){
            if (vals.at(i) < currMin){
                currMin = vals.at(i);
            }
            if (vals.at(i) > currMax){
                currMax = vals.at(i);
            }
            sum += vals.at(i);
        }
        arr[0] = currMin;
        arr[1] = currMax;
        arr[2] = sum / vals.size();
        return arr;
    }
    

private:
    Node* head = nullptr;
};
