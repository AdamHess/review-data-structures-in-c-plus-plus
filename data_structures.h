#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

namespace ADAM
{
class Node
{
private:
    Node * m_next;
    int m_val;
public:
    Node() : m_next(NULL) {}
    Node(int value): m_val(value), m_next(NULL) {}
    Node * getNext() const
    {
        return m_next;
    }
    void setNext(Node * &n)
    {
        m_next = n; // gets rid of copy
    }
    int getVal() const
    {
        return m_val;
    }
    int setVal(int &value)
    {
        m_val = value;
    }

};

class Stack
{
private:
    Node * 	m_head;
    int m_length;
public:
    Stack() : m_head(NULL), m_length(0) {};
    ~Stack()
    {
        while (m_length > 0)
        {
            this->pop();
        }
    }
    void push(int  value);
    const int & pop();
    const int & getLength()
    {
        return m_length;
    }
};

class Queue
{
private:
    Node * 	m_head;
    Node * 	m_tail;
    int m_length;
public:
    Queue() : m_head(NULL), m_length(0) {};
    ~Queue()
    {
        while (m_length > 0)
        {
            this->pop();
        }
    }
    void push(int  value);
    const int & pop();
    const int & getLength() const
    {
        return m_length;
    }

};
//Testing functions
void testLinkedList();
void testQueue();
void testStack();



}


#endif /*DATA_STRUCTURES_H*/
