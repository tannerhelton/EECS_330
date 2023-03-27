#ifndef _MY_LINKEDLIST_H_
#define _MY_LINKEDLIST_H_

#include <algorithm>
#include <iostream>

template <typename DataType>
class MyLinkedList
{
private:
    struct Node
    {
        DataType data;
        Node *prev;
        Node *next;

        Node(const DataType &d = DataType{}, Node *p = nullptr, Node *n = nullptr) : data{d},
                                                                                     prev{p},
                                                                                     next{n}
        {
        }

        Node(DataType &&d, Node *p = nullptr, Node *n = nullptr) : data{std::move(d)},
                                                                   prev{p},
                                                                   next{n}
        {
        }
    };

    int mySize; // the number of elements that the linked list is currently holding
    Node *head; // pointer to the head node; does not hold real data
    Node *tail; // pointer to the tail note; does not hold real data

    void init()
    {
        // code begins
        mySize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        // code ends

        return;
    }

public:
    // define the const_iterator class
    class const_iterator
    {
    protected:
        Node *current;
        // returns a mutable object
        // defined as proected as we don't expect it to be called directly by other classess
        DataType &retrieve() const
        {
            return current->data;
        }
        // constructor to be hidden from other classes;
        // we don't expect direct construction of iterator form pointer
        const_iterator(Node *p) : current{p}
        {
        }

        friend class MyLinkedList<DataType>;

    public:
        const_iterator() : current{nullptr}
        {
        }

        // add const to the return type and make the return value by retrieve() non-mutable
        const DataType &operator*() const
        {
            // code begins
            return const_iterator::retrieve();
            // code ends
        }

        // move to the next data element
        // the prefix increment (e.g. ++ p) with 0 parameter
        const_iterator &operator++()
        {
            // code begins
            current = current->next;
            return *this;
            // code ends
        }

        // move to the next data element
        // the suffix increment (e.g. p ++) with 1 int parameter
        const_iterator operator++(int)
        {
            // code begins
            const_iterator old = *this;
            ++(*this);
            return old;
            // code ends
        }

        // move to the previous data element
        // the prefix decrement (e.g. -- p) with 0 parameter
        const_iterator &operator--()
        {
            // code begins
            current = current->prev;
            return *this;

            // code ends
        }

        // move to the previous data element
        // the suffix decrement (e.g. p --) with 1 int parameter
        const_iterator operator--(int)
        {
            // code begins
            const_iterator old = *this;
            --(*this);
            return old;
            // code ends
        }

        // check whether two iterators point to the same data element
        bool operator==(const const_iterator &rhs) const
        {
            // code begins
            return current == rhs.current;
            // code ends
        }

        // check whether two iterators point to the same data element
        bool operator!=(const const_iterator &rhs) const
        {
            // code begins
            return !(*this == rhs);
            // code ends
        }
    };

    // define the iterator class; inherit from class const_iterator
    class iterator : public const_iterator
    {
    protected:
        iterator(Node *p) : const_iterator{p}
        {
        }

        friend class MyLinkedList<DataType>;

    public:
        // default constructor
        iterator()
        {
        }

        // the return type is mutable
        DataType &operator*()
        {
            // code begins
            return const_iterator::retrieve();
            // code ends
        }

        // keep the return type as non-mutable
        const DataType &operator*() const
        {
            // code begins
            return const_iterator::retrieve();
            // code ends
        }

        iterator &operator++()
        {
            // code begins
            const_iterator::current = const_iterator::current->next;
            return *this;
            // code ends
        }

        iterator operator++(int)
        {
            // code begins
            iterator old = *this;
            ++(*this);
            return old;
            // code ends
        }

        iterator operator--()
        {
            // code begins
            const_iterator::current = const_iterator::current->prev;
            return *this;
            // code ends
        }

        iterator operator--(int)
        {
            // code begins
            iterator old = *this;
            --(*this);
            return old;
            // code ends
        }

        // don't need to overload operator= and operator!= as they should behave the same as in const_iterator
    };

    // defining the MyLinkedList class methods
public:
    // default constructor
    MyLinkedList()
    {
        init();
    }

    // copy constructor
    MyLinkedList(const MyLinkedList &rhs)
    {
        // code begins
        init();
        for (const DataType &x : rhs)
        {
            push_back(x);
        }
        // code ends
    }

    // move constructor
    MyLinkedList(MyLinkedList &&rhs) : mySize(rhs.mySize),
                                       head(rhs.head),
                                       tail(rhs.tail)
    {
        // code begins
        rhs.mySize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
        // code ends
    }

    // destructor
    ~MyLinkedList()
    {
        // code begins
        clear();
        delete head;
        delete tail;
        // code ends
    }

    // copy assignment
    MyLinkedList &operator=(const MyLinkedList &rhs)
    {
        // code begins
        MyLinkedList copy = rhs;
        std::swap(*this, copy);
        return *this;
        // code ends
    }

    // move assignment
    MyLinkedList &operator=(MyLinkedList &&rhs)
    {
        // code begins
        clear();
        std::swap(mySize, rhs.mySize);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
        // code ends
    }

    // iterator interface
    iterator begin()
    {
        // code begins
        return iterator(head->next);
        // code ends
    }

    const_iterator begin() const
    {
        // code begins
        return const_iterator(head->next);
        // code ends
    }

    iterator end()
    {
        // code begins
        return iterator(tail);
        // code ends
    }

    const_iterator end() const
    {
        // code begins
        return const_iterator(tail);
        // code ends
    }

    // gets the size of the linked list
    int size() const
    {
        // code begins
        return mySize;
        // code ends
    }

    // checks if the linked list is empty; return True if empty, false otherwise
    bool empty() const
    {
        // code begins
        return mySize == 0;
        // code ends
    }

    // deletes all nodes excepts the head and tail
    void clear()
    {
        // code begins
        while (mySize > 0)
        {
            erase(begin());
        }
        // code ends
    }

    // return the first data element as mutable
    DataType &front()
    {
        // code begins
        return *begin();
        // code ends
    }

    // return the first data element as non-mutable
    const DataType &front() const
    {
        // code begins
        return *begin();
        // code ends
    }

    // return the last data element as mutable
    DataType &back()
    {
        // code begins
        return *(--end());
        // code ends
    }

    // return the last data element as non-mutable
    const DataType &back() const
    {
        // code begins
        return *(--end());
        // code ends
    }

    // insert x before itr; return iterator pointing to the newly inserted data element
    iterator insert(iterator itr, const DataType &x)
    {
        // code begins
        Node *p = itr.current;
        mySize++;
        return {p->prev = p->prev->next = new Node{x, p->prev, p}};
        // code ends
    }

    // insert x before itr; return iterator pointing to the newly inserted data element
    iterator insert(iterator itr, DataType &&x)
    {
        // code begins
        Node *p = itr.current;
        mySize++;
        return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
        // code ends
    }

    // delete the data element pointed by itr; return the iterator pointing to the data element next to the one being deleted
    iterator erase(iterator itr)
    {
        // code begins
        Node *p = itr.current;
        iterator retVal{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        mySize--;
        return retVal;
        // code ends
    }

    // delete the data elements from iterator "from" (inclusive) to iterator "to" (exclusive)
    // return the iterator "to"
    iterator erase(iterator from, iterator to)
    {
        // code begins
        for (iterator itr = from; itr != to;)
        {
            itr = erase(itr);
        }
        return to;
        // code ends
    }

    // insert data element x to the very begining of the linked list
    void push_front(const DataType &x)
    {
        // code begins
        insert(begin(), x);
        // code ends
    }

    void push_front(DataType &&x)
    {
        // code begins
        insert(begin(), std::move(x));
        // code ends
    }

    // insert data element x to the very end of the linked list
    void push_back(const DataType &x)
    {
        // code begins
        insert(end(), x);
        // code ends
    }

    void push_back(DataType &&x)
    {
        // code begins
        insert(end(), std::move(x));
        // code ends
    }

    // delete the very first data element
    void pop_front()
    {
        // code begins
        erase(begin());
        // code ends
    }

    // delete the very last data element
    void pop_back()
    {
        // code begins
        erase(--end());
        // code ends
    }

    // reverse the entire linked list
    void reverseList()
    {
        // code begins
        Node *current = head;
        head = tail;
        tail = current;
        while (current != nullptr)
        {
            Node *temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        // code ends
    }

    // append a linked list to the end of the current one
    MyLinkedList<DataType> &appendList(MyLinkedList<DataType> &&rlist)
    {
        // code begins
        for (iterator i = rlist.begin(); i != rlist.end(); ++i)
        {
            push_back(*i);
        }
        return *this;
        // code ends
    }

    // swap the data element pointed by itr with its next data element
    // return false if the next data element does not exist; true otherwise
    bool swapAdjElements(iterator &itr)
    {
        // code begins
        if (itr.current->next == nullptr)
        {
            return false;
        }
        else
        {
            DataType old = itr.current->data;
            itr.current->data = itr.current->next->data;
            itr.current->next->data = old;
            return true;
        }
        // code ends
    }
};

#endif // __MYLIST_H__