// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>
#include <frc/PWMTalonSRX.h>
//#include <ctre/phoenix/motorcontrol/TalonSRX.h>
//#include <ctre/TalonSRX.h>
//#include <Phoenix.h>
//#include "ctre/phoenix/motorcontrol/can/TalonSRX.h"
//#include "ctre/phoenix.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;


 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  frc::XboxController Driver{0};
  
  frc::PWMTalonSRX LeftFrontController{0};
  frc::PWMTalonSRX LeftRearController{1};
  frc::PWMTalonSRX RightFrontController{2};
  frc::PWMTalonSRX RightRearController{3};
  
};
