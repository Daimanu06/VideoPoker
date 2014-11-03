#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QMenuBar;
class QStatusBar;

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    signals:

    public slots:

    private:
        void createMenuBar();
        void createStatusBar();
        void createMainWidget();

    private:
        QMenuBar   *menubar;
        QStatusBar *statusbar;

};

#endif // MAINWINDOW_H
