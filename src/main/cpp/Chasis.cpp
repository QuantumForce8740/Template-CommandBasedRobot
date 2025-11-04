#include "Chasis.h"

Chasis::Chasis()
{
    m_leftBack.Follow(m_leftFront);
    m_rightBack.Follow(m_rightFront);

    m_rightFront.SetInverted(true);
    m_leftBack.SetInverted(true); 

    
}

void Chasis::SetMotors(double leftSpeed, double rightSpeed) {

    m_leftFront.Set(leftSpeed);
    m_RightFront.Set(RightSpeed);
}