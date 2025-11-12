#include "DriveSubsystem.h"

#include <wpi/sendable/SendableBuilder.h>

DriveSubsystem::DriveSubsystem(){

    globalConfig.SmartCurrentLimit(50).SetIdleMode(
      SparkMaxConfig::IdleMode::kBrake);

//Ar.N  ^
//A.m _   

    //Aplica la confg. global y lo invierte
    rightLeaderConfig.Apply(globalConfig).Inverted(true);

    //Aplica la confg. global y pone al leader SPARK para modo seguir
    rightFollowerConfig.Apply(globalConfig).Follow(m_rightLeader);

    //Aplica la confg. global
    leftLeaderConfig.Apply(globalConfig);

    //Aplica la confg. global y pone al leader SPARK para modo seguir
    leftFollowerConfig.Apply(globalConfig).Follow(m_leftLeader);


//°°°° N_//

/*
    Aplica la cofng. a los SPARKs.

    kResetSafeParameters es usado para obtener el estado del SPARK MAX.
    Esto es util en caso de que el SPARK MAX es remplasado

    kPersistParameters es usado para asegurar que la configuración no se
    pierda cuando el SPARK MAX pierda su poder. Esto es util para los 
    ciclos de energía que puedan ocurrir durante el funcionamiento.

*/


    m_leftLeadMotor.Configure(globalConfig,
                        SparkMax::ResetMode::kResetSafeParameters,
                        SparkMax::PersistMode::kPersistParameters);

    m_leftFollowMotor.Configure(leftFollowerConfig,
                        SparkMax::ResetMode::kResetSafeParameters,
                        SparkMax::PersistMode::kPersistParameters);

    m_rightLeadMotor.Configure(rightLeaderConfig,
                        SparkMax::ResetMode::kResetSafeParameters,
                        SparkMax::PersistMode::kPersistParameters);

    m_rightFollowMotor.Configure(rightFollowerConfig,
                        SparkMax::ResetMode::kResetSafeParameters,
                        SparkMax::PersistMode::kPersistParameters);

}



void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  m_drive.ArcadeDrive(fwd, rot);
}