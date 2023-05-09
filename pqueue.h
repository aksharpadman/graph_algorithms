#include <vector>
#include <map>
#include <queue>
#include <iostream>

class pqueue{
    public:
        std::string front();
        int& operator[](std::string key);
        const int& operator[](std::string key) const;
        void insert(std::string key, int value);
        bool empty();
        size_t size();

    private:
        bool _v_updated;
        std::vector<std::pair<std::string, int>> v;

        
        void reinitialize_q();

        struct {
            bool operator()(std::pair<std::string, int>&a, std::pair<std::string, int>&b)
            {  
                return a.second>=b.second;
            }
        }lesser_than;
       
};
