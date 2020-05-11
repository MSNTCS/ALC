//
// Created by Mohammadsadegh Najafi on 2020/04/22.
//

#ifndef ALC_SUBGRAPHS_H
#define ALC_SUBGRAPHS_H

#include "vector"
#include <bitset>
#include<iostream>
#include "list"

using namespace std;

struct Subgraphvertrx {
    int ID;
    bool visisted;
    bitset<5000> tc;
    bool landmark;
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
    list<int> landmarks;
    Subgraphs(int);
    void addvertex(int);
    void addedge(int, int);
    int vertex_size();
    int edge_size();
    void print_bitvector();
    bool BFS(int src, int target);
    int degree(int vertex);
    list<int> find_landmarks(int);
    bool has_vertex(int vertex);
    bool get_vertex_status(int vertex);
    Subgraphvertrx change_vertex_status(int);
    int * klargest (int*, int, int);
    void DFSUtil(int s, int v);
    void transitive_closure(int);
    bool BFS_for_landmarks(int src, int target);
};


#endif //ALC_SUBGRAPHS_H
