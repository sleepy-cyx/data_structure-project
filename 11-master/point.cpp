#include "point.h"



Point::Point()
{
}

Point::Point(int x, int y, int Id, std::string str, double rate)
{
    x_axis = x;
    y_axis = y;
    id = Id;
    building_name = str;
    point_flow_rate = rate;
}

Point::Point(const Point &oldone)
{

    x_axis = oldone.x_axis;
    y_axis = oldone.y_axis;
    id = oldone.id;
    building_name = oldone.building_name;
    point_flow_rate = oldone.point_flow_rate;
}

float Point::getXAxis()
{
    return x_axis;
}

float Point::getYaxis()
{
    return y_axis;
}

std::string Point::getBuildingName()
{
    return building_name;
}

double Point::getPointFlowRate()
{
    return point_flow_rate;
}

void Point::setXAxis(float x)
{
    x_axis = x;
}

void Point::setYAxis(float y)
{
    y_axis = y;
}

void Point::setBuildingName(std::string str)
{
    building_name = str;
}

void Point::setPointFlowRate(double flow_rate)
{
    point_flow_rate = flow_rate;
}

int Point::getid()
{
    return id;
}
void Point::setid(int x)
{
    id = x;
}
float Point::calculateDistance(Point other)
{
    float temp_x = pow(this->x_axis - other.x_axis,2);
    float temp_y = pow(this->y_axis - other.y_axis,2);
    float result = pow(temp_x+temp_y,0.5);
    return result;
}

