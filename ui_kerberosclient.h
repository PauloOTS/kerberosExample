/********************************************************************************
** Form generated from reading UI file 'kerberosclient.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KERBEROSCLIENT_H
#define UI_KERBEROSCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KerberosClient
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KerberosClient)
    {
        if (KerberosClient->objectName().isEmpty())
            KerberosClient->setObjectName(QStringLiteral("KerberosClient"));
        KerberosClient->resize(400, 300);
        centralWidget = new QWidget(KerberosClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        KerberosClient->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KerberosClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        KerberosClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KerberosClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KerberosClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KerberosClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KerberosClient->setStatusBar(statusBar);

        retranslateUi(KerberosClient);

        QMetaObject::connectSlotsByName(KerberosClient);
    } // setupUi

    void retranslateUi(QMainWindow *KerberosClient)
    {
        KerberosClient->setWindowTitle(QApplication::translate("KerberosClient", "KerberosClient", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class KerberosClient: public Ui_KerberosClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KERBEROSCLIENT_H
