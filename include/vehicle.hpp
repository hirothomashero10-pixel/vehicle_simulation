#pragma once

struct VehicleState
{
    double position;
    double velocity;
};

struct SimulationConfig
{
    double acceleration;
    double dt;
    double speed_limit;
};

class Vehicle
{
public:
    Vehicle(double initial_position, double initial_velocity);

    void update(const SimulationConfig& config);

    const VehicleState& get_state() const;

private:
    VehicleState state_;

    void update_position(double dt);

    void update_velocity(
        double acceleration,
        double dt,
        double speed_limit);
};