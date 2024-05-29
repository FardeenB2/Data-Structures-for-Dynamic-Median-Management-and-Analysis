#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <chrono>


#include "myList.hpp" 
#include "myVector.hpp"
#include "myHeap.hpp"


int main() {

    
   std::vector<int> numbersContainer;

   std::ifstream file("testinput.txt");

   if (!file.is_open())
   {
    std::cerr << "error in opening file";
    return 1;
   }

   std::string fileLine;    //for each line of the file
   while (std::getline(file, fileLine))
   {
        std::istringstream reader(fileLine);     //reader essentially takes in the current line to read and parse through.


        std::string command;
        reader >> command;      //read the command (insert or pop median);

        int number;




        if (command == "insert")
        {

            if (!(reader >> number)) 
            {
                std::cerr << "ERROR: Cannot read integer from line";
                return 1;
            }
            numbersContainer.push_back(number);     //vector

          // std::cout << number << std::endl;
        }

        else if (command == "pop")
        {
            numbersContainer.push_back(-1);
        }



   }

    file.close();





//--------------------------------------- VECTOR MAIN

   vectorMedian(&numbersContainer);
    

//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------



//--------------------------------------- LIST MAIN


  // listMedian(&numbersContainer);
    



//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------
//---------------------------------------



//--------------------------------------- HEAP MAIN


 // heapMedian(&numbersContainer);
    



return 0;

}
