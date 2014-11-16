#include <iostream>
#include <cstddef>

using namespace std;

namespace ADAM {
	class Node {
		private:
			Node * m_next;
			int m_val;
		public:
			Node() : m_next(NULL) {}
			Node(int value): m_val(value), m_next(NULL){};
			Node * getNext() const {
				return m_next;
			}
			void setNext(Node * &n) {
				m_next = n; // gets rid of copy 
			}
			int getVal() const {
				return m_val;
			}		
			int setVal(int &value) {
				m_val = value;
			}

	};
	//linked list has just nodes, there is no "overarching structure" that would be a 
	//stack or a queue 

	class Stack {
		private:
			Node * 	m_head;
			int m_length;
		public:
			Stack() : m_head(NULL), m_length(0){};
			~Stack() {
				while (m_length > 0){
					this->pop();
				}
			}
			void push(int  value) {
				Node * el = new Node(value);
				if (m_head == NULL) {
					m_head = el;
				}
				else {
					el->setNext(m_head);
					m_head = el;
				}
				m_length++;
			}
			const int & pop() {
				const int & value = m_head->getVal();
				if (m_head->getNext()) {
					Node * next = m_head->getNext();
					delete m_head;
					m_head = next;
			   }
			   else {
			   	delete m_head;
			   }


				m_length--;
				return value;
			}	
			const int & getLength() {
				return m_length;
			}

	};

	class Queue {
		private:
			Node * 	m_head;
			Node * 	m_tail;
			int m_length;
		public:
			Queue() : m_head(NULL), m_length(0){};
			~Queue() {
				while (m_length > 0){
					this->pop();
				}
			}
			void push(int  value) {
				Node * el = new Node(value);
				if (m_head == NULL) {
					m_head = el;
					m_tail = el;
				}
				else {
					m_tail->setNext(el);
					m_tail = el;
				}
				m_length++;
			}
			const int & pop() {
				const int & value = m_head->getVal();
				if (m_head->getNext()) {
					Node * next = m_head->getNext();
					delete m_head;
					m_head = next;
			   }
			   else {
			   	delete m_head;
			   }


				m_length--;
				return value;
			}	
			const int & getLength() {
				return m_length;
			}

	};

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
}
using namespace ADAM;
	void testQueue() {
		Queue aQueue; 

		aQueue.push(1);
		aQueue.push(2);
		aQueue.push(3);

		while(aQueue.getLength()) {
			cout<<"Queue Element Number: " << aQueue.pop()<<endl;
		}


	}
	void testStack() {
		Stack aStack; 

		aStack.push(1);
		aStack.push(2);
		aStack.push(3);

		while(aStack.getLength()) {
			cout<<"Stack Element Number: " << aStack.pop()<<endl;
		}


	}


	void testLinkedList() {
		Node * n1 = new Node(1);
		Node * n2 = new Node(2);
		Node * n3 = new Node(3);

		n1->setNext(n2);
		n2->setNext(n3);
		Node * &currNode = n1;
		while (currNode != NULL) {
			Node * nextNode = currNode->getNext();
			cout<<"Node Number: "<< currNode->getVal()<<endl;
			delete currNode;
			currNode = nextNode;
		}


		Node * &currNode_2 = n1;
		while (currNode_2 != NULL) {
			Node * nextNode = currNode_2->getNext();
			cout<<"Node Number: "<< currNode_2->getVal()<<endl;
			delete currNode_2;
			currNode_2 = nextNode;
		}


		
	}
          
          
          
	int main() {
		cout<<"Testing Queue"<<endl;
		testQueue();
		cout<<"Testing stack"<<endl;
		testStack();
		cout<<"Testing Linked List"<<endl;
		testLinkedList();
		return 1;		
	}
          
          
          
          

