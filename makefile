all:
	g++ phone_directory.cpp -o phone_directory.out
	./phone_directory.out test_input.txt
