#include "hittable_list.h"

// ----------------- CLASS METHODS -------------------------------

void hittable_list::clear(){
	objects.clear();
}

void hittable_list::add(std::shared_ptr<hittable> object){
	objects.push_back(object);
}

bool hittable_list::hit(const ray& r,double t_min, double t_max, hit_record& rec) const{
	// temp hit record to pass to each object to check collision
	hit_record temp_rec;
	// check if it hit anything
	bool hit_anything = false;
	// the closest distance it hit so far
	double closest_so_far = t_max;

	// loop through all the objects in the list of hittable objects
	// then for each object we check if it gets hit by the ray with the t_min and t_max distances
	// if it does hit something , then we set the hit_anything bool to true
	// set the closest hit point so far to be the t of the recent hit
	// this is so that we only have to render whats in front and not have to waste time on figuring out the
	// colors for the objects which are behind other objects
	// after this set the hit record to the temp record
	for(const std::shared_ptr<hittable>& obj : objects){
		if(obj->hit(r,t_min,closest_so_far,temp_rec)){
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;
		}
	}

	return hit_anything;
};


// ----------------------------------------------------------------