// included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

int main()
{

	//-----------------------------------------------------------------------------------
	// Game Setup
	// ----------------------------------------------------------------------------------

	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);

	//-----------------------------------------------------------------------------------
	// Game Loop
	//-----------------------------------------------------------------------------------
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{

		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);


		// Display the window contents on the screen
		gameWindow.display();


	} // Close Game While Loop

	
	// Exit Point of program
	return 0;

} // End of Main function
