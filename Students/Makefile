CC = clang++
CFLAGS = -O0
Students: Benchmark Choices PrintResults Random ReadData Student
	$(CC) -std=c++17 -o Students $(CFLAGS) Main.cpp Benchmark.o Choices.o PrintResults.o Random.o ReadData.o Student.o
Benchmark:
	$(CC) -std=c++17 -c $(CFLAGS) Benchmark.cpp
Choices:
	$(CC) -std=c++17 -c $(CFLAGS) Choices.cpp
PrintResults:
	$(CC) -std=c++17 -c $(CFLAGS) PrintResults.cpp
Random:
	$(CC) -std=c++17 -c $(CFLAGS) Random.cpp
ReadData:
	$(CC) -std=c++17 -c $(CFLAGS) ReadData.cpp
Student:
	$(CC) -std=c++17 -c $(CFLAGS) Student.cpp
Tests: Benchmark Student PrintResults Random
	$(CC) -std=c++17 -o Tests Tests.cpp Benchmark.o Student.o PrintResults.o Random.o
test: Tests 
	./Tests
clean:
	rm *.o Students