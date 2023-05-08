#include "pqueue.h"
#include <algorithm>
int a;
int& pqueue::operator[](std::string key){
    // auto it = std::find(v.begin(), v.end(), [key](std::pair<std::string, int>& elem){return elem.first == key;}); 
    std::cout<<key<<std::endl;
    // if(it != v.end())
    //     return it->second;
    // else    
    // {
    //     std::pair<std::string, int>p;
    //     v.push_back(p);
    //     auto it = v.end()-1;
    //     return it->second;
    // }
    a = 0;
    return a;
}

std::string pqueue::top(){
    reinitialize_q();
    auto key = v.back().first;
    v.pop_back();
    return key;
}

void pqueue::reinitialize_q()
{
    if(_v_updated)
    {
        std::sort(v.begin(),v.end(),lesser_than);
        _v_updated=false;
    }
    
}


