int add(int x, int y) {
  auto e{0};
  return x + y + e;
}

double accelerate(double u, double t) {
  constexpr auto g{9.81};
  return u + g * t;
}