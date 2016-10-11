/*
 * Copyright (C) Shuo Li
 *
 * This file is part of paparazzi
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/command_level_iros/command_level_iros.h"
 * @author Shuo Li
 * This module is the highest level
 */
#include "state.h"

#ifndef COMMAND_LEVEL_IROS_H
#define COMMAND_LEVEL_IROS_H

#ifndef CONSTANT_VELOCITY_STRAIGHT
#define CONSTANT_VELOCITY_STRAIGHT 0.8
#endif

#ifndef NUMBER_OF_GATES
#define NUMBER_OF_GATES 6               //second part
#endif

#ifndef ANGLE_AFTER_HALF_GATE
#define ANGLE_AFTER_HALF_GATE 100.0/180.0*PI     //degree
#endif

#ifndef VELOCITY_IN_FIRST_PART
#define VELOCITY_IN_FIRST_PART 0.5
#endif




#ifndef HOVER_TIME
#define HOVER_TIME 2
#endif

#ifndef NUMBER_OF_ZIGZAG
#define NUMBER_OF_ZIGZAG 5
#endif

#ifndef STRAIGHT_TIME
#define STRAIGHT_TIME 11.2
#endif

#ifndef TAKE_OFF_ALTITUDE
#define TAKE_OFF_ALTITUDE -2
#endif

#ifndef APPROACH_TIME
#define APPROACH_TIME 3
#endif

#ifndef PREPARE_TIME
#define PREPARE_TIME 3
#endif

extern void command_run(void);  // 20HZ
extern void command_init(void);

enum states_lower_level{WAIT_FOR_DETECTION_CM,ADJUST_POSITION_CM,GO_THROUGH_CM,HOVER_CM,
TURN_CM,SEARCH_GATE_CM,TAKE_OFF_OPEN_LOOP_CM,TAKE_OFF_CLOSE_LOOP_CM,LAND_CM,GO_STRAIGHT_CM,ADJUST_HEIGHT_CM,PREPARE_CM,
    REPLAY_CM,APPROACH_GATE_CM};

enum states_upper_level{FIRST_PART,SECOND_PART,THIRD_PART,FOURTH_PART};

struct parameters_to_be_tuned{
    float heading_after_gate[NUMBER_OF_GATES];
    float distance_after_gate[NUMBER_OF_GATES];
    float height_after_gate[NUMBER_OF_GATES];
    float approach_after_gate[NUMBER_OF_GATES];
    bool flag_zigzag[NUMBER_OF_ZIGZAG];
    float distance_after_zigzag[NUMBER_OF_ZIGZAG];
    float heading_after_zigzag[NUMBER_OF_ZIGZAG];
    int search_gate_velocity_in_zigzag[NUMBER_OF_ZIGZAG];
    float search_time_in_zigzag[NUMBER_OF_ZIGZAG];
};

extern enum states_lower_level state_lower_level;
extern enum states_upper_level state_upper_level;

extern struct parameters_to_be_tuned parameter_to_be_tuned;
extern uint8_t previous_lower_level;

#endif

