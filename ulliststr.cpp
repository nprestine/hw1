#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val) //looks good
{
  if(head_ == NULL) //there is no item object yet
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    head_->first = 0;
    head_->last = 0; 
    node->val[0] = val;
    node->last ++;
    size_++;
  }
  else if(tail_->last == 10) //there is no space in the last item in the list
  {
    Item* node = new Item();
    node->prev = tail_;
    tail_->next = node;
    tail_ = node;
    node->val[node->first] = val;
    node->last++;
    size_++;
  }
  else if(tail_->last < 10) //there is an item in the list and there is space to add a value
  {
    tail_->val[tail_->last] = val;
    tail_->last ++;
    size_++;
  }
}

void ULListStr::pop_back() //looks good this one works updayte popfront 
{
  if(tail_ == NULL || size_ == 0) //there is no item in the list
  {
    return;
  }

  else if(tail_->last == 1  || (tail_->last)-(tail_->first) <= 1) //only 1 element on item -> delte whole item
  {
    if(tail_ != head_)
    {
    Item* tmp = tail_;
    tail_ = tail_->prev;
    delete tmp;
    tail_->next= NULL;
    size_--;
    }
    else{
      tail_=NULL;
      delete head_;
      head_=NULL;
      size_--;
    }
  } 
  else if (tail_->last !=0) //there is an item in the list
  {
    tail_->last--;
    size_--;
  }
}

void ULListStr::push_front(const std::string& val) //looks good
{
  if(head_ == NULL) //there is no item object yet
  {
    Item* node = new Item();
    head_ = node;
    tail_ = node;
    node->val[9] = val;
    node->first = 9;
    node->last = 10;
    size_++;
  }
  else if(head_->first == 0) //there is an item in the list and it is full at the front
  {
    Item* node = new Item();
    node->next = head_;
    head_->prev = node;
    node->prev = nullptr;
    head_ = node;
    node->val[9] = val;
    node->first = 9;
    node->last = 10;
    size_++;
  }
  else if(head_->first > 0) //space in front of list
  {
    head_->val[head_ ->first-1] = val;
    head_->first --;
    size_++;
  }
}

void ULListStr::pop_front() //got updated need to check
{
  if(tail_ == NULL) //there is no item in the list
  {
    return;
  }

  else if((head_->last)-(head_->first) == 1) // only 1 element so delete whole item
  {
    if(tail_ != head_){
    Item* tmp = head_;
    Item* temp = head_->next;
    delete tmp;
    head_ = temp;
    head_->prev=NULL;
    size_--;
    }
    else{
      delete head_;
      tail_ = NULL;
      head_ = NULL;

    }
  } 
  else if (((head_->first) = 0) && (head_->last !=0)) //there is an item in the list
  {
    head_->first++;
    size_--;
  }
}

std::string const & ULListStr::back() const
{
 
  return tail_->val[(tail_->last)-1];
}

std::string const & ULListStr::front() const
{
 
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(size_==0){
    //std::cout <<"The list is empty" << "\n";
    return NULL;
  }
  if(head_ == NULL)
  {
    return NULL;
  }
  if(loc>size_)
  {
    return NULL;
  }
  int remainsize = (head_->last) - (head_->first);
  Item* temp = head_;
  while (true){
    remainsize = (temp->last) - (temp->first);
  if ((remainsize) > loc)
  {
    break;
  }
  loc = (loc-(remainsize));
  temp = temp->next;
}
  return &temp->val[temp->first + (loc)];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
