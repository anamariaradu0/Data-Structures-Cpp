// Copyright 2019 Ana-Maria Radu, 314CA
// Racer.h
// Purpose: defining a Racer-type object

#ifndef RACER_H_
#define RACER_H_

class Racer {
	int id;
	int current_race_time;
	int total_points;
	int current_level;
	int previous_level;

 public:
	// Constructor
	Racer() {
		id = 0;
		current_race_time = 0;
		total_points = 0;
		current_level = 0;
		previous_level = 0;
	}

	// Getters and setters
	int get_id() const{
		return id;
	}

	void set_id(int id) {
		this->id = id;
	}

	int get_current_race_time() const{
		return current_race_time;
	}

	void set_current_race_time(int time) {
		this->current_race_time = time;
	}

	int get_total_points() const{
		return total_points;
	}

	void set_total_points(int points) {
		this->total_points += points;
	}

	int get_current_level() const{
		return current_level;
	}

	void set_current_level(int level) {
		current_level = level;
	}

	int get_previous_level() const{
		return previous_level;
	}

	void set_previous_level(int previous_level) {
		this->previous_level = previous_level;
	}

	// Operator overloaded for SkipList use
	bool operator>=(Racer &other) {
		if (total_points >= other.total_points) {
			return true;
		}

		return false;
	}

	// Operator overloaded for std::sort use
	bool operator<(Racer &other) {
		if (this->total_points == other.total_points) {
			return this->id < other.id;

		} else if (this->total_points > other.total_points) {
			return true;
		}

		return false;
	}
};

#endif  // RACER_H_
