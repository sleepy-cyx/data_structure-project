#include "edge.h"

Edge::Edge()
{

}
Edge::Edge(int leftid, int rightid, double flow_rate, double len, double cap)
{
    left_id=leftid;
    right_id = rightid;
    flow = flow_rate;
    length = len;
    capacity = cap;
}
double Edge::ratio()
{
    return flow/capacity;
}
int Edge::getLeftId()
{
    return left_id;
}

int Edge::getRightId()
{
    return right_id;
}
double Edge::getcap()
{
    return capacity;
}
double Edge::getEdgeFlowRate()
{
    return flow;
}
double Edge::getLength()
{
    return length;
}
void Edge::setLeftId(double leftid)
{
    left_id = leftid;
}

void Edge::setRightId(double rightid)
{
    right_id = rightid;
}

void Edge::setcap(double c)
{
    capacity = c;
}
void Edge::setEdgeFlowRate(double flow_rate)
{
    flow = flow_rate;
}
void Edge::setLength(double len)
{
    length = len;
}
