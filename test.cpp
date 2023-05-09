#include <iostream>
#include <map>
#include <list>
#include<queue>
#include "pqueue.h"

using namespace std;


int main()
{   

    pqueue frontier;
    frontier.insert("A",4);
    frontier.insert("B",5);
    frontier["B"]=2;
    frontier["A"]=1;
    frontier["K"] = 4;
    std::cout<<frontier.size()<<std::endl;
    std::string curr_node  = frontier.front();
    std::cout<<curr_node<<std::endl;

}