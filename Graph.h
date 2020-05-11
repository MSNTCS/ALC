//
// Created by Mohammadsadegh Najafi on 2020/04/21.
//

#ifndef ALC_GRAPH_H
#define ALC_GRAPH_H


#pragma once
#include <unordered_map>
#include <unordered_set>
#include "Edge.cpp"
#include "Vertex.h"
#include "Subgraphs.cpp"
#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <utility>

class Edge;
using namespace std;

namespace sgraphs{
    pair<Subgraphs*, int> subgraph;
}

class Graph
{
private:
    unordered_map<string, Vertex*> ver_map;//vertex map
    unordered_map<int, string*> corespond;

    unordered_map<int, Edge*> edge_map;
    unordered_set<string> labelset;
    int number_of_scc;
    Graph* cor_scc;

    int M;
    int N;



public:
    vector<Subgraphs*> subgraphs;

    Graph();
    int vertex_size();
    int edge_size();
    void addvertex(string);
    void addedge(string, string, string);
    //bool contain_vertex(string);
    void add_label(string);
    Vertex* find_vertex(string);
    string print();
    void BFS(string s);
    bool check_vertices_labelset(string src, string to);
    bool BFS(string s, string to);
    bool BFS_scc(string s, string to);
    void loadedgefile(string);
    unordered_map<int, Edge*>* get_edgelist();
    void maping();
    void printlabelset();
    void DFSutil(Vertex*, int i);
    Vertex* get_vertex(string s);
    Graph* getTranspose();
    void fillorder(Vertex* s, stack<Vertex*> &stack);
    void SCC();
    unordered_set<string> find_landmarks(int k);
    void generate_subgraphs(int i);
    bool BFS_for_subgraphs (string s, string to, unordered_set<string> labelset);
    list<Vertex*> landmarkIndex(int);
    list<Vertex*> sortV();
    void merge(unordered_map<string, Vertex*>, int l, int m, int r);
    int get_num_scc();
    Graph* SCC_graph();
    ~Graph();
    int get_labels_edge_size(string label);
    void set_n();
    int get_n();
};



#endif //ALC_GRAPH_H
