//
// Created by Planck Chang on 2021/11/29.
//

#include "graph.h"

CRectgraph::CRectgraph(const double len, const double w):length(len), width(w)
{}

double CRectgraph::full_area(const double ext) const {
    return length * (width +2*ext) +PI *(width /2 + ext) * (width/2 + ext);
}

double CRectgraph::inner_area() const {
    return length * width;
}

CCirclegraph::CCirclegraph(double r) :radius(r){}

double CCirclegraph::full_area(const double ext) const {
    return PI*(radius + ext) * (radius + ext);
}

double CCirclegraph::inner_area() const {
    return PI * radius * radius;
}

