#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "vehicle.hpp"

struct SimulationHistory
{
    std::vector<double> time;
    std::vector<double> position;
    std::vector<double> velocity;
};

void print_state(
    const VehicleState& state,
    double time)
{
    std::cout
        << "time = " << time
        << " s, position = " << state.position
        << " m, velocity = " << state.velocity
        << " m/s"
        << std::endl;
}

void save_csv(
    const std::string& filename,
    const SimulationHistory& history)
{
    std::ofstream file(filename);

    file << "time,position,velocity" << std::endl;

    for (std::size_t i = 0; i < history.time.size(); i++)
    {
        file
            << history.time[i] << ","
            << history.position[i] << ","
            << history.velocity[i] 
            << std::endl;
    }

    file.close();
}

int main()
{
    const SimulationConfig config{
        2.0,
        0.1,
        10.0
    };

    Vehicle car(0.0, 0.0);

    SimulationHistory history;

    for (double time = 0.0; time <= 10.0; time += config.dt)
    {
        const VehicleState& state = car.get_state();

        print_state(
            state,
            time
        );

        history.time.push_back(time);
        history.position.push_back(state.position);
        history.velocity.push_back(state.velocity);
            
        car.update(config);
    
    }

    const std::string filename = "simulation_test.csv";

    save_csv(
        filename,
        history
    );

    return 0;

}