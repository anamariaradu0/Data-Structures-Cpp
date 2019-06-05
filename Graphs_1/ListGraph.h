/**
 * LabSD 6
 * ListGraph.h
 * Purpose: Skeleton code for the neighbors list graph.
 *
 * @author Gabriel Bercaru
 */

#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <map>
#include <vector>
#include <queue>
#include <stdio.h>
/**
 * Node structure is useful only for the neighbors list implementation.
 */
struct Node {
    std::vector<int> neighbors;
};

/**
 * Neighbors list implementation.
 */
class ListGraph {
private:
    std::vector<Node> nodes;
    std::map<std::pair<int, int>, int> edgeCosts;
    int size;

public:
    // Constructor
    ListGraph(int size) {
        // TODO: TASK 1
        this->size = size;
        for (int i = 0; i < size; i++) {
            nodes.push_back(Node{});
        }
    }

    // Destructor
    ~ListGraph() {

    }

    /**
     * Adds an edge between two existing nodes.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     */
    void addEdge(int src, int dst) {
        // TODO: TASK 1
        addEdgeWithCost(src, dst, 1);
    }

    /**
     * Adds an edge between two existing nodes, with given cost.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     * @param cost The cost associated with the new edge.
     */
    void addEdgeWithCost(int src, int dst, int cost) {
        // TODO: TASK 1
        nodes[src].neighbors.push_back(dst);
        nodes[dst].neighbors.push_back(src);
        edgeCosts.insert({ { src, dst }, cost });
        edgeCosts.insert({ { dst, src }, cost });
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
        int noNeighborsSrc = nodes[src].neighbors.size();
        for (int i = 0; i < noNeighborsSrc; i++) {
            if (nodes[src].neighbors[i] == dst) {
                nodes[src].neighbors.erase(nodes[src].neighbors.begin() + i);
            }
        }
        int noNeighborsDst = nodes[dst].neighbors.size();
        for (int i = 0; i < noNeighborsDst; i++) {
            if (nodes[dst].neighbors[i] == src) {
                nodes[dst].neighbors.erase(nodes[dst].neighbors.begin() + i);
            }
        }
        edgeCosts.erase({ src, dst });
        edgeCosts.erase({ dst, src });
    }

    /**
     * Checks if there is an edge between two existing nodes.
     * 
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return True if there is an edge between src and dst, False otherwise.
     */
    bool hasEdge(int src, int dst) {
        // TODO: TASK 1
        int noNeighborsSrc = nodes[src].neighbors.size();
        for (int i = 0; i < noNeighborsSrc; i++) {
            if (nodes[src].neighbors[i] == dst) {
                return true;
            }
        }
        return false;
    }

    /**
     * Returns the cost of the edge described by src and dst.
     *
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return Cost of the edge between src and dst.
     */
    int edgeCost(int src, int dst) {
        // TODO: TASK 1
        return edgeCosts.find({ src, dst })->second;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) {
        // TODO: TASK 1

        return nodes[node].neighbors;
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() {
        return size;
    }

    void BFS(int src) {
        bool *viz;
        viz = new bool[size]{};
        std::queue<int> q;
        q.push(src);
        viz[src] = 1;
        while(!q.empty()) {
            int node = q.front();
            std::cout << node << " ";
            q.pop();
            int noNeighborsNode = nodes[node].neighbors.size();
            for (int i = 0; i < noNeighborsNode; i++) {
                if (viz[nodes[node].neighbors[i]] == 0) {
                    viz[nodes[node].neighbors[i]] = 1;
                    q.push(nodes[node].neighbors[i]);
                }
            }
        }

        delete []viz;
    }
};

#endif // __LISTGRAPH_H__
