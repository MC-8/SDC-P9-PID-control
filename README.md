# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

In this project I implemented a PID controller to have the simulated car follow the track.
The PID controller aims to regulate the steering angle to reduce the cross track error to 0 (our control objective). In order to do that, it uses the cross track error in 3 ways to calculate the steering angle.

The proportional part acts proportionally to the cross track error, resulting in a large steering angle for large cross track error.

The integral part has an increasing effect on the steering angle as time goes by, and if the error is not reduced. In fact, integrating the cross track error over time yields an higher integral action, which forces the steering angle more and more if the proportional correciton is not sufficient. 
It is also a good way to remove systemic bias.

The derivative part can be used as a dampener, which reacts to sudden changes, it is useful to reduce oscillations and it is proportional to the derivative of the cross track error. It works against the sudden changes introduced by the proportional component to smooth the controller response. It should be used with caution, especially when the data input the PID controller is noisy, as the derivative of noisy/irregular signals can quickly skyrocket.

I tuned the 3 coefficients Kp, Ki, and Kd manually starting with a Kp value of 0.5 and Ki and Kp = 0.
Once I obtained the car following the track at a very low speed, I increased the throttle. At this point I tuned the Kp value so the car would oscillate many times before losing control (any value would not be enough to keep track). At this point I added a non-zero Kd component to dampen the oscillations, and repeat the Kp/Kd process until the car was able to follow the track. Even then, during longer turns, the car would tend to stay on the external side of the track, signaling  the need for a constant error.
Constant errors are very well tackled by introducing an integral component to the controller, which is what I did: I gradually increased Ki to obtain a satisfactory response.

This manual tuning worked well for the simple problem, but obviously there are many more techniques that can be used, like the ones menitoned during Udacity class "Twiddle", or the well known technique of Ziegler-Nichols, among many.

An idea to improve the controller would be to have a variable speed control depending on the curve (e.g. reduce speed while turning). And perhaps have a variable set of Kp, Ki, Kd parameters. As an example, at low speeds the integral action may grow quite a lot if the car starts far from the track, leading to actuator saturation and controller windup. Having the Ki parameter directly proportional to the speed could be an idea to investigate. Similarly Kp and Kd could be made speed or even track-curvature dependent, but these further experimentations are out of scope for this project.





---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

