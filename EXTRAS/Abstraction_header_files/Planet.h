#ifndef PLANET_H
#define PLANET_H

class Planet {
  double radius;
  double mass;
  const double G = 6.673e-11;
  
  public:
  Planet(double r, double m);
  double getMass();
  void setMass(double m);
  double getRadius();
  void setRadius(double r);
  double calculateGravity();
};

#endif