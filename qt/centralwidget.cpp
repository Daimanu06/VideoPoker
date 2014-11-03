#include "centralwidget.h"
#include <QVBoxLayout>
#include <QPushButton>

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new QPushButton("test"));
    layout->addWidget(new QPushButton("test"));
    layout->addWidget(new QPushButton("test"));
    layout->addWidget(new QPushButton("test"));
    setLayout(layout);
}
