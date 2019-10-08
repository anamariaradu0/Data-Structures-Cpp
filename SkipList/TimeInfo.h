// Copyright 2019 Ana-Maria Radu, 314CA
// Timeinfo.h
// Purpose: defining a Timeinfo-type object to be used for sorting

#ifndef TIMEINFO_H_
#define TIMEINFO_H_

class TimeInfo {
    int id;
    int time;
    int last_position;
    int current_position;

 public:
    // Constructor
    TimeInfo() {
        id = 0;
        time = 0;
        last_position = 0;
        current_position = 0;
    }

    // Explicit constructor
    TimeInfo(int id, int time, int cur = 0) {
        this->id = id;
        this->time = time;
        this->current_position = cur;
    }

    // Getters and setters
    int get_id() {
        return id;
    }

    void set_id(int id) {
        this->id = id;
    }

    int get_time() {
        return time;
    }

    void set_time(int time) {
        this->time = time;
    }

    int get_last_position()
    {
        return this->last_position;
    }

    void set_last_position(int last_position) {
        this->last_position = last_position;
    }

    int get_current_position() {
        return current_position;
    }

    void set_current_position(int current_position) {
        this->current_position = current_position;
    }

    // Overloading
    bool operator>=(TimeInfo &other) {
        if (this->time > other.time) {
            return true;
        } else if (this->time == other.time) {
            if (this->current_position > other.current_position) {
                return true;
            }
        }

        return false;
    }
};

#endif  // TIMEINFO_H_
