#include "lib/RenderGate.h"

RenderGate::RenderGate():FuncGate(50, 50, Qt::white,1,true){}
data_t RenderGate::eval()const{
    return input[0]->eval();
}

void RenderGate::paint(QPainter* painter,
           const QStyleOptionGraphicsItem* option,
           QWidget* widget){
    pen.setColor(Qt::darkGreen);
    FuncGate::paint(painter, option, widget);
}

void RenderGate::connectGate(FuncGate *g, unsigned i){
    FuncGate::connectGate(g,i);
}
