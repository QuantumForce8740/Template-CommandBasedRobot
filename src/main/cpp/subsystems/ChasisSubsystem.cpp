// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ChasisSubsystem.h"
#include <rev/SparkMax.h>
#include <wpi/sendable/SendableBuilder.h>

ChasisSubsystem::ChasisSubsystem() {

globalConfig.SmartCurrentLimit(40).SetIdleMode(
  SparkMaxConfig::IdleMode::kBrake); 

rightLeaderConfig.Apply(globalConfig).Inverted(true); 
leftLeaderConfig.Apply(globalConfig);

leftFollowerConfig.Apply(globalConfig).Follow(m_leftFollowMotor); 
rightFollowerConfig.Apply(globalConfig).Follow(m_rightFollowMotor);
}
  

void ChasisSubsystem::Periodic() {

}

void ChasisSubsystem::ArcadeDrive(double forward, double rotation){
  m_drive.ArcadeDrive(forward, rotation); 
}
  // Implementation of subsystem constructor goes here.


//frc2::CommandPtr ExampleSubsystem::ExampleMethodCommand() {
  // Inline construction of command goes here.
  // Subsystem::RunOnce implicitly requires `this` subsystem.
  //return RunOnce([/* this */] { /* one-time action goes here */ });


//bool ExampleSubsystem::ExampleCondition() {
  // Query some boolean state, such as a digital sensor.
 //return false;


//7oid ExampleSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.


//void ExampleSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.

