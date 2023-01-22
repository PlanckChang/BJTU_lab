//
// Created by Planck Chang on 2021/10/21.
//
#include "graph.h"

CPlaygraph::CPlaygraph(const double len, const double w) :m_length(len),m_width(w){}

double CPlaygraph::full_area(const double ext) const {
    return m_length*(m_width+2*ext) + PI * (m_width/2 + ext)*(m_width/2 +ext);
}

double CPlaygraph::inner_area() const {
    return m_width*m_length;
}
