#pragma once

struct VehicleState
{
    double x;
    double y;
    double speed;
    double heading;
};

struct SimulationConfig
{
    double acceleration;
    double dt;
    double speed_limit;
    double yaw_rate;
};

class Vehicle
{
public:
    Vehicle(
        double initial_x,
        double initial_y,
        double initial_speed,
        double initial_heading
    );

    void update(const SimulationConfig& config);

    const VehicleState& get_state() const;

private:
    VehicleState state_;

    void update_position(double dt);

    void update_speed(
        double acceleration,
        double dt,
        double speed_limit);

    void update_heading(
        double yaw_rate,
        double dt
    );
};