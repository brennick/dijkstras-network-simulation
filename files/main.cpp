#include <iostream>
#include <string>
#include <fstream>

#include "Network.h"

using namespace std;

int main(void)
{
	Network network;
	string line;
	ifstream input_file;
	int start_id = 0, end_id = 0;

	cout << "Enter graph file: ";
	getline(cin, line);
	input_file.open(line);
	network.createGraph(input_file);
	cout << "Enter a starting vertex: ";
	getline(cin, line);
	start_id = stoi(line);
	cout << "Enter a destination vertex: ";
	getline(cin, line);
	end_id = stoi(line);
	cout << "Enter a message to transmit: ";
	getline(cin, line);
	network.addMessage(line, start_id, end_id);
	while (network.isRunning() == true)
	{
		network.tick();
	}
	network.displayResults();
}