#include "titletext.h"

titleText::titleText(QString fontName, QPointF* center, int size, QString text)
{
    this->text = text;
    titleFont = new QFont(fontName,size,QFont::Normal,false);
    titleFontMetrics = new QFontMetrics(QFont(*titleFont));
    this->titleCenter = center;
    this->opacity = 1.0;
    this->setZValue(10);
}

QRectF titleText::boundingRect() const
{
    return QRectF(titleCenter->x()-size,titleCenter->y()-size,size*2,size*2);
}

void titleText::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QColor::fromRgb(255,255,255,255));
    painter->setBrush(QBrush(QColor::fromRgb(255,255,255,255)));
    painter->setFont(*titleFont);
    painter->setOpacity(opacity);
    painter->drawText(titleCenter->x()-titleFontMetrics->width(text)/2,titleCenter->y(),text);
}
