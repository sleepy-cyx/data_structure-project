#include "demo.h"
#include "ui_demo.h"
#include"imagewidget.h"
#include<algorithm>
#include<string>
#include<QLabel>
#include<map>
demo::demo(QWidget *parent) :
QMainWindow(parent),ui(new Ui::demo)
{
ui->setupUi(this);
build();
}

void demo::build()
{
    QGraphicsScene *scene = new QGraphicsScene;
    //向容器中添加文件路径为fileName的文件
    scene->addPixmap(QPixmap("D://11-master//map.jpg"));
    //借助graphicsView控件显示容器的内容
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //开始显示
    ui->graphicsView->show();

}
void demo::recvShowPicSignal(QImage image)
{
    QPixmap ConvertPixmap=QPixmap::fromImage(image);
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;//要用QGraphicsView就必须要有QGraphicsScene搭配着用
    m_Image = new ImageWidget(&ConvertPixmap);//实例化类ImageWidget的对象m_Image
    int nwith = ui->graphicsView->width();//获取界面控件Graphics View的宽度
    int nheight = ui->graphicsView->height();//获取界面控件Graphics View的高度
    m_Image->setQGraphicsViewWH(nwith,nheight);//将界面控件Graphics View的width和height传进类m_Image中
    qgraphicsScene->addItem(m_Image);//将QGraphicsItem类对象放进QGraphicsScene中
    ui->graphicsView->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->graphicsView->setScene(qgraphicsScene);
    ui->graphicsView->setFocus();//将界面的焦点设置到当前Graphics View控件
}
void demo::paintEvent(QPaintEvent *event)

{   switch (flag) {

    case 0:
        draw();
        break;
    case 1:
        draw();
        drawshortest();
        update();
        break;
    case 2:

        draw();
        drawfastest();
        update();
        break;
    case 3:
        showtrafic();
        update();
        break;

    default:
        break;

}
}
void demo::showedge()
{

    allowedge=true;
    update();
}
void demo::showpoint()
{

    allowpoint=true;
    update();
}
bool demo::flowByDemo()
{
    bool x;
    x = flowRateChange();
    update();
    return x;
}
void demo::draw()
{

    QPainter p(this);
    QPen pen;
    pen.setWidth(10);
    pen.setColor(Qt::red);

    p.setRenderHint(QPainter::Antialiasing, true);
    // 指定要绘制的图片
   p.drawPixmap(165,-15,1270,1480,QPixmap("D://11-master//map.jpg"));
    QTransform transform; //定义画家的转换


    p.setPen(pen);
    if(allowpoint)
        for(int i=1;i<point_array.size();i++)
        {
            p.drawPoint(point_array[i].getXAxis(),point_array[i].getYaxis());//先把负数搞正



        }
    pen.setColor(Qt::blue);
    pen.setWidth(4);
    p.setPen(pen);
    if(allowedge)
        for(int i=0;i<edge_array.size();i++)
        {
            Point p1=point_array[edge_array[i].left_id],p2=point_array[edge_array[i].right_id];
            p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
        }
        // 启用抗锯齿(反走样)

}
void demo::allowshort()
{
    allowshortest=true;
}
void demo::drawshortest()
{   if(!allowshortest)
        return;
    QPainter p(this);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::black);
    p.setPen(pen);

    for(int i=0;i<shortest_array.size()-1;i++)
    {
        int id=shortest_array[i],nextid=shortest_array[i+1];//id为pointarray中点的对应下标
        Point p1=point_array[id],p2=point_array[nextid];
        p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());

    }
    p.drawLine(point_array[shortest_array[shortest_array.size()-1]].getXAxis(),point_array[shortest_array[shortest_array.size()-1]].getYaxis(),point_array[ENDID].getXAxis(),point_array[ENDID].getYaxis());


}
std::string demo::drawshortesthelp(std::vector<int> in,int y)
{
    shortest_array=in;
    ENDID=y;
     flag=1;
     update();
     std::string temp = "The path is ";
     for(int i = 0 ; i < in.size(); i++)
     {

         temp += point_array[in[i]].getBuildingName();
         temp += " ";
     }
     return temp;
}
void demo::allowfast()
{
     allowfastest = true;
}
void demo::drawfastest()
{
    if(!allowfastest)
        return;
    QPainter p(this);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    p.setPen(pen);
    for(Edge x:fastest_array)
    {
        Point p1=point_array[x.getLeftId()],p2=point_array[x.getRightId()];
         p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
    }

}
std::string demo::drawfastestHelp(std::vector<Edge> in)
{
    fastest_array=in;
    flag=2;
    update();
    std::string temp = "The path is ";
    for(int i = 0 ; i < in.size(); i++)
    {

        temp += point_array[in[i].getLeftId()].getBuildingName();
        temp += " ";
    }
    temp += point_array[in[in.size() - 1].getLeftId()].getBuildingName();
    return temp;
}
void demo::showtrafic()
{
    if(!allowtraffic)
            return;
        QPainter p1(this);
        p1.setRenderHint(QPainter::Antialiasing, true);
        // 指定要绘制的图片（将图片路径替换为有效的图片路径）
        p1.drawPixmap(165,-15,1270,1480,QPixmap("D://11-master//map.jpg"));
        flag=3;
    std::map<std::pair<int,int>,double> m;
    for(Edge road :edge_array)
    {
        int l=road.getLeftId(),r=road.getRightId();
        if(m.find(std::pair<int,int>(l,r))==m.end())
        {
            m.emplace(std::pair<int,int>(r,l),road.getEdgeFlowRate()/road.getcap());

        }
        else {

            double rate=(m.find(std::pair<int,int>(l,r))->second+road.getEdgeFlowRate()/road.getcap())/2;
            if(rate<=0.2)
            {

                QPainter p(this);
                QPen pen;
                pen.setWidth(6);
                pen.setColor(Qt::green);

                p.setPen(pen);
                Point p1=point_array[l],p2=point_array[r];
                 p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
            }
            else if(rate < 0.4)
            {
                QPainter p(this);
                QPen pen;
                pen.setWidth(6);
                QColor c(192, 255, 62);
                pen.setColor(c);

                p.setPen(pen);
                Point p1=point_array[l],p2=point_array[r];
                p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
            }
            else if(rate < 0.6)
            {
                QPainter p(this);
                QPen pen;
                pen.setWidth(6);
                pen.setColor(Qt::yellow);

                p.setPen(pen);
                Point p1=point_array[l],p2=point_array[r];
                p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
            }
            else if(rate < 0.8)
            {
                QPainter p(this);
                QPen pen;
                pen.setWidth(6);
                QColor c(255, 165, 0);
                pen.setColor(c);

                p.setPen(pen);
                Point p1=point_array[l],p2=point_array[r];
                p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());
            }
            else {

                QPainter p(this);
                QPen pen;
                pen.setWidth(6);
                pen.setColor(Qt::red);

                p.setPen(pen);
                Point p1=point_array[l],p2=point_array[r];
                p.drawLine(p1.getXAxis(),p1.getYaxis(),p2.getXAxis(),p2.getYaxis());

               }
           }
    }
}
void demo::allowtrafic()
{
    allowtraffic=true;
}
void demo::showtraficHelp()
{
    allowtrafic();
    flag = 3;
    update();
}
bool demo::reset_flow(std:: pair<int,int> idpair, double flow)
{
    int pos = getEdgeByPointId(idpair.first, idpair.second);
    if(pos == -1)
    {
         return false;
    }
    edge_array[pos].setEdgeFlowRate(flow);
    return true;
}
std::string demo::getPointNameById(int id)
{
    return point_array[id].getBuildingName();
}
std::string demo::getSameBuildingName(int id)
{
    for(int i = 0;i < point_array.size(); i++)
    {
        if(point_array[i].getid() == id)
        {
            return point_array[i].getBuildingName();
        }
    }
}
void demo::clear()
{    allowedge=false;
     allowpoint=false;
     allowfastest=false;
     allowshortest=false;
     allowtraffic = false;
     flag = 0;
     update();
}
int demo::strToID(std::string s)
{   int ans=-1;
    for(int i=1;i<point_array.size();i++)
    {
        if(point_array[i].getBuildingName()==s)
            return i;
    }
    return ans;
}
demo::~demo()
{
delete ui;
}

void demo::shrink()
{
    QImage* img=new QImage;
        img->load("D://11-master//map.jpg");
       recvShowPicSignal(*img);
}
void demo::back()
{
    QGraphicsScene *scene = new QGraphicsScene;

        int nwith = ui->graphicsView->width();//获取界面控件Graphics View的宽度
        int nheight = ui->graphicsView->height();//获取界面控件Graphics View的高度
        scene->addPixmap(QPixmap("D://11-master//map.jpg"));
        ui->graphicsView->setSceneRect(QRectF(-135,-125,nwith,nheight));//使视窗的大小固定在原始大小，不会随图片的放大而放大,防止图片放大后重新缩小的时候视窗太大而不方便观察图片
        //借助graphicsView控件显示容器的内容
        ui->graphicsView->setScene(scene);
        //开始显示
        ui->graphicsView->show();

}

