//
// Created by Mohammadsadegh Najafi on 2020/04/22.
//

#ifndef ALC_SUBGRAPHS_H
#define ALC_SUBGRAPHS_H

#include "vector"
#include <bitset>
#include<iostream>

using namespace std;

struct Subgraphvertrx {
    int ID;
    bool visisted;
};

struct SubgraphEdge {
    Subgraphvertrx src, dest;
};

class Subgraphs {
private:
    vector<SubgraphEdge> subedges;
    int size;
    bitset<5000> bitvector;
public:
    vector<vector<int>> adjlist;
    vector<Subgraphvertrx> vertices;
    Subgraphs(int);
    void addvertex(int);
    void addedge(int, int);
    int vertex_size();
    int edge_size();
    void print_bitvector();
    bool BFS(int src, int target);
    bool has_vertex(int vertex);
    bool get_vertex_status(int vertex);
    Subgraphvertrx change_vertex_status(int);
};


#endif //ALC_SUBGRAPHS_H
