// Copyright 2019 Ana-Maria Radu, 314CA
// main.cpp
// Purpose: computing and managing a scoreboard by using a SkipList for
// sorting the expected output

#include <iostream>
#include <random>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <string>
#include "Racer.h"
#include "SkipList.h"
#include "TimeInfo.h"
#include "Functions.h"

int main() {
	int num_of_racers, num_of_races, num_of_prints;

	std::ifstream in;
    std::ofstream out;
    in.open("races.in", std::ifstream::in);
    out.open("races.out", std::ifstream::out);

    in >> num_of_racers >> num_of_races >> num_of_prints;

    Racer *racers_array = new Racer[num_of_racers + 1];
    Racer *printed_racers = new Racer[num_of_racers + 1];
    SkipList<TimeInfo> timeboard(get_logarithm(num_of_racers));

    // Each i-th member of the racers_array has an ID of i and a current
    // level of 0.
    initialize_racers_array(racers_array, num_of_racers);

    std::string check;
    int time;

    // Gradually receiving the input
    for (int i = 0; i < num_of_races + num_of_prints + 1; ++i) {
        // For each iteration, the printed_racers array is generated by copying
        // contents from racers_array, sorting by total points and setting the
        // current level for each racer.
        initialize_printed_racers(racers_array, printed_racers, num_of_racers);

    	std::getline(in, check);

    	if (check == "print") {
            print_updated_scoreboard(racers_array, printed_racers,
                num_of_racers, out);
    	} else {
            // Making room for a new timeboard
            timeboard.skip_delete();

    		int current_racers = 0;

            // Getting integers from the 'check' string, counting the racers
            // that participate in the current race and adding them to the
            // timeboard.
    		char *c = strdup(check.c_str());
    		char *save_ptr;
    		char *check2 = strtok_r(c, " ", &save_ptr);
    		int j = 0;
    		while(check2 != nullptr) {
    			time = atoi(check2);
    			if (time != 0) {
    				++current_racers;
                    timeboard.skip_insert(TimeInfo(j + 1,
                    	time, racers_array[j + 1].get_current_level()));
    			}

    			++j;

    			check2 = strtok_r(nullptr, " ", &save_ptr);
    		}

    		free(c);

            // Giving points to the racers in the timeboard SkipList
    		int points = current_racers / 2;
            int position = 1;

            Node<TimeInfo>* h = timeboard.get_first_element();

            while (points > 0) {
                racers_array[h->data.get_id()].set_total_points(points);
                ++position;
                --points;
                h = h->next;
            }

            if (current_racers % 2 == 0) {
                --points;
            }

            while (h != nullptr) {
                racers_array[h->data.get_id()].set_total_points(points);
                ++position;
                --points;
                h = h->next;
            }
    	}
    }

    // Freeing used memory, closing used files
    delete[] racers_array;
    delete[] printed_racers;
    in.close();
    out.close();

    return 0;
}
