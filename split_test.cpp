#include "split.h"
#include <iostream>


int main()
{
  Node* tail = new Node(1, nullptr);

  Node* one = new Node(3, tail);

  Node* two = new Node(4, one);
  
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(two, odds, evens);

while(odds){
  std::cout<<odds->value << " ";
  odds = odds->next;
}

while(evens){
  std::cout <<evens->value << " ";
  evens = evens->next;
}
  delete tail;
  delete one;
  delete two;
return 0;
}
