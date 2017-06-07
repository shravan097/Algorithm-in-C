//
//  heap.h
//  TextBook
//
//  Created by Shravan on 2/19/17.
//  Copyright © 2017 Shravan. All rights reserved.
//

#ifndef heap_h
#define heap_h


template<typename T>
class Heap
{
public:
    Heap() { heap_used=0; }
    
    static const size_t CAPACITY= 10;
    
    
    
    //Getter
     int getData(const int &index) const { return data[index];}
    std::size_t total_size() const { return heap_used;}
    
    
    
    
    //Insert Function
    //Precondtion: Inputs a entry
    //Postcondition: Puts the entry at next available free spot and then
    //maintains heap property by calling heapify().
    void insert(const int &entry)
    {
        data[heap_used]=entry;
        heap_used++;
        build_heap();
    }
    
    
    //Find Max
    //Postcondition: Returns the data[0]
    inline int find_max(){ return data[0];}
    
    //Delete Function
    //Postcondtion: Swaps value of data[0] with the last used location the heapify().
    void delete_max()
    {
        if(heap_used==0) std::cerr<<"Empty Heap!"<<std::endl;
        else{
            heap_used--;
            std::swap(data[0],data[heap_used]);
            build_heap();
        }
        
    }
    
    friend std::ostream& operator <<(std::ostream& outs, const Heap<T>& source);

    
private:
    T data[CAPACITY];
    size_t heap_used;
    
    
    //Max-Heapify Fucntions
    //Precondtion: Takes in an Array
    //Postcondtions: Maintians the property PARENT >= CHILD. Top-Down Process
    // Runtime O(lg n)
    
    
    void max_heapify(const int& root=0)
    {
        int largest=root;
        int left_child= 2*root+1;
        int right_child= 2*root+2;
        
        if( (left_child < heap_used) && (data[root]<data[left_child]))
            largest=left_child;
        if((right_child < heap_used) && (data[root]<data[right_child]))
            largest=right_child;
        
        if (largest!=root)
        {
            std::swap(data[root],data[largest]);
            max_heapify(largest);
        }
        
    }
    
    //Postcondition: Builts heap using bottom up procedure.
    //Runtime is shortned by O(n) by using bottom up procedure.
    void build_heap()
    {
        for(size_t i=(heap_used/2); i>0; --i)
            max_heapify();
        
    }
    
};




template<typename T>
std::ostream& operator <<(std::ostream& outs, Heap<T>& source)
{
    for(auto i=0; i<source.total_size(); ++i)
        outs<<source.getData(i)<<std::endl;
    return outs;
}



#endif /* heap_h */
