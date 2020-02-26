#pragma once
class circle {
public:
	//Constructor to construct the circle with center and radius
	circle(int center_x, int center_y, int r);
	/*It Generates the coordinates (x, y) which lie on circle and call the function 'plot_circle'
	to plot them in all 8 part symmetries corresponding its center.
	*/
	void draw();
private:
	int center_x, center_y, r; //Center coordinates and radius of the circle
	
/*Takes the input of Coordinates (x, y), the center (cx, cy) and the color of the pixle (R, G, B)
*/
	void plot_circle(int x, int y, int cx, int cy, int r = 0, int g = 0, int b = 0);
};