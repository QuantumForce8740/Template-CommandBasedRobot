// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class HalfSpeedDrive
    : public frc2::CommandHelper<frc2::Command, HalfSpeedDrive> {
 public:
  explicit HalfSpeedDrive(DriveSubsystem* subsystem);

  void Initialize() override;

  void End(bool interrupted) override;

 private:
  DriveSubsystem* m_drive;
};