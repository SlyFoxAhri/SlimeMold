# Interactive Physarum / Slime Mold Simulation

inspired by:

>***[Jeff Jones, “Characteristics of Pattern Formation and Evolution in Approximations of Physarum Transport Networks” - Artificial life 16.2 (2010)](https://uwe-repository.worktribe.com/preview/980585/artl.2010.16.2.pdf)***
>
>The original model explores how Physarum-like agents can form efficient transport networks through simple rules involving movement, sensing, trail deposition, and trail evaporation.

This project allows to observe how simple agentic behaviours can produce complex, adaptive network-like structures, it extends the basic Physarum simulation with interactive controls and configurable environmental constraints.


## Overview

The simulation consists of a collection of agents moving through a 2D environment.\
Each agent follows a simple process:

1. Sense the trail of chemical field around its current position.
2. Compare the trail strength at different sensor locations.
3. Rotate toward the strongest detected signal.
4. Move forward through the environment.
5. Deposit a trail of chemical signal.

## Parameters by user input

**Environment**

- Number of agents
- Trail evaporation rate
- Trail diffusion rate
- Environment boundaries
- Trail intensity
- Reset the environment
- Clear the trail field

**Agent**

- Agent movement speed
- Sensor distance
- Sensor angle
- Sensor size
- Turning speed
- Trail deposition amount
- Agent size
- Random movement or directional noise

**COMING SOON \
(Interactive Objects)**

- Place obstacles in the environment
- Remove obstacles
- Add food sources
- Remove food sources

## Controls

`Space` - Pause or resume the simulation \
`R` - Reset the simulation \
`C` - Clear the trail field \
`X` - Show/hide UI \
`Esc` - Exit the application 


## Installing

>**The project was only tested on linux and still under development, there is no guarantee that is works on other systems**

**Requirements:**
- C++17 compatible compiler
- [raylib](https://www.raylib.com/)


**Install raylib**

Ubuntu/Debian:

```bash
sudo apt update
sudo apt install libraylib-dev
```

**Clone the Repository**

```bash
git clone https://github.com/SlyFoxAhri/SlimeMold.git
cd SlimeMold
```

**Build & run**

```bash
./build run
```
## COMING SOON
- Food and obstacle drawing and shapes
- Adjustable window size

## Future Improvements

- More accurate implementations of Physarum transport equations
- Multiple types of food sources
- Weighted or directional grid setting
- Saving and loading simulation configurations
- Exporting generated networks as images or graphs
- GPU-accelerated trail processing
- Additional agent behaviour


## License

This project is licensed under the ?? License. See the `LICENSE` file for more information.
