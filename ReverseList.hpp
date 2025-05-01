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
    
    LinkedList reverseList() const {
        // implement your function here!
        LinkedList newList;
        std::vector<int> vals;
        Node* curr = head;
        while(curr!=nullptr){
            vals.push_back(curr->data);
            curr = curr->next;
        }
        Node* node = new Node;
        node->data = vals.at(vals.size()-1);
        newList.head = node;

        curr = newList.head;
        for(int i = vals.size()-2; i >= 0; i--){
            Node* aNode = new Node;
            aNode->data = vals.at(i);
            curr->next = aNode;
            curr = curr->next;
        }
        return newList;
    }

    Node* head = nullptr;
};
