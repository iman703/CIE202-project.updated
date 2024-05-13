#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "operations.h"
#include "grid.h"



//Main class that coordinates the game operation
class game
{

	/// Add more members if needed

	toolbar* gameToolbar;
	
	window* pWind;	//Pointer to the CMU graphics window
	grid* shapesGrid;
	int playerLife;
	

public:
	game();
	~game();

	string getSrting() const;	 //Returns a string entered by the user
	void createWind(int, int, int, int); //creates the game window
	void clearStatusBar() const;	//Clears the status bar
	void printMessage(string msg) const;	//Print a message on Status bar
	void createToolBar();		//creates the toolbar
	void createGrid();		//creates the shapes grid

	window* getWind() const;		//returns a pointer to the graphics window
	grid* getGrid() const;		//returns a pointer to the shapes grid

	//creates an operation according to the toolbar item clicked
	operation* createRequiredOperation(toolbarItem clickedItem);



	void run();	//start the game
	void move();
	void draw();
	void generateRandomShapes();
	void isGameOver();
	void refreshGame();
	void DecrementLife();
	//game() : playerLife(3) {}

	bool unsavedChanges;
	game(): unsavedChanges(false){}

	bool unsavedChangesExist() {
		return unsavedChanges;
	}

	bool userWantsToSaveChanges() {
		// Implement logic to prompt the user
		return true; // For simplicity, always return true here
	}

	void saveChanges() {
		std::cout << "Changes saved." << std::endl;
		unsavedChanges = false;
	}

	void cleanMemory() {
		std::cout << "Cleaning memory." << std::endl;
	}

};

