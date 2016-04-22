#include <QApplication>
#include <QTimer>wwww
#include <QObject>
#include <QGraphicsScene>
#include <GGraphicsView.h>
#include <QGraphicsRectItem>
#include <QPen>
#include "ggamescene.h"
#include "ggraphicsview.h"
#include <QPainter>
#include <helper.h>
#include <constants.h>
#include <QWindow>

int main(int argc, char *argv[])
{
    seedRandomFunction();
    QApplication a(argc, argv);
    GGameScene* scene = new GGameScene();
    GGraphicsView* view = new GGraphicsView();
    view->setWindowTitle("Tau");
    view->setRenderHint(QPainter::Antialiasing);
    view->setGScene(scene);
    view->setFixedSize(windowWidth,windowHeight);
    scene->setSceneRect(0,0,windowWidth,windowHeight);
    view->setVisible(true);
    scene->drawGradBackground();
    scene->drawBoard();

    return a.exec();
}
