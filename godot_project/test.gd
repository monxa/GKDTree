extends Control

var kdtree := GKDTree.new()
var points := PackedVector3Array()
const NEIGHBORHOOD_SEARCH_RANGE = 3.
const SEARCH_POINT = Vector3.ZERO
const RAND_FAC = 4.

func _ready() -> void:
	for _i in range(10000):
		points.push_back(Vector3(randf() * RAND_FAC, randf() * RAND_FAC, randf() * RAND_FAC))

func _on_button_initialize_pressed() -> void:
	kdtree.initialize(points)
	print("GKDTree initialized")

func _on_button_nearest_point_pressed() -> void:
	var nearest_to_zero = kdtree.nearest_point(SEARCH_POINT)
	print("Nearest point to Vector3.ZERO: ", nearest_to_zero)

func _on_button_neighborhood_pressed() -> void:
	var neighborhood_points = kdtree.neighborhood(SEARCH_POINT, NEIGHBORHOOD_SEARCH_RANGE)
	print("Number points in neighborhood {0} around {1}: {2}".format(
		[NEIGHBORHOOD_SEARCH_RANGE, SEARCH_POINT, neighborhood_points.size()])
	)
	print("We expected ~{0} points".format([1./RAND_FAC * points.size()]))
