// Copyright 2019 Ana-Maria Radu, 314CA
// Functions.h
// Purpose: implementing auxiliary functions used in main.cpp

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <algorithm>

// Function used to initialize the array of racers
void initialize_racers_array(Racer *racers_array, int num_of_racers) {
	for (int i = 1; i <= num_of_racers; i++) {
        racers_array[i].set_id(i);
        racers_array[i].set_current_level(0);
    }
}

// Function used to initialize the array of racers that will be printed
void initialize_printed_racers(Racer *racers_array, Racer *printed_racers,
	int num_of_racers) {
	for (int i = 1; i <= num_of_racers; i++) {
            printed_racers[i] = racers_array[i];
        }

    std::sort(printed_racers + 1, printed_racers + num_of_racers + 1);

    for (int i = 1; i <= num_of_racers; i++) {
        racers_array[printed_racers[i].get_id()].set_current_level(i);
    }
}

// Function used for printing the scoreboard
void print_updated_scoreboard(Racer *racers_array, Racer *printed_racers,
	int num_of_racers, std::ofstream &out) {
	for (int i = 1; i <= num_of_racers; i++) {
        out << printed_racers[i].get_id() << " " <<
        printed_racers[i].get_total_points() << " ";

        if (printed_racers[i].get_previous_level() == 0) {
            out << "0";
        } else {
            out << printed_racers[i].get_previous_level() - i;
        }

        out << std::endl;

    	racers_array[printed_racers[i].get_id()].set_previous_level(i);
    }

    out << std::endl;
}

// Function used for determining the base 2 logarithm of an integer; used to
// determine the maximum height of the SkipList
int get_logarithm(int number) {
	int power = 0;

	while(number >= 1) {
		number = number / 2;
		++power;
	}

	return power;
}

#endif  // FUNCTIONS_H_
