#include "stackwidget.h"
#include "drawzone.h"
#include "imagewidget.h"

QWidget* makeImage(QString name)
{
    QImage* img = new QImage(name);
    QWidget* w = new ImageWidget(img);
    delete img;
    return w;
}

StackWidget::StackWidget(QWidget *parent) :
    QWidget(parent),
    m_stackSize(0)
{
    QStackedLayout* l = new QStackedLayout(this);
    l->setStackingMode(QStackedLayout::StackAll);
    this->setLayout(l);
}

StackWidget::~StackWidget()
{

}

QWidget* StackWidget::getTopElement()
{
    return this->layout()->itemAt(0)->widget();
}

void StackWidget::push(QWidget *img)
{
    this->layout()->addWidget(img);
    m_stackSize++;
    update();
}

void StackWidget::push(QLayoutItem *img)
{
    this->push(img->widget());
}

void StackWidget::push(QString imgName)
{
    this->push(makeImage(imgName));
}

QList<QLayoutItem*>* StackWidget::removeAll()
{
    QList<QLayoutItem*>* list(new QList<QLayoutItem*>());
    QLayoutItem* item;
    while(!this->layout()->isEmpty())
    {
        item = this->layout()->itemAt(0);
        this->layout()->removeItem(item);
        list->append(item);
    }
    m_stackSize = 0;
    update();
    return list;
}

QLayoutItem* StackWidget::removeBottom()
{
    if(!this->layout()->isEmpty())
    {
        m_stackSize--;
        QLayoutItem* item(this->layout()->itemAt(m_stackSize));
        this->layout()->removeItem(item);
        update();
        return item;
    }
    return 0;
}

QList<QLayoutItem*>* StackWidget::removeMiddle()
{
    QLayoutItem* top(this->layout()->itemAt(0));
    QLayoutItem* bottom(this->layout()->itemAt(m_stackSize-1));
    this->layout()->removeItem(top);
    this->layout()->removeItem(bottom);
    QList<QLayoutItem*>* list(this->removeAll());
    if(top != bottom && bottom != 0) {
        this->layout()->addItem(top);
        this->layout()->addItem(bottom);
        m_stackSize = 2;
    } else if(top == bottom && top != 0) {
        this->layout()->addItem(top);
        m_stackSize = 1;
    }
    update();
    return list;
}

int StackWidget::stackCount()
{
    return this->m_stackSize;
}

void StackWidget::enterEvent(QEvent*)
{
    emit mouseOver();
}

void StackWidget::leaveEvent(QEvent*)
{
    emit mouseOut();
}

void StackWidget::resizeEvent(QResizeEvent *event)
{
    QSize newSize(event->size());
    for(int i=0;i<m_stackSize;i++)
    {
        this->layout()->itemAt(i)->widget()->resize(newSize);
    }
}
