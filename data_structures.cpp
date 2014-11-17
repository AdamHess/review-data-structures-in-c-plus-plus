#include <iostream>
#include <cstddef>
#include "data_structures.h"

using namespace std;

namespace ADAM
{

    //
    //  Stack
    //
    void Stack::push(int  value)
    {
        Node * el = new Node(value);
        if (m_head == NULL)
        {
            m_head = el;
        }
        else
        {
            el->setNext(m_head);
            m_head = el;
        }
        m_length++;
    }
    const int & Stack::pop()
    {
        const int & value = m_head->getVal();
        if (m_head->getNext())
        {
            Node * next = m_head->getNext();
            delete m_head;
            m_head = next;
        }
        else
        {
            delete m_head;
        }
        m_length--;
        return value;
    }

    //
    // Queue
    //
    void Queue::push(int  value)
    {
        Node * el = new Node(value);
        if (m_head == NULL)
        {
            m_head = el;
            m_tail = el;
        }
        else
        {
            m_tail->setNext(el);
            m_tail = el;
        }
        m_length++;
    }
    const int & Queue::pop()
    {
        const int & value = m_head->getVal();
        if (m_head->getNext())
        {
            Node * next = m_head->getNext();
            delete m_head;
            m_head = next;
        }
        else
        {
            delete m_head;
        }
        m_length--;
        return value;
    }

    // use linked list like a tree
    /*
    class BinaryTreeNode {
        private:
            BinaryTreeNode * m_left;
            BinaryTreeNode * m_right
            int m_val;
        public:
            BinaryTreeNode() : m_left(NULL), m_right(NULL){}
            BinaryTreeNode(int value): m_val(value), m_left(NULL), m_right(NULL){};
            BinaryTreeNode * getLeft() const {
                return m_left;
            }
            void setLeft(BinaryTreeNode * &n) {
                m_left = n; // gets rid of copy
            }
            BinaryTreeNode * getRight() const {
                return m_Right;
            }
            void setRight(BinaryTreeNode * &n) {
                m_Right = n; // gets rid of copy
            }
            int getVal() const {
                return m_val;
            }
            int setVal(int &value) {
                m_val = value;
            }

    };*/


    void testQueue()
    {
        Queue aQueue;
        aQueue.push(1);
        aQueue.push(2);
        aQueue.push(3);
        while(aQueue.getLength())
        {
            cout<<"Queue Element Number: " << aQueue.pop()<<endl;
        }
    }

    void testStack()
    {
        Stack aStack;

        aStack.push(1);
        aStack.push(2);
        aStack.push(3);

        while(aStack.getLength())
        {
            cout<<"Stack Element Number: " << aStack.pop()<<endl;
        }


    }

    void testLinkedList()
    {
        Node * n1 = new Node(1);
        Node * n2 = new Node(2);
        Node * n3 = new Node(3);

        n1->setNext(n2);
        n2->setNext(n3);
        Node * &currNode = n1;
        while (currNode != NULL)
        {
            Node * nextNode = currNode->getNext();
            cout<<"Node Number: "<< currNode->getVal()<<endl;
            delete currNode;
            currNode = nextNode;
        }
        Node * &currNode_2 = n1;
        while (currNode_2 != NULL)
        {
            Node * nextNode = currNode_2->getNext();
            cout<<"Node Number: "<< currNode_2->getVal()<<endl;
            delete currNode_2;
            currNode_2 = nextNode;
        }
    }
}

using namespace ADAM;

int main()
{
    cout<<"Testing Queue"<<endl;
    testQueue();
    cout<<"Testing stack"<<endl;
    testStack();
    cout<<"Testing Linked List"<<endl;
    testLinkedList();
    return 1;
}





