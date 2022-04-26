#include <iostream>

using namespace std;

template <typename T>
class DoubleLinkedList
{

private:
	class Node
	{
	public:
		Node* pNext;
		Node* prev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->prev = prev;
		}
	};
	Node* head, * tail;
	int size;

public:
	class Iterator
	{
	public:
		Iterator(Node* node) : curNode(node) {};
		T& operator*() const {
			return (this->curNode)->data;
		}
		void operator++();
		void operator--();
		bool operator==(const DoubleLinkedList::Iterator other) const;
		bool operator!=(const DoubleLinkedList::Iterator other) const;
		void operator+(int a);
		void operator-(int a);
		Iterator next() const;

	private:
		Node* curNode;
		friend void DoubleLinkedList<T>::remove(Iterator it);
		friend void DoubleLinkedList<T>::insertAfter(Iterator it, T data);
		friend void DoubleLinkedList<T>::insertBefore(Iterator it, T data);
	};
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void push_back(T data);

	void push_front(T data);
	T pop_front();

	void remove(Iterator it);
	void insertAfter(Iterator it, T data);

	bool empty();
	int getSize();

	//для а
	void insertBefore(Iterator it, T data);
	void insertAroundMin();
	//
	//Для b
	T findMaxNeg();
	void changeMid(T newMid);
	//

	Iterator begin();
	Iterator end();

};
template<typename T>
typename DoubleLinkedList<T>::Iterator findMin(DoubleLinkedList<T>& lst)
{
	typename DoubleLinkedList<T>::Iterator first = lst.begin();
	typename DoubleLinkedList<T>::Iterator last = lst.end();
	if (first == last) {
		return last;
	}
	typename DoubleLinkedList<T>::Iterator ans = first;
	++first;
	for (; first != last; ++first) {
		if (*first < *ans)
			ans = first;
	}
	return ans;
}




int main()
{
	DoubleLinkedList<int> lst;
	lst.push_back(-5);
	lst.push_back(52);
	lst.push_back(0);
	lst.push_back(15);
	lst.push_back(-578);
	lst.changeMid(lst.findMaxNeg());
	auto it = lst.begin();
	while (it != lst.end()) {
		cout << *it << ' ';
		++it;
	}
	
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	while (!empty())
		pop_front();
}

template<typename T>
void DoubleLinkedList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node(data);
		tail = head;
	}
	else
	{
		Node* cur = tail;
		tail = new Node(data);
		cur->pNext = tail;
		tail->prev = cur;
	}
	size++;
}


template<typename T>
void DoubleLinkedList<T>::push_front(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data, head);
		tail = head;
	}
	else
		head = new Node<T>(data, head);
	size++;
}

template<typename T>
T DoubleLinkedList<T>::pop_front()
{
	if (size == 1) {
		Node* temp = head;
		head = nullptr;
		tail = nullptr;
		T inf = temp->data;
		delete temp;
		return inf;
	}
	Node* temp = head;
	head = temp->pNext;
	T inf = temp->data;
	delete temp;
	size--;
	return inf;
}

template<typename T>
void DoubleLinkedList<T>::remove(Iterator it)
{
	if (it == nullptr)
		return;
	if (it.curNode == head) {
		pop_front();
		return;
	}
	Node* deleted = it.curNode;
	Node* cur1 = deleted->prev;
	Node* cur2 = deleted->pNext;
	cur1->pNext = cur2;
	cur2->prev = cur1;
	delete deleted;
	size--;
}

template<typename T>
void DoubleLinkedList<T>::insertAfter(Iterator it, T data)
{
	if ((it.curNode)->pNext == nullptr) {
		Node* inserted=new Node(data);
		Node* cur1 = it.curNode;
		cur1->pNext = inserted;
		inserted->prev = cur1;
	}
	else {
		Node* inserted=new Node(data);
		Node* cur1 = it.curNode;
		Node* cur2 = (it.curNode)->pNext;
		cur1->pNext = inserted;
		inserted->prev = cur1;
		inserted->pNext = cur2;
		cur2->prev = inserted;
	}
}

template<typename T>
void DoubleLinkedList<T>::insertBefore(Iterator it, T data)
{
	if (it.curNode == head) {
		Node* cur = head;
		head = new Node(data, head);
		cur->prev = head;
	}
	else {
		Node* inserted = new Node(data);
		Node* cur = (it.curNode)->prev;
		cur->pNext = inserted;
		inserted->prev = cur;
		(it.curNode)->prev = inserted;
		inserted->pNext = it.curNode;
	}
}

template<typename T>
bool DoubleLinkedList<T>::empty()
{
	return head == nullptr;
}

template<typename T>
int DoubleLinkedList<T>::getSize()
{
	return size;
}

template<typename T>
void DoubleLinkedList<T>::insertAroundMin()
{
	typename DoubleLinkedList<T>::Iterator it = findMin(*this);
	insertBefore(it, 0);
	insertAfter(it, 0);
}

template<typename T>
T DoubleLinkedList<T>::findMaxNeg()
{
	
	Iterator it = begin();
	T ans = 1;
	while (it != end()) {
		if (*it < 0 && ans == 1)
			ans = *it;
		else if (*it<0 && *it>ans)
			ans = *it;
		++it;
	}
	return ans;
}

template<typename T>
void DoubleLinkedList<T>::changeMid(T newMid)
{
	if (newMid > 0 || size % 2 == 0) {
		cout << "Something is wrong!!";
		return;
	}
	Iterator it = begin();
	for (int i = 0; i < size / 2; i++) {
		++it;
	}
	*it = newMid;
}

template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin()
{
	Iterator a(this->head);
	return a;
}

template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end()
{
	Iterator a(nullptr);
	return a;
}



template<typename T>
void DoubleLinkedList<T>::Iterator::operator++()
{
	if (curNode != nullptr)
		curNode = curNode->pNext;
}

template<typename T>
void DoubleLinkedList<T>::Iterator::operator--()
{
	curNode = curNode->prev;
}

template<typename T>
bool DoubleLinkedList<T>::Iterator::operator==(const Iterator other) const
{
	return (curNode == other.curNode);
}

template<typename T>
bool DoubleLinkedList<T>::Iterator::operator!=(const Iterator other) const
{
	return !operator==(other);
}

template<typename T>
void DoubleLinkedList<T>::Iterator::operator+(int a)
{
	for (int i = 0; i < a; i++)
		++this;
}

template<typename T>
void DoubleLinkedList<T>::Iterator::operator-(int a)
{
	for (int i = 0; i < a; i++)
		--this;
}

template<typename T>
typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::Iterator::next() const
{
	return Iterator((this->curNode)->pNext);
}

