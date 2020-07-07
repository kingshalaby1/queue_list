//
//  main.cpp
//  queue_list
//
//  Created by ahmed shalaby on 7/5/20.
//  Copyright © 2020 ahmed shalaby. All rights reserved.
//

#include <iostream>
#include "queue.hpp"



int main(int argc, const char * argv[]) {
    Queue* q = new Queue();
    
    q->is_empty();
    int size = q->size();
    cout << "queue size: " << size << "\n\n";
    
    q->enqueue(new Node(10));
    q->is_empty();
    
    q->enqueue(new Node(20));
    q->enqueue(new Node(30));
    
    size = q->size();
    cout << "queue size: " << size << "\n\n";
    
    Node* first = q->first();
    first->print();
    
    Node* last = q->last();
    last->print();
    
    q->traverse();
    
    q->enqueue(new Node(40));
    q->enqueue(new Node(30));
    q->enqueue(new Node(20));
    int max = q->max_sum_of_subarray(3);
    cout << "max sum: " << max << endl;
    
    Node* deq = q->dequeue();
    deq->print();
    
    q->traverse();
    
    return 0;
}
