#include "myVector.hpp"

void insertVector(const int& new_integer, std::vector<int> &vectorSTL)
{
    //we don't want to just push back here and then use std::sort because constant use of that per integer is inefficient

    if (vectorSTL.empty())
    {
        vectorSTL.insert(vectorSTL.begin(), new_integer);
        return;

    }



    auto it = std::lower_bound(vectorSTL.begin(), vectorSTL.end(), new_integer);   //(find the first integer already in vector that is greater than or equal to new_integer) 
    if (it != vectorSTL.end()) //if it is found
    {
        vectorSTL.insert(it, new_integer);

    }
    else    //the new_integer is greater than all current integers
    {
        vectorSTL.push_back(new_integer);      //push new_integer to the end of vector.
    }


}

void vectorMedian(const std::vector<int> * instructions)
{
    std::vector<int> medianList;
    std::vector<int> vectorSTL;



    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& elem : *instructions) 
    {
        if (elem != -1)
        {
            insertVector(elem, vectorSTL);           //inserts each element to the class vector and to be sorted properly after insertion.
        }

        else
        {

            if (!vectorSTL.empty())
            {
                if (vectorSTL.size() % 2 > 0)     //vector size is odd
                {
                    auto it = std::next(vectorSTL.begin(), vectorSTL.size() / 2);

                    medianList.push_back(*it);  

                    vectorSTL.erase(it);

                }


                else if (vectorSTL.size() % 2 == 0)       //vector size is even
                {
                    auto it = std::next(vectorSTL.begin(), vectorSTL.size() / 2 - 1);

                    medianList.push_back(*it);  

                   vectorSTL.erase(it);

                }
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
