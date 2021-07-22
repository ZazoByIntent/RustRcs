#include "Weapon.h"
void mouse_move(const Weapon &chosen, const float& timer, const float& random);
void perform_move(const Vec2& delta);
void smooth_move(const float& x, const float& y, const float repeatDelay, float animationTime);
