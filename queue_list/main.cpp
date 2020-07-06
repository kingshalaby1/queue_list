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
    
    Node* first = q->first();
    first->print();
    
    Node* last = q->last();
    last->print();
    
    q->traverse();
    
    Node* deq = q->dequeue();
    deq->print();
    
    q->traverse();
    
    return 0;
}
