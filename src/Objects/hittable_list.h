#ifndef HITTABLE_LIST_H_

#define HITTABLE_LIST_H_

#include <memory>
#include <vector>
#include "hittable.h"
#include "../Ray/ray.h"


class hittable_list : public hittable{
	public:
		// vector of shared pointers to the list of hittable objects
		std::vector<std::shared_ptr<hittable>> objects;

		hittable_list(){}

		hittable_list(std::shared_ptr<hittable> object){
			objects.push_back(object);
		}

		// clear all the objects in the list
		void clear();

		//  add a new object to the list of objects
		void add(std::shared_ptr<hittable> object);

		// override the hit function for each object in the list of objects
		virtual bool hit(const ray& r,double t_min, double t_max, hit_record& rec) const  override;
};

#endif