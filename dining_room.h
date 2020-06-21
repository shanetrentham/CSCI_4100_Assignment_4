// CSCI 4100
// Programming Assignment 4
// Header file for Dining Philosophers simulation

#ifndef __DINING_ROOM_H__
#define __DINING_ROOM_H__

#define MAX_PHILS 20

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>

enum p_state {THINKING, HUNGRY, EATING};

struct dining_room;

// Structure used to pass arguments to start_philosopher function
struct p_args {
  int phil_num;
  int num_cycles;
  struct dining_room *room;
};

// The dining_room struct acts as a monitor for the simulation
struct dining_room
{
  int num_phils;
  int num_cycles;
  pthread_mutex_t table_lock;
  enum p_state phil_state[MAX_PHILS];
  pthread_cond_t safe_to_eat[MAX_PHILS];
  pthread_t phil_threads[MAX_PHILS];
  struct p_args phil_args[MAX_PHILS];
};

// Tests to see if it is safe for the philosopher with the ID provided to eat
// If it is safe, it changes the philosopher's state to EATING and returns
// true, if not it returns false.
// This function must only be called after table_lock has been acquired
int test_phil(struct dining_room *room,  int phil);

// Starts a dining philosopher simulation
void run_simulation(struct dining_room *room);

// Simulates a philosopher picking up forks
void grab_forks(struct dining_room *room, int phil);

// Simulates a philosopher putting down forks
void release_forks(struct dining_room *room, int phil );

// Displays the headings for the state change table
void display_headings(struct dining_room *room);

// Displays the current state of all philosophers.
// This should only be called if table_lock has been acquired
void display_states(struct dining_room *room);

// Gets the ID of the left neighbor of phil
int left_neighbor(struct dining_room *room, int phil );

// Gets the ID of the right neighbor of phil
int right_neighbor(struct dining_room *room, int phil );

// Simulates a philosopher thinking
void think( );

// Simulates a philosopher eating
void eat( );

// Code for a philosopher thread to run.
// This function should be used when creating a new philosopher thread
void *start_philosopher( void *the_args );

// Initializes a dining_room structure
// num_phils is the number of philosophers
// num_cycles is the number of times each philosopher tries to eat
void init_dining_room(struct dining_room *room, int num_phils, int num_cycles );

#endif
