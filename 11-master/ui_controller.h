/********************************************************************************
** Form generated from reading UI file 'controller.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_H
#define UI_CONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_controller
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QPushButton *showpoint;
    QSpacerItem *verticalSpacer;
    QPushButton *showedge;
    QSpacerItem *verticalSpacer_2;
    QPushButton *clearbtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *showtrafic;
    QSpacerItem *verticalSpacer_4;
    QPushButton *flow;
    QSpacerItem *verticalSpacer_5;
    QTextEdit *textEdit_3;
    QLabel *start;
    QLabel *label_5;
    QLabel *flownumber;
    QLabel *label;
    QPushButton *scale;
    QPushButton *resetFlow;
    QPushButton *fastest;
    QPushButton *shortest;
    QPushButton *backk;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *controller)
    {
        if (controller->objectName().isEmpty())
            controller->setObjectName(QString::fromUtf8("controller"));
        controller->resize(638, 697);
        controller->setStyleSheet(QString::fromUtf8("#controller{background-image:url(:/background.jpg);}"));
        centralwidget = new QWidget(controller);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(290, 450, 131, 51));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(480, 450, 131, 51));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(20, 20, 231, 351));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"func\";\n"
"font: 10pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
""));

        verticalLayout_3->addWidget(label_3);

        showpoint = new QPushButton(verticalLayoutWidget_3);
        showpoint->setObjectName(QString::fromUtf8("showpoint"));

        verticalLayout_3->addWidget(showpoint);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        showedge = new QPushButton(verticalLayoutWidget_3);
        showedge->setObjectName(QString::fromUtf8("showedge"));

        verticalLayout_3->addWidget(showedge);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        clearbtn = new QPushButton(verticalLayoutWidget_3);
        clearbtn->setObjectName(QString::fromUtf8("clearbtn"));

        verticalLayout_3->addWidget(clearbtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        showtrafic = new QPushButton(verticalLayoutWidget_3);
        showtrafic->setObjectName(QString::fromUtf8("showtrafic"));

        verticalLayout_3->addWidget(showtrafic);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);

        flow = new QPushButton(verticalLayoutWidget_3);
        flow->setObjectName(QString::fromUtf8("flow"));

        verticalLayout_3->addWidget(flow);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(410, 510, 104, 70));
        start = new QLabel(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setGeometry(QRect(230, 400, 121, 41));
        start->setStyleSheet(QString::fromUtf8("font:10pt \"AcadEref\";color:rgb(255, 0, 0)"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(420, 400, 151, 41));
        label_5->setStyleSheet(QString::fromUtf8("font: 10pt \"AcadEref\";color:rgb(255, 0, 0)"));
        flownumber = new QLabel(centralwidget);
        flownumber->setObjectName(QString::fromUtf8("flownumber"));
        flownumber->setGeometry(QRect(300, 520, 91, 41));
        flownumber->setStyleSheet(QString::fromUtf8("font:12pt \"AcadEref\";color:rgb(255, 0, 0)"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(300, 30, 141, 41));
        label->setStyleSheet(QString::fromUtf8("font: 10pt \"func\";\n"
"font: 10pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
""));
        scale = new QPushButton(centralwidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(460, 110, 111, 41));
        resetFlow = new QPushButton(centralwidget);
        resetFlow->setObjectName(QString::fromUtf8("resetFlow"));
        resetFlow->setGeometry(QRect(290, 90, 131, 41));
        fastest = new QPushButton(centralwidget);
        fastest->setObjectName(QString::fromUtf8("fastest"));
        fastest->setGeometry(QRect(300, 250, 111, 41));
        shortest = new QPushButton(centralwidget);
        shortest->setObjectName(QString::fromUtf8("shortest"));
        shortest->setGeometry(QRect(300, 170, 111, 41));
        backk = new QPushButton(centralwidget);
        backk->setObjectName(QString::fromUtf8("backk"));
        backk->setGeometry(QRect(460, 230, 111, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(450, 30, 191, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"func\";\n"
"font: 10pt \"\345\215\216\346\226\207\344\270\255\345\256\213\";\n"
""));
        controller->setCentralWidget(centralwidget);
        menubar = new QMenuBar(controller);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 638, 21));
        controller->setMenuBar(menubar);
        statusbar = new QStatusBar(controller);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        controller->setStatusBar(statusbar);

        retranslateUi(controller);

        QMetaObject::connectSlotsByName(controller);
    } // setupUi

    void retranslateUi(QMainWindow *controller)
    {
        controller->setWindowTitle(QCoreApplication::translate("controller", "\345\234\260\345\233\276\346\216\247\345\210\266\345\217\260", nullptr));
        label_3->setText(QCoreApplication::translate("controller", "\345\234\260\345\233\276\346\223\215\344\275\234", nullptr));
        showpoint->setText(QCoreApplication::translate("controller", "showpoints", nullptr));
        showedge->setText(QCoreApplication::translate("controller", "showedges", nullptr));
        clearbtn->setText(QCoreApplication::translate("controller", "clear", nullptr));
        showtrafic->setText(QCoreApplication::translate("controller", "\346\265\201\351\207\217\346\230\276\347\244\272", nullptr));
        flow->setText(QCoreApplication::translate("controller", "flow_change", nullptr));
        start->setText(QCoreApplication::translate("controller", "\350\265\267\345\247\213\347\202\271", nullptr));
        label_5->setText(QCoreApplication::translate("controller", "\347\233\256\347\232\204\347\202\271", nullptr));
        flownumber->setText(QCoreApplication::translate("controller", "\346\265\201\351\207\217", nullptr));
        label->setText(QCoreApplication::translate("controller", "\345\257\274\350\210\252\346\223\215\344\275\234", nullptr));
        scale->setText(QCoreApplication::translate("controller", "\347\274\251\346\224\276", nullptr));
        resetFlow->setText(QCoreApplication::translate("controller", "\350\256\276\347\275\256\346\265\201\351\207\217", nullptr));
        fastest->setText(QCoreApplication::translate("controller", "\346\234\200\345\277\253", nullptr));
        shortest->setText(QCoreApplication::translate("controller", "\346\234\200\347\237\255", nullptr));
        backk->setText(QCoreApplication::translate("controller", "\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("controller", "\345\260\217\345\234\260\345\233\276\346\223\215\344\275\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class controller: public Ui_controller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_H
