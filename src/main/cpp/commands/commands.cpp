// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <functional>
#include <utility>
#include "subsystems/Chasis.h"

class DefaultDrive::DefaultDrive(ChasisSubsystem* subsystem,
          std::function<double()> forward,
          std::function<double()> turn)

       : m_chasis{susbystem},
      m_forward{std::move(forward)},
      m_turn{std::move(turn)} 
      

   void DefaultDrive::Execute() {
    m_chasis->SetMotors(m_forward(), m_rotation()); 
   }
 






