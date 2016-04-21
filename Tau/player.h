#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QPen>

class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Player(double pos, double size,int playerNum);
    int pos; // angular position
    double size; // angular distance from center to edge
    int startAngle();
    int spanAngle();
    QRectF* rect();
    void setPen(QPen pen);
    void setBrush(QBrush brush);
    virtual QRectF boundingRect() const;
    void move(int dtheta);
    void sizeUp();
    void sizeDown();

public slots:
    void moveClockwise();
    void moveCClockwise();

protected:
    int playerNum;
    QPen pen;
    QBrush brush;
    QRectF* rekt;
    void paint ( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // PLAYER_H
