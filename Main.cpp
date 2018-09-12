// included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
// End Libraries


int main()
{

	//-----------------------------------------------------------------------------------
	// Game Setup
	// ----------------------------------------------------------------------------------

	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Quick Draw",
		sf::Style::Titlebar | sf::Style::Close);


	// Seed our Random Number Generation
	srand(time(NULL));



	// Create Button Spirte
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);

	//Center the sprite on the screen
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);


	//Timer functionallity
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal = sf::seconds(5.0f);
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;

	//----------------------------------------------------------------------------------
	//End game Setup
	//----------------------------------------------------------------------------------



	//-----------------------------------------------------------------------------------
	// Game Loop
	//-----------------------------------------------------------------------------------
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{

		//-------------------------------------------------------------------------------
		//Input
		//-------------------------------------------------------------------------------

		sf::Event gameEvent;

		// Check if game event is closed
		while (gameWindow.pollEvent(gameEvent))
		{


			if (gameEvent.type == sf::Event::Closed) // Begin Close Window Loop
			{

				// Close the game window
				gameWindow.close();


			} // End Close Window loop


			if (gameEvent.type == sf::Event::MouseButtonPressed) // Check if we clicked
			{

				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y)) // Check if we clicked the button
				{

					// We Clicked the button
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timeTilSignal = sf::seconds(signalSeconds);


				} //End click button if

			} // End Click if



		} // End event polling while loop


		//-------------------------------------------------------------------------------
		// End Input
		//-------------------------------------------------------------------------------





		//-------------------------------------------------------------------------------
		// Update
		//-------------------------------------------------------------------------------

		sf::Time frameTime = gameClock.restart();

		timeTilSignal = timeTilSignal - frameTime;

		if (timeTilSignal.asSeconds() <= 0.0f)
		{
			buttonSprite.setColor(sf::Color::Red);
		}

		//-------------------------------------------------------------------------------
		// End Update
		//-------------------------------------------------------------------------------




		//-------------------------------------------------------------------------------
		// Draw
		//-------------------------------------------------------------------------------


		// Clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		// Draw everything
		gameWindow.draw(buttonSprite);


		// Display the window contents on the screen
		gameWindow.display();


		//-------------------------------------------------------------------------------
		//End Draw
		//-------------------------------------------------------------------------------


	} // Close Game While Loop

	
	// Exit Point of program
	return 0;

} // End of Main function
