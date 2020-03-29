//
//  StackIter.h
//  SB_IteratorPattern
//
//  Created by Scott Bing on 3/28/20.
//  Copyright © 2020 Scott Bing. All rights reserved.
//

#ifndef StackIter_h
#define StackIter_h

//#include "Stack.h"
#include "Stk.h"


class StackIter
{
    // 1. Design an "iterator" class
    const Stack *stk;
    int index;
  public:
    StackIter(const Stack *s)
    {
        stk = s;
    }
    void first()
    {
        index = 0;
    }
    void next()
    {
        index++;
    }
    bool isDone()
    {
        return index == stk->sp + 1;
    }
    int currentItem()
    {
        return stk->items[index];
    }
};

StackIter *Stack::createIterator()const
{
  return new StackIter(this);
}


#endif /* StackIter_h */
