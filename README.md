# Rush01_4x4

# wrong number of arguments

	./rush-01 "4 3 2 1"
	./rush-01 "4 3 2 1 1 2 2 2 4 3 1 1 2 2 2 5"
	./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 5 3"

<bt>

# a wrong grid

	./rush-01 "4 +3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 5"

# invalid chars

	./rush-01 "4 -3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	./rush-01 "4 ; 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	./rush-01 "4 +3 2 1 1 2 2 2 4 3 2 1 1 2 2 12"
	./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 0"

# valid

Test (4x4) --> solved

	./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	./rush-01 "04 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
	./rush-01 "4 +3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

Solution (4x4) --> solved

	1 2 3 4
	2 3 4 1
	3 4 1 2
	4 1 2 3

	./rush-01 "2 2 1 2 2 3 4 1 2 2 1 2 2 3 4 1"

Solution (4x4)

	2 1 4 3
	1 4 3 2
	4 3 2 1
	3 2 1 4

Test (5x5) --> sovled

	./rush-01 "1 5 3 2 4 2 1 2 2 2 1 4 3 3 2 3 2 2 1 3"

solution

	5 1 3 4 2
	1 2 4 5 3
	2 3 5 1 4
	3 4 1 2 5
	4 5 2 3 1

Test (6x6) --> solved

	./rush-01 "2 1 3 3 3 2 1 3 2 2 2 4 2 5 3 3 3 1 3 1 2 2 3 4"

solution

	5 6 3 4 1 2
	2 3 4 1 5 6
	1 4 6 3 2 5
	3 2 1 5 6 4
	4 5 2 6 3 1
	6 1 5 2 4 3

Test (6x6) --> no solution found?

	./rush-01 "2 1 2 4 2 3 4 2 3 1 3 2 2 1 4 2 3 3 3 2 2 3 1 2"

	2 6 4 3 5 1
	6 1 2 4 3 5
	3 4 1 5 6 2
	5 2 6 1 4 3
	4 3 5 2 1 6
	1 5 3 6 2 4

Test (9x9) --> takes forever?

	./rush-01 "3 1 4 3 2 2 3 1 4 3 2 2 4 2 2 2 3 3 2 3 1 3 3 2 4 2 1 3"

	2 7 1 4 3 6 5
	6 5 4 1 7 3 2
	3 6 5 2 4 7 1
	1 4 7 6 5 2 3
	4 1 3 7 2 5 6
	5 2 6 3 1 4 7
	7 3 2 5 6 1 4

Test (9x9) --> takes forever?

	./rush-01 "2 4 4 3 3 2 2 2 1 3 2 2 4 4 2 1 3 3 6 1 2 4 3 4 2 2 3 1 4 2 2 3 2 2 3 2"

solution:

	1 3 5 2 4 6 8 7 9
	9 5 3 6 8 2 7 1 4
	8 4 7 9 2 1 3 5 6
	5 1 6 8 3 4 2 9 7
	4 8 1 7 9 3 5 6 2
	2 7 8 1 6 9 4 3 5
	6 9 2 3 7 5 1 4 8
	3 2 9 4 5 7 6 8 1
	7 6 4 5 1 8 9 2 3

How to run with visulizer:

	ARG="2 2 1 2 2 3 4 1 2 2 1 2 2 3 4 1" ; ./rush-01 $ARG | ../rush_01_checker_visualizer/./Checker_rush $ARG

	ARG="2 2 1 2 2 3 4 1 2 2 1 2 2 3 4 1" ; ./rush-01 $ARG | ../rush_01_checker_visualizer/./Checker_rush $ARG; ../rush_01_checker_visualizer/visualizer/./fdf output
