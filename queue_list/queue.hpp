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
    
    Node* dequeue(){
        if(head == NULL){
            cout << "queue is empty!\n\n";
            return NULL;
        }
        
        Node* temp_head = head;
        if(head == tail){
            head = tail = NULL;
        }
        else{
            head = head-> next;
            head->prev = NULL;
        }
        return temp_head;
    }

    Node* first(){return head;}
    
    Node* last(){return tail;}
    
    bool is_empty(){
        if(head){
            cout << "queue is NOT empty\n";
            return false;
        }
        else{
            cout << "queue is empty\n";
            return true;
        }
    }
    
    int size(){
        if(head == NULL){
            cout << "queue is empty!\n";
            return 0 ;
        }
        Node* current = head;
        int counter = 0;
        do{
            current = current->next;
            counter++;
            
        }while(current != NULL);
        return counter;
    }
    
    Node* set_end_pointer(Node* current, int* steps){
        cout << "end : " << current->data << endl;
        *steps = *steps - 1;
        
        if(*steps > 0 && current->next != NULL){
            current = current->next;
            current = set_end_pointer(current, steps);
        }
        if(*steps > 0)
            return NULL;
        
        cout << "end will be: " << current->data << endl;
        
        return current;
    }
    
    
    //Sliding Window Maximum summation of all sub-arrays of size k
    int max_sum_of_subarray(int array_size){
        int max_sum = 0, temp_sum = 0;
        int temp_size = array_size;
        int queue_size = size();
        Node* start = head;
        Node* end = set_end_pointer(start, &temp_size);
        Node* current;
        
        
        if (array_size > queue_size || array_size < 1){
            cout << "insufficient array size, it should be > 1 and < " << queue_size << endl;
            return -1;
        }
        cout << "looping \n\n";

        if(end == NULL)
            cout << "end is null\n";
        while(end){
            cout << "looping big while\n\n";
            temp_sum = 0;
            current = start;
            while(current != end->next){
                temp_sum += current->data;
                cout << "temp sum: " << temp_sum << " data: " << current->data << endl;
                current = current->next;
            }
            cout << "temp sum: " << temp_sum << endl;
            if(temp_sum > max_sum)
                max_sum = temp_sum;
            
//            max_sum = temp_sum > max_sum? temp_sum : max_sum;
            start = start->next;
            end = end->next;
        }
        return max_sum;
    }
    
};

#endif /* queue_hpp */
