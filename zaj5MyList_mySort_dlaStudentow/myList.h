using namespace std;

template <typename T>
class MyList 
{
    public:
        struct Node
        {
            using node_ptr = unique_ptr<Node>;

            Node(const T& data, Node* next) {this->data = new T(data);this->next = next;}
            ~Node() {delete data; }

            T* data;
            Node* next; //node_ptr??

            Node* operator++(int){ return next; }
        };

        using node_ptr = unique_ptr<Node>;
 
    public:
        MyList();

        size_t size() const;
        T& front() const;

        node_ptr begin();
        node_ptr end();

        node_ptr begin() const;
        node_ptr end() const;

        void push_front(const T&);
        T& pop_front();

        void remove(T);

    protected:
        node_ptr head;
};

typedef MyList<int*> iterator_type;
typedef MyList<const int*> const_iterator_type;

template<class T> MyList<T>::MyList() { head = nullptr; }

template<class T> T& MyList<T>::front() const {  return *(head->data); }

template<class T> MyList<T>::node_ptr MyList<T>::begin() {  return head; }
template<class T> MyList<T>::node_ptr MyList<T>::begin() const {  return head; }

template<class T> MyList<T>::node_ptr MyList<T>::end()
{
    MyList<T>::node_ptr prev=nullptr,curr=head;
    while(curr!=nullptr)
    {
        prev = curr;
        curr= curr->next;
    }
    return prev;
}
template<class T> MyList<T>::node_ptr MyList<T>::end() const 
{
    unique_ptr<MyList::Node> prev=nullptr,curr=head;
    while(curr!=nullptr)
    {
        prev = curr;
        curr= curr->next;
    }
    return prev;
}

template<class T> size_t MyList<T>::size() const
{
    MyList<T>::node_ptr curr = head;

    size_t cnt =0;
    while(curr!=nullptr)
    {
        curr=curr->next;
        cnt++;
    }

    return cnt;
}

 
template<class T> void MyList<T>::push_front(const T& e) 
{
    Node* new_node;
    
    if (head==nullptr) 
    {
        new_node = new Node(e, nullptr);
        head = new_node;
        return;
    }

    new_node = new Node(e, head);
    head = new_node;
}

template<class T> T& MyList<T>::pop_front() 
{
    if (head==nullptr)  { throw std::out_of_range;  }

    T& data = head->data;

    head = head->next;

    return data;
}


template<class T> void MyList<T>::remove(T element) {
    
    MyList<T>::node_ptr curr = head,prev = nullptr,tmp;
    
    while (curr != nullptr) 
    {
        if (curr->data == element) 
        {
            if (curr == head) 
            {
                curr = curr->next;
                delete head;
                head = curr;
            }
            else 
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else
        {
            curr = curr->next;
            prev = prev->next
        }
    }
}

template<class T> ostream& operator<< (ostream& out, const MyList<T>& l) {
    MyList<T>::node_ptr curr= l.begin();
    
    while (curr != nullptr) 
    {
        out << *(curr->data) << " ";
        curr = curr->next;
    }

    return out;
}