#pragma once
//
//  Stack.cpp
//  SB_IteratorPattern
//
//  Created by Scott Bing on 3/28/20.
//  Copyright © 2020 Scott Bing. All rights reserved.
//

#include "StackIter.cpp"
#include <iostream>


class Stack
{
    int items[10];
      int sp;
    public:
      friend class StackIter;
      Stack()
      {
          sp =  - 1;
      }
      void push(int in)
      {
          items[++sp] = in;
      }
      int pop()
      {
          return items[sp--];
      }
      bool isEmpty()
      {
          return (sp ==  - 1);
      }
      StackIter *createIterator()const; // 2. Add a createIterator() member

};
