// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {
inline constexpr int kDriverControllerPort = 0;
}  // namespace OperatorConstants

namespace DriveConstants {
inline constexpr int kLeftMotor1Port = 1;
inline constexpr int kLeftMotor2Port = 2;
inline constexpr int kRightMotor1Port = 6;
inline constexpr int kRightMotor2Port = 5;
}  // namespace DriveConstants

namespace AutoConstants {
constexpr double kAutoDriveDistanceInches = 2.0;
constexpr double kAutoDriveSpeed = 0.3;
}  // namespace AutoConstants