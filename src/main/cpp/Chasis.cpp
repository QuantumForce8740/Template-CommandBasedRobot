#include "Chasis.h"
#include <utility>

#include <Robot.h>



Chasis::Chasis(){



    void Chasis::SetMotors(double leftSpeed, double rightSpeed) {



         m_leftFront.Set(leftSpeed);
        m_RightFront.Set(RightSpeed);
    }   
}




DefaultDrive::DefaultDrive(DriveSubsystem* subsystem,
                           std::function<double()> forward,
                           std::function<double()> rotation)
    : m_drive{subsystem},
      m_forward{std::move(forward)},
      m_rotation{std::move(rotation)} {
  AddRequirements(subsystem);
}

void DefaultDrive::Execute() {
  m_drive->ArcadeDrive(m_forward(), m_rotation());
}