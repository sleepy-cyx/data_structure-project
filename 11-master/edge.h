#ifndef EDGE_H
#define EDGE_H


#include<iostream>

class Edge
{
protected:
    //边的流量 左右点的id

public:
    //点的初始化，获取，修改
    Edge();
    int left_id;
    int right_id;
    double flow;//<100
    double capacity;//<flow+99
    double length;
    Edge(int leftid, int rightid, double flow_rate, double len, double cap);
    int getLeftId();
    int getRightId();
    double getEdgeFlowRate();
    double ratio();
    double getcap();
    double getLength();
    void setLeftId(double left_id);
    void setcap(double c);
    void setRightId(double right_id);    
    void setEdgeFlowRate(double flow_rate);
    void setLength(double len);
};

#endif // EDGE_H
