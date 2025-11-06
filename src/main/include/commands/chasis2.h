// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/chasis.h"



/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ChasisDrive : public frc2::CommandHelper<frc2::Command, ChasisDrive> {
 public:
  /**
   * Creates a new ExampleCommand.
   *
   //@param subsystem The subsystem used by this command.

   */
 
 ChasisDrive(ChasisSubsystem* subsystem, std::function<double()> forward, 
 std:: function<double()> rotation); 
  


void Execute() override; 
 private:
  ChasisDrive* m_chasis;
  std::function<double()> m_forward; 
  std::function<double()> m_rotation; 
};
