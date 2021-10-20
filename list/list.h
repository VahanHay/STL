#ifndef _LIST_
#define _LIST_
#include<iostream>
#include <initializer_list>
   
 
   
template <typename T>
class List
{ 
  class Node;
public:
  class Iterator;
  Iterator begin()
  {
    return Iterator(head);
  }
  Iterator end()
  {
    return Iterator(nullptr);
  }
  List();
  List(const T& rhs);
  ~List();
  List(const List<T>&);
  List(std::initializer_list<T> init);
  //bool operator==(const List<T>& rhs);
  //bool operator!=(const List<T>& rhs);
  void insert(int pos, const T& elem);
  void insert(int pos, int count, const T& value);
  void assingn(int count,const T& elem);
  void in_rage(int count);
  void push_back( T elem);
  void push_front( T elem);
  void remove(T elem);
  void pop_front();
  void pop_back();
  void clear();
  void swap(List<T>& rhs);
  void resize(int count);
  void print();
  void revers();
  void erase(int pos);
  int get_m_size()
  {
    return m_size;
  }
  bool empty();
  //bool operator==(const List<T>& other);
  //bool operator!=(const List<T>& other);
  
  List<T>& operator=(const List<T>& other);

  class Iterator
  {
  public:
    Iterator() noexcept : cur(head){}
    Iterator(const Node* PNode) noexcept : cur(PNode){}
    Iterator& operator=(Node* PNode)
    {
      cur = PNode;
      return *this;
    }
    Iterator& operator++()
    {
      if(cur)
      {
        cur=cur->next;
      }
      return *this;
    }
    Iterator operator++(int)
    {
      Iterator iterator = *this;
      ++* this;
      return iterator;
    }
    bool operator!=(const Iterator& iterator)
    {
      return cur != iterator.cur;
    }
    T operator*()
    {
      return cur->data;
    }
  private:
    const Node* cur;
  };
private:
  class Node
  {
    public:
      T data;
      Node* next;
      Node(T data=T(),Node* next=nullptr)
      {
        this->data=data;
        this->next=next;
      }
  
  };
  int m_size;
   Node *head;
 
};



template <typename T>
List<T>::List()
{
  head=nullptr;
  m_size=0;
}

 template <typename T>
 List<T>::List(const List<T>& other)
 {
   
   if (other.head == nullptr) 
   {
		return;
	 }
    
    Node*tmp=other.head;
    while (tmp!=nullptr)
    {
       this->push_back(tmp->data);
       tmp=tmp->next;
    }
    
   
   
 }

template <typename T>
List<T>::List(const T& elem)
{

  head=new Node(elem);
  ++m_size;
}

//template <typename T>
//List(std::initializer_list<T> init);




template <typename T>
void List<T>::in_rage(int count)
{
  if(count < 0 || count > m_size)
   std::cout<<"Out Of Rang"<<std::endl;
   exit(1);
}

template <typename T>
List<T>::~List()
{
  clear();
}
 
template <typename T>
void List<T>::push_front( T elem)
{
  if(head==nullptr)
  {
    head=new Node(elem);
    return;
  }
  Node* cur =new Node(elem);
  cur->next=head;
  head=cur;
  cur=nullptr;
  ++m_size;
}
template <typename T>
void List<T>::pop_front()
{
  if(m_size==1)
  {
    delete head;
    head=nullptr;
  }
  Node * cur=head;
  head=head->next;
  delete cur;
  --m_size;
}
template <typename T>
void List<T>::clear()
{
  while(head!=nullptr)
  {
    Node* tmp=head;
    head=head->next;
    delete tmp;
    --m_size;
  }
}

template <typename T>
void List<T>::push_back(T elem)
{
  if(head==nullptr)
  {
    head=new Node(elem);
    head->next=nullptr;
    ++m_size;
    return;
  }
  if(m_size==1)
  {
    head->next=new Node(elem);
    head->next->next=nullptr;
    ++m_size;
    return;
  }
  Node*cur=head;
  Node*cur1=head->next;
  
  for(int i = 1 ;i<m_size;++i)
  {
    cur=cur->next;
   
  }
  cur->next=new Node(elem);
  
  ++m_size;
}

template <typename T>
void List<T>::pop_back()
{
  if(!m_size)
  {
    std::cout<<"Out OF Range" << std::endl;
    exit(23);
  }
  if(m_size==1)
  {
    delete head;
    head=nullptr;
    return;
  }
  Node* cur=head;
  Node* cur1=head->next;
  while(cur1->next!=nullptr)
  {
    cur=cur1;
    cur1=cur1->next;
  }
  delete cur1;
  cur->next=nullptr;
  --m_size;
}

template <typename T>
bool List<T>::empty()
{
  return !m_size;
}

template <typename T>
void List<T>::swap(List<T>& rhs)
{
  int tmp2 =this->get_m_size();
  this->m_size=rhs.m_size;
  rhs.m_size=tmp2;
  Node*tmp=this->head;
  this->head=rhs.head;
  rhs.head=tmp;
  tmp=nullptr;
}

template <typename T>
void List<T>::print()
{
  Node* tmp=head;
  int k=m_size;
  while(k)
  {
    std::cout<<tmp->data;
    tmp=tmp->next;
    --k;
  }
}

template <typename T>
void List<T>::resize(int count)
{
  if(count<0)
  {
    std::cout<<"Out Of Range"<<std::endl;
    exit(2);
  }
  int k=m_size-count;
  for(;k<0 ; ++k)
  {
    push_back(T());
  }
  for(;k>0; --k)
  {
    pop_back();
  }
}

template <typename T>
void List<T>::remove(T elem)
{
  Node* tmp=this->head;
  while(tmp != nullptr && tmp->data == elem)
  {
    head=head->next;
    delete tmp;
    tmp=head;
    --m_size;
  }
  if(m_size==0)
  {
    return;
  }
  Node* tmp2 = tmp->next;
  while(tmp2!=nullptr)
  {
    if(tmp2->data==elem)
    {
      
      tmp->next=tmp2->next;
      delete tmp2;
      tmp2=tmp->next;
      --m_size;
      
    }
    else
    {
      tmp=tmp2;
      tmp2=tmp2->next;
    }
  }

}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
   if(head==other.head)
   {
     return *this;
   }
   this->clear();
   Node*tmp=other.head;
   while(tmp)
   {
    this->push_back(tmp->data);
    tmp=tmp->next;
   }
   return *this;
}

template <typename  T>
void List<T>::assingn(int count,const T& elem)
{
  if(count < 1 )
  {
    std::cout<<"Out Of Rang " << std::endl;
    exit(1008);
  }
  this->clear();
  for(int i = 0 ; i < count; ++i)
  {
    this->push_back(elem);
  }
}

template <typename  T>
void List<T>::insert(int pos, const T& elem)
{  
    if(pos==0)
    {
      this->push_front(elem);
      ++m_size;
      return;
    }
  if((pos>0)&&(pos<=m_size))
  {
  
    Node* tmp = new Node(elem);
    Node* tmp2 = head;

    for(int i = 1;i < pos; ++i)
    {
      tmp2 = tmp2->next;
    }
    if(tmp2->next==nullptr)
    {
      tmp->next=tmp2;
    } 
    tmp->next = tmp2->next;
    tmp2->next = tmp;
    tmp=nullptr;
  }
  else
  {
    std::cout<<"out of range"<<std::endl;
    exit(1);
  }
}

template <typename  T>
void List<T>::insert(int pos, int count, const T& value)
{
  if (pos > 0 && pos <= m_size+1 && count > 0)
	{
		if (pos == 1)
		{
			for (int i = 0; i <count; ++i)
			{
				this->push_front(value);
			}
			return;
		}
		if (pos == m_size + 1)
		{
			for (int i = 0; i < count; ++i)
			{
				this->push_back(value);
			}
			return;
		}
		Node* L1 = this->head;
		Node* temp = new Node(value);
		Node* cur = temp;
		for (int i = 1; i < count; ++i)
		{
			cur->next = new Node(value);
			cur = cur->next;
		}
		for(int i = 2;i<pos;++i)
		{
			L1 = L1->next;
		}
		Node* f = temp;
		for (int i = 1; i < count; ++i)
		{
			f = f->next;
		}
		f->next = L1->next;
		L1->next = temp;
    m_size=m_size+count;
	}
   else
  {
    std::cout<<"out of range"<<std::endl;
    exit(1);
  }
}

template <typename  T>
void List<T>::erase(int pos)
{
  if(pos > 0 && pos<=m_size)
  {
    if(pos==1)
    {
      Node*tmp=head;
      head=head->next;
      delete tmp;
      --m_size;
      return;
    }
    if(pos==m_size)
    {
      this->pop_back();
      return;
    }
    Node*tmp=head;
    Node*tmp2=head->next;
    for(int i = 2; i<pos; ++i)
    {
      tmp = tmp2;
      tmp2=tmp->next;
    }
     tmp->next=tmp2->next;
     delete tmp2;
     --m_size;
  }
  else
  {
    std::cout<<"Out Of Rang"<<std::endl;
    exit(33);
  }
}

template <typename  T>
void List<T>::revers()
{
   if(head==nullptr || head->next==nullptr)
        {
            return ;
        }
        if(head->next->next==nullptr)
        {
              Node*tmp=head->next;
              tmp->next=head;
              head->next=nullptr;
              head=tmp;
             tmp=nullptr;
             return;
        }
        Node*tmp=head;
        Node*tmp2=head;
        Node*cur=head->next;
        Node*ptr=nullptr;
        int k=0;
        while(tmp->next!=nullptr)
        {
            while(cur->next!=nullptr)
            {
               tmp2=cur;
                cur=cur->next;
            }
             if(k==0)
                {
                    ++k;
                    tmp2->next=nullptr;
                    head=cur;
                    ptr=head;
                }
               else
               {
                   tmp2->next=nullptr;
                   ptr->next=cur;
                   ptr=ptr->next;
               }
            tmp2=tmp;
            cur=tmp->next;
        }
        ptr->next=tmp;
       
}

#endif  //LIST