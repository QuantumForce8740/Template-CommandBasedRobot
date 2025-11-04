#pragma once

#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <rev/CANSparkMax.h>

class Chasis : public frc:SubsystemBase {
  public: 
  Chasis();
  void Periodic() override; 

  void SetMotors(double leftSpeed, double rightSpeed);
  
}
class Robot : public frc::TimedRobot {
 private:
  static constexpr int leftLeadDeviceID = 1, leftFollowDeviceID = 2, rightLeadDeviceID = 6, rightFollowDeviceID = 5;

  rev::CANSparkMax m_leftLeadMotor{leftLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightLeadMotor{rightLeadDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_leftFollowMotor{leftFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_rightFollowMotor{rightFollowDeviceID, rev::CANSparkMax::MotorType::kBrushless};

  frc::MotorControllerGroup m_grupoIzquierdo{m_leftLeadMotor, m_leftFollowMotor};
  frc::MotorControllerGroup m_grupoDerecho{m_rightLeadMotor, m_rightFollowMotor};
  frc::DifferentialDrive m_robotDrive{m_grupoIzquierdo, m_grupoDerecho};

  frc::XboxController m_stick{0};

 public:
  void RobotInit() override;
  void TeleopPeriodic() override;
  void AutonomousPeriodic() override;
  void DisabledPeriodic() override;
  void TestPeriodic() override;
};
