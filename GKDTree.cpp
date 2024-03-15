#include "GKDTree.hpp"
#include <gdextension_interface.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

godot::Variant GKDTree::nearestPoint(godot::Variant point) {
	point_t pt = extract_point(point);
	point_t res = tree.nearest_point(pt);
	
	if (res.size() == 2){
		return godot::Vector2(res[0], res[1]);
	}
	if (res.size() == 3){
		return godot::Vector3(res[0], res[1], res[2]);
	}

	return godot::Variant();
}

godot::Array GKDTree::neighborhood(godot::Variant point, float rad) const{
	point_t pt = extract_point(point);
	pointVec vec = tree.neighborhood_points(pt, rad);
	godot::Array arr; 
	for (point_t p : vec){
		if (p.size() == 2) arr.push_back(godot::Vector2(p[0], p[1]));
		if (p.size() == 3) arr.push_back(godot::Vector3(p[0], p[1], p[2]));
	}
	return arr;
}

point_t GKDTree::extract_point(godot::Variant p) const{
	point_t result;
	if (p.get_type() == godot::Variant::VECTOR2) {
		godot::Vector2 v = p;
		for (int i = 0; i < 2; i++) {
			result.push_back(v[i]);
		}
	}
	if (p.get_type() == godot::Variant::VECTOR3) {
		godot::Vector3 v = p;
		for (int i = 0; i < 3; i++) {
			result.push_back(v[i]);
		}
	}
	return result;
}

using namespace godot;
void GKDTree::_bind_methods() {
	ClassDB::bind_method(D_METHOD("nearest_point", "point"), &GKDTree::nearestPoint);
	ClassDB::bind_method(D_METHOD("initialize", "points"), &GKDTree::initialize);
	ClassDB::bind_method(D_METHOD("neighborhood", "point", "rad"), &GKDTree::neighborhood);
}
