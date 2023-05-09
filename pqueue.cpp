#include "pqueue.h"
#include <algorithm>

int& pqueue::operator[](std::string key){
    auto it = std::find_if(v.begin(), v.end(), [key](std::pair<std::string, int>& elem){return elem.first == key;}); 
    if(it == v.end())   
    {
        std::pair<std::string, int>p;
        p.first = key;
        v.push_back(p);
        it = v.end()-1;
        
    }
    return it->second;
}

const int& pqueue::operator[](std::string key) const{
    auto it = std::find_if(v.begin(), v.end(), [key](const std::pair<std::string, int>& elem){return elem.first == key;}); 
    return it->second;
}

std::string pqueue::front(){
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

void pqueue::insert(std::string key, int value){
    std::pair<std::string, int>p;
    p.first = key;
    p.second = value;
    v.push_back(p);
    _v_updated = true;

}

bool pqueue::empty(){
    return v.empty();
}

size_t pqueue::size(){
    return v.size();
}
