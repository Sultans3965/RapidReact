// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
using namespace frc;

GenericHID::JoystickHand LEFT_HAND = GenericHID::kLeftHand;
GenericHID::JoystickHand RIGHT_HAND = GenericHID::kRightHand;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  LeftFrontController.SetInverted(true); 
  LeftRearController.SetInverted(true); 

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {

 
}

void Robot::TestPeriodic() {
  double X,Y,Z;
  double powLF,powLB,powRF,powRB;

  X = Robot::Driver.GetX(LEFT_HAND); 
  Y = Robot::Driver.GetY(LEFT_HAND);
  Z = Robot::Driver.GetX(RIGHT_HAND);

  powLF = Y + X + Z ;
  powLB = Y - X + Z ;
  powRF = Y - X - Z ;
  powRB = Y + X - Z ;

  if((abs(powLF)>1) || 
     (abs(powLB)>1) ||
     (abs(powRF)>1) ||
     (abs(powRB)>1))
  {
    double max;
    if (abs(powLF)> abs(powLB))
      max = abs(powLF);
    else
      max = abs(powLB);
    
    if (abs(powRF)> max)
      max = abs(powRF);
    if (abs(powRB)> max)
      max = abs(powRB);
    powLF /= max;
    powLB /= max;
    powRF /= max;
    powRB /= max;
  }



  LeftFrontController.Set(powLF);
  LeftRearController.Set(powLB);
  RightFrontController.Set(powRF);
  RightRearController.Set(powRB);

}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
