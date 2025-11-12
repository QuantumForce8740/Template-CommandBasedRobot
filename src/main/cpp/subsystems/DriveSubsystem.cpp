// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

#include <wpi/sendable/SendableBuilder.h>

DriveSubsystem::DriveSubsystem(){

  /*
   * Set parameters that will apply to all SPARKs. We will also use this as
   * the left leader config.
   */
  globalConfig.SmartCurrentLimit(50).SetIdleMode(
      SparkMaxConfig::IdleMode::kBrake);

  // Apply the global config and invert since it is on the opposite side
  rightLeaderConfig.Apply(globalConfig).Inverted(true);

  // Apply the global config
  leftLeaderConfig.Apply(globalConfig);

  // Apply the global config and set the leader SPARK for follower mode
  leftFollowerConfig.Apply(globalConfig).Follow(m_leftLeadMotor);

  // Apply the global config and set the leader SPARK for follower mode
  rightFollowerConfig.Apply(globalConfig).Follow(m_rightLeadMotor);

  /*
   * Apply the configuration to the SPARKs.
   *
   * kResetSafeParameters is used to get the SPARK MAX to a known state. This
   * is useful in case the SPARK MAX is replaced.
   *
   * kPersistParameters is used to ensure the configuration is not lost when
   * the SPARK MAX loses power. This is useful for power cycles that may occur
   * mid-operation.
   */
  m_leftLeadMotor.Configure(globalConfig,
                         SparkMax::ResetMode::kResetSafeParameters,
                         SparkMax::PersistMode::kPersistParameters);
  m_leftFollowMotor.Configure(leftFollowerConfig,
                           SparkMax::ResetMode::kResetSafeParameters,
                           SparkMax::PersistMode::kPersistParameters);
  m_rightLeadMotor.Configure(rightLeaderConfig,
                          SparkMax::ResetMode::kResetSafeParameters,
                          SparkMax::PersistMode::kPersistParameters);
  m_rightFollowMotor.Configure(rightFollowerConfig,
                            SparkMax::ResetMode::kResetSafeParameters,
                            SparkMax::PersistMode::kPersistParameters);

}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}

void DriveSubsystem::ResetEncoders() {
  m_leftEncoder.SetPosition(0);
  m_rightEncoder.SetPosition(0);
}

double DriveSubsystem::GetAverageEncoderDistance() {
  return (m_leftEncoder.GetPosition() + m_rightEncoder.GetPosition()) / 2.0;
}

// void DriveSubsystem::InitSendable(wpi::SendableBuilder& builder) {
//   SubsystemBase::InitSendable(builder);

//   // Publish encoder distances to telemetry.
//   builder.AddDoubleProperty(
//       "leftDistance", [this] { return m_leftEncoder.GetDistance(); }, nullptr);
//   builder.AddDoubleProperty(
//       "rightDistance", [this] { return m_rightEncoder.GetDistance(); },
//       nullptr);
// }