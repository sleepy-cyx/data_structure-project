#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QMainWindow>
#include<demo.h>
#include<ui_controller.h>
#include<imagewidget.h>

namespace Ui {
class controller;
}

class controller : public QMainWindow
{
Q_OBJECT

public:
explicit controller(QWidget *parent = nullptr);
~controller();
demo *dm;
std::pair<int,int>TextToID(QString s1,QString s2);
bool isasc(QString s);
void shorthelp();
void paintmap();
void flow();
void fasthelp();
void reset_flow_help();


private:
Ui::controller ui;
};

#endif // CONTROLLER_H
