#include <iostream>
#include <string>
using namespace std;

using ItemType = string;

struct Node {
    ItemType value;
    Node *next;
    Node * prev;
};

class LinkedList {
    
private:
    Node *head;
    Node *tail;
    
public:
    
      // default constructor
    LinkedList() : head(nullptr), tail(nullptr) { }
    
    
      // copy constructor
    LinkedList(const LinkedList& rhs);
    
      // Destroys all the dynamically allocated memory
      // in the list.
    ~LinkedList();
    
      // assignment operator
    const LinkedList& operator=(const LinkedList& rhs);
    
      // Inserts val at the front of the list
    void insertToFront(const ItemType &val);
    
      // Prints the LinkedList
    void printList() const;
    
      // Sets item to the value at position i in this
      // LinkedList and return true, returns false if
      // there is no element i
    bool get(int i, ItemType& item) const;
    
      // Reverses the LinkedList
    void reverseList();
    
      // Prints the LinkedList in reverse order
    void printReverse() const;
    
      // Appends the values of other onto the end of this
      // LinkedList.
    void append(const LinkedList &other);
    
      // Exchange the contents of this LinkedList with the other one.
    void swap(LinkedList &other);
    
      // Returns the number of items in the Linked List.
    int size() const;
};

LinkedList::LinkedList(const LinkedList& rhs){
    if(rhs.head==nullptr)
        return;
    else{
        Node* i = rhs.head;
        Node* curr;
        while(i!=nullptr){
            Node* add = new Node;
            add->value = i->value;
            add->next = nullptr;
            add->prev = nullptr;
            
            if(head==nullptr){
                head=add;
                tail=add;
            }
        
            else{
                curr = head;
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                curr->next=add;
                curr->next->prev=curr;
                tail=add;
            }
            i=i->next;
        }
    }
}

void LinkedList::swap(LinkedList &other){
    LinkedList* temp = new LinkedList(other);
      other = *this;
      *this = *temp;
      delete temp;
}


void LinkedList::insertToFront(const ItemType &val){
    Node* add = new Node;
    add->value = val;
    add->next=nullptr;
    add->prev=nullptr;
    if(head==nullptr){
        head=add;
        tail=add;
    }
    else{
        head->prev=add;
        add->next=head;
        head=add;
    }
}

void LinkedList::printReverse() const{
    Node* i = tail;
    while(i!=nullptr){
        cout<<i->value<< " ";
        i=i->prev;
    }
}

void LinkedList::append(const LinkedList &other){
    Node* traverse = other.head;
    while(traverse!=nullptr){
        Node* addNode = new Node;
        addNode->value = traverse->value;
        addNode->prev = nullptr;
        addNode->next = nullptr;
        if(head==nullptr){
            head=addNode;
            tail=addNode;
        }
        else{
            tail->next = addNode;
            addNode->prev = tail;
            tail = addNode;
        }
        traverse = traverse->next;
    }
}


bool LinkedList::get(int i, ItemType& item) const{
    int count{};
    for(Node* k = head; k!=nullptr; k = k->next){
        if(k!=head)
            count++;
        if(count==i){
            item=k->value;
            return true;
        }
    }
    return false;
}


void LinkedList::printList() const {
    Node* i = head;
    while(i!=nullptr){
        cout<<i->value << " ";
        i=i->next;
    }
}

LinkedList::~LinkedList(){
    Node* n = head;
    Node* curr = head;
    while(n!=nullptr){
        n = n->next;
        delete curr;
        curr = n;
    }
    head = nullptr;
    tail = nullptr;
    curr = nullptr;
}

const LinkedList& LinkedList:: operator=(const LinkedList& rhs){
    Node* n = head;
    Node* curr = head;
    while(n!=nullptr){
        n = n->next;
        delete curr;
        curr = n;
    }
    head=nullptr;
    
    if(rhs.head==nullptr)
        return *this;
    else{
        Node* i = rhs.head;
        Node* curr;
        while(i!=nullptr){
            Node* add = new Node;
            add->value = i->value;
            add->next = nullptr;
            add->prev = nullptr;
            
            if(head==nullptr){
                head=add;
                tail=add;
            }
        
            else{
                curr = head;
                while(curr->next!=nullptr){
                    curr=curr->next;
                }
                curr->next=add;
                curr->next->prev=curr;
                tail=add;
            }
            i=i->next;
        }
    }
    return *this;
}


int LinkedList:: size() const{
    int count{};
    for(Node* i = head; i!=nullptr; i = i->next)
        count++;
    return count;
}

int main(){
    LinkedList a;
    a.insertToFront("bill");
    a.insertToFront("tommy");
    a.insertToFront("wally");
    
    LinkedList b;
    b.insertToFront("cock");
    b.insertToFront("ill");
    b.insertToFront("hen");
 

}
