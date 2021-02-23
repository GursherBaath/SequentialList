#include "sequential-list.h"
#include <iostream>

SequentialList::SequentialList(unsigned int cap)
{
    capacity_= cap;
    size_= 0;
    data_= new int[cap];
}

SequentialList::~SequentialList()
{
    delete[] data_;
    data_ = NULL;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size_ == 0)
        return true;
    else
        return false;
}

bool SequentialList::full() const
{
    if (size_ == capacity_)
        return true;
    else
        return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
   if (index < size_ && index >= 0)
   {
        return data_[index];
   }
   else
       return data_[size_ - 1];
}

unsigned int SequentialList::search(DataType val) const
{
    for ( int i = 0; i < size_; i++)
    {
        if (data_[i] == val)
            return i;
    }

    return size_;
}

void SequentialList::print() const
{
    for ( int i = 0; i < size_; i++)
    {
        std::cout << data_[i] << "\n" << std::endl;
    }

}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if ( size_ == capacity_ || index > size_)
        return false;
    else{
        int j = index;
        for ( int i = size_ - 1; i >= j; i--)
        {
            data_[i+1] = data_[i];
        }
        data_[index] = val;
        size_++;
        return true;
    }

}

bool SequentialList::insert_front(DataType val)
{
    if ( size_ == capacity_)
        return false;
    else {
        for (int i = size_ - 1; i >= 0; i--) {
            data_[i + 1] = data_[i];
        }
        data_[0] = val;
        size_++;
        return true;
    }

}

bool SequentialList::insert_back(DataType val)
{
    if ( size_ == capacity_)
        return false;
    else{

        data_[size_] = val;
        size_++;
        return true;
    }

}

bool SequentialList::remove(unsigned int index)
{
    if (size_ <= 0 || index >= size_)
        return false;
    else {
        for (int i = index; i < size_ - 1; i++) {
            data_[i] = data_[i + 1];
        }
        size_--;
        return true;
    }
}

bool SequentialList::remove_front()
{
    if (size_ <= 0 )
        return false;
    else {
        for (int i = 0; i < size_-1; i++) {
            data_[i] = data_[i + 1];
        }
        size_--;
        return true;
    }
}

bool SequentialList::remove_back()
{
    if (size_ == 0 )
        return false;
    else {
        size_--;
        return true;
    }
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (index >= size_ )
        return false;
    else {
        data_[index] = val;
        return true;
    }
}
