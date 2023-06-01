#include "graph.h"
#include<sstream>
#include<time.h>
#include<algorithm>
#include<QDebug>

Graph::Graph() //把图的每一个点push到临时vector里 再变成邻接表
{
    Point temp_point(0, 0, 0, " ", 0.0);
    vertex_number = 0;
    edge_number = 0;
    std::string name;
    float x;
    float y;
    std::ifstream data_input("D://11-master//Data.txt", std::ios::in);
    std::vector <Point> temp_vector_point; //临时的，从0号元素开始有效
    point_array.push_back(temp_point); //填充[0]号元素使point数据从[1]开始
    vertex_adjacency_matrix.push_back({}); //同上
    srand(time(0));
    while (data_input >> name >> x >> y)  //首先创建一维的Data.txt中的Point类型数组
    {
        vertex_number++;
        temp_point.setid(vertex_number);
        temp_point.setXAxis((x+300));
        temp_point.setYAxis((y+300));
        temp_point.setBuildingName(name);
        temp_point.setPointFlowRate((rand() % 99) + 1);
        temp_vector_point.push_back(temp_point);
        point_array.push_back(temp_point);
    }
    data_input.close();


    std::ifstream data_connected_input("D://11-master//DataConnected.txt", std::ios::in);
    for (int i = 0; i < vertex_number; i++) //在每次循环中先把上面的temp_vector中的第i个Point元素加到temp_vector_Point_in_for中，再用temp_vector_int_in_for来存储DataConnected.txt中每个点的邻接点的数据（用getline和string stream来完成）再用for遍历temp_vector_int_in_for中的如 28 31等元素减一来确定在temp_vector中的Point元素位置，并把其加到temp_vector_Point_in_for中，for之后把temp_vector_Point_in_for数组push到邻接矩阵中。
    {
        //点和边的初始化 点按照DataConnect中的数据初始化，边按照点初始化
        int for_search_connection = 0;
        std::vector <Point> temp_vector_Point_in_for;
        temp_vector_Point_in_for.push_back(temp_vector_point[i]);
        std::vector <int> temp_vector_int_in_for;
        std::string temp_line;
        getline(data_connected_input, temp_line);
        std::stringstream ss(temp_line);

        while (ss >> for_search_connection)
        {
            Edge temp_edge_in_for;
            Point temp_point_in_while(temp_vector_point[for_search_connection-1]);  //用temp_vector_point中的来初始化新的用于边距离的计算
            temp_edge_in_for.setLeftId(i + 1);
            temp_edge_in_for.setRightId(for_search_connection);
            temp_edge_in_for.setEdgeFlowRate((rand() % 99) + 1);
            flow_rate_judge.push_back(temp_edge_in_for.getEdgeFlowRate());
            temp_edge_in_for.setLength(temp_vector_point[i].calculateDistance(temp_point_in_while));
            temp_edge_in_for.setcap(temp_edge_in_for.getEdgeFlowRate() + (rand() % 99));
            edgemap.emplace(std::pair <int, int> (i+1, for_search_connection), edge_number);
            edge_number++;
            edge_array.push_back(temp_edge_in_for);
            temp_vector_int_in_for.push_back(for_search_connection);
        }

        for (int j = 0; j < temp_vector_int_in_for.size(); j++)
        {
            temp_vector_Point_in_for.push_back(temp_vector_point[temp_vector_int_in_for[j] - 1]);
        }
        vertex_adjacency_matrix.push_back(temp_vector_Point_in_for);

    }
    data_connected_input.close();

}

int Graph::getVertexNumber()
{
    return vertex_number;
}

int Graph::getEdgeNumber()
{
    return edge_number;
}

std::vector <int> Graph::showAdjacency(int num)
{
    std::vector<int> temp;
        for (int j = 1; j < vertex_adjacency_matrix[num].size(); j++)
        {
            temp.push_back(vertex_adjacency_matrix[num][j].getid());
        }
        return temp;
}

int Graph::showAdjacencyNumber(int num)
{
    return vertex_adjacency_matrix[num].size()-1;
}

bool Graph::resetEdgeFlowRate(std::string left_name, std::string right_name, double flow_rate)
{
    //规范性检查
    if(flow_rate < 0) return false;
    if(left_name == right_name)return false;
    int flag1 = 0;
    int flag2 = 0;
    for(int i=1; i < point_array.size(); i++)
    {
        if(left_name == point_array[i].getBuildingName())flag1 = 1;
        if(right_name == point_array[i].getBuildingName())flag2 = 1;
    }
    if(flag1 && flag2==0)return false;

    int left_id = 0;
    int right_id = 0;
    for(int i=1; i < point_array.size(); i++)
    {
        if(left_name == point_array[i].getBuildingName())left_id=point_array[i].getid();
        if(right_name == point_array[i].getBuildingName())right_id=point_array[i].getid();
    }

    for(int j=0; j < edge_array.size(); j++)
    {
        if(left_id == edge_array[j].getLeftId() && right_id == edge_array[j].getRightId())
        {
            edge_array[j].setEdgeFlowRate(flow_rate);
            break;
        }
    }
    return true;
}
int Graph::getEdgeByPointId(int left_id, int right_id)
{
    int flag = -1;
    for(int j = 0; j < edge_array.size(); j++)
    {
         if(left_id == edge_array[j].getLeftId() && right_id == edge_array[j].getRightId())
         {
             return j;
         }
    }
    return flag;
}
bool Graph::flowRateChange()
{
    std::vector <double> temp =  flow_rate_judge;
    //一次for循环处理一个点的变化,按照50%的比例流动，邻接点的邻接点数越多代表其越处于交通中心地带，故流量也越多，按比例分配流出
    for(int i = 1; i < point_array.size(); i++)
    {
        std::vector <int> out_point_list = showAdjacency(i); //比如29的临界点有：28 30 34 64
        double point_total_flow_rate;
        point_total_flow_rate = point_array[i].getPointFlowRate();
        for(int j = 0; j < out_point_list.size(); j++)   //获得入度的flow rate
        {
            int temp = getEdgeByPointId(out_point_list[j], point_array[i].getid());
            point_total_flow_rate += edge_array[temp].getEdgeFlowRate() / 2.0;
            edge_array[temp].setEdgeFlowRate(edge_array[temp].getEdgeFlowRate() - edge_array[temp].getEdgeFlowRate() / 2.0);    //取一半的flow rate到点上，还有一半继续在边上
        }
        point_array[i].setPointFlowRate(point_total_flow_rate);
        std::vector <int> out_point_list_adjacency_number; //比如对应的邻接点的邻接点：4 3 5 2，根据这个来分配出度的flow rate的权值
        double total_point_number = 0;
        for(int j = 0; j < out_point_list.size(); j++)  //获取总的点数如：4+3+5+2=14作为分母
        {
            out_point_list_adjacency_number.push_back(showAdjacencyNumber(out_point_list[j]));
            total_point_number += showAdjacencyNumber(out_point_list[j]);
        }
        double half_out_flow_rate = point_array[i].getPointFlowRate() / 2;  //一半的流量
        point_array[i].setPointFlowRate(point_array[i].getPointFlowRate() - half_out_flow_rate);
        for(int j = 0; j < out_point_list.size(); j++)  //流出
        {
            int temp = getEdgeByPointId(point_array[i].getid(), out_point_list[j]);
            edge_array[temp].setEdgeFlowRate(edge_array[temp].getEdgeFlowRate() + half_out_flow_rate * double(out_point_list_adjacency_number[j] / total_point_number));
        }
    }
    for(int i = 0; i < edge_array.size(); i++)
    {
        flow_rate_judge[i] = edge_array[i].getEdgeFlowRate();
    }


    if(temp == flow_rate_judge)
    {
       return false;   //说明没有继续改变了
    }
    return true;
}
std::vector <int> Graph::shortest_path(int start_id, int terminal_id)
{
    int start = start_id;
    double min = 0;

    std::vector <double> length(vertex_number +1, -1);
    std::vector <int> ans; //返回点的id数组
    std::vector <std::vector <int> > x(vertex_number + 1, ans); //当前得到最短的路径边数组
    std::vector <bool> ok(vertex_number + 1, false);

    if (start_id == terminal_id)
        return ans;
    length[start] = 0;

    ok[start_id] = true;
    while (1)
    {

        Point pt = vertex_adjacency_matrix[start][0];
        for (int i = 1; i < vertex_adjacency_matrix[start].size(); i++)
        {
            if (ok[vertex_adjacency_matrix[start][i].getid()])
                continue;
            if (length[vertex_adjacency_matrix[start][i].getid()] == -1)//新点
            {

                double len = length[vertex_adjacency_matrix[start][0].getid()] + pt.calculateDistance(vertex_adjacency_matrix[start][i]);
                x[vertex_adjacency_matrix[start][i].getid()] = x[vertex_adjacency_matrix[start][0].getid()];
                x[vertex_adjacency_matrix[start][i].getid()].push_back(vertex_adjacency_matrix[start][0].getid());
                length[vertex_adjacency_matrix[start][i].getid()] = len;


            }
            else //旧点更新
            {
                double len = length[vertex_adjacency_matrix[start][0].getid()] + pt.calculateDistance(vertex_adjacency_matrix[start][i]);
                if (len < length[vertex_adjacency_matrix[start][i].getid()])
                {
                    length[vertex_adjacency_matrix[start][i].getid()] = len;
                    x[vertex_adjacency_matrix[start][i].getid()] = x[vertex_adjacency_matrix[start][0].getid()];
                    x[vertex_adjacency_matrix[start][i].getid()].push_back(vertex_adjacency_matrix[start][0].getid());

                }
            }
        }


        int p;
        int m = -1;
        for (int num = 1; num < vertex_number+1; num++)
        {
            if ((m == -1 || length[num] < m) && !ok[num] && length[num] != -1)
            {
                m = length[num];
                p = num;
            }
        }
        start = p;
        ok[start] = true;
        if (p == terminal_id)
            break;


    }
    return x[terminal_id];
}
Graph::~Graph()
{

}

std::vector<Edge> Graph::quickest_path(int start_id, int terminal_id)
{
    int start=start_id;
    int end=terminal_id;

    std::vector<double> time(vertex_number +1, -1);
    std::vector<Edge>ans;//返回点的id数组
    std::vector<std::vector<Edge>> x(vertex_number + 1, ans);//当前得到最短的路径边数组
    std::vector<bool>ok(vertex_number + 1, false);

    if (start_id == terminal_id)
        return ans;
    time[start] = 0;

    ok[start_id] = true;
    while (1)
    {

        Point pt = vertex_adjacency_matrix[start][0];
        for (int i = 1; i < vertex_adjacency_matrix[start].size(); i++)
        {
            if (ok[vertex_adjacency_matrix[start][i].getid()])
                continue;
            Edge road=edge_array[ edgemap.find(std::pair<int,int>(vertex_adjacency_matrix[start][0].getid(),vertex_adjacency_matrix[start][i].getid()))->second];
            double real_speed=speed*road.ratio();//在这条单向路上的速度
            if (time[vertex_adjacency_matrix[start][i].getid()] == -1)//新点
            {

                double t = time[vertex_adjacency_matrix[start][0].getid()] + pt.calculateDistance(vertex_adjacency_matrix[start][i])/real_speed;
                x[vertex_adjacency_matrix[start][i].getid()] = x[vertex_adjacency_matrix[start][0].getid()];
                x[vertex_adjacency_matrix[start][i].getid()].push_back(road);
                time[vertex_adjacency_matrix[start][i].getid()] = t;


            }
            else //旧点更新
            {
                double t = time[vertex_adjacency_matrix[start][0].getid()] + pt.calculateDistance(vertex_adjacency_matrix[start][i])/real_speed;
                if (t < time[vertex_adjacency_matrix[start][i].getid()])
                {
                    time[vertex_adjacency_matrix[start][i].getid()] = t;
                    x[vertex_adjacency_matrix[start][i].getid()] = x[vertex_adjacency_matrix[start][0].getid()];
                    x[vertex_adjacency_matrix[start][i].getid()].push_back(road);

                }
            }
        }


        int p;
        int m = -1;
        for (int num = 1; num < vertex_number+1; num++)
        {
            if ((m == -1 || time[num] < m) && !ok[num] && time[num] != -1)
            {
                m = time[num];
                p = num;
            }
        }
        start = p;
        ok[start] = true;
        if (p == terminal_id)
            break;


    }
    return x[terminal_id];
}

