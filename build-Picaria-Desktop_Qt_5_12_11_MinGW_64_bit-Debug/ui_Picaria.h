/********************************************************************************
** Form generated from reading UI file 'Picaria.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICARIA_H
#define UI_PICARIA_H

#include <Hole.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Picaria
{
public:
    QAction *actionNew;
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *action9holes;
    QAction *action13holes;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    Hole *hole01;
    QSpacerItem *spacer01;
    Hole *hole02;
    QSpacerItem *spacer02;
    Hole *hole03;
    QSpacerItem *spacer03;
    Hole *hole04;
    QSpacerItem *spacer04;
    Hole *hole05;
    QSpacerItem *spacer07;
    Hole *hole06;
    QSpacerItem *spacer06;
    Hole *hole07;
    Hole *hole08;
    QSpacerItem *spacer08;
    Hole *hole09;
    QSpacerItem *spacer09;
    Hole *hole10;
    QSpacerItem *spacer10;
    Hole *hole11;
    QSpacerItem *spacer11;
    Hole *hole12;
    QSpacerItem *spacer12;
    Hole *hole13;
    QSpacerItem *spacer05;
    QMenuBar *menubar;
    QMenu *menuJogo;
    QMenu *menuAjuda;
    QMenu *menuModo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Picaria)
    {
        if (Picaria->objectName().isEmpty())
            Picaria->setObjectName(QString::fromUtf8("Picaria"));
        Picaria->resize(515, 564);
        actionNew = new QAction(Picaria);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionQuit = new QAction(Picaria);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout = new QAction(Picaria);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        action9holes = new QAction(Picaria);
        action9holes->setObjectName(QString::fromUtf8("action9holes"));
        action9holes->setCheckable(true);
        action9holes->setChecked(false);
        action13holes = new QAction(Picaria);
        action13holes->setObjectName(QString::fromUtf8("action13holes"));
        action13holes->setCheckable(true);
        action13holes->setChecked(true);
        centralwidget = new QWidget(Picaria);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget { background: url(':/grid'); }"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        hole01 = new Hole(centralwidget);
        hole01->setObjectName(QString::fromUtf8("hole01"));
        hole01->setMinimumSize(QSize(100, 100));
        hole01->setMaximumSize(QSize(100, 100));
        hole01->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole01->setIconSize(QSize(50, 50));
        hole01->setFlat(true);
        hole01->setProperty("row", QVariant(0));
        hole01->setProperty("col", QVariant(0));

        gridLayout->addWidget(hole01, 0, 0, 2, 2);

        spacer01 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer01, 0, 2, 2, 1);

        hole02 = new Hole(centralwidget);
        hole02->setObjectName(QString::fromUtf8("hole02"));
        hole02->setMinimumSize(QSize(100, 100));
        hole02->setMaximumSize(QSize(100, 100));
        hole02->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole02->setIconSize(QSize(50, 50));
        hole02->setFlat(true);
        hole02->setProperty("row", QVariant(0));
        hole02->setProperty("col", QVariant(2));

        gridLayout->addWidget(hole02, 0, 3, 2, 1);

        spacer02 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer02, 0, 5, 2, 1);

        hole03 = new Hole(centralwidget);
        hole03->setObjectName(QString::fromUtf8("hole03"));
        hole03->setMinimumSize(QSize(100, 100));
        hole03->setMaximumSize(QSize(100, 100));
        hole03->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole03->setIconSize(QSize(50, 50));
        hole03->setFlat(true);
        hole03->setProperty("row", QVariant(0));
        hole03->setProperty("col", QVariant(4));

        gridLayout->addWidget(hole03, 0, 6, 2, 3);

        spacer03 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer03, 2, 0, 2, 1);

        hole04 = new Hole(centralwidget);
        hole04->setObjectName(QString::fromUtf8("hole04"));
        hole04->setMinimumSize(QSize(100, 100));
        hole04->setMaximumSize(QSize(100, 100));
        hole04->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole04->setIconSize(QSize(50, 50));
        hole04->setFlat(true);
        hole04->setProperty("row", QVariant(1));
        hole04->setProperty("col", QVariant(1));

        gridLayout->addWidget(hole04, 2, 1, 2, 2);

        spacer04 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer04, 2, 3, 2, 2);

        hole05 = new Hole(centralwidget);
        hole05->setObjectName(QString::fromUtf8("hole05"));
        hole05->setMinimumSize(QSize(100, 100));
        hole05->setMaximumSize(QSize(100, 100));
        hole05->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole05->setIconSize(QSize(50, 50));
        hole05->setFlat(true);
        hole05->setProperty("row", QVariant(1));
        hole05->setProperty("col", QVariant(2));

        gridLayout->addWidget(hole05, 2, 5, 1, 2);

        spacer07 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer07, 3, 4, 2, 3);

        hole06 = new Hole(centralwidget);
        hole06->setObjectName(QString::fromUtf8("hole06"));
        hole06->setMinimumSize(QSize(100, 100));
        hole06->setMaximumSize(QSize(100, 100));
        hole06->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole06->setIconSize(QSize(50, 50));
        hole06->setFlat(true);
        hole06->setProperty("row", QVariant(2));
        hole06->setProperty("col", QVariant(0));

        gridLayout->addWidget(hole06, 4, 0, 1, 1);

        spacer06 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer06, 4, 1, 1, 2);

        hole07 = new Hole(centralwidget);
        hole07->setObjectName(QString::fromUtf8("hole07"));
        hole07->setMinimumSize(QSize(100, 100));
        hole07->setMaximumSize(QSize(100, 100));
        hole07->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole07->setIconSize(QSize(50, 50));
        hole07->setFlat(true);
        hole07->setProperty("row", QVariant(2));
        hole07->setProperty("col", QVariant(2));

        gridLayout->addWidget(hole07, 4, 3, 1, 1);

        hole08 = new Hole(centralwidget);
        hole08->setObjectName(QString::fromUtf8("hole08"));
        hole08->setMinimumSize(QSize(100, 100));
        hole08->setMaximumSize(QSize(100, 100));
        hole08->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole08->setIconSize(QSize(50, 50));
        hole08->setFlat(true);
        hole08->setProperty("row", QVariant(2));
        hole08->setProperty("col", QVariant(4));

        gridLayout->addWidget(hole08, 4, 6, 1, 3);

        spacer08 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer08, 5, 0, 1, 1);

        hole09 = new Hole(centralwidget);
        hole09->setObjectName(QString::fromUtf8("hole09"));
        hole09->setMinimumSize(QSize(100, 100));
        hole09->setMaximumSize(QSize(100, 100));
        hole09->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole09->setIconSize(QSize(50, 50));
        hole09->setFlat(true);
        hole09->setProperty("row", QVariant(3));
        hole09->setProperty("col", QVariant(1));

        gridLayout->addWidget(hole09, 5, 1, 1, 2);

        spacer09 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer09, 5, 3, 1, 1);

        hole10 = new Hole(centralwidget);
        hole10->setObjectName(QString::fromUtf8("hole10"));
        hole10->setMinimumSize(QSize(100, 100));
        hole10->setMaximumSize(QSize(100, 100));
        hole10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole10->setIconSize(QSize(50, 50));
        hole10->setFlat(true);
        hole10->setProperty("row", QVariant(3));
        hole10->setProperty("col", QVariant(3));

        gridLayout->addWidget(hole10, 5, 4, 1, 2);

        spacer10 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer10, 5, 7, 1, 2);

        hole11 = new Hole(centralwidget);
        hole11->setObjectName(QString::fromUtf8("hole11"));
        hole11->setMinimumSize(QSize(100, 100));
        hole11->setMaximumSize(QSize(100, 100));
        hole11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole11->setIconSize(QSize(50, 50));
        hole11->setFlat(true);
        hole11->setProperty("row", QVariant(4));
        hole11->setProperty("col", QVariant(0));

        gridLayout->addWidget(hole11, 6, 0, 1, 2);

        spacer11 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer11, 6, 2, 1, 1);

        hole12 = new Hole(centralwidget);
        hole12->setObjectName(QString::fromUtf8("hole12"));
        hole12->setMinimumSize(QSize(100, 100));
        hole12->setMaximumSize(QSize(100, 100));
        hole12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole12->setIconSize(QSize(50, 50));
        hole12->setFlat(true);
        hole12->setProperty("row", QVariant(4));
        hole12->setProperty("col", QVariant(2));

        gridLayout->addWidget(hole12, 6, 3, 1, 1);

        spacer12 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer12, 6, 4, 1, 2);

        hole13 = new Hole(centralwidget);
        hole13->setObjectName(QString::fromUtf8("hole13"));
        hole13->setMinimumSize(QSize(100, 100));
        hole13->setMaximumSize(QSize(100, 100));
        hole13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    outline: none;\n"
"}"));
        hole13->setIconSize(QSize(50, 50));
        hole13->setFlat(true);
        hole13->setProperty("row", QVariant(4));
        hole13->setProperty("col", QVariant(4));

        gridLayout->addWidget(hole13, 6, 6, 1, 3);

        spacer05 = new QSpacerItem(100, 100, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(spacer05, 2, 7, 1, 1);

        Picaria->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Picaria);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 515, 20));
        menuJogo = new QMenu(menubar);
        menuJogo->setObjectName(QString::fromUtf8("menuJogo"));
        menuAjuda = new QMenu(menubar);
        menuAjuda->setObjectName(QString::fromUtf8("menuAjuda"));
        menuModo = new QMenu(menubar);
        menuModo->setObjectName(QString::fromUtf8("menuModo"));
        Picaria->setMenuBar(menubar);
        statusbar = new QStatusBar(Picaria);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Picaria->setStatusBar(statusbar);

        menubar->addAction(menuJogo->menuAction());
        menubar->addAction(menuModo->menuAction());
        menubar->addAction(menuAjuda->menuAction());
        menuJogo->addAction(actionNew);
        menuJogo->addAction(actionQuit);
        menuAjuda->addAction(actionAbout);
        menuModo->addAction(action9holes);
        menuModo->addAction(action13holes);

        retranslateUi(Picaria);

        QMetaObject::connectSlotsByName(Picaria);
    } // setupUi

    void retranslateUi(QMainWindow *Picaria)
    {
        Picaria->setWindowTitle(QApplication::translate("Picaria", "Picaria", nullptr));
        actionNew->setText(QApplication::translate("Picaria", "Novo", nullptr));
        actionQuit->setText(QApplication::translate("Picaria", "Sair", nullptr));
        actionAbout->setText(QApplication::translate("Picaria", "Sobre", nullptr));
        action9holes->setText(QApplication::translate("Picaria", "9 Buracos", nullptr));
        action13holes->setText(QApplication::translate("Picaria", "13 Buracos", nullptr));
        hole01->setText(QString());
        hole02->setText(QString());
        hole03->setText(QString());
        hole04->setText(QString());
        hole05->setText(QString());
        hole06->setText(QString());
        hole07->setText(QString());
        hole08->setText(QString());
        hole09->setText(QString());
        hole10->setText(QString());
        hole11->setText(QString());
        hole12->setText(QString());
        hole13->setText(QString());
        menuJogo->setTitle(QApplication::translate("Picaria", "Jogo", nullptr));
        menuAjuda->setTitle(QApplication::translate("Picaria", "Ajuda", nullptr));
        menuModo->setTitle(QApplication::translate("Picaria", "Modo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Picaria: public Ui_Picaria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICARIA_H
