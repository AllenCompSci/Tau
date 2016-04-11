#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QPen>

class Player : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    Player(double pos, double size);
    double pos; // angular position
    double size; // angular distance from center to edge
    int startAngle();
    int spanAngle();
    QRectF* rect();
    void setPen(QPen pen);
    void setBrush(QBrush brush);
    virtual QRectF boundingRect() const;

protected:
    QPen pen;
    QBrush brush;
    QRectF* rekt;
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

};

#endif // PLAYER_H
