#include "myList.hpp"


void insertList(const int& new_integer, std::list<int> &listSTL) {     

    if (listSTL.empty())
    {
        listSTL.insert(listSTL.begin(), new_integer);           //if list is empty originally, then just add new integer to beginning
        return;

    }



        for (auto it = listSTL.begin(); it != listSTL.end(); ++it) 
        {

            if (new_integer <= *it)
            {
                listSTL.insert(it, new_integer);     //insert the new_integer before the current element if the value is less than or equal to current element

                return;
            }         

        }

                listSTL.insert(listSTL.end(), new_integer);     //insert new integer after the end element if it is greater than all.
                return;
}




void listMedian(const std::vector<int> * instructions)      
{
    std::vector<int> medianList;
    std::list<int> listSTL;

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& elem : *instructions) 
    {
        if (elem != -1)
        {
            insertList(elem, listSTL);
        }

        else
        {
            if (!listSTL.empty())
            {         

                if (listSTL.size() % 2 > 0)     //list size is odd
                {
                    auto it = std::next(listSTL.begin(), listSTL.size() / 2);

                    medianList.push_back(*it);  

                    listSTL.erase(it);


                }


                else if (listSTL.size() % 2 == 0)       //list size is even
                {

                    auto it = std::next(listSTL.begin(), listSTL.size() / 2 - 1);

                    medianList.push_back(*it);  

                    listSTL.erase(it);

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

