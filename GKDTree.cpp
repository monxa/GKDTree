#include "GKDTree.hpp"
#include <gdextension_interface.h>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

godot::Variant GKDTree::nearestPoint(const godot::Variant &point) {
	if (size == 0) return nullptr;
	point_t pt = extract_point(point);
	point_t res = tree.nearest_point(pt);
	if (res.size() == 2) {
		return godot::Vector2(res[0], res[1]);
	}
	if (res.size() == 3) {
		return godot::Vector3(res[0], res[1], res[2]);
	}

	return godot::Variant();
}

godot::Array GKDTree::neighborhood(const godot::Variant &point, float rad) const {
	if (size == 0) return godot::Array();
	point_t pt = extract_point(point);
	pointVec vec = tree.neighborhood_points(pt, rad);

	godot::Array result;
	result.resize(vec.size());
	int vector_type = vec[0].size();
	if (vector_type == 2) {
		for (int i = 0; i < vec.size(); i++)
			result[i] = godot::Vector2(vec[i][0], vec[i][1]);
	}
	if (vector_type == 3) {
		for (int i = 0; i < vec.size(); i++)
			result[i] = godot::Vector3(vec[i][0], vec[i][1], vec[i][2]);
	}
	return result;
}

int GKDTree::nearestPointIndex(const godot::Variant &point) {
	point_t pt = extract_point(point);
	return tree.nearest_index(pt);
}

godot::PackedInt32Array GKDTree::neighborhoodIndices(const godot::Variant &point, float rad) {
	if (size == 0) return godot::PackedInt32Array();
	point_t pt = extract_point(point);
	indexArr vec = tree.neighborhood_indices(pt, rad);
	godot::PackedInt32Array arr;
	arr.resize(vec.size());
	for (int i = 0; i < vec.size(); i++) {
		arr[i] = vec[i];
	}
	if (size == 0) return godot::PackedInt32Array();
	return arr;
}

point_t GKDTree::extract_point(const godot::Variant &p) const {
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
	ClassDB::bind_method(D_METHOD("initialize", "points"), &GKDTree::initialize);
	ClassDB::bind_method(D_METHOD("nearest_point", "point"), &GKDTree::nearestPoint);
	ClassDB::bind_method(D_METHOD("neighborhood", "point", "rad"), &GKDTree::neighborhood);
	ClassDB::bind_method(D_METHOD("nearest_point_index", "point"), &GKDTree::nearestPointIndex);
	ClassDB::bind_method(D_METHOD("neighborhood_indices", "point", "rad"), &GKDTree::neighborhoodIndices);
	ClassDB::bind_method(D_METHOD("size"), &GKDTree::get_size);
}
