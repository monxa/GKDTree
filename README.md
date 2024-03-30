# GKDTree - A KDTree Extension for Godot Engine

GKDTree is a godot-cpp compatible wrapper for a KDTree implementation as provided by @walaj and @crvs.

## Features
- **Versatile Data Handling**: GKDTree is designed to work with Godot's dynamic data types, accepting both `godot::PackedVector2Array` and `godot::PackedVector3Array` through `godot::Variant` and `godot::Array` parameters. This makes it flexible and easy to use within the Godot environment.
- **Nearest Point and Neighborhood Queries**: With methods for finding the nearest point and querying neighborhoods, GKDTree allows for efficient spatial queries.
- **Optimized for Godot-cpp**: Specifically optimized for use with godot-cpp.


# KDTree

Simple C++ static KD-Tree implementation with minimal functionality.

- points are given as STL vectors (and inserted in their own STL vector) so supports n-dimensional points for any n
- makes full trees, (i.e. does not cut-off the branching at some arbitrary level) giving the nearest neighbor query have (strong) logarithmic complexity.
- builds the tree in one go (does not support adding nodes, the tree is built from a list of points and cannot be altered afterwards)
- points are assumed to be STL vectors
- it provides the following queries:
	- nearest neighbor
	- neighbors within a given distance

## License and copyright

© J. Frederico Carvalho
Licensed under the [BSD3 License](LICENSE)
