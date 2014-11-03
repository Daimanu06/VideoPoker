#include "mainwindow.h"
#include "centralwidget.h"
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createMenuBar();
    createStatusBar();
    createMainWidget();
}

void MainWindow::createMenuBar() {
    menubar = new QMenuBar(this);
    QMenu *menu_game = menubar->addMenu(tr("&Game"));
    //menu_game->addAction("Quit", qApp, SLOT(quit()), QKeySequence(QKeySequence::Quit));
    menu_game->addAction("Quit", qApp, SLOT(quit()), QKeySequence(Qt::CTRL + Qt::Key_Q));
    setMenuBar(menubar);
}

void MainWindow::createStatusBar() {
    statusbar = new QStatusBar(this);
    setStatusBar(statusbar);
}

void MainWindow::createMainWidget() {
    setCentralWidget(new CentralWidget(this));
}
