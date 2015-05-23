#include "updatepos.h"


updatePos::updatePos()
{

}

updatePos::~updatePos()
{

}

float updatePos::getXSpeed() const
{
    return xSpeed;
}

void updatePos::setXSpeed(float value)
{
    xSpeed = value;
}

void updatePos::addXSpeed(float value)
{
    xSpeed += value;
}

void updatePos::addXSpeed(float speedConst, float angle)
{
    if (xSpeed >= 10)
    {
        xSpeed = 10;
    }
    else if (xSpeed <= -10)
    {
        xSpeed = -10;
    }
    else
    {
        xSpeed = xSpeed+speedConst*cos(M_PI/180*angle);
    }
}

float updatePos::getYSpeed() const
{
    return ySpeed;
}

void updatePos::setYSpeed(float value)
{
    ySpeed = value;
}

void updatePos::addYSpeed(float value)
{

    ySpeed += value;

}

void updatePos::addYSpeed(float speedConst, float angle)
{
    if (ySpeed >= 10)
    {
        ySpeed = 10;
    }
    else if (ySpeed <= -10)
    {
        ySpeed = -10;
    }
    else
    {
        ySpeed = ySpeed+speedConst*sin(M_PI/180*angle);
    }
}

float updatePos::getXPos() const
{
    return xPos;
}

void updatePos::setXPos(float value)
{
    xPos = value;
}

float updatePos::getYPos() const
{
    return yPos;
}

void updatePos::setYPos(float value)
{
    yPos = value;
}

float updatePos::getMomentumAngle() const
{
    return momentumAngle;
}

void updatePos::setMomentumAngle(float value)
{
    momentumAngle = value;
}
