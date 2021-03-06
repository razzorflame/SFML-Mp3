#include "stdafx.h" // The PCH, optional

// Custom includes:
#include "MP3.hpp"

// Standard includes:
#include <iostream>		// for: logging.
#include <thread>		// for: sleep.
#include <chrono>		// for: time manipulation.
#include <string>		// for: string manipulation.

int main()
{
	std::string fileName;
	std::cout << "Enter MPEG file, you want to play:\n";
	std::getline(std::cin, fileName);

	sf::Mp3 mp3;
	if (!mp3.openFromFile(fileName))
	{
		std::cout << "Could not open MP3 file: \"" << fileName << "\".\nPress enter to continue..." << std::endl;
		std::cin.get();
		return 1;
	}

	mp3.play();

	std::clog << "Playing the music..." << std::flush;
	while (mp3.getStatus() != sf::Mp3::Stopped)
	{
		
		// Sleep one second to leave processing time to other threads...
		namespace chr = std::chrono;
		std::this_thread::sleep_for(chr::seconds{ 1 });
	}
}

