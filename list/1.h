#ifndef _MYLIST_
#define _MYLIST_
#include <iostream>
#include <string>
#include <initializer_list>


template <typename T>
class MyList
{
	class Node;
public:
	//Constructors
	class Iterator;
	Iterator begin()
	{
		return Iterator(head);
	}
	Iterator end()
	{
		return Iterator(nullptr);
	}
	MyList();
	MyList(const MyList<T>& other);
	MyList(std::initializer_list<T> init);
	//Destructor
	~MyList();
	//operator=
	MyList<T>& operator=(const MyList<T>& other);
	MyList<T>& operator=(std::initializer_list<T> ilist);
	//assign
	void assign(int count, const T& value);
	//Element access
	MyList<T>& front();
	const MyList<T>& front() const;
	MyList<T>& back();
	const MyList<T>& back() const;
	//Capacity
	bool empty() const;
	int size() const;
	//Modifiers
	void clear();
	void insert(Iterator pos, int count, const T& value);
	void insert(Iterator pos, const T& value);
	void erase(int pos);
	void push_back(const T& value);
	void pop_back();
	void push_front(const T& value);
	void pop_front();
	void resize(int count);
	void swap(MyList<T>& other);
	T& operator[](const int index);
	//Operations
	void merge(MyList<T>& other);
	void remove(const T& value);
	void reverse();
	void unique();
	void sort();
	//cout
	void print();
	
	class Iterator
	{
	public:
		Iterator() noexcept : m_pCurrentNode(head) { }
		Iterator(const Node* pNode) noexcept : m_pCurrentNode(pNode) { }
		Iterator& operator=(Node* pNode)
		{
			this->m_pCurrentNode = pNode;
			return *this;
		}
		Iterator begin()
		{
			return Iterator(head);
		}
		Iterator end()
		{
			return Iterator(nullptr);
		}
		// Prefix ++ overload
		Iterator& operator++()
		{
			if (m_pCurrentNode)
				m_pCurrentNode = m_pCurrentNode->next;
			return *this;
		}
		// Postfix ++ overload
		Iterator operator++(int)
		{
			Iterator iterator = *this;
			++* this;
			return iterator;
		}
		bool operator!=(const Iterator& iterator)
		{
			return m_pCurrentNode != iterator.m_pCurrentNode;
		}
		int operator*()
		{
			return m_pCurrentNode->data;
		}
	private:
		const Node* m_pCurrentNode;
	};
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int m_size;
	static Node* head;
	
};

template <typename T>
typename MyList<T>::Node* MyList<T>::head = nullptr;
template <typename T>
MyList<T>::MyList() : m_size{ 0 } { head= nullptr; }
template<typename T>
MyList<T>::MyList(const MyList<T>& other)
{
	if (other.head == nullptr) {
		head = nullptr;
	}
	else
	{
		m_size = other.m_size;
		head = new Node(other.head->data);
		Node* current = head;
		Node* currentobj = other.head;
		while (currentobj->next != nullptr)
		{
			current->next = new Node(currentobj->next->data);
			currentobj = currentobj->next;
			current = current->next;
		}
	}
}
template<typename T>
MyList<T>::MyList(std::initializer_list<T> init)
{
	Node* curr = new Node;
	Node* tmp = curr;
	
	typename std::initializer_list<T>::iterator it = init.begin();
	m_size = init.size();
	while (it != init.end()-1)
	{
		curr->data = *it;
		curr->next = new Node;
		curr = curr->next;
		++it;
	}
	curr->data = *it;
	curr->next = nullptr;
	head = tmp;
}
template <typename T>
MyList<T>::~MyList()
{
	Node* current = head;
	while (current != NULL) {
		Node* garbage = current;
		current = current->next;
		delete garbage;
	}
}
template <typename T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other)
{
	if (this == &other) {
		std::cout << "self-attribution";
		return *this;
	}
	if (other.head == nullptr) {
		head = nullptr;
		return *this;
	}
	else
	{
		m_size = other.m_size;
		head = new Node(other.head->data);
		Node* current = head;
		Node* currentobj = other.head;
		while (currentobj->next != nullptr)
		{
			current->next = new Node(currentobj->next->data);
			currentobj = currentobj->next;
			current = current->next;
		}
		return *this;
	}
}
template <typename T>
MyList<T>& MyList<T>::operator=(std::initializer_list<T> ilist)
{
	Node* curr = new Node;
	Node* tmp = curr;
	typename std::initializer_list<T>::iterator it = ilist.begin();
	m_size = ilist.size();
	while (it != ilist.end() - 1)
	{
		curr->data = *it;
		curr->next = new Node;
		curr = curr->next;
		++it;
	}
	curr->data = *it;
	curr->next = nullptr;
	head = tmp;
	return *this;
}
template <typename T>
void MyList<T>::assign(int count, const T& value)
{
	if (count <= 0)
	{
		std::cout << "error";
		exit(1);
	}
	this->clear();
	for (int i = 0; i < count; ++i)
	{
		this->push_back(value);
	}
}
template <typename T>
MyList<T>& MyList<T>::front()
{
	if (head == nullptr)
	{
		return nullptr;
	}
	return head->data;
}
template <typename T>
const MyList<T>& MyList<T>::front() const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	return head->data;
}
template <typename T>
MyList<T>& MyList<T>::back()
{
	if (head == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->data;
	}
}
template <typename T>
const MyList<T>& MyList<T>::back() const
{
	if (head == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->data;
	}
}
template <typename T>
bool MyList<T>::empty() const
{
	return !m_size;
}
template <typename T>
int MyList<T>::size() const
{
	return this->m_size;
}
template <typename T>
void MyList<T>::clear()
{
	Node* current = head;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}
template <typename T>
void MyList<T>::insert(Iterator pos, int count, const T& value)
{
	if ((pos >= 1) && (pos <= count))
	{
	}
}
template<typename T>
void MyList<T>::insert(Iterator pos, const T& value)
{
}
template <typename T>
void MyList<T>::erase(int pos)
{
}
template<typename T>
void MyList<T>::push_back(const T& value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}
	else
	{
		Node* current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(value);
	}
	++m_size;
}
template <typename T>
void MyList<T>::pop_back()
{
}
template <typename T>
void MyList<T>::push_front(const T& value)
{
	Node* tmp = new Node;
	tmp->data = value;
	if (m_size == 0) {
		head = tmp;
		++m_size;
		return;
	}
	Node* cur = head;
	tmp->next = cur;
	head = tmp;
	++m_size;
}
template <typename T>
void MyList<T>::pop_front()
{
}
template <typename T>
void MyList<T>::resize(int count)
{
}
template <typename T>
void MyList<T>::swap(MyList<T>& other)
{
}
template <typename T>
T& MyList<T>::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current == index)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		++current;
	}
}
template <typename T>
void MyList<T>::merge(MyList<T>& other)
{
}
template <typename T>
void MyList<T>::remove(const T& value)
{
}
template <typename T>
void MyList<T>::reverse()
{
}
template <typename T>
void MyList<T>::unique()
{
}
template <typename T>
void MyList<T>::sort()
{
}
template <typename T>
void MyList<T>::print()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}
#endif // !_MYLIST_