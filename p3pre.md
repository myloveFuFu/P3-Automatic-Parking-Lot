# Zoom in & out
### Q: How should the entire shape be handled when zooming in and out of the car?
## Four aspects to consider:
1. Uniform Scaling:
- To preserve the car's shape, apply uniform scaling to all parts of the car. This ensures that no part of the car distorts or becomes disproportionate during zooming.
- In most 2D or 3D graphics systems, this is achieved by applying a scaling factor uniformly to the entire car model or image.
2. Maintain Aspect Ratio:
- Particularly in 2D graphics, it’s important to maintain the car's aspect ratio when zooming. This ensures the width and height scale proportionally so the car doesn't appear stretched or compressed.
3. Zoom Center:
- The zoom should be centered on the car (or the point of interest). When zooming in or out, the view should adjust to keep the car in focus, meaning the car's center should stay fixed in the view while zooming.
- This can be achieved by updating the view so that the car remains at the center of the zoom level.
4. Consider Detail:
- If the car model is complex, zooming in or out might introduce issues with visual clarity. Make sure that at different zoom levels, the details of the car are adequately displayed without distortion or blurring.

## Implementation Steps:
1. Determine the zoom level or scaling factor for the car.
2. Apply the scaling factor uniformly to all parts of the car model or image.
3. Ensure that the aspect ratio is maintained during scaling.
4. Update the view to center the car during zooming.
5. Check the visual quality and detail of the car at different zoom levels.

## Detailed Implementation:
### Basic Principles of Scaling
How 2D Scaling Works:
- 2D scaling modifies the coordinates of each point in the object based on scaling factors for the X and Y axes.
- The new coordinates of a point are calculated by multiplying the original coordinates by the scaling factors.
- Scaling factors greater than 1 enlarge the object, while factors between 0 and 1 reduce the object.
- Uniform scaling uses the same scaling factor for both axes, maintaining proportional scaling.
-  Let's say you have a point `𝑃(𝑥,𝑦)` in the object, and you want to scale it by a scaling factor (or scale factor). The new coordinates `𝑃′(𝑥′,𝑦′)` are calculated using the scaling factors.
- Formula:
  If the scaling factors are `𝑠𝑥` for the X-axis and `𝑠𝑦` for the Y-axis, the new coordinates `𝑃′(𝑥′,𝑦′)` of a point `𝑃(𝑥,𝑦)` are:
  `𝑥′=𝑥×𝑠𝑥`
  `𝑦′=𝑦×𝑠𝑦`

### How to Perform 2D Scaling
(1) Choosing the Scaling Center
By default, scaling is performed around the origin (0, 0). If you want to scale the object around its center, you need to translate the object to the origin first, apply the scaling, and then translate it back to its original position.

(2) Scaling Process
Step 1: Compute the center of the object (if needed).
Step 2: Scale each point in the object by applying the scaling factor.
Step 3: If using a custom scaling center, move each point to the scaling center, apply the scaling, and then move the points back to their original positions.

### Code Implementation
```cpp
#include <iostream>
#include <vector>

// Define a 2D Point class
class Point {
public:
    float x, y;

    // Constructor to initialize a point with given x and y coordinates
    Point(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    // Method to print the coordinates of the point
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// Function to scale the object by the given scale factors for X and Y axes
void scale2D(std::vector<Point>& points, float scaleX, float scaleY) {
    for (auto& point : points) {
        point.x *= scaleX;  // Scale by scaleX for the X-axis
        point.y *= scaleY;  // Scale by scaleY for the Y-axis
    }
}

// Function to calculate the center of the object (average of all points)
Point findCenter(const std::vector<Point>& points) {
    float sumX = 0.0f, sumY = 0.0f;
    for (const auto& point : points) {
        sumX += point.x;
        sumY += point.y;
    }
    // Return the average point as the center
    return Point(sumX / points.size(), sumY / points.size());
}

// Function to scale the object around its center by given scale factors
void scaleAroundCenter(std::vector<Point>& points, float scaleX, float scaleY) {
    // Find the center of the object
    Point center = findCenter(points);

    for (auto& point : points) {
        // Translate the point to the origin, scale it, and then translate it back to the center
        point.x = center.x + (point.x - center.x) * scaleX;
        point.y = center.y + (point.y - center.y) * scaleY;
    }
}

// Function to print all points
void printPoints(const std::vector<Point>& points) {
    for (const auto& point : points) {
        point.print();  // Print each point's coordinates
    }
}

int main() {
    // Define a simple quadrilateral (4 points)
    std::vector<Point> points = {
        Point(0.0f, 0.0f),  // Point 1
        Point(1.0f, 0.0f),  // Point 2
        Point(1.0f, 1.0f),  // Point 3
        Point(0.0f, 1.0f)   // Point 4
    };

    std::cout << "Original Points:" << std::endl;
    printPoints(points);  // Print original points

    // Apply uniform scaling (scale factor 2) to all points
    scale2D(points, 2.0f, 2.0f);
    std::cout << "\nScaled Points (2x):" << std::endl;
    printPoints(points);  // Print points after scaling

    // Apply scaling around the center with a scale factor of 0.5
    scaleAroundCenter(points, 0.5f, 0.5f);
    std::cout << "\nScaled Points Around Center (0.5x):" << std::endl;
    printPoints(points);  // Print points after scaling around the center

    return 0;
}
```
```cpp
// Sample Output:
Original Points:
(0.0, 0.0)
(1.0, 0.0)
(1.0, 1.0)
(0.0, 1.0)

Scaled Points (2x):
(0.0, 0.0)
(2.0, 0.0)
(2.0, 2.0)
(0.0, 2.0)

Scaled Points Around Center (0.5x):
(0.5, 0.5)
(1.5, 0.5)
(1.5, 1.5)
(0.5, 1.5)
```

### Summary
- When zooming in and out of a car, it's essential to maintain the car's shape and aspect ratio.
- Uniform scaling ensures that the entire car is scaled proportionally without distortion.
- Maintaining the aspect ratio prevents the car from appearing stretched or compressed.
- Zooming should be centered on the car to keep it in focus during scaling.
