// #include <iostream>
// #include <boost/thread/thread.hpp>
// #include <boost/config.hpp>

// using namespace std;
// using boost::thread;
// using boost::mutex;

//  mutex a;
 

// const int THREAD_COUNT = 10;

// void worker(int i) {
//     a.lock();
//     cout << "Worker thread " << i << endl;

//     a.unlock();
// }

// int main(int argc, char** argv)
// {
//     thread *threads[THREAD_COUNT];

//     // Creation
//     for(int i = 0; i < THREAD_COUNT; i++) {
//         threads[i] = new thread(worker, i);
//     }

//     // Cleanup
//     for(int i = 0; i < THREAD_COUNT; i++) {
//         threads[i]->join();
//         delete threads[i];
//     }

//     return 0;
// }

#include <iostream>
#include <thread>
#include <mutex>
#include <random>
using namespace std::chrono_literals;

const int LINE_LEN = 80;

// Evil globals
bool running = false;
std::mutex ConsoleLock;

// This is untested on Linux but should work
#ifdef __linux__ 
void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}
#define clear() printf("\033[H\033[J")

#elif _WIN32
#include <Windows.h>
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}
#define clear() system("cls");
#else
// Put your own console gotoxy() and clear() definitions here
#endif

std::string MakeBar(int value)
{
	std::string bar(value, 219);
	return bar;
}

std::string MakeBlankLine()
{
	std::string bar(LINE_LEN, ' ');
	return bar;
}

void DrawGraph(int line, int i, bool down)
{
	ConsoleLock.lock();
	// Only need to erase a line if we're making it shorter
	if(down)
	{
		gotoxy(1, line);
		std::cout << MakeBlankLine();
	}
	gotoxy(1, line);
	std::cout << MakeBar(i);
	ConsoleLock.unlock();
}

void DrawBar(int line, int speed)
{
	// Wait for the green flag so we all start at the same time
	while (!running)
		;
	while(running)
	{
		for (int i = 1; i < LINE_LEN; i++)
		{
			DrawGraph(line, i, false);
			std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		}
		for (int i = LINE_LEN-1; i > 0; i--)
		{
			DrawGraph(line, i, true);
			std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		}
	}
}

int main()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(10, 100);

	// Spawn the threads
	std::thread t1(DrawBar, 1, distr(eng));
	std::thread t2(DrawBar, 2, distr(eng));
	std::thread t3(DrawBar, 3, distr(eng));
	std::thread t4(DrawBar, 4, distr(eng));
	std::thread t5(DrawBar, 5, distr(eng));
	std::thread t6(DrawBar, 6, distr(eng));
	std::thread t7(DrawBar, 7, distr(eng));
	std::thread t8(DrawBar, 8, distr(eng));
	std::thread t9(DrawBar, 9, distr(eng));
	std::thread t10(DrawBar, 10, distr(eng));
	std::thread t11(DrawBar, 11, distr(eng));
	std::thread t12(DrawBar, 12, distr(eng));
	std::thread t13(DrawBar, 13, distr(eng));
	std::thread t14(DrawBar, 14, distr(eng));
	std::thread t15(DrawBar, 15, distr(eng));
	std::thread t16(DrawBar, 16, distr(eng));
	std::thread t17(DrawBar, 17, distr(eng));
	std::thread t18(DrawBar, 18, distr(eng));
	std::thread t19(DrawBar, 19, distr(eng));
	std::thread t20(DrawBar, 20, distr(eng));
	std::thread t21(DrawBar, 21, distr(eng));

	// Go!
	running = true;

	// Let them run for a while
	std::this_thread::sleep_for(10s);
	
	// Tell them to stop
	running = false;

	// Wait for them all to finixh
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();
	t12.join();
	t13.join();
	t14.join();
	t15.join();
	t16.join();
	t17.join();
	t18.join();
	t19.join();
	t20.join();
	t21.join();
	clear();
	return 0;
}