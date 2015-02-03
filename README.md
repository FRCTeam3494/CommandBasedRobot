# CommandBasedRobot
Command Based Programming NEW!!!!

Largely based off the template, this repo is for educational purposes.  
It will help understand how the code will flow:

Robot.cpp is minimalistic, and uses the Scheduler.

The Scheduler loop has five stages:
1. Poll the Buttons 
2. Execute/Remove the Commands 
3. Send values to SmartDashboard 
4. Add Commands 
5. Add Defaults 

A lot of functionality is encapsulated in Scheduler, Command, and CommandBase classes.  Which makes things a little confusing at first, but much cleaner when understood.
