# Vehicle simulation

A C++ project for learning vehicle dynamics and control.

## Current Features

- 2D vehicle motion simulation
- Acceleration and speed limit
- Heading update using steering angle and wheelbase
- Vehicle class for state management
- Simulation history using `std::vector<VehicleState>`
- CSV output
- SVG trajectory visualization
- CMake build system

## Project Structure

```text
vehicle_simulation/
├── CMakeLists.txt
├── README.md
├── include/
│   └── vehicle.hpp
└── src/
    ├── main.cpp
    └── vehicle.cpp
```

## Build

Requirements:

- CMake 3.16 or later
- C++20 compatible compiler

From the project root directory, run:

```bash
cmake -S . -B build
cmake --build build
```

The executable will be generated in the `build` directory.

## Run

After building the project, run the executable from the project root directory:

```bash
./build/vehicle_simulation_v28
```

The program will print the vehicle position and velocity at each simulation step.

## Output

The simulation prints the vehicle state at each time step:

```text
time = 0 s, x = 0 m, y = 0 m, speed = 0 m/s, heading = 0.785398 rad
time = 0.1 s, x = 0 m, y = 0 m, speed = 0.2 m/s, heading = 0.786201 rad
time = 0.2 s, x = 0.0141308 m, y = 0.0141535 m, speed = 0.4 m/s, heading = 0.787806 rad
```

The simulation results are also saved to:

```text
simulation_test.csv
```


The CSV file contains the following columns:

- `time`: simulation time [s]
- `x`: vehicle x position [m]
- `y`: vehicle y position [m]
- `speed`: vehicle speed [m/s]
- `heading`: vehicle heading [rad]



## Simulation Parameters

The current simulation uses:

- `acceleration`: 2.0 m/s²
- `dt`: 0.1 s
- `speed_limit`: 10.0 m/s
- `steering_angle`: 0.1 rad
- `wheelbase`: 2.5 m

### SVG Trajectory

The simulation also generates:

```text
trajectory.svg

## Roadmap

- [x] 1D vehicle motion simulation
- [x] Vehicle class and state management
- [x] CSV output
- [x] CMake build system
- [x] Git / GitHub setup
- [x] 2D vehicle motion model
- [x] Simulation history with `std::vector`
- [x] SVG trajectory visualization
- [ ] Kinematic bicycle model
- [ ] PID controller
- [ ] LQR controller
- [ ] Model Predictive Control (MPC)