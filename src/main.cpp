#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numbers>

#include "vehicle.hpp"

struct SimulationHistory
{
    std::vector<double> time;
    std::vector<VehicleState> states;
};

void print_state(
    const VehicleState& state,
    double time)
{
    std::cout
        << "time = " << time
        << " s, x = " << state.x
        << " m, y = " << state.y
        << " m, speed = " << state.speed
        << " m/s, heading = " << state.heading
        << " rad"
        << std::endl;
}

void save_csv(
    const std::string& filename,
    const SimulationHistory& history)
{
    std::ofstream file(filename);

    file << "time,x,y,speed,heading" << std::endl;

    for (std::size_t i = 0; i < history.time.size(); i++)
    {
        file
            << history.time[i] << ","
            << history.states[i].x << ","
            << history.states[i].y << ","
            << history.states[i].speed << ","
            << history.states[i].heading
            << std::endl;
    }

    file.close();
}

void save_svg(
    const std::string& filename,
    const SimulationHistory& history)
{
    std::ofstream file(filename);

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\""
         << " width=\"800\" height=\"600\">"
         << std::endl;

    const double scale = 8.0;
    const double origin_x = 400.0;
    const double origin_y = 550.0;

    //polyline の開始
    file << "<polyline points=\"";

    // 座標を全部追加
    for (std::size_t i = 0; i < history.states.size(); i++)
    {
        double svg_x = origin_x + history.states[i].x * scale;
        double svg_y = origin_y - history.states[i].y * scale;

        file << svg_x << "," << svg_y << " ";
    }

    //polyline の終了
    file << "\" fill=\"none\" stroke=\"white\" stroke-width=\"2\" />"
         << std::endl;

    file << "</svg>" << std::endl;

    file.close();

}

int main()
{
    const SimulationConfig config{
        2.0,        // acceleration [m/s^2]
        0.1,        // dt [s]
        10.0,       //speed_limit [m/s]
        0.1,        // steering_angle [rad]
        2.5         // wheelbase [m]
    };

    Vehicle car(
        0.0,    // initial_x
        0.0,    // initial_y
        0.0,    // initial_speed
        std::numbers::pi / 4.0     // initial_heading
    );

    SimulationHistory history;

    for (double time = 0.0; time <= 10.0; time += config.dt)
    {
        const VehicleState& state = car.get_state();

        print_state(
            state,
            time
        );

        history.time.push_back(time);
        history.states.push_back(state);
            
        car.update(config);
    
    }

    const std::string filename = "simulation_test.csv";

    save_csv(
        filename,
        history
    );

    const std::string svg_filename = "trajectory.svg";

    save_svg(
        svg_filename,
        history
    );

    return 0;

}