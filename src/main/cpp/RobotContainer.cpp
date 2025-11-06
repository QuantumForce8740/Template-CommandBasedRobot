// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/button/Trigger.h>

//#include "commands/Autos.h"
#include "commands/chasis2.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

m_drive.SetDefaultCommand(DefaultDrive(
  &m_drive, [this] { return -m_driverController.GetLeftY(1); },
  [this] {return -m_driverController.GetRightX(2); })); 
}

  frc2::Command* RobotContainer::GetAutonomousCommand() {
    return m_chooser.GetSelected(); 
  }
