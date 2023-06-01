#include "controller.h"
#include "ui_controller.h"
#include<string>
controller::controller(QWidget *parent) :
QMainWindow(parent)

{
    ui.setupUi(this);
    dm = new demo;
    QString start = ui.textEdit->toPlainText(),end=ui.textEdit_2->toPlainText();

    connect(ui.clearbtn,&QPushButton::clicked,dm,&demo::clear);
    connect(ui.shortest,&QPushButton::clicked,this,&controller::shorthelp);
    connect(ui.showtrafic,&QPushButton::clicked,dm,&demo::showtraficHelp);
    connect(ui.showpoint,&QPushButton::clicked,dm,&demo::showpoint);
    connect(ui.showedge,&QPushButton::clicked,dm,&demo::showedge);
    connect(ui.flow,&QPushButton::clicked,this,&controller::flow);
    connect(ui.fastest,&QPushButton::clicked,this,&controller::fasthelp);
    connect(ui.resetFlow, &QPushButton::clicked, this, &controller::reset_flow_help);
    connect(ui.scale,&QPushButton::clicked,dm,&demo::shrink);
    connect(ui.backk,&QPushButton::clicked,dm,&demo::back);
}

controller::~controller()
{

}
void controller::paintmap()
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    // 指定要绘制的图片
    p.drawPixmap(165,-15,1270,1480,QPixmap("D://11-master//map.jpg"));
}
void controller::flow()
{

    bool flag = true;
    flag = dm->flowByDemo();
    if(flag == false)
    {
        QMessageBox::information(this, tr("提示"), tr("已经达到模拟的效果"));
    }
   // QMessageBox::information(this, tr("提示"), tr("流量已改变"));
}
void controller::shorthelp()
{
    QString start = ui.textEdit->toPlainText(),end=ui.textEdit_2->toPlainText();
    std:: pair<int,int>idpair=TextToID(start,end);
    dm->allowshort();
    if(idpair.first == -1 && idpair.second == -1)
    {
        return;
    }
    else if(idpair.first<=0||idpair.second<=0||idpair.second>68||idpair.first>68)
    {
        QMessageBox::information(this, tr("提示"), tr("点的范围在1~68"));
        return;
    }

    else
    {
        int startid=idpair.first,endid=idpair.second;
        std::string temp;
        temp = dm->drawshortesthelp(dm->shortest_path(startid,endid),endid);
        temp += (dm->getPointNameById(idpair.second));
        const char* t = temp.c_str();
        QMessageBox::information(this, tr("提示"), tr(t));
    }

}

void controller::fasthelp()
{
    QString start = ui.textEdit->toPlainText(),end=ui.textEdit_2->toPlainText();
    std:: pair<int,int>idpair=TextToID(start,end);
    dm->allowfast();
    if(idpair.first == -1 && idpair.second == -1)
    {
        return;
    }
    else if(idpair.first<=0||idpair.second<=0||idpair.second>68||idpair.first>68)
    {
        QMessageBox::information(this, tr("提示"), tr("点的范围在1~68"));
        return;
    }
    else if(idpair.first == idpair.second)
    {
        std::string temp = "The path is " + dm->getSameBuildingName(idpair.first);
        const char* t = temp.c_str();
         QMessageBox::information(this, tr("提示"), tr(t));
    }
    else
    {
        int startid=idpair.first,endid=idpair.second;
        std::string temp;
        temp = dm->drawfastestHelp(dm->quickest_path(startid,endid));
        const char* t = temp.c_str();
        QMessageBox::information(this, tr("提示"), tr(t));
    }

}

void controller::reset_flow_help()
{
    QString start = ui.textEdit->toPlainText(), end = ui.textEdit_2->toPlainText();
    std::pair<int, int> idpair = TextToID(start, end);
    QString flow = ui.textEdit_3->toPlainText();
    if(flow.toStdString() == "")
    {
         QMessageBox::information(this, tr("提示"), tr("请输入流量"));
         return;
    }
    double f = flow.toDouble();
    if(f >= 100 || f < 0)
    {
        QMessageBox::information(this, tr("提示"), tr("设置流量的范围在0~99"));
        return;
    }
    else if(idpair.first == -1 && idpair.second == -1)
    {
        return;
    }
    else if(idpair.first<=0||idpair.second<=0||idpair.second>68||idpair.first>68)
    {
        QMessageBox::information(this, tr("提示"), tr("点的范围在1~68"));
        return;
    }
    else
    {
        bool flag = true;
        flag = dm->reset_flow(idpair, f);
        if(flag == false)
        {
            QMessageBox::information(this, tr("提示"), tr("两点之间没有直接的通路"));
        }
        else
        {
            QMessageBox::information(this, tr("提示"), tr("设置成功"));
        }
    }


}
std::pair<int,int> controller::TextToID(QString s1,QString s2)
{   std::pair<int,int> ans=std::pair<int,int>(0,0);
    std::string ss1=s1.toStdString(),ss2=s2.toStdString();
    if(ss1 == "" && ss2 == "")
    {
         QMessageBox::information(this, tr("提示"), tr("请输入地名"));
         ans.first = -1;
         ans.second = -1;
    }
    else if(ss1 == "" || ss2 == "")
    {
        QMessageBox::information(this, tr("提示"), tr("请输入完整"));
        ans.first = -1;
        ans.second = -1;
    }
    else if(isasc(s1)&&isasc(s2))//id处理
    {
        int startid=stoi(ss1),endid=stoi(ss2);
        ans.first=startid;
        ans.second=endid;

    }
    //混合处理
    else if(isasc(s1) && !isasc(s2))
    {
        int startid=stoi(ss1);
        ans.first=startid;
        ans.second=dm->strToID(ss2);
    }
    else if(isasc(s2) && !isasc(s1))
    {
        ans.first = dm->strToID(ss1);
        int endid = stoi(ss2);
        ans.second=endid;
    }
    //地名处理
    else
    {
        ans.first=dm->strToID(ss1);
        ans.second=dm->strToID(ss2);
    }
    return ans;
}

bool controller::isasc(QString s)
{   std:: string ss=s.toStdString();
    for(char c:ss)
    {
        if(c<'0'||c>'9')
            return false;
    }
    return true;
}

