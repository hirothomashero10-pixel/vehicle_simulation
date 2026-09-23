#include "vehicle.hpp"
#include <cmath>    // std::cos() std::sin()が使えるようになる

Vehicle::Vehicle(
    double initial_x,
        double initial_y,
        double initial_speed,
        double initial_heading)
    : state_{initial_x, initial_y, initial_speed, initial_heading}
    {

    }

void Vehicle::update(const SimulationConfig& config)
{
    update_position(config.dt);

    update_speed(
        config.acceleration,
        config.dt,
        config.speed_limit
    );

    update_heading(
        config.yaw_rate,
        config.dt
    );
}

const VehicleState& Vehicle::get_state() const
{
    return state_;
}

void Vehicle::update_position(double dt)
{
    state_.x =
        state_.x + state_.speed * std::cos(state_.heading) * dt;

    state_.y =
        state_.y + state_.speed * std::sin(state_.heading) * dt;
}

void Vehicle::update_speed(
        double acceleration,
        double dt,
        double speed_limit)
{
        state_.speed = state_.speed + acceleration * dt;

    if (state_.speed > speed_limit)
    {
        state_.speed = speed_limit;
    }

}

void Vehicle::update_heading(
        double yaw_rate,
        double dt)
{
    state_.heading = state_.heading + yaw_rate * dt;
}