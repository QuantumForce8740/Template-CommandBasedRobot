// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Trigger.h>

//#include "commands/Autos.h"
#include "commands/ChasisDrive.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
  
  m_drive.SetDefaultCommand(ChasisDrive(
  &m_drive, [this] { return -m_drivecontroller.GetRawAxis(1); },
  [this] {return -m_drivecontroller.GetRawAxis(2); })); 
}


void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

}

  frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return m_chooser.GetSelected();
}