#include "shape.h"
#include "game.h"
#include "gameConfig.h"

shape::shape(game* r_pGame, point ref)
{
	RefPoint = ref;
	pGame = r_pGame;
	fillColor = config.fillColor;
	borderColor = config.penColor;
}

void shape::setRefPoint(point p)
{
	RefPoint = p;
}
shape* shape::getActiveShape() const
{
	return nullptr;
}
void shape::VerticalFlip()
{}
void shape::resize(double)
{}
void shape::rotate()
{}
void shape::move(direction dir)
{
	switch (dir)
	{
	case Right:
		RefPoint.x += config.gridSpacing;
		break;
	case Up:
		RefPoint.y += config.gridSpacing;
		break;
	case Left:
		RefPoint.x -= config.gridSpacing;
		break;
	case Down:
		RefPoint.y -= config.gridSpacing;
		break;
	}
	
}
//class move_shape :public operation
//{
//public:
//	move_shape(game* r_pGame);
//	virtual void Act();
//};
//void shape::MoveUp()
//{
//    // Check if moving up will keep the shape within the grid
//    if (RefPoint.y - 1 >= 0)
//    {
//        // Move the shape up by decrementing the y-coordinate
//        RefPoint.y -= 1;
//    }
//}
//void shape::MoveDown()
//{
//    // Check if moving down will keep the shape within the grid
//    if (RefPoint.y + 1 < gridHeight)
//    {
//        // Move the shape down by incrementing the y-coordinate
//        RefPoint.y += 1;
//    }
//}
//
//void shape::MoveLeft()
//{
//    // Check if moving left will keep the shape within the grid
//    if (RefPoint.x - 1 >= 0)
//    {
//        // Move the shape left by decrementing the x-coordinate
//        RefPoint.x -= 1;
//    }
//}
//
//void shape::MoveRight()
//{
//    // Check if moving right will keep the shape within the grid
//    if (RefPoint.x + 1 < gridWidth)
//    {
//        // Move the shape right by incrementing the x-coordinate
//        RefPoint.x += 1;
//    }
//}
//void setup() {
//	window(600, 400);
//	rectMode(CENTER);
//	noStroke();
//}

//float referenceX = 300; // Initial reference point X-coordinate
//float referenceY = 200; // Initial reference point Y-coordinate

// Don not use this if you have your shapes already drawn
//void drawCompositeShape(float x, float y) {
//	// Draw rectangle
//	fillColor(255);
//	Rect(x, y, 200, 100);
//
//	// Draw triangle
//	float halfBase = 100;
//	float height = 50;
//	fill(200);
//	Triangle(x, y, x - halfBase, y - height, x + halfBase, y - height);
//
//	// Draw circle
//	float radius = 12.5;
//	fill(50);
//	Circle(x, y, radius);
//
//	// Display text
//	textAlign(CENTER, Bottom);
//	textSize(25);
//	text("Composite Shape", x, y + 50);
//}

/*oid draw() {
	background(255);
	drawCompositeShape(referenceX, referenceY);
}*/

//void keyPressed() {
//	// Update reference point based on arrow keys
//	if (keytype == Left) {
//		referenceX -= 10; // Move left UPDAtE your refrence 
//	}
//	else if (keytype == Right) {
//		referenceX += 10; // Move right UPDAtE your refrence 
//	}
//	else if (keytype == Up) {
//		referenceY -= 10; // Move up UPDAtE your refrence 
//	}
//	else if (keytype == Down) {
//		referenceY += 10; // Move down UPDAtE your refrence 
//	}
//}