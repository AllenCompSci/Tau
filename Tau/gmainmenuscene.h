#ifndef GMAINMENUSCENE_H
#define GMAINMENUSCENE_H
#include <QObject>
#include <QGraphicsScene>
#include <arena.h>
#include <constants.h>
#include <playbutton.h>
#include <titletext.h>
#include <QTextItem>
#include <QThread>

class GMainMenuScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GMainMenuScene(Arena* box);
    QTimer* refresher;
    void exitSequence();
    void entrySequence();

signals:
    void doneExiting();

public slots:
    void refresh();

private:
    titleText* title = new titleText("Times New Roman",new QPointF(windowWidth/2,windowHeight/4),200,"\u03C4");
    titleText* description = new titleText("Georgia",new QPointF(windowWidth/2,windowHeight/2+mainMenuArenaRadius+100),20,"\u03C4 (Tau) -- torque (physics), 2\u03C0 \u2248 6.28 (math, c. 2001)");
    playButton* pb;
    QBrush* brush = new QBrush(QColor::fromRgb(255,255,255));
    QPen* arenaPen = new QPen(*brush,arenaWidth,Qt::SolidLine,Qt::SquareCap);
    Arena* box;
};

#endif // GMAINMENUSCENE_H
