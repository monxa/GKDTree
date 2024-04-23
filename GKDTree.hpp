#pragma once
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/godot.hpp>

#include "KDTree.hpp"

class GDE_EXPORT GKDTree : public godot::RefCounted {
	GDCLASS(GKDTree, godot::RefCounted)

public:
	GKDTree() = default;
	void initialize(godot::Array points) {
		if (points.size() == 0)
			return;
		pointVec point_vec;
		for (int i = 0; i < points.size(); i++) {
			godot::Variant point = points[i];
			point_vec.push_back(extract_point(point));
		}
		tree = KDTree(point_vec);
	}

	godot::Variant nearestPoint(const godot::Variant &point);
	godot::Array neighborhood(const godot::Variant &point, float rad) const;
	int nearestPointIndex(const godot::Variant &point);
	godot::PackedInt32Array neighborhoodIndices(const godot::Variant &point, float rad);

private:
	mutable KDTree tree;
	point_t extract_point(const godot::Variant &p) const;

protected:
	static void _bind_methods();
};