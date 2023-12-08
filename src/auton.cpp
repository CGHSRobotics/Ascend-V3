
#include "ace.h"

namespace ace::auton {

/* ========================================================================== */
/*                        Global Variables Definitions                        */
/* ========================================================================== */

int auton_selection_index = 0;
/* ========================================================================== */
/*                               Score Auton                                   */
/* ========================================================================== */
void score() {
  drive_chassis(60, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(90, ace::AUTON_TURN_SPEED, true);
  auton_intake_reverse(2000, ace::INTAKE_SPEED);
  turn_chassis(270, ace::AUTON_TURN_SPEED, true);
  drive_chassis(-50, ace::AUTON_DRIVE_SPEED, true);
}

/* ========================================================================== */
/*                               Contact Auton                                  */
/* ========================================================================== */
void contact() {
  drive_chassis(105, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(-90, ace::AUTON_TURN_SPEED, true);
  auton_intake_reverse(2000, ace::INTAKE_SPEED);
  turn_chassis(270, ace::AUTON_TURN_SPEED, true);
  drive_chassis(50, ace::AUTON_DRIVE_SPEED, true);
}

/* ========================================================================== */
/*                              Three Side Auton                              */
/* ========================================================================== */
void three_side() {
  // Dead
}

// ross is good

/* ========================================================================== */
/*                               Two Side Auton                               */
/* ========================================================================== */
void two_side() {
  // Dead
}

/* ========================================================================== */
/*                                   Skills                                   */
/* ========================================================================== */
void skills() {
  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(40, ace::AUTON_TURN_SPEED, true);

  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);

  drive_chassis(-35, ace::AUTON_DRIVE_SPEED, true);

  /* turn_chassis(95, ace::AUTON_TURN_SPEED, true);

   drive_chassis(10, ace::AUTON_DRIVE_SPEED, true); */

  turn_chassis(-65, ace::AUTON_TURN_SPEED, true);
  drive_chassis(6, ace::AUTON_DRIVE_SPEED, true);
  // 5
  /*
  launch_auton(ace::launch_speed);
  pros::delay(40000);
  ace::launcherMotor.move_voltage(0);
  ace::launcherMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  ace::launcherMotor.brake();
  */
  drive_chassis(-5, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(-190, ace::AUTON_TURN_SPEED, true);
  // 200

  ace::intakePneumatics.set_value(1);
  drive_chassis(40, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-220, ace::AUTON_TURN_SPEED, true);

  // launch_auton(ace::launch_speed);
  // pros::delay(125);
  ace::launcherMotor.move_voltage(0);
  ace::launcherMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  ace::launcherMotor.brake();

  ace::intakeMotorLeft.move_voltage(80 * 120);
  drive_chassis(125, ace::AUTON_DRIVE_SPEED, true);

  ace::intakePneumatics.set_value(0);

  turn_chassis(-270, ace::AUTON_TURN_SPEED, true);
  // ace::intakePneumatics.set_value(0);

  // 30
  drive_chassis(65, ace::AUTON_DRIVE_SPEED, true);
 
  turn_chassis(-300, ace::AUTON_TURN_SPEED, true);
  ace::intakeMotorLeft.move_voltage(0);
  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);
  drive_chassis(-30, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(-20, ace::AUTON_TURN_SPEED, true);
  drive_chassis(70, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(20, ace::AUTON_TURN_SPEED, true);
  drive_chassis(30, ace::AUTON_DRIVE_SPEED, true);

  turn_chassis(-310, ace::AUTON_TURN_SPEED, true);

  ace::flapPneumatics.set_value(1);
  turn_chassis(100, ace::AUTON_TURN_SPEED, true);
  drive_chassis(50, ace::AUTON_DRIVE_SPEED, true);

  /*
  turn_chassis(-90, ace::AUTON_TURN_SPEED, true);
  drive_chassis(10, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(90, ace::AUTON_TURN_SPEED, true);
  drive_chassis(20, ace::AUTON_DRIVE_SPEED, true);
  */
}

/* ========================================================================== */
/*                         Auton Function Definitions                         */
/* ========================================================================== */

/* ------------------------------ Auton Page Up ----------------------------- */
void auton_page_up() {
  auton_selection_index += 1;
  if (auton_selection_index > auton_selection.size() - 1) {
    auton_selection_index = 0;
  }
}

/* ----------------------------- Auton Page Down ---------------------------- */
void auton_page_down() {
  auton_selection_index -= 1;
  if (auton_selection_index < 0) {
  }
  auton_selection_index = auton_selection.size() - 1;
}

/* ------------------------------ Roller Auton ------------------------------ */
/*
void roller_auton(float rollerDegrees) {

  float actual_degrees = rollerDegrees * 3.0;
  //Untested, previously only for 1 motor
  intakeMotorLeft.move_relative(actual_degrees, 100);
  intakeMotorRight.move_relative(actual_degrees, 100);
  while (intakeMotorLeft.is_stopped() == 0)
  {
    pros::delay(ez::util::DELAY_TIME);
  }
}
*/

/* --------------------------- Drive Chassis Auton -------------------------- */
void drive_chassis(float distance, float speed, bool wait) {
  bool slew_enabled = distance >= 14;
  chassis.set_drive_pid(distance, speed, slew_enabled);
  if (wait) {
    chassis.wait_drive();
  }
}

/* --------------------------- Turn Chassis Auton --------------------------- */
void turn_chassis(float angle, float speed, bool wait) {
  chassis.set_turn_pid(angle, speed);
  if (wait) {
    chassis.wait_drive();
  }
}

/* ------------------------------ Launch Auton ------------------------------ */

void launch_auton(float speed) {
  ace::launch(speed);
}

/* ------------------------------ Endgame Auton ----------------------------- */
void endgame_auton() {
}

void auton_intake_reverse(float time, float speed) {
  ace::intakeMotorLeft.spin_percent(speed);
  pros::delay(time);
  ace::intakeMotorLeft.spin_percent(0);
}
}  // namespace ace::auton