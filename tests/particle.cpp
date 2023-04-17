#include "defs.hpp"
#include "ref.hpp"
#include "array.hpp"
#include "library.hpp"
#include "expr.hpp"

namespace uc {

  // Forward type declarations

  struct UC_TYPEDEF(particle);


  // Forward function declarations

  UC_PRIMITIVE(int) UC_FUNCTION(num_particles)();
  UC_PRIMITIVE(int) UC_FUNCTION(num_steps)();
  UC_PRIMITIVE(float) UC_FUNCTION(box_size)();
  UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_x_positions)();
  UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_y_positions)();
  UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_x_velocities)();
  UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_y_velocities)();
  UC_PRIMITIVE(float) UC_FUNCTION(density)();
  UC_PRIMITIVE(float) UC_FUNCTION(mass)();
  UC_PRIMITIVE(float) UC_FUNCTION(cutoff_radius)();
  UC_PRIMITIVE(float) UC_FUNCTION(min_radius_squared)();
  UC_PRIMITIVE(float) UC_FUNCTION(time_interval)();
  UC_PRIMITIVE(float) UC_FUNCTION(max)(UC_PRIMITIVE(float) UC_VAR(a), UC_PRIMITIVE(float) UC_VAR(b));
  UC_PRIMITIVE(void) UC_FUNCTION(apply_force)(UC_REFERENCE(particle) UC_VAR(p), UC_REFERENCE(particle) UC_VAR(other));
  UC_PRIMITIVE(void) UC_FUNCTION(move_particle)(UC_REFERENCE(particle) UC_VAR(p));
  UC_PRIMITIVE(void) UC_FUNCTION(print_particle_positions)(UC_ARRAY(UC_REFERENCE(particle)) UC_VAR(ps));
  UC_ARRAY(UC_REFERENCE(particle)) UC_FUNCTION(make_particles)(UC_PRIMITIVE(int) UC_VAR(num_particles));
  UC_PRIMITIVE(void) UC_FUNCTION(simulate)(UC_PRIMITIVE(int) UC_VAR(num_steps));
  UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args));


  // Full type definitions

struct UC_TYPEDEF(particle) 
{
	UC_PRIMITIVE(float) UC_VAR(x);
	

	UC_PRIMITIVE(float) UC_VAR(y);
	

	UC_PRIMITIVE(float) UC_VAR(x_vel);
	

	UC_PRIMITIVE(float) UC_VAR(y_vel);
	

	UC_PRIMITIVE(float) UC_VAR(x_acc);
	

	UC_PRIMITIVE(float) UC_VAR(y_acc);
	

	UC_PRIMITIVE(int) UC_VAR(id);
	

	UC_TYPEDEF(particle)() = default;
	

UC_TYPEDEF(particle)(UC_PRIMITIVE(float) UC_VAR(x), UC_PRIMITIVE(float) UC_VAR(y), UC_PRIMITIVE(float) UC_VAR(x_vel), UC_PRIMITIVE(float) UC_VAR(y_vel), UC_PRIMITIVE(float) UC_VAR(x_acc), UC_PRIMITIVE(float) UC_VAR(y_acc), UC_PRIMITIVE(int) UC_VAR(id)) : UC_VAR(x)(UC_VAR(x)), UC_VAR(y)(UC_VAR(y)), UC_VAR(x_vel)(UC_VAR(x_vel)), UC_VAR(y_vel)(UC_VAR(y_vel)), UC_VAR(x_acc)(UC_VAR(x_acc)), UC_VAR(y_acc)(UC_VAR(y_acc)), UC_VAR(id)(UC_VAR(id)) {}
	bool operator==(const UC_TYPEDEF(particle) &rhs) const
	{
	return this->UC_VAR(x) == rhs.UC_VAR(x) && this->UC_VAR(y) == rhs.UC_VAR(y) && this->UC_VAR(x_vel) == rhs.UC_VAR(x_vel) && this->UC_VAR(y_vel) == rhs.UC_VAR(y_vel) && this->UC_VAR(x_acc) == rhs.UC_VAR(x_acc) && this->UC_VAR(y_acc) == rhs.UC_VAR(y_acc) && this->UC_VAR(id) == rhs.UC_VAR(id);
	}
	bool operator!=(const UC_TYPEDEF(particle) &rhs) const
	{
	return !((*this)==(rhs));
	}
};


  // Full function definitions

  UC_PRIMITIVE(int) UC_FUNCTION(num_particles)()
{
	return 20;
}
	UC_PRIMITIVE(int) UC_FUNCTION(num_steps)()
{
	return 10;
}
	UC_PRIMITIVE(float) UC_FUNCTION(box_size)()
{
	return 0.1;
}
	UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_x_positions)()
{
	return uc::uc_construct<UC_ARRAY(UC_PRIMITIVE(float))>(0.0167, 0.033, 0.05, 0.0667, 0.0833, 0.0167, 0.033, 0.05, 0.0667, 0.0833, 0.0167, 0.033, 0.05, 0.0667, 0.0833, 0.0167, 0.033, 0.05, 0.0667, 0.0833);
}
	UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_y_positions)()
{
	return uc::uc_construct<UC_ARRAY(UC_PRIMITIVE(float))>(0.02, 0.02, 0.02, 0.02, 0.02, 0.04, 0.04, 0.04, 0.04, 0.04, 0.06, 0.06, 0.06, 0.06, 0.06, 0.08, 0.08, 0.08, 0.08, 0.08);
}
	UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_x_velocities)()
{
	return uc::uc_construct<UC_ARRAY(UC_PRIMITIVE(float))>(-0.482, 0.430, -0.338, -0.556, -0.332, 0.880, -0.730, 0.458, 0.576, 0.792, -0.810, -0.836, 0.572, -0.038, -0.960, 0.872, 0.704, -0.35, -0.374, -0.348);
}
	UC_ARRAY(UC_PRIMITIVE(float)) UC_FUNCTION(initial_y_velocities)()
{
	return uc::uc_construct<UC_ARRAY(UC_PRIMITIVE(float))>(-0.330, -0.622, 0.088, -0.058, 0.328, 0.292, 0.792, 0.648, 0.812, -0.460, -0.382, -0.624, 0.262, -0.662, -0.212, 0.914, -0.898, -0.026, -0.062, 0.008);
}
	UC_PRIMITIVE(float) UC_FUNCTION(density)()
{
	return 0.0005;
}
	UC_PRIMITIVE(float) UC_FUNCTION(mass)()
{
	return 0.01;
}
	UC_PRIMITIVE(float) UC_FUNCTION(cutoff_radius)()
{
	return 0.01;
}
	UC_PRIMITIVE(float) UC_FUNCTION(min_radius_squared)()
{
	return UC_FUNCTION(pow)(UC_FUNCTION(cutoff_radius)() / 100, 2);
}
	UC_PRIMITIVE(float) UC_FUNCTION(time_interval)()
{
	return 0.0005;
}
	UC_PRIMITIVE(float) UC_FUNCTION(max)(UC_PRIMITIVE(float) UC_VAR(a), UC_PRIMITIVE(float) UC_VAR(b))
{
	if (UC_VAR(a) > UC_VAR(b)) 
	{
	return UC_VAR(a);
	None
	}
	else 
	{
	None
	}
	return UC_VAR(b);
}
	UC_PRIMITIVE(void) UC_FUNCTION(apply_force)(UC_REFERENCE(particle) UC_VAR(p), UC_REFERENCE(particle) UC_VAR(other))
{
	UC_PRIMITIVE(float) UC_VAR(dx);
	UC_PRIMITIVE(float) UC_VAR(dy);
	UC_PRIMITIVE(float) UC_VAR(radius2);
	UC_PRIMITIVE(float) UC_VAR(radius);
	UC_PRIMITIVE(float) UC_VAR(coefficient);
	UC_VAR(dx) = UC_VAR(other)->UC_VAR(x) - UC_VAR(p)->UC_VAR(x);
	UC_VAR(dy) = UC_VAR(other)->UC_VAR(y) - UC_VAR(p)->UC_VAR(y);
	if (UC_VAR(dx) == 0 && UC_VAR(dy) == 0) 
	{
	return;
	None
	}
	else 
	{
	None
	}
	UC_VAR(radius2) = UC_FUNCTION(max)(uc::uc_add(UC_VAR(dx) * UC_VAR(dx), UC_VAR(dy) * UC_VAR(dy)), UC_FUNCTION(min_radius_squared)());
	if (UC_VAR(radius2) > UC_FUNCTION(cutoff_radius)() * UC_FUNCTION(cutoff_radius)()) 
	{
	return;
	None
	}
	else 
	{
	None
	}
	UC_VAR(radius) = UC_FUNCTION(sqrt)(UC_VAR(radius2));
	UC_VAR(coefficient) = 1 - UC_FUNCTION(cutoff_radius)() / UC_VAR(radius) / UC_VAR(radius2) / UC_FUNCTION(mass)();
	UC_VAR(p)->UC_VAR(x_acc) = uc::uc_add(UC_VAR(p)->UC_VAR(x_acc), UC_VAR(coefficient) * UC_VAR(dx));
	UC_VAR(p)->UC_VAR(y_acc) = uc::uc_add(UC_VAR(p)->UC_VAR(y_acc), UC_VAR(coefficient) * UC_VAR(dy));
}
	UC_PRIMITIVE(void) UC_FUNCTION(move_particle)(UC_REFERENCE(particle) UC_VAR(p))
{
	UC_VAR(p)->UC_VAR(x_vel) = uc::uc_add(UC_VAR(p)->UC_VAR(x_vel), UC_VAR(p)->UC_VAR(x_acc) * UC_FUNCTION(time_interval)());
	UC_VAR(p)->UC_VAR(y_vel) = uc::uc_add(UC_VAR(p)->UC_VAR(y_vel), UC_VAR(p)->UC_VAR(y_acc) * UC_FUNCTION(time_interval)());
	UC_VAR(p)->UC_VAR(x) = uc::uc_add(UC_VAR(p)->UC_VAR(x), UC_VAR(p)->UC_VAR(x_vel) * UC_FUNCTION(time_interval)());
	UC_VAR(p)->UC_VAR(y) = uc::uc_add(UC_VAR(p)->UC_VAR(y), UC_VAR(p)->UC_VAR(y_vel) * UC_FUNCTION(time_interval)());
	while (UC_VAR(p)->UC_VAR(x) < 0 || UC_VAR(p)->UC_VAR(x) > UC_FUNCTION(box_size)()) 
	{
	if (UC_VAR(p)->UC_VAR(x) < 0) 
	{
	UC_VAR(p)->UC_VAR(x) = -UC_VAR(p)->UC_VAR(x);
	None
	}
	else 
	{
	UC_VAR(p)->UC_VAR(x) = 2 * UC_FUNCTION(box_size)() - UC_VAR(p)->UC_VAR(x);
	None
	}
	UC_VAR(p)->UC_VAR(x_vel) = -UC_VAR(p)->UC_VAR(x_vel);
	None
	}
	while (UC_VAR(p)->UC_VAR(y) < 0 || UC_VAR(p)->UC_VAR(y) > UC_FUNCTION(box_size)()) 
	{
	if (UC_VAR(p)->UC_VAR(y) < 0) 
	{
	UC_VAR(p)->UC_VAR(y) = -UC_VAR(p)->UC_VAR(y);
	None
	}
	else 
	{
	UC_VAR(p)->UC_VAR(y) = 2 * UC_FUNCTION(box_size)() - UC_VAR(p)->UC_VAR(y);
	None
	}
	UC_VAR(p)->UC_VAR(y_vel) = -UC_VAR(p)->UC_VAR(y_vel);
	None
	}
}
	UC_PRIMITIVE(void) UC_FUNCTION(print_particle_positions)(UC_ARRAY(UC_REFERENCE(particle)) UC_VAR(ps))
{
	UC_PRIMITIVE(int) UC_VAR(i);
	for (
	UC_VAR(i) = 0
; 
	UC_VAR(i) < uc::uc_length_field(UC_VAR(ps))
; 
	++UC_VAR(i)
	) 
	{
	UC_FUNCTION(println)(uc::uc_add(uc::uc_add(uc::uc_add(uc::uc_add(uc::uc_array_index(UC_VAR(ps), UC_VAR(i))->UC_VAR(id), ": "), uc::uc_array_index(UC_VAR(ps), UC_VAR(i))->UC_VAR(x)), ", "), uc::uc_array_index(UC_VAR(ps), UC_VAR(i))->UC_VAR(y)));
	None
	}
	UC_FUNCTION(println)("");
}
	UC_ARRAY(UC_REFERENCE(particle)) UC_FUNCTION(make_particles)(UC_PRIMITIVE(int) UC_VAR(num_particles))
{
	UC_ARRAY(UC_REFERENCE(particle)) UC_VAR(particles);
	UC_ARRAY(UC_PRIMITIVE(float)) UC_VAR(xs);
	UC_ARRAY(UC_PRIMITIVE(float)) UC_VAR(ys);
	UC_ARRAY(UC_PRIMITIVE(float)) UC_VAR(xvs);
	UC_ARRAY(UC_PRIMITIVE(float)) UC_VAR(yvs);
	UC_PRIMITIVE(int) UC_VAR(i);
	UC_VAR(particles) = uc::uc_construct<UC_ARRAY(UC_REFERENCE(particle))>();
	UC_VAR(xs) = UC_FUNCTION(initial_x_positions)();
	UC_VAR(ys) = UC_FUNCTION(initial_y_positions)();
	UC_VAR(xvs) = UC_FUNCTION(initial_x_velocities)();
	UC_VAR(yvs) = UC_FUNCTION(initial_y_velocities)();
	for (
	UC_VAR(i) = 0
; 
	UC_VAR(i) < UC_VAR(num_particles)
; 
	++UC_VAR(i)
	) 
	{
	UC_VAR(particles) << uc::uc_construct<UC_REFERENCE(particle)>(uc::uc_array_index(UC_VAR(xs), UC_VAR(i)), uc::uc_array_index(UC_VAR(ys), UC_VAR(i)), uc::uc_array_index(UC_VAR(xvs), UC_VAR(i)), uc::uc_array_index(UC_VAR(yvs), UC_VAR(i)), 0, 0, UC_VAR(i));
	None
	}
	return UC_VAR(particles);
}
	UC_PRIMITIVE(void) UC_FUNCTION(simulate)(UC_PRIMITIVE(int) UC_VAR(num_steps))
{
	UC_ARRAY(UC_REFERENCE(particle)) UC_VAR(particles);
	UC_PRIMITIVE(int) UC_VAR(step);
	UC_PRIMITIVE(int) UC_VAR(i);
	UC_PRIMITIVE(int) UC_VAR(j);
	UC_VAR(particles) = UC_FUNCTION(make_particles)(UC_FUNCTION(num_particles)());
	UC_FUNCTION(println)("Initial");
	UC_FUNCTION(print_particle_positions)(UC_VAR(particles));
	for (
	UC_VAR(step) = 0
; 
	UC_VAR(step) < UC_VAR(num_steps)
; 
	++UC_VAR(step)
	) 
	{
	UC_FUNCTION(println)(uc::uc_add("Step ", uc::uc_add(UC_VAR(step), 1)));
	for (
	UC_VAR(i) = 0
; 
	UC_VAR(i) < UC_FUNCTION(num_particles)()
; 
	++UC_VAR(i)
	) 
	{
	uc::uc_array_index(UC_VAR(particles), UC_VAR(i))->UC_VAR(x_acc) = 0;
	uc::uc_array_index(UC_VAR(particles), UC_VAR(i))->UC_VAR(y_acc) = 0;
	UC_VAR(j) = 0;
	for (
	UC_VAR(j) = 0
; 
	UC_VAR(j) < UC_FUNCTION(num_particles)()
; 
	++UC_VAR(j)
	) 
	{
	UC_FUNCTION(apply_force)(uc::uc_array_index(UC_VAR(particles), UC_VAR(i)), uc::uc_array_index(UC_VAR(particles), UC_VAR(j)));
	None
	}
	None
	}
	for (
	UC_VAR(i) = 0
; 
	UC_VAR(i) < UC_FUNCTION(num_particles)()
; 
	++UC_VAR(i)
	) 
	{
	UC_FUNCTION(move_particle)(uc::uc_array_index(UC_VAR(particles), UC_VAR(i)));
	None
	}
	UC_FUNCTION(print_particle_positions)(UC_VAR(particles));
	None
	}
}
	UC_PRIMITIVE(void) UC_FUNCTION(main)(UC_ARRAY(UC_PRIMITIVE(string)) UC_VAR(args))
{
	if (uc::uc_length_field(UC_VAR(args)) > 0) 
	{
	UC_FUNCTION(simulate)(UC_FUNCTION(string_to_int)(uc::uc_array_index(UC_VAR(args), 0)));
	None
	}
	else 
	{
	UC_FUNCTION(simulate)(UC_FUNCTION(num_steps)());
	None
	}
}


} // namespace uc

int main(int argc, char **argv) {
  uc::UC_ARRAY(uc::UC_PRIMITIVE(string)) args = uc::uc_make_array_of<uc::UC_PRIMITIVE(string)>();
  for (int i = 1; i < argc; i++) {
    uc::uc_array_push(args, uc::UC_PRIMITIVE(string)(argv[i]));
  }
  uc::UC_FUNCTION(main)(args);
  return 0;
}
