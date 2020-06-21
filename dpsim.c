// CSCI 4100
// Programming Assignment 4
// Main source file for Dining Philosophers simulation

#include "dining_room.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // Check to make sure there are two comand line arguments
  if( argc < 2 ) {
    fprintf(stderr, "Usage: dpsim num_phils num_cycles\n");
    exit(1);
  }

  // Convert the command line arguments to integers
  int num_phils = atoi(argv[1]);
  int num_cycles = atoi(argv[2]);

  // Create and initialize dining_room monitor structure
  struct dining_room room;
  init_dining_room(&room, num_phils, num_cycles);

  // Run the simulation
  run_simulation(&room);
  
  return 0;
}
