#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::LListInt(const LListInt& other):head_(NULL),tail_(NULL),size_(0) {
  *this = other;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

LListInt& LListInt::operator=(const LListInt& other) {
  if (this != &other) {
    if (!this->empty()) clear();
    Item* cur = other.head_;
    for (int i = 0; i < other.size(); i++) {
      // since insert specifically take care of inserting to the tail
      // in this case, constant times would be taken
      this->insert(i, cur->val); 
      cur = cur->next;
    }
  }
  return *this;
}

LListInt LListInt::operator+(const LListInt& other) const {
  LListInt *list1 = new LListInt(*this);
  LListInt *list2 = new LListInt(other);
  if (list1->empty()) {
    delete list1;
    return *list2;
  }
  if (list2->empty()){
    delete list2;
    return *list1;
  }

  list1->size_ += list2->size_;
  list1->tail_->next = list2->head_;
  list2->head_->prev = list1->tail_;
  list1->tail_ = list2->tail_;
  return *list1;
}

int const & LListInt::operator[](int position) const {
  return get(position);
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  if (loc > size_ || loc < 0) return;
  // in case that the list is empty
  if (size_ == 0) {
    Item* it = new Item;
    it->val = val; it->prev = NULL; it->next = NULL;
    size_++;
    head_ = tail_ = it;
    return;
  }

  // create the new item
  Item* it = new Item;
  it->val = val;
  // insert at head
  if (loc == 0) {
    it->prev = NULL; it->next = head_;
    head_->prev = it;
    size_++;
    head_ = it;
    return;
  }
  // insert at tail
  if (loc == size_) {
    it->prev = tail_; it->next = NULL;
    tail_->next = it;
    size_++;
    tail_ = it;
    return;
  }

  Item* cur = getNodeAt(loc);
  it->prev = cur->prev; it->next = cur;

  cur->prev->next = it;
  cur->prev = it;
  size_++;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  if (size_ == 0) return;
  if (loc < 0 || loc > size_ - 1) return;
  if (size_ == 1) {
    Item* temp = head_;
    head_ = tail_ = NULL;
    delete temp;
    size_--;
    return;
  }

  if (loc == 0) {
    head_->next->prev = NULL;
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
    size_--;
    if (size_ == 1) tail_ = head_;
    return;
  }

  if(loc == size_ - 1) {
    tail_->prev->next = NULL;
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    size_--;
    if (size_ == 1) head_ = tail_;
    return;
  }

  Item* cur = getNodeAt(loc);
  cur->next->prev = cur->prev;
  cur->prev->next = cur->next;
  delete cur;
  size_--;
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item* cur = head_;
  for (int i = 0; i < loc; ++i) cur = cur->next;
  return cur;
}
