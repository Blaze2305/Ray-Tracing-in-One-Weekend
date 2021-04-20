#ifndef CAMERA_H
#define CAMERA_H

#include "../Utils/utils.h"
#include "../Vec3/vec3.h"
#include "../Objects/hittable.h"

class camera {
	public:
		camera() {
			// aspect ratio of the camera view
			auto aspect_ratio = 16.0 / 9.0;
			auto viewport_height = 2.0;
			auto viewport_width = aspect_ratio * viewport_height;
			auto focal_length = 1.0;

			// origin of the camera
			origin = point3(0, 0, 0);
			horizontal = vec3(viewport_width, 0.0, 0.0);
			vertical = vec3(0.0, viewport_height, 0.0);
			lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
		}

		// function to get a ray from the camera, the ray pointing at (u,v) pixel in the grid
		ray get_ray(double u, double v) const {
			return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
		}

	private:
		point3 origin;
		point3 lower_left_corner;
		vec3 horizontal;
		vec3 vertical;
};
#endif