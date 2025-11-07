// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h> 
#include <frc/drive/DifferentialDrive.h>
#include "Constants.h"

using namespace rev::spark; 

class ChasisSubsystem : public frc2::SubsystemBase {
 public:
  ChasisSubsystem();


  /**
   * An example method querying a boolean state of the subsystem (for example, a
   * digital sensor).
   *
   * @return value of some boolean subsystem state, such as a digital sensor.
   */

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void ArcadeDrive(double forward, double rotation);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  SparkMax m_leftLeadMotor{1, SparkMax::MotorType::kBrushless};
  SparkMax m_rightLeadMotor{6, SparkMax::MotorType::kBrushless};
  SparkMax m_leftFollowMotor{2, SparkMax::MotorType::kBrushless};
  SparkMax m_rightFollowMotor{5, SparkMax::MotorType::kBrushless};

  frc::DifferentialDrive m_drive{m_leftLeadMotor, m_rightLeadMotor};

  SparkMaxConfig globalConfig; 
  SparkMaxConfig rightLeaderConfig;
  SparkMaxConfig leftLeaderConfig; 
  SparkMaxConfig leftFollowerConfig;
  SparkMaxConfig rightFollowerConfig; 

};
