// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {

  // Configure the button bindings
  ConfigureBindings();
  
  m_drive.SetDefaultCommand(DefaultDrive(
      &m_drive, [this] { return -m_driverController.GetLeftY(); },
      [this] { return -m_driverController.GetRightX(); }));
}
  )

  )

  m_chasis.SetDefaultCommand(
    frc2::RunCommand(
      [this] {

        double drive = -m_controller.GetLeftY();
        double turn = m_controller.GetRightX(); 

      }
    )|
  )
}


void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
