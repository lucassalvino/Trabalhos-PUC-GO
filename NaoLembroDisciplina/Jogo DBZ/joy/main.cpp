#include "joy.cpp"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

int main()
{
  // Create an instance of Joystick
  Joystick joystick("/dev/input/js1");
  Joystick joystick2("/dev/input/js2");

  // Ensure that it was found and that we can use it
  /*if (!joystick.isFound() || !joystick2.isFound())
  {
    printf("open failed.\n");
    exit(1);
  }*/

  while (true)
  {
    // Restrict rate
    usleep(1000);

    // Attempt to sample an event from the joystick
    JoystickEvent event;
    if (joystick.sample(&event))
    {
      if (event.isButton())
      {
        printf("play_1 %d \n",event.number);
      }
      else if (event.isAxis())
      {
        printf("Axis_1 → %d → %d\n", event.number, event.value);
      }

    }

    ///////////////
   // JoystickEvent event;
    if (joystick2.sample(&event))
    {
      if (event.isButton())
      {
        printf("Button play_2 %u is %s\n",
          event.number,
          event.value == 0 ? "up" : "down");
      }
      else if (event.isAxis())
      {
        printf("Axis %u is at position %d\n", event.number, event.value);
      }

    }
  }
}
