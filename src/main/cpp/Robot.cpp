// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <frc2/command/CommandScheduler.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include "rev/CANSparkMax.h"


class Robot : public frc::TimedRobot {

// 

   * The example below initializes four brushless motors with CAN IDs 1, 2, 3 and 4. Change
   * these parameters to match your setup
   

   static const int leftLeadDeviceID = 1, leftFollowDeviceID = 2, rightLeadDeviceID = 6, rightFollowDeviceID = 5;
   
  rev::CANSparkMax m_leftLeadMotor{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightLeadMotor{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollowMotor{leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollowMotor{rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};


  frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};

  frc::Joystick m_stick{0};

  ///

  public:
    void RobotInit() {

      m_leftFollowMotor.Follow(m_leftLeadMotor);

      m_rightFollowMotor.Follow(m_rightLeadMotor);
    }

    void TeleopPeriodic() {

      m_robotDrive.ArcadeDrive(-m_stick.GetY(), m_stick.GetX());
    }

};

