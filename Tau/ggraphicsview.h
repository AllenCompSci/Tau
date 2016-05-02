#ifndef GGRAPHICSVIEW_H
#define GGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QTimer>
#include <QCloseEvent>
#include <ggamescene.h>

class GGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GGraphicsView();
    void setGScene(GGameScene* scene);
    void startGame();

protected:
    GGameScene* GScene;
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Arena* box;
    bool clockWise[2];
    void closeEvent(QCloseEvent*);
    QTimer* movep1;
    QTimer* movep0;
    void setupTimer(QTimer* t, Player* p, bool cw);
};

#endif // GGRAPHICSVIEW_H
