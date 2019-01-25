#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
public:
  struct Node {
    T value;
    Node* next = nullptr;
  };

  ~LinkedList(){
    for (auto node = GetHead(); node; node = node->next) {
      delete node;
    }
  }

  void PushFront(const T& value){
    Node* newNode = new Node{value, head};
    head = newNode;
  }
  void InsertAfter(Node* node, const T& value){
    if(node){
      Node* nextNode = node->next;
      Node* newNode = new Node{value, nextNode};
      node->next = newNode;
    } else {
      PushFront(value);
    }
  }
  void RemoveAfter(Node* node){
    if(!node){
      PopFront();
    }
    if(node->next){
      Node* removing_node = node->next;
      node->next = node->next->next;
      delete removing_node;
    }
  }

  void PopFront(){
    if(head == nullptr)
      return;
    Node* head_temp = head->next;
    delete head;
    head = head_temp;
  }

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }

private:
  Node* head = nullptr;
};


#endif // LINKEDLIST_H
