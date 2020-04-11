#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayQueue.h"
#include "Customer.h"
#include "Teller.h"
using namespace std;

int main()
{
	Teller server;
	ArrayQueue <Customer> waitingLine;
	Customer temp;
	float prob;
	int totalWaitTime = 0;
	int numCustomers = 0;
	srand(time(NULL));

	for (int i = 1; i <= 100; i++)
	{
		prob = float(rand()) / float(RAND_MAX);
		if (prob <= .2)
		{
			temp.arrivalTime = i;
			waitingLine.enqueue(temp);
			numCustomers++;
		}
		if (server.isFree && !waitingLine.isEmpty())
		{
			temp = waitingLine.peekFront();
			temp.departureTime = i;
			waitingLine.dequeue();
			server.isFree = false;
			server.serviceTime = 6;
			totalWaitTime += (temp.departureTime - temp.arrivalTime);
		}
		else if (!server.isFree)
		{
			server.serviceTime--;
		}
		if (server.serviceTime == 0)
		{
			server.isFree = true;
		}
	}
	cout << "Average wait time is: " << totalWaitTime/numCustomers << " minutes" << endl;

	system("pause");
	return 0;
}