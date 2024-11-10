# Advanced Algorithms

The goal in the bin packing problem is to pack objects of various sizes into bins of fixed capacity in such a way that the total number of bins used in minimized. Each bins has a fixed capacity and no bin can contain objects whose size exceeds the bin's capacity.

The algorithms implemented to solve this problem:
- First Fit Decreasing
- Best Fit Decreasing

Please view the report for more information on the problem and the solutions.

## Pre-requisites

- Make
- G++

If on Mac, these will be already installed if the Xcode Command Line tools are installed. If not done already, open the terminal and run `xcode-select --install`

If on Windows, it is recommended to install [Windows Subsystem For Linux (WSL)](https://learn.microsoft.com/en-us/windows/wsl/install) as the Make file uses Unix-based terminal commands. Once WSL is installed, run the following to install the project dependencies:
1. `sudo apt update`
2. `sudo apt install make`
3. `sudo apt install g++`


## Running the test suite

1. Navigate to the project's root directory.
2. Run `make` to compile the test executable.
3. Run `./binPackingTest` to run the tests.

If any modifications are made to the project files, `make` will need to be re-run to recompile the test executable.

### Clean up

If necessary, run `make clean` to clean-up the test executable
