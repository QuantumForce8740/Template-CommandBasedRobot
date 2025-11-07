// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>

#include "commands/DefaultDrive.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();

  // Set up default drive command
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -m_driverController.GetRawAxis(1); },
      [this] { return -m_driverController.GetRawAxis(2); }));
}

void RobotContainer::ConfigureBindings() {
  // Configure your button bindings here

  // NOTE: since we're binding a CommandPtr, command ownership here is moved to
  // the scheduler thus, no memory leaks!

}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // Runs the chosen command in autonomous
  return m_chooser.GetSelected();
}