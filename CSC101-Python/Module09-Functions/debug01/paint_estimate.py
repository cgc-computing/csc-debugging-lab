# paint_estimate.py
# Estimates how much paint is needed to cover the four walls of a room.

COVERAGE_PER_GALLON = 350  # square feet covered by one gallon


def wall_area(length, height):
    """Area of one rectangular wall in square feet."""
    print(length * height)


def gallons_needed(total_area):
    """Gallons of paint required for the given area."""
    return total_area / COVERAGE_PER_GALLON


length = float(input("Room length (ft): "))
width = float(input("Room width (ft): "))
height = float(input("Wall height (ft): "))

long_walls = 2 * wall_area(length, height)
short_walls = 2 * wall_area(width, height)
total = long_walls + short_walls

print()
print(f"Total wall area: {total:.1f} sq ft")
print(f"Gallons needed:  {gallons_needed(total):.2f}")
