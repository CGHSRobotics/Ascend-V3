
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
  // grab triball
  ace::intake_pneu_enabled = true;
  ace::intake_enabled = true;
  drive_chassis(4, ace::AUTON_DRIVE_SPEED, true);

  /*
  drive_chassis(22, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(-40, ace::AUTON_TURN_SPEED, true);
  drive_chassis(25, ace::AUTON_DRIVE_SPEED, true);
  */
}

/* ========================================================================== */
/*                               Contact Auton                                  */
/* ========================================================================== */
void contact() {
  // ace::reset_launcher(ace::launch_speed);
  launcherMotor.move_voltage(0);
  launcherMotor.set_brake_mode(MOTOR_BRAKE_HOLD);
  launcherMotor.brake();
  drive_chassis(22, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(40, ace::AUTON_TURN_SPEED, true);
  drive_chassis(23, ace::AUTON_DRIVE_SPEED, true);
  drive_chassis(-17, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(105, ace::AUTON_TURN_SPEED, true);
  ace::intake_toggle(true);
  ace::intakePneumatics.set_value(1);
  drive_chassis(45, ace::AUTON_DRIVE_SPEED, true);
  // 83
  turn_chassis(55, ace::AUTON_TURN_SPEED, true);
  drive_chassis(25, ace::AUTON_DRIVE_SPEED, true);
  drive_chassis(-10, ace::AUTON_DRIVE_SPEED, true);
  pros::delay(1000);
  turn_chassis(315, ace::AUTON_TURN_SPEED, true);
  drive_chassis(5, ace::AUTON_DRIVE_SPEED, true);
  ace::launch(ace::LAUNCH_SPEED);
  pros::delay(500);
  ace::launch(0);

  /*
  ace::launcherMotor.move_voltage(ace::LAUNCH_SPEED * -120);
  pros::delay(285);
  launcherMotor.move_voltage(0);
  turn_chassis(100, ace::AUTON_TURN_SPEED, true);
  // reset_launcher(ace::LAUNCH_SPEED);
  drive_chassis(25, ace::AUTON_DRIVE_SPEED, true);
  pros::delay(1000);
  drive_chassis(-10, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(315, ace::AUTON_TURN_SPEED, true);
  ace::launch(ace::LAUNCH_SPEED);
  pros::delay(500);
  ace::launch(0);
  ace::intake_toggle(false);
  */
  // drive_chassis(-5, ace::AUTON_DRIVE_SPEED, true);

  // turn_chassis(18, ace::AUTON_TURN_SPEED, true);
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
  drive_chassis(22, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(40, ace::AUTON_TURN_SPEED, true);
  drive_chassis(23, ace::AUTON_DRIVE_SPEED, true);
  drive_chassis(-22, ace::AUTON_DRIVE_SPEED, true);
  turn_chassis(290, ace::AUTON_TURN_SPEED, true);
  ace::launcherMotor.move_voltage(ace::LAUNCH_SPEED * -120);
  drive_chassis(8, ace::AUTON_DRIVE_SPEED, true);
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
void intake_pneu_auton() {
  ace::intake_pneu_enabled = !ace::intake_pneu_enabled;
}
}  // namespace ace::auton
   // namespace ace::auton