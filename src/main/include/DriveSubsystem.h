#pragma once


#include <frc/drive/DifferentialDrive.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/SparkMax.h>
#include <rev/config/SparkMaxConfig.h>

#include "Constants.h"



using namespace rev::spark;

class DriveSubsystem : public frc2::SubsystemBase {
    public:
        DriveSubsystem();

        //Sera llamada cada vez que CommandScheduler corra
        void Periodic() override;

        /*

        Controla el robot usando controles tipo arcade

        @param fwd para el movimiento movimiento en las ordenadas

        @param rot para la rotación
  
        */
  
        void ArcadeDrive(double fwd, double rot);

//Ar.N ^
//A.M_

        private:

        //Los controladores del motor

        SparkMax m_leftLeader{1, SparkMax::MotorType::kBrushless};
        SparkMax m_leftFollower{2, SparkMax::MotorType::kBrushless};
        SparkMax m_rightLeader{6, SparkMax::MotorType::kBrushless};
        SparkMax m_rightFollower{5, SparkMax::MotorType::kBrushless};

        // EL DRIVE DEL ROBOT

        SparkMaxConfig globalConfig;
        SparkMaxConfig leftLeaderConfig;
        SparkMaxConfig leftFollowerConfig;
        SparkMaxConfig rightLeaderConfig;
        SparkMaxConfig rightFollowerConfig;
};