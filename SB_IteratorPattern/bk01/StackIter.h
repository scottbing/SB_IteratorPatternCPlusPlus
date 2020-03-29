#pragma once
//
//  StackIter.cpp
//  SB_IteratorPattern
//
//  Created by Scott Bing on 3/28/20.
//  Copyright © 2020 Scott Bing. All rights reserved.
//


#include "Stack.cpp"
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

bool operator == (const Stack &l, const Stack &r)
{
  // 3. Clients ask the container object to create an iterator object
  StackIter *itl = l.createIterator();
  StackIter *itr = r.createIterator();
  // 4. Clients use the first(), isDone(), next(), and currentItem() protocol
  for (itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next())
    if (itl->currentItem() != itr->currentItem())
      break;
  bool ans = itl->isDone() && itr->isDone();
  delete itl;
  delete itr;
  return ans;
}

