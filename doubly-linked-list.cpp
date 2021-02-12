#include "doubly-linked-list.h"
#include <iostream>
#include <new>

DoublyLinkedList::Node::Node(DataType data):
        value(data), next(NULL), prev(NULL)
{
}
DoublyLinkedList::DoublyLinkedList()
        :head_(NULL), tail_(NULL), size_(0)
{
}
/*DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& list)
:size_(list.size_)
{
	


}*/
DoublyLinkedList::~DoublyLinkedList()
{
    Node* current = head_;
    while (current != NULL)
    {
        Node* dnode = current;
        current = current->next;
        dnode->next = nullptr;
        dnode->prev = nullptr;
        dnode->value = 0;

        delete dnode;
        dnode = NULL;
    }
    size_ = 0;
    head_ = nullptr;
    tail_ = nullptr;

}
bool DoublyLinkedList::empty() const
{
    if (size_==0)
        return true;
    else
        return false;

}
unsigned int DoublyLinkedList::size() const
{
    return size_;

}
void DoublyLinkedList::print() const
{
    Node* current = head_;
    while (current != NULL)
    {
        std::cout << current->value<< "\n" << std::endl;
        current = current->next;
    }

}
bool DoublyLinkedList::insert_front(DataType value)
{
    Node* front = new Node (value);
    if ( size_ == 0){
        head_ = front;
        tail_ = front;
    }
    else {
        head_->prev = front;
        front->next = head_;
        head_ = front;
    }
    size_++;
    return true;
}
bool DoublyLinkedList::remove_front()
{
    if (size_ == 0 )
    {
        return false;
    }
    else
    {
        if (!head_->next)
        {
            delete head_;
            head_ = NULL;
            tail_ = NULL;
        }
        else {
            Node* newHead = head_->next;
            newHead->prev = NULL;
            delete head_;
            head_ = newHead;
        }
    }
    size_--;
    return true;
 


}
bool DoublyLinkedList::insert_back(DataType value)
{
    Node* back = new Node (value);
    if (size_ == 0)
    {
        head_ = back;
        tail_ = back;
    }
    else{
        back->prev = tail_;
        tail_->next = back;
        tail_ = back;
    }
    size_++;
    return true;
}
bool DoublyLinkedList::remove_back()
{
    if (size_ == 0 )
    {
        return false;
    }

    else {
        if (!head_->next) {
            delete head_;
            head_ = NULL;
            tail_ = NULL;
        }
        else{
            Node* temp = tail_;
            tail_ = tail_->prev;
            delete (temp);
            tail_->next = NULL;
        }
    }
    size_--;
    return true;



}
bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node* in = new Node (value);
    if (index==0)
    {
        if (size_==0)
        {
            head_ = in;
            tail_ = in;
        }
        else{
            head_->prev = in;
            in->next = head_;
            head_ = in;
        }
    }
    else if (index == size_)
    {
        in->prev = tail_;
        tail_->next = in;
        tail_ = in;
    }
    else if (index > size_)
    {
        return false;
    }
    else
    {
        int track = 0;
        Node* current = head_;
        while(track < index-1) {
            current = current -> next;
            track++;
        }
        in->prev = current;
        in -> next = current -> next;
        current->next = in;
    }
    size_++;
    return true;


}
bool DoublyLinkedList::remove(unsigned int index)
{
    if (size_ == 0 || index >= size_ )
    {
        return false;
    }
    else if (index == 0)
    {
        if (!head_->next)
        {
            delete head_;
            head_ = NULL;
            tail_ = NULL;
        }
        else {
            Node* newHead = head_->next;
            newHead->prev = NULL;
            delete head_;
            head_ = newHead;
        }
    }
    else {
        Node* current = head_;
        for (int i =0; i < index-1; i++){
            current = current->next;
        }
        if ( !current->next->next){
            tail_=current;
            delete(current->next);
            current->next = NULL;
        }
        else {
            Node* temp = current->next->next;
            temp->prev = current;
            delete (current->next);
            current->next = temp;
        }
    }
    size_--;
    return true;
}
unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* current = head_;
    for (int i = 0; i < size_; i++)
    {
        if (current->value == value)
            return i;
        else
            current = current->next;
    }
    return size_;
}
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
  Node* current = head_;
  if (index < size_) {
      for (int i = 0; i < index; i++) {
          current = current->next;
      }
      return current->value;
  }
  else
      return tail_->value;
}
bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    if (index >= size_ || size_==0){
        return false;
    }
    else {
        Node* current = head_;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->value = value;
        return true;
    }


}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{
    if ( index < size_) {
        Node *current = head_;
        if (index < size_) {
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current;
        }
    }

}
bool DoublyLinkedList::full() const
{
    return false;
}
