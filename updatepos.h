#ifndef UPDATEPOS_H
#define UPDATEPOS_H

#include <QtMath>
#include <cmath>

class updatePos
{
private:
    float xSpeed;
    float ySpeed;
    float xPos;
    float yPos;
    float momentumAngle;

public:
    updatePos();
    ~updatePos();

    float getXSpeed() const;
    void setXSpeed(float value);
    void setXSpeed(float speedConst, float angle);
    float getYSpeed() const;
    void setYSpeed(float value);
    void setYSpeed(float speedConst, float angle);
    float getXPos() const;
    void setXPos(float value);
    float getYPos() const;
    void setYPos(float value);
    float getMomentumAngle() const;
    void setMomentumAngle(float value);
};

#endif // UPDATEPOS_H
