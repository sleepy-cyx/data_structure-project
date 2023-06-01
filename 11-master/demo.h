#ifndef DEMO_H
#define DEMO_H

#include <QMainWindow>
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include<imagewidget.h>
#include<qpainter.h>
#include<qpushbutton.h>
#include<QLabel>
#include<qcombobox.h>
#include"graph.h"

namespace Ui {
class demo;
}

class demo : public QMainWindow,  public Graph,public Edge
{
Q_OBJECT

public:
    ImageWidget     *m_Image;
    void            recvShowPicSignal(QImage image);//接收并显示图片的函数
    std::vector<int>shortest_array;
    std::vector<Edge>fastest_array;
    int ENDID;
    int flag=0;
    bool allowpoint=true;
    bool allowedge=true;
    bool allowfastest=true;
    bool allowshortest=true;
    bool allowtraffic = false;
explicit demo(QWidget *parent = nullptr);
~demo();
void draw();
std::string drawshortesthelp(std::vector<int>in,int y);
void drawfastest();//最快
std::string drawfastestHelp(std::vector<Edge>in);
void showtrafic();
void allowshort();
void allowtrafic();
void showtraficHelp();
void scale();
void scaleHelp();
void drawshortest();
void showpoint();
bool flowByDemo();
void allowfast();
void build();
void showedge();
void shrink();
void back();
bool reset_flow(std::pair<int, int> idpair, double flow);
std::string getPointNameById(int id);
std::string getSameBuildingName(int id);
void PE(QPaintEvent* eve,int x,int y);
void paintEvent(QPaintEvent*);
int strToID(std::string s);
void clear();
private slots:

private:
Ui::demo *ui;
};

#endif // DEMO_H
