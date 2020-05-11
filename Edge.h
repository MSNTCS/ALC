//
// Created by Mohammadsadegh Najafi on 2020/04/21.
//

#ifndef ALC_EDGE_H
#define ALC_EDGE_H


#pragma once
#include <iostream>
#include <iostream>

#include <string>
using namespace std;
class Vertex;
class Edge
{
private:
    string label;
    Vertex* destination;
    Vertex* source;
    int id;
public:
    Edge();
    Edge(Vertex* dest, Vertex* src, string label, int);
    Edge(Vertex* dest);
    Edge(Vertex* dest, Vertex* src);
    string getlabel();
    Vertex* getDestVertex();
    Vertex* getSorceVertex();
    void setlabel(string label);


    ~Edge();
};





#endif //ALC_EDGE_H
