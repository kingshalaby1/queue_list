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
    q->enqueue(new Node(10));
    q->enqueue(new Node(20));
    q->enqueue(new Node(30));
    q->traverse();
    return 0;
}
