#include "CompositeShapes.h"
#include "gameConfig.h"
#include <cmath>


////////////////////////////////////////////////////  class Sign  ///////////////////////////////////////
Sign::Sign(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	//calc the ref point of the Sign base and top rectangles relative to the Sign shape
	point topRef = ref;	//top rect ref is the same as the sign
	point baseRef = { ref.x, ref.y + config.sighShape.topHeight / 2 + config.sighShape.baseHeight / 2 };
	top = new Rect(pGame, topRef, config.sighShape.topHeight, config.sighShape.topWdth);
	base = new Rect(pGame, baseRef, config.sighShape.baseHeight, config.sighShape.baseWdth);
}
void Sign::draw() const
{
	base->draw();
	top->draw();
}
void Sign::resize(double size)
{
	point newbase;
	newbase = { (base->getref().x - RefPoint.x) * size + RefPoint.x, (base->getref().y - RefPoint.y) * size + RefPoint.y};
	base->setRefPoint(newbase);
	top->resize(size);
	base->resize(size);
}
void Sign::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (base->getref().x - top->getref().x) * rotcos - (base->getref().y - top->getref().y) * rotsin + top->getref().x;
	newrefp.y = (base->getref().y - top->getref().y) * rotcos + (base->getref().x - top->getref().x) * rotsin + top->getref().y;

	base->setRefPoint(newrefp);
	base->rotate();
	top->rotate();
}
void Sign::VerticalFlip()
{
	

	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (base->getref().x - top->getref().x) * rotcos - (base->getref().y - top->getref().y) * rotsin + top->getref().x;
	newrefp.y = (base->getref().y - top->getref().y) * rotcos + (base->getref().x - top->getref().x) * rotsin + top->getref().y;

	base->setRefPoint(newrefp);
	base->rotate();
	top->rotate();
}



House::House(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point buildingRef = ref;
	point roofRef = { ref.x, ref.y - config.HouseShape.baseHeight / 2 - config.HouseShape.topHeight / 2 };


	building = new Rect(pGame, buildingRef, config.HouseShape.baseHeight, config.HouseShape.baseWidth);
	roof = new Triangle(pGame, roofRef, config.HouseShape.topWidth, config.HouseShape.topHeight);

}
void House::draw() const
{
	building->draw();
	roof->draw();


}
void House::resize(double size)
{
	point newroof, newWindow;
	newroof = { (roof->getref().x - RefPoint.x) * size + RefPoint.x, (roof->getref().y - RefPoint.y) * size + RefPoint.y };
	roof->setRefPoint(newroof);


	roof->resize(size);
	building->resize(size);

}
void House::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (roof->getref().x - building->getref().x) * rotcos - (roof->getref().y - building->getref().y) * rotsin + building->getref().x;
	newrefp.y = (roof->getref().y - building->getref().y) * rotcos + (roof->getref().x - building->getref().x) * rotsin + building->getref().y;

	roof->setRefPoint(newrefp);
	roof->rotate();
	building->rotate();

}
void House::VerticalFlip()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);


	point newrefp;
	newrefp.x = (roof->getref().x - building->getref().x) * rotcos - (roof->getref().y - building->getref().y) * rotsin + building->getref().x;
	newrefp.y = (roof->getref().y - building->getref().y) * rotcos + (roof->getref().x - building->getref().x) * rotsin + building->getref().y;

	roof->setRefPoint(newrefp);
	roof->rotate();
	building->rotate();

}



Car::Car(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point topRef = { ref.x - config.CarShape.baseWidth / 6, ref.y - config.CarShape.baseHeight/1.2 };
	point leftwheelRef = { ref.x - config.CarShape.baseWidth / 4, ref.y + config.CarShape.baseHeight/2 };
	point rightwheelRef = { ref.x + config.CarShape.baseWidth / 4, ref.y + config.CarShape.baseHeight/2 };

	base = new Rect(pGame, baseRef, config.CarShape.baseHeight, config.CarShape.baseWidth);
	top = new Triangle(pGame, topRef, config.CarShape.topHeight, config.CarShape.topWidth);
	leftwheel = new Circle(pGame, leftwheelRef, config.CarShape.wheelRadius);
	rightwheel = new Circle(pGame, rightwheelRef, config.CarShape.wheelRadius);
}
void Car::draw() const
{
	base->draw();
	top->draw();
	leftwheel->draw();
	rightwheel->draw();
}
void Car::resize(double size)
{
	point newtop;
	newtop = { (top->getref().x - RefPoint.x) * size + RefPoint.x, (top->getref().y - RefPoint.y) * size + RefPoint.y };
	top->setRefPoint(newtop);
	top->resize(size);
	point newleftwheel;
	newleftwheel = { (leftwheel->getref().x - RefPoint.x) * size + RefPoint.x, (leftwheel->getref().y - RefPoint.y) * size + RefPoint.y };
	leftwheel->setRefPoint(newleftwheel);
	leftwheel->resize(size);
	point newrightwheel;
	newrightwheel = { (rightwheel->getref().x - RefPoint.x) * size + RefPoint.x, (rightwheel->getref().y - RefPoint.y) * size + RefPoint.y };
	rightwheel->setRefPoint(newrightwheel);
	rightwheel->resize(size);

	base->resize(size);
	rightwheel->resize(*config.CarSize);
}
void Car::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point nlwheel;
	nlwheel.x = (leftwheel->getref().x - RefPoint.x) * rotcos - (leftwheel->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	nlwheel.y = (leftwheel->getref().y - RefPoint.y) * rotcos + (leftwheel->getref().x - RefPoint.x) * rotsin + RefPoint.y;

	leftwheel->setRefPoint(nlwheel);
	leftwheel->rotate();

	point nrwheel;
	nrwheel.x = (rightwheel->getref().x - RefPoint.x) * rotcos - (rightwheel->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	nrwheel.y = (rightwheel->getref().y - RefPoint.y) * rotcos + (rightwheel->getref().x - RefPoint.x) * rotsin + RefPoint.y;

	rightwheel->setRefPoint(nrwheel);
	rightwheel->rotate();
	base->rotate();

	point ntop;
	ntop.x = (top->getref().x - RefPoint.x) * rotcos - (top->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	ntop.y = (top->getref().y - RefPoint.y) * rotcos + (top->getref().x - RefPoint.x) * rotsin + RefPoint.y;

	top->setRefPoint(ntop);
	top->rotate();
}
void Car::VerticalFlip()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point nlwheel;
	nlwheel.x = (leftwheel->getref().x - RefPoint.x) * rotcos - (leftwheel->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	nlwheel.y = (leftwheel->getref().y - RefPoint.y) * rotcos + (leftwheel->getref().x - RefPoint.x) * rotsin + RefPoint.y;

	leftwheel->setRefPoint(nlwheel);
	leftwheel->rotate();

	point nrwheel;
	nrwheel.x = (rightwheel->getref().x - RefPoint.x) * rotcos - (rightwheel->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	nrwheel.y = (rightwheel->getref().y - RefPoint.y) * rotcos + (rightwheel->getref().x - RefPoint.x) * rotsin + RefPoint.y;

	rightwheel->setRefPoint(nrwheel);
	rightwheel->rotate();
	base->rotate();

	point ntop;
	ntop.x = (top->getref().x - RefPoint.x) * rotcos - (top->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	ntop.y = (top->getref().y - RefPoint.y) * rotcos + (top->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	top->setRefPoint(ntop);
	top->rotate();
}




IceCream::IceCream(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point topRef = ref;
	point bottomRef = { ref.x, ref.y + config.iceCreamShape.bottomHeight / 1.5 };

	top = new Circle(pGame, topRef, config.iceCreamShape.topRadius);
	bottom = new Triangle(pGame, bottomRef, config.iceCreamShape.bottomWidth, -config.iceCreamShape.bottomHeight);

}
void IceCream::draw() const
{
	top->draw();
	bottom->draw();
}
void IceCream::resize(double size)
{
	point newbottom;
	newbottom = { (bottom->getref().x - RefPoint.x) * size + RefPoint.x, (bottom->getref().y - RefPoint.y) * size + RefPoint.y };
	bottom->setRefPoint(newbottom);
	bottom->resize(size);
	top->resize(size);
}
void IceCream::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newbottom;
	newbottom.x = (bottom->getref().x - RefPoint.x) * rotcos - (bottom->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newbottom.y = (bottom->getref().y - RefPoint.y) * rotcos + (bottom->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	bottom->setRefPoint(newbottom);

	bottom->rotate();

}
void IceCream::VerticalFlip()
{

	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newbottom;
	newbottom.x = (bottom->getref().x - RefPoint.x) * rotcos - (bottom->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newbottom.y = (bottom->getref().y - RefPoint.y) * rotcos + (bottom->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	bottom->setRefPoint(newbottom);

	bottom->rotate();
}




Tree::Tree(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point triangle1Ref = { ref.x, ref.y - config.TreeShape.baseHeight/1.5 };
	point triangle2Ref = { ref.x, ref.y - config.TreeShape.baseHeight / 1.2 };
	point triangle3Ref = { ref.x, ref.y - config.TreeShape.baseHeight / 0.99 };

	base = new Rect(pGame, baseRef, config.TreeShape.baseHeight, config.TreeShape.baseWidth);
	triangle1 = new Triangle(pGame, triangle1Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
	triangle2 = new Triangle(pGame, triangle2Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
	triangle3 = new Triangle(pGame, triangle3Ref, config.TreeShape.triangleHeight, config.TreeShape.triangleWidth);
}
void Tree::draw() const
{
	base->draw();
	triangle1->draw();
	triangle2->draw();
	triangle3->draw();
}
void Tree::resize(double size)
{
	point newtriangle3;
	newtriangle3 = { (triangle3->getref().x - RefPoint.x) * size + RefPoint.x, (triangle3->getref().y - RefPoint.y) * size + RefPoint.y };
	triangle3->setRefPoint(newtriangle3);
	triangle3->resize(size);

	point newtriangle2;
	newtriangle2 = { (triangle2->getref().x - RefPoint.x) * size + RefPoint.x, (triangle2->getref().y - RefPoint.y) * size + RefPoint.y };
	triangle2->setRefPoint(newtriangle2);
	triangle2->resize(size);

	point newtriangle1;
	newtriangle1 = { (triangle1->getref().x - RefPoint.x) * size + RefPoint.x, (triangle1->getref().y - RefPoint.y) * size + RefPoint.y };
	triangle1->setRefPoint(newtriangle1);
	triangle1->resize(size);

	base->resize(size);
}
void Tree::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newtriangle1;
	newtriangle1.x = (triangle1->getref().x - RefPoint.x) * rotcos - (triangle1->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle1.y = (triangle1->getref().y - RefPoint.y) * rotcos + (triangle1->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle1->setRefPoint(newtriangle1);
	triangle1->rotate();

	point newtriangle2;
	newtriangle2.x = (triangle2->getref().x - RefPoint.x) * rotcos - (triangle2->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle2.y = (triangle2->getref().y - RefPoint.y) * rotcos + (triangle2->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle2->setRefPoint(newtriangle2);

	triangle2->rotate();

	point newtriangle3;
	newtriangle3.x = (triangle3->getref().x - RefPoint.x) * rotcos - (triangle3->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle3.y = (triangle3->getref().y - RefPoint.y) * rotcos + (triangle3->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle3->setRefPoint(newtriangle3);

	triangle3->rotate();

	base->rotate();

}
void Tree::VerticalFlip()
{

	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newtriangle1;
	newtriangle1.x = (triangle1->getref().x - RefPoint.x) * rotcos - (triangle1->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle1.y = (triangle1->getref().y - RefPoint.y) * rotcos + (triangle1->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle1->setRefPoint(newtriangle1);
	triangle1->rotate();

	point newtriangle2;
	newtriangle2.x = (triangle2->getref().x - RefPoint.x) * rotcos - (triangle2->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle2.y = (triangle2->getref().y - RefPoint.y) * rotcos + (triangle2->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle2->setRefPoint(newtriangle2);

	triangle2->rotate();

	point newtriangle3;
	newtriangle3.x = (triangle3->getref().x - RefPoint.x) * rotcos - (triangle3->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newtriangle3.y = (triangle3->getref().y - RefPoint.y) * rotcos + (triangle3->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	triangle3->setRefPoint(newtriangle3);

	triangle3->rotate();

	base->rotate();
}




Butterfly::Butterfly(game* r_pGame, point ref) :shape(r_pGame, ref)
{

	point bodyRef = ref;
	point LwingRef = { ref.x - (config.butterflyShape.bodyHeight / 4)    , ref.y  };
	point RwingRef = { ref.x + (config.butterflyShape.bodyHeight / 4)    , ref.y };
	point headRef = { ref.x, ref.y - config.butterflyShape.bodyWidth - 20 };

	
	body = new Rect(pGame, bodyRef, config.butterflyShape.bodyHeight, config.butterflyShape.bodyWidth);
	Lwing = new Triangle(pGame, LwingRef, config.butterflyShape.WingHeight, config.butterflyShape.WingWidth);
	Rwing = new Triangle(pGame, RwingRef, config.butterflyShape.WingHeight, config.butterflyShape.WingWidth);
	head = new Circle(pGame, headRef, config.butterflyShape.circleRadius);
	Rwing->rotate(); Rwing->rotate(); Rwing->rotate();	Lwing->rotate();
}
void Butterfly::draw() const
{
	body->draw();
	Lwing->draw();
	Rwing->draw();
	head->draw();
}
void Butterfly::resize(double size)
{
	point newLwing;
	newLwing = { (Lwing->getref().x - RefPoint.x) * size + RefPoint.x, (Lwing->getref().y - RefPoint.y) * size + RefPoint.y };
	Lwing->setRefPoint(newLwing);
	Lwing->resize(size);

	point newRwing;
	newRwing = { (Rwing->getref().x - RefPoint.x) * size + RefPoint.x, (Rwing->getref().y - RefPoint.y) * size + RefPoint.y };
	Rwing->setRefPoint(newRwing);
	Rwing->resize(size);

	point newhead;
	newhead = { (head->getref().x - RefPoint.x) * size + RefPoint.x, (head->getref().y - RefPoint.y) * size + RefPoint.y };
	head->setRefPoint(newhead);
	head->resize(size);

	body->resize(size);
}
void Butterfly::rotate()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newLwing;
	newLwing.x = (Lwing->getref().x - RefPoint.x) * rotcos - (Lwing->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newLwing.y = (Lwing->getref().y - RefPoint.y) * rotcos + (Lwing->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	Lwing->setRefPoint(newLwing);
	Lwing->rotate();

	point newRwing;
	newRwing.x = (Rwing->getref().x - RefPoint.x) * rotcos - (Rwing->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newRwing.y = (Rwing->getref().y - RefPoint.y) * rotcos + (Rwing->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	Rwing->setRefPoint(newRwing);
	Rwing->rotate();

	point newhead;
	newhead.x = (head->getref().x - RefPoint.x) * rotcos - (head->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newhead.y = (head->getref().y - RefPoint.y) * rotcos + (head->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	head->setRefPoint(newhead);
	head->rotate();

	body->rotate();
}
void Butterfly::VerticalFlip()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);

	point newLwing;
	newLwing.x = (Lwing->getref().x - RefPoint.x) * rotcos - (Lwing->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newLwing.y = (Lwing->getref().y - RefPoint.y) * rotcos + (Lwing->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	Lwing->setRefPoint(newLwing);
	Lwing->rotate();

	point newRwing;
	newRwing.x = (Rwing->getref().x - RefPoint.x) * rotcos - (Rwing->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newRwing.y = (Rwing->getref().y - RefPoint.y) * rotcos + (Rwing->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	Rwing->setRefPoint(newRwing);
	Rwing->rotate();

	point newhead;
	newhead.x = (head->getref().x - RefPoint.x) * rotcos - (head->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newhead.y = (head->getref().y - RefPoint.y) * rotcos + (head->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	head->setRefPoint(newhead);
	head->rotate();

	body->rotate();
}




Castle::Castle(game* r_pGame, point ref) :shape(r_pGame, ref)
{
	point baseRef = ref;
	point triangle1Ref = { ref.x - config.CastleShape.baseWidth / 3.5, ref.y - config.CastleShape.baseHeight/1.5 };
	point triangle2Ref = { ref.x + config.CastleShape.baseWidth / 3.5, ref.y - config.CastleShape.baseHeight/1.5 };
	point circleRef = { ref.x, ref.y - config.CastleShape.baseHeight/1.5 };


	base = new Rect(pGame, baseRef, config.CastleShape.baseHeight, config.CastleShape.baseWidth);
	c_circle = new Circle(pGame, circleRef, config.CastleShape.circleRadius);
	l_triangle = new Triangle(pGame, triangle1Ref, config.CastleShape.triangleHeight, config.CastleShape.triangleWidth);
	r_triangle = new Triangle(pGame, triangle2Ref, config.CastleShape.triangleHeight, config.CastleShape.triangleWidth);
}
void Castle::draw() const
{
	base->draw();
	c_circle->draw();
	l_triangle->draw();
	r_triangle->draw();
}
void Castle::resize(double size)
{
	point newc_circle;
	newc_circle = { (c_circle->getref().x - RefPoint.x) * size + RefPoint.x, (c_circle->getref().y - RefPoint.y) * size + RefPoint.y };
	c_circle->setRefPoint(newc_circle);
	c_circle->resize(size);
	
	point newl_triangle;
	newl_triangle = { (l_triangle->getref().x - RefPoint.x) * size + RefPoint.x, (l_triangle->getref().y - RefPoint.y) * size + RefPoint.y };
	l_triangle->setRefPoint(newl_triangle);
	l_triangle->resize(size);

	point newr_triangle;
	newr_triangle = { (r_triangle->getref().x - RefPoint.x) * size + RefPoint.x, (r_triangle->getref().y - RefPoint.y) * size + RefPoint.y };
	r_triangle->setRefPoint(newr_triangle);
	r_triangle->resize(size);

	base->resize(size);
}
void Castle::rotate() 
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newc_circle;
	newc_circle.x = (c_circle->getref().x - RefPoint.x) * rotcos - (c_circle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newc_circle.y = (c_circle->getref().y - RefPoint.y) * rotcos + (c_circle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	c_circle->setRefPoint(newc_circle);
	c_circle->rotate();

	point newl_triangle;
	newl_triangle.x = (l_triangle->getref().x - RefPoint.x) * rotcos - (l_triangle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newl_triangle.y = (l_triangle->getref().y - RefPoint.y) * rotcos + (l_triangle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	l_triangle->setRefPoint(newl_triangle);
	l_triangle->rotate();

	point newr_triangle;
	newr_triangle.x = (r_triangle->getref().x - RefPoint.x) * rotcos - (r_triangle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newr_triangle.y = (r_triangle->getref().y - RefPoint.y) * rotcos + (r_triangle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	r_triangle->setRefPoint(newr_triangle);
	r_triangle->rotate();
	base->rotate();
}
void Castle::VerticalFlip()
{
	double angle = 90 * 3.14159265358979323846264338327950288419716939937510 / 180.0;
	double rotcos = cos(angle);
	double rotsin = sin(angle);
	point newc_circle;
	newc_circle.x = (c_circle->getref().x - RefPoint.x) * rotcos - (c_circle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newc_circle.y = (c_circle->getref().y - RefPoint.y) * rotcos + (c_circle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	c_circle->setRefPoint(newc_circle);
	c_circle->rotate();

	point newl_triangle;
	newl_triangle.x = (l_triangle->getref().x - RefPoint.x) * rotcos - (l_triangle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newl_triangle.y = (l_triangle->getref().y - RefPoint.y) * rotcos + (l_triangle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	l_triangle->setRefPoint(newl_triangle);
	l_triangle->rotate();

	point newr_triangle;
	newr_triangle.x = (r_triangle->getref().x - RefPoint.x) * rotcos - (r_triangle->getref().y - RefPoint.y) * rotsin + RefPoint.x;
	newr_triangle.y = (r_triangle->getref().y - RefPoint.y) * rotcos + (r_triangle->getref().x - RefPoint.x) * rotsin + RefPoint.y;
	r_triangle->setRefPoint(newr_triangle);
	r_triangle->rotate();
	base->rotate();
}