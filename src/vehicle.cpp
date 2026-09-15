#include "vehicle.hpp"

Vehicle::Vehicle(
    double initial_position,
    double initial_velocity)
    : state_{initial_position, initial_velocity}
    {

    }

void Vehicle::update(const SimulationConfig& config)
{
    update_position(config.dt);

    update_velocity(
        config.acceleration,
        config.dt,
        config.speed_limit
    );
}

const VehicleState& Vehicle::get_state() const
{
    return state_;
}

void Vehicle::update_position(double dt)
{
    state_.position = state_.position + state_.velocity * dt;
}

void Vehicle::update_velocity(
        double acceleration,
        double dt,
        double speed_limit)
{
        state_.velocity = state_.velocity + acceleration * dt;

    if (state_.velocity > speed_limit)
    {
        state_.velocity = speed_limit;
    }

}