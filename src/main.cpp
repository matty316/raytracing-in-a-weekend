#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

int main() {
	hittableList world;
    
    auto R = std::cos(pi/4);
    
    auto materialLeft = make_shared<lambertian>(color(0, 0, 1));
    auto materialRight = make_shared<lambertian>(color(1, 0, 0));

	world.add(make_shared<sphere>(point3(-R, 0, -1), R, materialLeft));
	world.add(make_shared<sphere>(point3(R, 0, -1), R, materialRight));

	camera cam;

	cam.aspectRatio = 16.0 / 9.0;
	cam.imageWidth = 400;
	cam.samplesPerPixel = 100;
	cam.maxDepth = 50;
    
    cam.vfov = 90;

	cam.render(world);
}
