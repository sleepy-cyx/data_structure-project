#ifndef POINT_H
#define POINT_H

#include<iostream>
#include<cmath>
class Point
{
protected:
    //x,y坐标 建筑名
    int x_axis;
    int y_axis;
    int id;
    std::string building_name;
    double point_flow_rate; //用于flowrate change
public:
    //点的初始化，获取，修改
    Point();
    Point(int x, int y, int Id, std::string str, double rate);
    Point(const Point & oldone);
    float getXAxis();
    float getYaxis();
    int getid();
    std::string getBuildingName();
    double getPointFlowRate();
    void setXAxis(float x);
    void setYAxis(float y);
    void setid(int x);  
    void setBuildingName(std::string str);
    void setPointFlowRate(double flow_rate);
    float calculateDistance(Point otherone);
};

#endif // POINT_H
