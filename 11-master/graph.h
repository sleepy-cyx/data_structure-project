#ifndef GRAPH_H
#define GRAPH_H


#include"point.h"
#include"edge.h"
#include<vector>
#include<fstream>
#include<queue>
#include<map>
const int INF = 0x3f3f3f3f;
const int speed = 30;//速度
class Graph
{
protected:
    //顶点 边 的数量
    int vertex_number;
    int edge_number;
    std::vector <Point> point_array; //有效数据从下标1开始
    std::vector <std::vector <Point> > vertex_adjacency_matrix; //有效数据从下标1开始
    std::vector <Edge> edge_array; //0开始有效数据
    std::map <std::pair <int, int>, int> edgemap;
    std::vector <double> flow_rate_judge;
public:
    //图的初始化（用指定的数据文件） 点和边的获取
    Graph();
    int getVertexNumber();
    int getEdgeNumber();
    std::vector <int> shortest_path(int start_id, int terminal_id); //返回数组为点的id数组，不包含目标地点的id
    std::vector <int> showAdjacency(int num);
    std::vector <Edge> quickest_path(int start_id, int terminal_id);
    bool flowRateChange();
    bool resetEdgeFlowRate(std::string left_name, std::string right_name, double flow_rate); //带有输入name完整性检查
    int getEdgeByPointId(int left_id, int right_id); //通过点的id来找边
    int showAdjacencyNumber(int num);
    ~Graph();
};



#endif // GRAPH_H
