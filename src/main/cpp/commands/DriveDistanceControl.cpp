// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveDistanceControl.h"
#include <frc/RobotController.h>
#include <units/velocity.h>

#include <cmath>

DriveDistanceControl::DriveDistanceControl(units::meter_t distance, double speed,
                             DriveSubsystem* subsystem)
    : m_drive(subsystem), m_distance(distance), m_speed(speed) {
  AddRequirements(subsystem);
}

void DriveDistanceControl::Initialize() {
  m_drive->ResetEncoders();
//   m_drive->ArcadeDrive(m_speed, 0);
}

void DriveDistanceControl::Execute() {
    // En lugar de gyro hay que calcular con los encoders
    // Calculate(measurement, goal)
  m_drive->ArcadeDrive(
    m_controller.Calculate(units::meter_t{m_drive->GetAverageEncoderDistance()}, m_distance) +
                          // Divide feedforward voltage by battery voltage to
                          // normalize it to [-1, 1]
    m_feedforward.Calculate(m_controller.GetSetpoint().velocity) / frc::RobotController::GetBatteryVoltage(), 
    0);
}

void DriveDistanceControl::End(bool interrupted) {
  m_drive->ArcadeDrive(0, 0);
}

bool DriveDistanceControl::IsFinished() {
  return m_controller.AtGoal();
}