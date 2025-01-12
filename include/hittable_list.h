#pragma once

#include "hittable.h"
#include <vector>

class hittableList : public hittable {
public: 
	std::vector<shared_ptr<hittable>> objects;
	
	hittableList() {}
	hittableList(shared_ptr<hittable> object) { add(object); }

	void clear() { objects.clear(); }

	void add(shared_ptr<hittable> object) {
		objects.push_back(object);
	}

	bool hit(const ray& r, interval t, hitRecord& rec) const override {
		hitRecord tempRec;
		bool hitAnything = false;
		auto closestSoFar = t.max;

		for (const auto& object : objects) {
			if (object->hit(r, interval(t.min, closestSoFar), tempRec)) {
				hitAnything = true;
				closestSoFar = tempRec.t;
				rec = tempRec;
			}
		}

		return hitAnything;
	}
};