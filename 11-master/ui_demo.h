/********************************************************************************
** Form generated from reading UI file 'demo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMO_H
#define UI_DEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_demo
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *demo)
    {
        if (demo->objectName().isEmpty())
            demo->setObjectName(QString::fromUtf8("demo"));
        demo->resize(907, 670);
        centralWidget = new QWidget(demo);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(1500, 300, 1000, 1000));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1600, 110, 971, 201));
        label->setStyleSheet(QString::fromUtf8("\n"
"font: 26pt \"\345\215\216\345\205\211\350\266\205\347\262\227\351\273\221_CNKI\";"));
        demo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(demo);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 907, 21));
        demo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(demo);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        demo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(demo);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        demo->setStatusBar(statusBar);

        retranslateUi(demo);

        QMetaObject::connectSlotsByName(demo);
    } // setupUi

    void retranslateUi(QMainWindow *demo)
    {
        demo->setWindowTitle(QCoreApplication::translate("demo", "Map", nullptr));
        label->setText(QCoreApplication::translate("demo", "\345\215\216\345\215\227\347\220\206\345\267\245\345\244\247\345\255\246(\345\244\247\345\255\246\345\237\216\346\240\241\345\214\272)\345\271\263\351\235\242\345\257\274\350\210\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class demo: public Ui_demo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMO_H
