# Monty Hall Problem Simulation

This program simulates the classic Monty Hall Problem, a famous probability brainteaser, to demonstrate the counterintuitive advantage of switching doors.

# Understanding the Problem

There are n doors, one of which conceals a prize, and after the contestant makes an initial choice, the host opens k doors, revealing non-prize doors, and the contestant then has the option to stick with their original choice or switch to another door.
The simulation should output the simulated probability of winning for both strategies: sticking with the initial choice and switching doors.

# Building and Running the Simulation

## Prerequisites:

- C++ compiler (e.g., GCC, Clang) - You can usually install them through your package manager or download from official websites.
- Basic knowledge of C++

## Instructions:

### Compile and Run:

Open a terminal or command prompt and navigate to the directory where you saved MontyHallProblem.cpp. Use a command like this to compile (replace g++ with your compiler if different):

```
g++ MontyHallProblem.cpp -o Monty_Hall_Problem  # Creates an executable named Monty_Hall_Problem
```

Then, run the program:

```
./monty_hall
```

### Customization (Optional):

- Modify *num_simulations* in the code to adjust the number of simulations.
- Explore advanced output formatting using libraries like iostream manipulators.
