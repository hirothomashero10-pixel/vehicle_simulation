# Vehicle simulation

A C++ project for learning vehicle dynamics and control.

## Current Features

- 2D vehicle motion simulation
- Acceleration and speed limit
- Heading update using yaw rate
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
mkdir -p build
cd build
cmake ..
cmake --build .
```

The executable will be generated in the `build` directory.

## Run

After building the project, run the executable from the project root directory:

```bash
./build/vehicle_simulation_v23
```

The program will print the vehicle position and velocity at each simulation step.

## Output

The simulation prints the vehicle state at each time step:

```text
time = 0 s, position = 0 m, velocity = 0 m/s
time = 0.1 s, position = 0 m, velocity = 0.2 m/s
time = 0.2 s, position = 0.02 m, velocity = 0.4 m/s
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