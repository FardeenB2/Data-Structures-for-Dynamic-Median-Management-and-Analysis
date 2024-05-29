#include "myHeap.hpp"


void insertHeap(const int& new_integer, std::priority_queue<int>& maxheapSTL, std::priority_queue<int, std::vector<int>, std::greater<int> >& minheapSTL)
{
    int moveElement;

    if (maxheapSTL.empty())
    {
        maxheapSTL.push(new_integer);       

    }

    else if (new_integer <= maxheapSTL.top())       //maxheap has all the smaller integers than the median and the median is the root. each consecutive child is smaller.
    {
        maxheapSTL.push(new_integer);
    }

    else if (new_integer > maxheapSTL.top())        //minheap has all the larger integers than the median. the root is the smallest while its children are larger.
    {
        minheapSTL.push(new_integer);
    }




    if (maxheapSTL.size() > minheapSTL.size()+1)            //balance the heaps if the maxheap is larger than the minheap by more than 1.
    {
        moveElement = maxheapSTL.top();
        minheapSTL.push(moveElement);

        maxheapSTL.pop();

    }

    else if (minheapSTL.size() > maxheapSTL.size()) //minheap contains all higher data than median, not the median itself. maxheap can store the median and all lower data. so we cannot let minheap have a single element more. 
    {
        moveElement = minheapSTL.top();
        maxheapSTL.push(moveElement);

        minheapSTL.pop();

    }


    

}

void heapMedian(const std::vector<int> * instructions)
{
    std::vector<int> medianList;

    std::priority_queue<int> maxheapSTL;
    std::priority_queue<int, std::vector<int>, std::greater<int> > minheapSTL;

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& elem : *instructions) 
    {
        if (elem != -1)
        {
            insertHeap(elem, maxheapSTL, minheapSTL);           //inserts each element to the class vector and to be sorted properly after insertion.
        }

        else
        {
            if (!maxheapSTL.empty())
            {
                    medianList.push_back(maxheapSTL.top());
                    maxheapSTL.pop();

                if (maxheapSTL.size() > minheapSTL.size()+1)
                {
                    minheapSTL.push(maxheapSTL.top());

                    maxheapSTL.pop();

                }

                else if (minheapSTL.size() > maxheapSTL.size())     //minheap contains all higher data than median, not the median itself. maxheap can store the median and all lower data. so we cannot let minheap have a single element more. 
                {
                    
                    maxheapSTL.push(minheapSTL.top());

                    minheapSTL.pop();

                }
                

                

            

            //Just like insert function, balance the trees if there is a size issue, but from popping.



            }

        }
    }


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " microseconds\n";

        for (auto& element : medianList)
        {
            std::cout << element << " ";
        }




}
