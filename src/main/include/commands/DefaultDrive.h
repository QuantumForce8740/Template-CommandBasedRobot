#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();
  void Periodic() override;
  void ArcadeDrive(double fwd, double rot);

  void ResetEncoders();
  double GetAverageEncoderDistance();

  void SetMaxOutput(double maxOutput);

  void InitSendable(wpi::SendableBuilder& builder) override;

 private:
 
  frc::PWMSparkMax m_left1;
  frc::PWMSparkMax m_left2;
  frc::PWMSparkMax m_right1;
  frc::PWMSparkMax m_right2;

  frc::DifferentialDrive m_drive{[&](double output) { m_left1.Set(output); },
                                 [&](double output) { m_right1.Set(output); }};
  frc::Encoder m_leftEncoder;
  frc::Encoder m_rightEncoder;
};