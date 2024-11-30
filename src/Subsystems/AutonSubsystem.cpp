// #include "AutonSubsystem.h"
// #include "Log.h"

// // Constructor
// AutonSubsystem::AutonSubsystem(DriveSubsystem& drive, ArmSubsystem& arm, 
//                                IntakeSubsystem& intake, OdometrySubsystem& odometry, 
//                                SensorSubsystem& sensor)
//     : driveSubsystem(drive), armSubsystem(arm), intakeSubsystem(intake), 
//       odometrySubsystem(odometry), sensorSubsystem(sensor) {}

// void AutonSubsystem::moveForward(double speed, double distance) {
//     Log::log("AutonSubsystem - Moving forward with speed: ", speed, " and distance: ", distance);
//     double initialDistance = odometrySubsystem.getXPosition();

//     while (odometrySubsystem.getXPosition() - initialDistance < distance) {
//         driveSubsystem.drive(speed, speed);
//         vex::task::sleep(20);
//     }

//     driveSubsystem.stop();
//     Log::log("AutonSubsystem - Reached target distance.");
// }


// void AutonSubsystem::turnToAngle(double angle) {
//     Log::log("AutonSubsystem - Turning to angle: ", angle);
//     double currentHeading = odometrySubsystem.getHeading();

//     while (abs(currentHeading - angle) > 5.0) {  //tolerance
//         double turnSpeed = (angle - currentHeading) * 0.5;
//         driveSubsystem.drive(-turnSpeed, turnSpeed);
//         currentHeading = odometrySubsystem.getHeading();
//         vex::task::sleep(20);
//     }

//     driveSubsystem.stop();
//     Log::log("AutonSubsystem - Reached target angle.");
// }

// void AutonSubsystem::alignToVisionTarget() {
//     Log::log("AutonSubsystem - Aligning to vision target.");
//     int objectCenterX = sensorSubsystem.getVisionObjectX();
//     const int screenCenterX = 69;

//     while (abs(objectCenterX - screenCenterX) > 10) {  // tolerance 
//         double turnSpeed = (objectCenterX - screenCenterX) * 0.3;  // control 
//         driveSubsystem.drive(-turnSpeed, turnSpeed);
//         objectCenterX = sensorSubsystem.getVisionObjectX();
//         vex::task::sleep(20);
//     }

//     driveSubsystem.stop();
//     Log::log("AutonSubsystem - Aligned to vision target.");
// }

// void AutonSubsystem::stopAtDistance(double targetDistance) {
//     Log::log("AutonSubsystem - Stopping at distance: ", targetDistance);
//     while (sensorSubsystem.getDistance() > targetDistance) {
//         driveSubsystem.drive(30, 30);
//         vex::task::sleep(20);
//     }
//     driveSubsystem.stop();
//     Log::log("AutonSubsystem - Stopped at target distance.");
// }

// void AutonSubsystem::placeRingInHighGoal() {
//     Log::log("AutonSubsystem - Placing ring in high goal.");
//     armSubsystem.lift();
//     vex::task::sleep(1000);
//     intakeSubsystem.reverseIntake(50);
//     vex::task::sleep(500);
//     intakeSubsystem.stop();
//     armSubsystem.lower();
//     Log::log("AutonSubsystem - Ring placed in high goal.");
// }

// void AutonSubsystem::pickUpRing() {
//     Log::log("AutonSubsystem - Picking up ring.");
//     intakeSubsystem.intake(50);
//     vex::task::sleep(1000);
//     intakeSubsystem.stop();
//     Log::log("AutonSubsystem - Ring picked up.");
// }


// // random ass autonomous routines
// void AutonSubsystem::autonomousRoutine1() {
//     Log::log("AutonSubsystem - Starting autonomous routine 1.");
//     moveForward(50, 36);
//     alignToVisionTarget();
//     pickUpRing();
//     placeRingInHighGoal();
//     stopAtDistance(10); 
//     Log::log("AutonSubsystem - Finished autonomous routine 1.");
// }

// void AutonSubsystem::autonomousRoutine2() {
//     Log::log("AutonSubsystem - Starting autonomous routine 2.");
//     turnToAngle(45);
//     alignToVisionTarget();
//     pickUpRing();
//     climbPlatform();
//     Log::log("AutonSubsystem - Finished autonomous routine 2.");
// }
