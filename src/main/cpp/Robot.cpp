#include "Robot.h"

// Implementación de la inicialización del robot
void Robot::RobotInit() {
  m_leftFollowMotor.Follow(m_leftLeadMotor);
  m_rightFollowMotor.Follow(m_rightLeadMotor);
  m_grupoDerecho.SetInverted(true); // O m_grupoIzquierdo.SetInverted(true); si es necesario
}

// Implementación del modo teleoperado
void Robot::TeleopPeriodic() {
  double velocidad = m_stick.GetLeftY();
  double giro = m_stick.GetLeftX();
  m_robotDrive.ArcadeDrive(-velocidad, giro);
}

// Implementaciones vacías para otros modos
void Robot::AutonomousPeriodic() {}
void Robot::DisabledPeriodic() {}
void Robot::TestPeriodic() {}
