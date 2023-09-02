#include <bits/stdc++.h>

using namespace std;

/**
 * Graphs is one of non linear data structure.
 * Graphs is a collection of entities that we called nodes or vertices 
 * connected to each other through set of edges.
 * A graph contain set of nodes and edges can be connected to nodes in certain way.
 * ----------------------------------------------------------------------------------------
 * A graph G is an ordered pair of a set V of vertices and a set E of edges (G = (V, E)).
 * ----------------------------------------------------------------------------------------
 * Edges can be represented 2 types, directed, in which connection is 1 way and undirected, in which connection is 2 way
 * Some graphs can also have weight which means all connections cannot be treated equally,
 * some connections is preferable than others. 
 * Example : city a to city b is shorter than city c to city b
 * Unweighted graph is a weighted graph with all edges (connection) having weight = 1 unit (same)
 * -----------------------------------------------------------------------------------------
 * Properties of graphs : 
 * |v| => number of vertices
 * |e| => number of edges
 * -----------------------------------------------------------------------------------------
 * An edge is called multiedge if it occurs more than once
 * An edge is called selfloop if it redirect to its node
 * A graph is called simple graph if there are no self loops or multiedges
 * -----------------------------------------------------------------------------------------
 * Maximum number of edges in a graph can be calculated with : max = n * (n-1) 
 * wheres n is number of nodes in a graph if graph is directed.
 * If its undirected : max = (n * (n-1) )/ 2 (assuming no self loop or multiedge)
 * -----------------------------------------------------------------------------------------
 * Path in a graph is sequence of vertices where each adjacent pair is connected by an edge
 * A path is called simple path if no vertices are repeated
 * A graph is called strongly connected if there is path from any vertex to any other vertex
*/

/**
 * We can represent graph using 2D array. In each Aij will be filled 1 if there is connection from i to j
 * otherwise we fill it with 0
 * We can also represent graph using dynamic list. In each node, we will add adjacent if there is connection
*/

/**
 * In these class graph application, we will assume the graph is undirected and has no weight
*/
class GraphMatrix {
    /**
     * Adjacency matrix graph is very easy to implement, 
     * However, that ease of implement comes at a cost of too many memory consumption O(V^2)
     * Where V is how many node we need
    */
    vector<vector<int>> matrix;

    GraphMatrix(int v) { // v merupakan banyaknya node
        matrix = vector<vector<int>>(v,vector<int>(v,0));
    }

    void addEdge(int node1, int node2) {
        matrix[node1][node2] = matrix[node2][node2] = 1;
    }

    void deleteEdge(int node1, int node2) {
        matrix[node1][node2] = matrix[node2][node2] = 0;
    }
};

class GraphList {
    /**
     * Adjacency list only takes O(E) memory consumption, where E is how many edges are there in a graph
    */
    vector<vector<int>> list;

    GraphList() {
        list = vector<vector<int>>(n);
    }

    void addEdge(int node1, int node2) {
        list[node1].push_back(node2);
        list[node2].push_back(node1);
    }   

    void deleteEdge(int node1, int node2) {
        
    }
};


int main() {
    return 0;
}