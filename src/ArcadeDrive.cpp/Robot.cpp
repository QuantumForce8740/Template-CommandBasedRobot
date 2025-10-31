// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <rev/CANSparkMax.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot {
    static const int leftLeadDeviceID = 1, leftFollowDeviceID = 2, rightLeadDeviceID = 5, rightLeadDeviceID = 6;
    rev::CANSparksMax m_leftLeadMotor{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparksMax m_rightLeadMotor{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparksMax m_leftFollowMotor{leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparksMax m_rightFollowMotor{rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};

    frc::DifferentialDrive m_robotDrive{m_leftLeadMotor, m_rightLeadMotor};
    frc::Joystick m_stick{0};


 public:
   void RobotInit() {
    m_leftLeadMotor.RestoreFactoryDefaults();
    m_rigthLeadMotor.RestoreFactoryDefaults();
    m_leftFollowMotor.RestoreFactoryDefaults();
    m_rightFollowMotor.RestoreFactoryDefaults();

    m_leftFollowMotor.Follow(m_leftLeadMotor);
    m_rightFollowMotor.Follow(m_rightLeadMotor);

   }

  void TeleopPeriodic() override {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(-m_stick.GetY(), -m_stick.GetX());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif