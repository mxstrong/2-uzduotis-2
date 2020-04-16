CC = clang++
CFLAGS = -O1
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
clean:
	rm *.o Students