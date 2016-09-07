## CPP-Final
This was my final for my Data Structures course in college. It emulates the fabled race of

the tortoise and the hare. They race from left to right. The Hare is represented by "H", while the tortoise
is represented by "T". If they move to the same tile, "BUMP!" is printed.


The tortoise and the hare make moves with different random probabilities. The moves are summed up here:

### Tortoise

Fast Plod (3 forward): 50% probability

Slip (6 backward): 20% probability

Slow Plod (1 forward): 30% probability

### Hare

Sleep (no change): 20%

Big Hop (9 forward): 20%

Big Slip (12 backward): 10%

Small Hop (1 forward): 30%

Small Slip (2 forward): 20%

A visualization of the race is made by printing a line representing their positions after each move.
