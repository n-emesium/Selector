# Randomizer Tools

A collection of C and C++ utilities for randomly selecting, pairing, and grouping items.

## Compilation

Run make to compile all executables (picker, pair, grouper).
Run make clean to remove object files and binaries.

## Executables

### 1. picker (C)
Generates randomly partitioned groups of numbers.
**Usage:** ./picker <pool_size> <group_size>
**Example:**
bash
./picker 20 30
./picker 5 2
