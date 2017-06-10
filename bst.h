//
//  bst.h
//  TextBook
//
//  Created by Shravan on 1/21/17.
//  Copyright © 2017 Shravan. All rights reserved.
//

#ifndef bst_h
#define bst_h

//NODE CLASS
class Node
{
public:
    Node(int dat, Node* init_left=nullptr, Node* init_right= nullptr) { data=dat; left=init_left; right=init_right;}
    Node* getLeft() const {return left; }
    Node* getRight() const { return right;}
    Node*& getLeft()  {return left; }
    Node*& getRight()  { return right;}
    void setLeft( Node* new_left)  {left=new_left; }
    void setRight(Node* new_right)  { right=new_right;}
    int getData() const {return data;}
    
    
private:
    Node* left;
    Node* right;
    int data;
    
    
    
};
//END OF NODE CLASS

class BST
{
public:
    //Default Constructor
    BST()
    {
        head_ptr=nullptr;
    }
    //Copy Constructor
    //   BST( const BST& source);
    
    //Destructor
    ~BST()
    {
        clear_all_tree(head_ptr);
    }
    
    //Tree Remove
    void clear_all_tree(Node*& root)
    {
        Node *cursor ;
        if(root!=nullptr)
        {
            cursor=root->getLeft();
            clear_all_tree(cursor);
            cursor=root->getRight();
            clear_all_tree(cursor);
            delete root;
            root=nullptr;
        }
    }
    //MODIFICATION functions
    
    void insert_bst(const int& entry)
    {
        if(head_ptr==nullptr)
        {
            head_ptr= new Node(entry);
            return;
        }
        
        Node* cursor= head_ptr;
        bool done= false;
        while(!done)
        {
            if(entry<=cursor->getData())
            {
                if(cursor->getLeft()== nullptr)
                {
                    cursor->setLeft(new Node(entry));
                    done=true;
                }
                cursor=cursor->getLeft();
                
            }
            else
            {
                if(cursor->getRight()== nullptr)
                {
                    cursor->setRight(new Node(entry));
                    done=true;
                }
                cursor=cursor->getRight();
            }
        }
    }
    
    
    
    void in_orderTraversal(Node*cursor)
    {
        if(cursor==nullptr) return;
        in_orderTraversal(cursor->getLeft());
        std::cout<<cursor->getData()<<std::endl;
        in_orderTraversal(cursor->getRight());
        
    }
    
    void in_orderTraversal()
    {
        in_orderTraversal(head_ptr);
    }
    
private:
    //Head pointer for the Binary Search Tree
    Node* head_ptr;
    
};

void maxHeapify(int *arr, int start_index, int used_total)
{
    //In Max- Heap the root should be largest compared to its children.
    //While using array the root will be the start of the index
    int largest= start_index;
    int left_child_index=2*start_index+1;
    int right_child_index=2*start_index+2;
    
    //If the left child > the root then largest will be left child.
    if(  (left_child_index<used_total) && arr[left_child_index]> arr[start_index])
        largest=left_child_index;
    if((right_child_index< used_total) && arr[right_child_index]> arr[start_index])
        largest=right_child_index;
    
    //While largest doesnt equal root keep swapping with its children.
    if(largest!=start_index)
    {
        swap(arr[start_index], arr[largest]);
        maxHeapify(arr, largest, used_total);
    }
    
    return;
    
    
}


#endif /* bst_h */
