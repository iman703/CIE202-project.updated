#include "operations.h"
#include "game.h"
#include "CompositeShapes.h"
#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;
/////////////////////////////////// class operation  //////////////////
operation::operation(game* r_pGame)
{
	pGame = r_pGame;
}


/////////////////////////////////// class operAddSign  //////////////////

operAddTree::operAddTree(game* r_pGame) : operation(r_pGame)
{}

//void operAddTree::Act()
//{
//	window* pw = pGame->getWind();
//
//
//	int xGrid = config.RefX - config.RefX % config.gridSpacing;
//	int yGrid = config.RefY - config.RefX % config.gridSpacing;
//
//	point treeShapeRef = { xGrid, yGrid };
//
//	shape* psh = new Tree(pGame, treeShapeRef);
//
//	grid* pGrid = pGame->getGrid();
//	pGrid->setActiveShape(psh);
//}


/////////////////////////////////// class operAddSign  //////////////////

operAddSign::operAddSign(game* r_pGame) :operation(r_pGame)
{
}

void operAddSign::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();*/
	/*if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create a sign shape
	shape* psh = new Sign(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddHouse::operAddHouse(game* r_pGame) : operation(r_pGame)
{
}
void operAddHouse::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new House(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}


operAddCar::operAddCar(game* r_pGame) : operation(r_pGame)
{
}

void operAddCar::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Car(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddIceCream::operAddIceCream(game* r_pGame) : operation(r_pGame)
{
}
void operAddIceCream::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new IceCream(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
void operAddTree::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Tree(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}

operAddButterfly::operAddButterfly(game* r_pGame) : operation(r_pGame)
{
}

void operAddButterfly::Act()
{
	window* pw = pGame->getWind();
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Butterfly(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}
operAddCastle::operAddCastle(game* r_pGame) : operation(r_pGame)
{
}
void operAddCastle::Act()
{
	window* pw = pGame->getWind();

	//TODO:
	// Don't allow adding new shape if there is alreday an active shape

	// Check if there is already an active shape
	/*grid* pGrid = pGame->getGrid();
	if (pGrid->getActiveShape() != nullptr)
	{
		cout << " There is already an active shape, so do not add a new one";

		return;
	}*/

	//align reference point to the nearest grid point
	int xGrid = config.RefX - config.RefX % config.gridSpacing;
	int yGrid = config.RefY - config.RefX % config.gridSpacing;

	//take the aligned point as the sign shape ref point
	point signShapeRef = { xGrid,yGrid };

	//create house shape
	shape* psh = new Castle(pGame, signShapeRef);

	//Add the shape to the grid
	grid* pGrid = pGame->getGrid();
	pGrid->setActiveShape(psh);

}



operDeleteShape::operDeleteShape(game* r_pGame) : operation(r_pGame)
{
}


void operDeleteShape::Act()
{
	// Get the grid from the game
	grid* pGrid = pGame->getGrid();
	pGrid->clearGrid();
}




	// Get the active shape from the grid
	/*shape* pActiveShape = pGrid->getActiveShape();*/

	//if (pActiveShape)
	//{
	//	// Delete the active shape from the grid
	//	pGrid->deleteShape(pActiveShape);

	//	// Optionally, you may want to delete the shape object from memory
	//	delete pActiveShape;

	//	// Clear the active shape pointer in the grid
	//	pGrid->setActiveShape(nullptr);
	//}


operresizeup::operresizeup(game* r_pGame):operation(r_pGame)
{
}

void operresizeup::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	activeShape->resize(2);
}


operresizedwn::operresizedwn(game* r_pGame) :operation(r_pGame)
{
}

void operresizedwn::Act()
{
	grid* pGrid = pGame->getGrid();
	shape* activeShape = pGrid->getActiveShape();

	activeShape->resize(0.5);
}

	// Check if there is an active shape selected
	/*shape* activeShape = pGrid->getActiveShape();
	if (activeShape) {*/
		// Resize the active shape up by a factor of 2
		/*activeShape->resize();*/

		//// Redraw the grid to reflect the changes
		//pGrid->draw();
	/*}*/

//operResizeUp::operResizeUp(game* r_pGame) : operation(r_pGame) {}
//void operResizeUp::Act() {
//	// Get the window and grid pointers from the game
//	window* pW = pGame->getWind();
//	grid* pGrid = pGame->getGrid();
//
//	// Check if there is an active shape selected
//	shape* activeShape = pGrid->getActiveShape();
//	if (activeShape) {
//		// Resize the active shape up by a factor of 2
//		activeShape->ResizeUp(2.0);
//
//		// Redraw the grid to reflect the changes
//		pGrid->draw();
//	}
//}
//operResizeDown::operResizeDown(game* r_pGame) : operation(r_pGame) {}
//void operResizeDown::Act() {
//	// Get the window and grid pointers from the game
//	window* pW = pGame->getWind();
//	grid* pGrid = pGame->getGrid();
//
//	// Check if there is an active shape selected
//	shape* activeShape = pGrid->getActiveShape();
//	if (activeShape) {
//		// Resize the active shape up by a factor of 2
//		activeShape->resizeDown(2.0);
//
//		// Redraw the grid to reflect the changes
//		pGrid->draw();
//	}
//}

// operations.cpp
operRotate::operRotate(game* r_pGame) : operation(r_pGame) {}

void operRotate::Act() {
	// Get the window and grid pointers from the game
	window* pW = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	/*
	// Check if there is an active shape selected
	//shape* activeShape = pGrid->getActiveShape();
	//if (activeShape) {
		//activeShape->rotate();   
		// Implement the rotation logic here
		// Example: activeShape->rotate(angle);

		// Redraw the grid to reflect the changes

	//}
	*/
	config.SignRotation = config.SignRotation + 1;
	pGrid->rotate();

}

operverticalFlip::operverticalFlip(game* r_pGame) : operation(r_pGame) {}

void operverticalFlip::Act()
{
	// Get the window and grid pointers from the game
	window* pW = pGame->getWind();
	grid* pGrid = pGame->getGrid();
	/*
	// Check if there is an active shape selected
	//shape* activeShape = pGrid->getActiveShape();
	//if (activeShape) {
		//activeShape->rotate();
		// Implement the rotation logic here
		// Example: activeShape->rotate(angle);

		// Redraw the grid to reflect the changes

	//}
	*/
	config.SignRotation = config.SignRotation + 1;
	pGrid->rotate();
	pGrid->rotate();

}


////operMoveShape: This class represents the operation to move a shape to a new position by clicking on the grid.

//operMoveShape::operMoveShape(game* r_pGame) : operation(r_pGame)
//{
//}
//

// r_pGame makes an error "undefined"

void operExit::Act()
{
	if (pGame->unsavedChangesExist()) {
		if (pGame->userWantsToSaveChanges()) {
			pGame->saveChanges();
		}
	}
	pGame->cleanMemory();
	// Exit the game
	exit(0);
}
operMove::operMove(game* r_pGame) :operation(r_pGame)
{
}


void operMove::Act()
{
	keytype itempressed;
	window* pw = pGame->getWind();
	grid* pg = pGame->getGrid();
	shape* pe = pg->getActiveShape();
	char cKeyData;
	itempressed = pw->GetKeyPress(cKeyData);
	do {
		if (itempressed == ARROW)
		{
			pg->clearGridArea();
			switch (cKeyData)
			{
			case 2:	//Down Arrow
				pe->move(Up);

				break;
			case 4:	//left Arrow
				pe->move(Left);

				break;
			case 6:	//Down Arrow
				pe->move(Right);

				break;
			case 8:	//Down Arrow
				pe->move(Down);

				break;
			}
			pg->draw();
			pw->UpdateBuffer();
		}
	} while (itempressed != ESCAPE);
	//pg->move();
}

ShapeType getRandomShapeType() {
	int randomNumber = rand() % 2; // Generate a random number between 0 and 1 (assuming there are 2 shape types)
	switch (randomNumber) {
	case 0:
		return SIGN;
	case 1:
		return TREE;
		// Add more cases for additional shape types if needed
	case 2:
		return CASTLE;
	case 3:
		return HOUSE;
	case 4:
		return BUTTERFLY;
	case 5:
		return CAR;
	default:
		return SIGN; // Default to SIGN if an unexpected value is generated
	}
}
//////////////////////////////////////////////////////////////////////////////////////
void operRefresh::Act() {
	// Get the window and grid pointers from the game
	window* pW = pGame->getWind();
	grid* pGrid = pGame->getGrid();

	// Redraw the grid to clear the current state
	pGrid->clearGrid();
	pGrid->draw();
	pW->UpdateBuffer();

	// Generate new random shapes and add them to the grid
	int numShapes = 5; // Change this to the desired number of new shapes
	for (int i = 0; i < numShapes; ++i) {
		// Generate random coordinates for the shape
		////int x = rand() % pW->getWidth();// 
		////int y = rand() % pW->getHeight();
		// Generate new random shapes and add them to the grid
		ShapeType type = getRandomShapeType(); // Implement this function accordingly
		// Create the shape based on the random type
		/*shape* psh = nullptr;
		switch (type) {
		case SIGN:
			psh = new Sign(pGame, { x, y });
			break;
		case TREE:
			psh = new Tree(pGame, { x, y });
			break;
		case CASTLE:
			psh=new Castle(pGame, { x, y });
			break;
		case HOUSE:
			psh = new House(pGame, { x, y });
			break;
		case BUTTERFLY:
			psh = new Butterfly(pGame, { x, y });
			break;
		case CAR:
			psh = new Car(pGame, { x, y });
			break;
		}*/
		/*if (psh) {
			pGrid->addShape(psh);
		}*/
	}

	pW->UpdateBuffer();
}

// pGame makes an error 'undefined'
 

//////////////////////////////////////////////////////////////////////////////////////
//operRefresh::operRefresh(game* r_pGame) :operation(r_pGame)
//{
//}
//void operRefresh::Act()
//{
////
//	operRefresh(game * r_pGame) : operation(r_pGame) {}
////
//	virtual void Act() override //function to implement the refresh logic
////	 
//	 {
////		// Redraw existing shapes
//		pGame->draw();
////
////		// Generate new random shapes
//		pGame->generateRandomShapes();
////
////		// Check if the game is over and if so, refresh the game state
////		//if (pGame->isGameOver()) {
//			pGame->refreshGame();
////		//}
//    }
////	//pg->Refresh();
//}

////operCreateShape::operCreateShape(game* r_pGame, int level) : operation(r_pGame) {}
////
////void operCreateShape::Act()
////{
////	int count = 0;
////	for (int i = 0; i < shapeNo; i++)
////	{
////		int shape = 1 + rand() % 7;
////		point ref;
////		ref.x = rand() % 900; ref.y = rand() % 300;
////		switch (shape) {
////		case 1:
////			Sign * Shape;
////			Shape = new Sign(r_pGame, ref) : shape(r_pGame, ref)
////				break;
////		case 2:
////			House * house(game * r_pGame, point ref);
////			break;
////		case 3:
////			Car * car(game * r_pGame, point ref);
////			break;
////		case 4:
////			IceCream * icecream(game * r_pGame, point ref);
////			break;
////		case 5:
////			Tree * tree(game * r_pGame, point ref);
////			break;
////		case 6:
////			Butterfly * butterfly(game * r_pGame, point ref);
////			break;
////		case 7:
////			Castle * castle(game * r_pGame, point ref);
////			break;
////
////		};
////		count += 1;
////	}
////}
////
////drawRandomShape::drawRandomShape(game* r_pGame, shape array) :operation(r_pGame) {}
////
////void drawRandomShape::Act()
////{
////	for (int i = 0; i < count; i++)
////	{
////		array[i].draw();
////	}
////}