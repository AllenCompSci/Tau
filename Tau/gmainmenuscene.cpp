#include "gmainmenuscene.h"
#include <QtConcurrent>

GMainMenuScene::GMainMenuScene(Arena* box)
{
    this->box = box;
    this->box->setPermRadius(mainMenuArenaRadius);
    this->box->setPen(*arenaPen);
    this->box->setRadius(mainMenuArenaRadius);
    this->addItem(this->box);
    this->addItem(this->box->bkg);
    this->box->pulseDist = 5;
    pb = new playButton(playButtonSize);
    pb->setBrush(brush);
    pb->setPen(arenaPen);
    this->addItem(pb);

    this->addItem(title);
    this->addItem(description);
    creditsButton->opacity=0.7;
    this->addItem(creditsButton);
    QtConcurrent::run(this,&GMainMenuScene::entrySequence);

    QObject::connect(box,SIGNAL(pulsed()),pb,SLOT(pulse()));
    refresher = new QTimer();
    QObject::connect(refresher,SIGNAL(timeout()),this,SLOT(refresh()));
    refresher->start(refreshInterval);
}

void GMainMenuScene::exitSequence()
{
    while(box->radius<arenaRadius){
        title->opacity-=0.1;
        description->opacity-=0.1;
        pb->setSize(pb->getSize()-7);
        box->radius+=(arenaRadius-box->radius)/3+3;
        box->setPermRadius(box->radius-box->pulseDist);
        QThread::msleep(refreshInterval);
    }
    doneExiting();
}

void GMainMenuScene::entrySequence()
{
    pb->setSize(0);
    title->opacity = 0;
    description->opacity = 0;
    for(int i = 0; i < 50; i++){
        pb->setSize(pb->getSize()+playButtonSize/50);
        title->opacity+=0.02;
        description->opacity+=0.02;
        QThread::msleep(refreshInterval);
    }
    pb->setSize(playButtonSize);
}

void GMainMenuScene::refresh()
{
    if(box->radius > box->permRadius)
        box->setRadius(box->radius-1);
    pb->incrementAngle();
    if(pb->getSize() > pb->permSize)
        pb->setSize(pb->getSize()-1);
    this->update();
}
