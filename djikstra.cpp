#include "graph.h"
#include <queue>
#include <list>
#include <map>
#include "pqueue.h"

int main()
{
    graph G{"A","B","C","D","E","F","G"};
    G.find_node("A")->add_neighbour({{"D",1},{"B",1}});
    G.find_node("B")->add_neighbour({{"F",1},{"C",1}});
    G.find_node("C")->add_neighbour({{"E",1},{"G",1}});
    G.find_node("D")->add_neighbour({{"F",1}});
    G.find_node("E")->add_neighbour({{"B",1},{"F",1}});
    G.find_node("F")->add_neighbour({{"A",1}});
    G.find_node("G")->add_neighbour({{"E",1}});

    //Frontier 
    pqueue frontier;
    //Maps the node name to the total cost of reaching the node
    std::map<std::string,int> node_cost;
    auto start = G.find_node("D");
    frontier["D"]=0;
    node_cost["D"] = 0;

    /*
        map came_from keeps track of the node it came from.
    */
   std::map<std::vector<Node>::iterator,std::vector<Node>::iterator>came_from;

    while(!frontier.empty())
    {
        //Assings and removes the element the queue
        auto current_node_name = frontier.front();
        auto curr_it = G.find_node(current_node_name);
       for(auto& next_edge: G.get_neighbours(current_node_name))
        {
            auto next_node_it = G.find_node(next_edge.first);

            int cost_to_go = node_cost[current_node_name]+next_edge.second;

            if(node_cost.find(next_edge.first)==node_cost.end() ||node_cost[next_edge.first]>=cost_to_go) 
            {
                    node_cost[next_edge.first]=cost_to_go;
                    frontier[next_edge.first] = cost_to_go;
                    came_from[next_node_it]=curr_it;
            }
            
        }
    }

    
    
    auto goal_node=G.find_node("G");
    auto current_node = goal_node;

    while(current_node!=start)
    {   
        std::cout<<"Path from bfs: "<<current_node->name<<std::endl;
        current_node = came_from[current_node];
    }
}