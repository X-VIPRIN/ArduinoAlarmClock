/*
* Colton Paul Badock; October, 2024;
* A alarm clock system for controlling a alarm clock; No copyright, do whatever you want, just leave credit!
*/

#include <LiquidCrystal.h>

//Parameters: RS, E, DB4, DB5, DB6, DB7
LiquidCrystal LCD(2, 3, 4, 5, 6, 7); //LCD Screen; Controlled by LiquadCrystal.h

//Execute first (main)
void setup() {
  initSetup(); //Setup the clock and show a intro message.
  
}

//Setup the clock on power on. Wait; Displays a message showing the clock is loading.
void initSetup() {
  //Bootup loop; The clock boots up and intializes components/systems whilst showing a loading screen controlled in this loop.
  for (int i = 0; i < 20; i++) {
    if (i == 0) {
      LCD.begin(16, 2); //Start LCD screen via Liquad Crystal Library. The LCD can now recieve data via this instance.

      LCD.print("Welcome!");
      LCD.setCursor(0, 1);
      LCD.print("LOADING...");
    }

    runLoadingAnimation(i); //Run the loading animation.

    //Remove the loading animation entirely once we reach iteration 20 of the For loop.
    if (i == 19) {
      killLoadingAnimation();
    }

    delay(250); //Delay the boot up (250milliseconds * 20interations) so the loading screen can play and the clock can intialize/setup systems throughout said interations.
  }

  completeSetup(); //End the setup; Remove the loading screen and animation entirely.

}


//Ends the setup, and clears the LCD screen.
void completeSetup() {
  LCD.clear();
}


//Gets rid of the loading animation; Removes all zeros from the left side of the LCD.
void killLoadingAnimation() {
  //Basically, clear the animation for the next animation frame, controlled by loop "dgieiud7"
  LCD.setCursor(14, 0);
  LCD.print("  ");
  LCD.setCursor(14, 1);
  LCD.print("  ");
}

//Shows the loading animation in the left of the LCD; Depends on the 'i'/position of a for loop or while loop, which will determine the animations position.
void runLoadingAnimation(int pos) {
  
  //Clear last loading animation's "0".
  //Basically, clear the animation for the next animation frame, controlled by loop "dgieiud7"
  LCD.setCursor(14, 0);
  LCD.print("  ");
  LCD.setCursor(14, 1);
  LCD.print("  ");


  //"dgieiud7"
  //Based on "pos" which is the iteration of a loop (hopefully), determine where the next square in the loading animation should be.
  if (pos % 4 == 0) {
    LCD.setCursor(14, 0);
    LCD.print("0");
  } else if (pos % 4 == 1) {
    LCD.setCursor(15, 0);
    LCD.print("0");
  } else if (pos % 4 == 2) {
    LCD.setCursor(15, 1);
    LCD.print("0");
  } else if (pos % 4 == 3) {
    LCD.setCursor(14, 1);
    LCD.print("0");
  }
}


//Infite application loop.
void loop() {
  
}
