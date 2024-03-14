#pragma once
#include "KDTree.hpp"
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/godot.hpp>

class GKDTree : public godot::RefCounted {
	GDCLASS(GKDTree, godot::RefCounted)

public:
    GKDTree() = default;
	void initialize(godot::Array points) {
		if (points.size() == 0)
			return;
		pointVec point_vec;
        for (int i = 0; i < points.size(); i++){
            godot::Variant point = points[i];
            point_vec.push_back(extract_point(point));
        }
		tree = KDTree(point_vec);
	}

    godot::Variant nearestPoint(godot::Variant point);
    GDE_EXPORT godot::Array neighborhood(godot::Variant point, float rad) const;
	
private:
	mutable KDTree tree;
    GDE_EXPORT point_t extract_point(godot::Variant p) const;
protected:
	static void _bind_methods();
};