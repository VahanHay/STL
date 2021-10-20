#ifndef  _DList_H
#define  _DList_H

template <typename T>
class DList
{
private:
    class Node
    {
        public:
        T val; 
        Node * next;
        Node * prev;
        Node(T  val= T() , Node* next = nullptr , Node * prev = nullptr)
        {
            this -> val  = val;
            this -> next = nullptr;
            this -> prev = nullptr;
        } 
       
    };
        Node * head{nullptr} ;
        Node * tail{nullptr} ;
        int    size{0} ; 
public:
        //constructors 0-5;
        DList();
        DList(const T& rhs);
        DList(const DList<T>& rhs);
        DList(const DList<T>&& rhs);
        ~DList();
        //add or delete element front and  back
        void push_back(const T& rhs);//
        void push_front(const T& rhs);//
        void pop_back();//
        void pop_front();//

        //supplement
        void clear();//
        bool empty();//
        void print();//
        int get_size() ;//
       // void sort();
        void unique();
    void insert(int pos , const T& rhs);
   // void insert(int pos , int count , const T& rhs);
    //void erase (int pos);
    T& front() ;
    T& back()  ;
    //void remove(const T& rhs);
    //void remove_if(const T& rhs);
    void swap(DList<T>& rhs);
    //void assing (int count , const T& rhs);
    
    //DList<T>
   // DList<T>& operator=(const DList<T>& other); // copy assignment
	
	//DList<T>&& operator=(const DList<T>&& other); // move assignment
	//DList<T>& operator=(std::initializer_list<T> ilist);
};
   

template <typename T>
DList<T>::DList():head{nullptr},tail{nullptr},size{0} 
{
    std::cout<< "ctor "<< std::endl;
}

template <typename T>
DList<T>::DList(const T& rhs)
{
    head = new Node(rhs);
    tail = head ;
    size = 1;
}

template <typename T>
void DList<T>::push_back(const T& rhs)
{
    if(head == nullptr)
    {
        head = new Node(rhs);
        tail = head ;
      
    }
    else
    {
        Node * tmp = new Node(rhs);
        tail -> next  = tmp;
        tmp  -> prev = tail;
        tail = tmp; 
        tmp = nullptr;
      
    }
    ++size;
}

template <typename T>
void DList<T>::push_front(const T& rhs)
{
    if(head==nullptr)
    {
        head = new Node(rhs);
        tail = head ;
       
    }
    else
    {
        Node * tmp = new Node(rhs);
        tmp -> next = head;
        head -> prev = tmp;
        head = tmp;
        tmp = nullptr;
       
    }
     ++size;
}

template <typename T>
void DList<T>::pop_back()
{
    if(head==nullptr)
    {
        std::cout << " There is no elements " << std::endl;
        exit(1);
    }
    else if(tail->prev == nullptr)
    {
       delete tail;
       head = nullptr;
       tail = nullptr;
       size = 0; 
    }
    else
    {
        Node* tmp = tail;
        tail = tail -> prev;
        tail -> next = nullptr;
        delete tmp;
        --size; 
    }
}

template <typename T>
void DList<T>::pop_front()
{
    if(head==nullptr)
    {
        std::cout << " There is no elements " << std::endl;
        exit(1);
    }
    else if(head -> next == nullptr)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0 ;
    }
    else 
    {
        Node * tmp = head;
        head = head -> next ;
        head -> prev = nullptr;
        delete tmp;
        --size;
    }
}

template <typename T>
void DList<T>::clear()
{
     Node* current = head;
	while (current)
	{
		current = current->next;
		delete(head);
		head = current;
	}
	tail = nullptr;
	head = nullptr;
	size = 0;
}

template <typename T>
bool DList<T>::empty()
{
    return head == nullptr;
}

template <typename T>
void DList<T>::print()
{
    Node * tmp = head;
    while(tmp!=nullptr)
    {
        std::cout << tmp -> val << " ";
        tmp = tmp ->next;
    }
    std::cout << std::endl;
}

template <typename T>
int DList<T>::get_size() 
{
    return size;
}

template <typename T>
T& DList<T>::front()
{
    if(head==nullptr)
    std::cout <<"no elem " << std::endl;
    return head -> val;
}

template <typename T>
T& DList<T>::back()
{
    if(head==nullptr)
    std::cout <<"no elem " << std::endl;
    return tail -> val;
}

template <typename T>
DList<T>::DList(const DList<T>& rhs)
{
   /* this -> size = 0 ;
    if(rhs.head==nullptr)
    {
        std::cout<<"1st"<<std::endl;
        this -> head = nullptr;
        this -> tail = nullptr;
        this -> size = 0 ;
    }
    else if(rhs.head -> next == nullptr)
    {
         std::cout<<"2st"<<std::endl;
        //this -> push_front(rhs.head -> val);
        this->head = new Node(rhs.head -> val);
        this->tail = head;
        ++this->size;
        std::cout<<"2st"<<std::endl;

    }
    else
    {
        // std::cout<<"fg";
       
        // std::cout<<"3st"<<std::endl;
        //this -> push_front(rhs.head -> val);
        this->head = new Node(rhs.head -> val);
        this->tail = head;
        ++this->size;
        Node * cur = rhs.head->next;
        while(cur != nullptr)
        {
            //std::cout<<" for " <<" ";
            Node* tmp = new Node(cur -> val);
            this->tail-> next = tmp;
            tmp->prev= tail;
            tail = tmp;
            tmp= nullptr;
            cur = cur -> next;
            ++this->size;
        }
        //this->size = rhs.size;
       
    }*/
    std::cout << "Copy ctor" << std::endl;
	if (rhs.head == nullptr)
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	else if (rhs.head->next == nullptr)
	{
        std::cout << "Copy ctor" << std::endl;
		this->push_front(rhs.head->val);
	}
	else
	{
		Node* cur = rhs.head;
		while (cur)
		{
			this->push_back(cur->val);
			cur = cur->next;
		}
	}
   
}

template <typename T>
DList<T>::DList(const DList<T>&& rhs)
{
  this -> head = rhs.head;
  this -> tail = rhs.tail;
  this -> size = rhs.size;
  rhs.head = nullptr;
  rhs.tail = nullptr;
  rhs.size = 0;
}

template <typename T>
void DList<T>::swap(DList<T>& rhs)
{
    DList<T> tmp;

    tmp.head = this -> head;
    tmp.tail = this->tail;
    tmp.size = this->size;
    //
    this->head = rhs.head;
    this->tail = rhs.tail;
    this->size = rhs.size;
    //
    rhs.head = tmp.head;
    rhs.tail = tmp.tail;
    rhs.size = tmp.size; 

    tmp.head = nullptr;
    tmp.tail = nullptr;
    tmp.size = 0;
}

template<typename T>
void DList<T>::insert(int pos , const T& rhs)
{
    if(pos<0 || pos>get_size())
    {
      std::cout <<" Out of Range " << std::endl;
      exit(1);
    }
    

    
    if(pos == 0)
    {
        push_front(rhs);
        return;
    }
    else if(pos == size)
    {
        push_back(rhs);
        return;
    }
    else
    {
        Node * cur = new Node(rhs);
        Node * tmp = head;
        --pos;
        while (pos)
        {
            tmp = tmp -> next;
            --pos; 
        }
        cur -> next = tmp -> next;
        cur -> prev = tmp;
        tmp -> next = cur;
        cur = nullptr;
        ++size; 
        return;
    }
     
 
}

template <typename T>
void DList<T>::unique()
{
    if(this-> head == nullptr || this-> head -> next == nullptr)
    {
        return;
    }
    if(size == 2)
    {
        if(head -> val == tail -> val)
        {
            pop_back();
        }
        return;
    }
    Node * tmp  = this -> head;
    
    while (tmp -> next != nullptr)
    {
        Node * tmp2 = tmp -> next;
        while (tmp2 != nullptr)
        {
             if(tmp -> val == tmp2 -> val)
             {
                 Node * cur = tmp2 ;
                 tmp2 = tmp2 -> next;
                 tmp  
             }
        }
        

          
    }
    

}

template <typename T>
DList<T>::~DList()
{
    std::cout<<"dec"<<std::endl;
    clear();
}





#endif //_DLIST