#include <vector>
#include <map>
#include <queue>
#include <iostream>


struct {
    bool operator()(std::pair<std::string, int>&a, std::pair<std::string, int>&b)
    {  
        return a.second<=b.second;
    }
}lesser_than;


class pqueue{
    public:
        std::string top();
        int& operator[](std::string key);

    private:
        bool _v_updated;
        std::vector<std::pair<std::string, int>> v;
        // std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,lesser_than> q;

        void reinitialize_q();
       
};
