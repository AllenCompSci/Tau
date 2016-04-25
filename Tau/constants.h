#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QPointF>
#include <QString>

enum class powerUpType{ballSizeUp=0,paddleSizeUp,paddleSizeDown,arrow,
                       NUM_POWERUPTYPES};
const QString icos[(int)powerUpType::NUM_POWERUPTYPES] = {":/ico/sizeUp.png",
        ":/ico/add.png",
        ":/ico/minus.png",
        ":/ico/arrowRight.png"};

const int refreshInterval = 20; //time between frame refreshes
const int windowWidth = 750; //width of window
const int windowHeight = 750; //height of window
const int playerWidth = 15; //width of paddle
const int arenaWidth = 5; //width of arena circle
const int arenaRadius = windowHeight/2*.9; //radius of arena circle
const int playerInitSize = 180; //in 16ths of degrees (angular difference from center to side of paddle)
const int playerRadius = arenaRadius-playerWidth-arenaWidth/2; //radius of circle in which the paddles are drawn
const int ballInitRadius = 10; //the ball's initial radius
const double ballInitSpeed = 8.5; //ball's initial speed
const int powerUpRadius = 20; //radius of a powerup
const int powerUpInterval = 10000; //in ms; amount of time between powerups added
const int powerUpLastingTime = 10000; //how long a powerup lasts

#endif // CONSTANTS_H
