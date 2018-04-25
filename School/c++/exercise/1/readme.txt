you can determine the type of polygon with this algorithm

basic idea:
extend every line of the polygon and check if there are points on 2 sides
if points are all on one side: convex polygon
if points are on both side: concave polygon

to compile, run:
> g++ polygon.cpp -o main


by kmykoh97