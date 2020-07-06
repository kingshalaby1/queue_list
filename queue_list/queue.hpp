//
//  queue.hpp
//  queue_list
//
//  Created by ahmed shalaby on 7/5/20.
//  Copyright © 2020 ahmed shalaby. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
    void print(){
        cout << "node data: " << data << "\n";
    }
    
};

class Queue {
    public:
    Node* head;
    Node* tail;
    Queue() {
        head = NULL;
        tail = NULL;
    }
    void enqueue(Node* node){
        if(head == NULL){
            head = node;
            tail = node;
            cout << "node added successfully!\n";
            cout << "queue has only one node for now\n\n";
        }
        else{
            tail->next = node;
            node->prev = tail;
            tail = node;
            cout << "node added successfully!\n\n";
        }
        
    }
    
    void traverse(){
        if(head == NULL){
            cout << "queue is empty!\n\n";
            return;
        }
        Node* current = head;
        int counter = 1;
        do{
            cout << "node " << counter++ << " has data: ";
            current->print();
            current = current->next;
            
        }while(current != NULL);
    }
};

#endif /* queue_hpp */