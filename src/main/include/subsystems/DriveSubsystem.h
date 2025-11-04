// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

#include "Constants.h"

using namespace rev::spark;

class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Subsystem methods go here.

  /**
   * Drives the robot using arcade controls.
   *
   * @param fwd the commanded forward movement
   * @param rot the commanded rotation
   */
  void ArcadeDrive(double fwd, double rot);

  /**
   * Resets the drive encoders to currently read a position of 0.
   */
  // void ResetEncoders();

  // /**
  //  * Gets the average distance of the TWO encoders.
  //  *
  //  * @return the average of the TWO encoder readings
  //  */
  // double GetAverageEncoderDistance();

  // /**
  //  * Sets the max output of the drive.  Useful for scaling the drive to drive
  //  * more slowly.
  //  *
  //  * @param maxOutput the maximum output to which the drive will be constrained
  //  */
  // void SetMaxOutput(double maxOutput);

  // void InitSendable(wpi::SendableBuilder& builder) override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  // The motor controllers
  
  SparkMax m_leftLeadMotor{1, rev::spark::SparkMax::MotorType::kBrushless};
  SparkMax m_rightLeadMotor{6, rev::spark::SparkMax::MotorType::kBrushless};
  SparkMax m_leftFollowMotor{2, rev::spark::SparkMax::MotorType::kBrushless};
  SparkMax m_rightFollowMotor{5, rev::spark::SparkMax::MotorType::kBrushless};

  // The robot's drive
  frc::DifferentialDrive m_drive{m_leftLeadMotor, m_rightLeadMotor};

  SparkMaxConfig globalConfig;
  SparkMaxConfig rightLeaderConfig;
  SparkMaxConfig leftLeaderConfig;
  SparkMaxConfig leftFollowerConfig;
  SparkMaxConfig rightFollowerConfig;
};