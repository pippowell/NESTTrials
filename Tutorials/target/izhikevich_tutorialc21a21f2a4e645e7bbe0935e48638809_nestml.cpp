// #define DEBUG 1
/*
 *  izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml.cpp
 *
 *  This file is part of NEST.
 *
 *  Copyright (C) 2004 The NEST Initiative
 *
 *  NEST is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  NEST is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NEST.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Generated from NESTML at time: 2023-12-04 13:22:53.551436
**/

// C++ includes:
#include <limits>

// Includes from libnestutil:
#include "numerics.h"

// Includes from nestkernel:
#include "exceptions.h"
#include "kernel_manager.h"
#include "universal_data_logger_impl.h"

// Includes from sli:
#include "dict.h"
#include "dictutils.h"
#include "doubledatum.h"
#include "integerdatum.h"
#include "lockptrdatum.h"

#include "izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml.h"

// ---------------------------------------------------------------------------
//   Recordables map
// ---------------------------------------------------------------------------
nest::RecordablesMap<izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml> izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::recordablesMap_;
namespace nest
{

  // Override the create() method with one call to RecordablesMap::insert_()
  // for each quantity to be recorded.
template <> void RecordablesMap<izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml>::create()
  {
    // add state variables to recordables map
   insert_(izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml_names::_v, &izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::get_v);
   insert_(izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml_names::_u, &izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::get_u);

    // Add vector variables  
  }
}

// ---------------------------------------------------------------------------
//   Default constructors defining default parameters and state
//   Note: the implementation is empty. The initialization is of variables
//   is a part of izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml's constructor.
// ---------------------------------------------------------------------------

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::Parameters_::Parameters_()
{
}

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::State_::State_()
{
}

// ---------------------------------------------------------------------------
//   Parameter and state extractions and manipulation functions
// ---------------------------------------------------------------------------

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::Buffers_::Buffers_(izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml &n):
  logger_(n)
  , spike_inputs_( std::vector< nest::RingBuffer >( NUM_SPIKE_RECEPTORS ) )
  , spike_inputs_grid_sum_( std::vector< double >( NUM_SPIKE_RECEPTORS ) )
  , __s( nullptr ), __c( nullptr ), __e( nullptr )
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::Buffers_::Buffers_(const Buffers_ &, izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml &n):
  logger_(n)
  , spike_inputs_( std::vector< nest::RingBuffer >( NUM_SPIKE_RECEPTORS ) )
  , spike_inputs_grid_sum_( std::vector< double >( NUM_SPIKE_RECEPTORS ) )
  , __s( nullptr ), __c( nullptr ), __e( nullptr )
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

// ---------------------------------------------------------------------------
//   Default constructor for node
// ---------------------------------------------------------------------------

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml():StructuralPlasticityNode(), P_(), S_(), B_(*this)
{
  init_state_internal_();
  recordablesMap_.create();
  pre_run_hook();
}

// ---------------------------------------------------------------------------
//   Copy constructor for node
// ---------------------------------------------------------------------------

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml(const izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml& __n):
  StructuralPlasticityNode(), P_(__n.P_), S_(__n.S_), B_(__n.B_, *this) {

  // copy parameter struct P_
  P_.a = __n.P_.a;
  P_.b = __n.P_.b;
  P_.c = __n.P_.c;
  P_.d = __n.P_.d;

  // copy state struct S_
  S_.ode_state[State_::v] = __n.S_.ode_state[State_::v];
  S_.ode_state[State_::u] = __n.S_.ode_state[State_::u];

  // copy internals V_
  V_.__h = __n.V_.__h;
}

// ---------------------------------------------------------------------------
//   Destructor for node
// ---------------------------------------------------------------------------

izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::~izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml()
{
  // GSL structs may not have been allocated, so we need to protect destruction

  if (B_.__s)
  {
    gsl_odeiv_step_free( B_.__s );
  }

  if (B_.__c)
  {
    gsl_odeiv_control_free( B_.__c );
  }

  if (B_.__e)
  {
    gsl_odeiv_evolve_free( B_.__e );
  }
}

// ---------------------------------------------------------------------------
//   Node initialization functions
// ---------------------------------------------------------------------------
void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::calibrate_time( const nest::TimeConverter& tc )
{
  LOG( nest::M_WARNING,
    "izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml",
    "Simulation resolution has changed. Internal state and parameters of the model have been reset!" );

  init_state_internal_();
}
void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::init_state_internal_()
{
#ifdef DEBUG
  std::cout << "izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::init_state_internal_()" << std::endl;
#endif

  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function

  // use a default "good enough" value for the absolute error. It can be adjusted via `node.set()`
  P_.__gsl_error_tol = 1e-3;
  // initial values for parameters
    

    P_.a = 0.02; // as real
    

    P_.b = 0.2; // as real
    

    P_.c = (-65); // as mV
    

    P_.d = 8.0; // as real

  recompute_internal_variables();
  // initial values for state variables
    

    S_.ode_state[State_::v] = (-65); // as mV
    

    S_.ode_state[State_::u] = 0; // as real
}

void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::init_buffers_()
{
#ifdef DEBUG
  std::cout << "izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::init_buffers_()" << std::endl;
#endif
  // spike input buffers
  get_spike_inputs_().clear();
  get_spike_inputs_grid_sum_().clear();

  // continuous time input buffers  

  get_I_e().clear();
  B_.I_e_grid_sum_ = 0;

  B_.logger_.reset();



  if ( not B_.__s )
  {
    B_.__s = gsl_odeiv_step_alloc( gsl_odeiv_step_rkf45, State_::STATE_VEC_SIZE );
  }
  else
  {
    gsl_odeiv_step_reset( B_.__s );
  }

  if ( not B_.__c )
  {
    B_.__c = gsl_odeiv_control_y_new( P_.__gsl_error_tol, 0.0 );
  }
  else
  {
    gsl_odeiv_control_init( B_.__c, P_.__gsl_error_tol, 0.0, 1.0, 0.0 );
  }

  if ( not B_.__e )
  {
    B_.__e = gsl_odeiv_evolve_alloc( State_::STATE_VEC_SIZE );
  }
  else
  {
    gsl_odeiv_evolve_reset( B_.__e );
  }

  B_.__sys.function = izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml_dynamics;
  B_.__sys.jacobian = nullptr;
  B_.__sys.dimension = State_::STATE_VEC_SIZE;
  B_.__sys.params = reinterpret_cast< void* >( this );
  B_.__step = nest::Time::get_resolution().get_ms();
  B_.__integration_step = nest::Time::get_resolution().get_ms();
}

void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::recompute_internal_variables(bool exclude_timestep) {
  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function

  if (exclude_timestep) {    
  }
  else {    
      

      V_.__h = __resolution; // as ms
  }
}
void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::pre_run_hook() {
  B_.logger_.init();

  // parameters might have changed -- recompute internals
  recompute_internal_variables();

  // buffers B_
  B_.spike_inputs_.resize(NUM_SPIKE_RECEPTORS);
  B_.spike_inputs_grid_sum_.resize(NUM_SPIKE_RECEPTORS);
}

// ---------------------------------------------------------------------------
//   Update and spike handling functions
// ---------------------------------------------------------------------------

extern "C" inline int izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml_dynamics(double __time, const double ode_state[], double f[], void* pnode)
{
  typedef izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::State_ State_;
  // get access to node so we can almost work as in a member function
  assert( pnode );
  const izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml& node = *( reinterpret_cast< izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml* >( pnode ) );

  // ode_state[] here is---and must be---the state vector supplied by the integrator,
  // not the state vector in the node, node.S_.ode_state[].
  f[State_::v] = 1.0 * node.B_.I_e_grid_sum_ - 1.0 * ode_state[State_::u] + 0.04 * pow(ode_state[State_::v], 2) + 5.0 * ode_state[State_::v] + 140.0;
  f[State_::u] = 1.0 * node.P_.a * node.P_.b * ode_state[State_::v] - 1.0 * node.P_.a * ode_state[State_::u];
  return GSL_SUCCESS;
}

void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::update(nest::Time const & origin,const long from, const long to)
{
  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function



  for ( long lag = from ; lag < to ; ++lag )
  {
    auto get_t = [origin, lag](){ return nest::Time( nest::Time::step( origin.get_steps() + lag + 1) ).get_ms(); };

    for (long i = 0; i < NUM_SPIKE_RECEPTORS; ++i)
    {
        get_spike_inputs_grid_sum_()[i] = get_spike_inputs_()[i].get_value(lag);
    }
    B_.I_e_grid_sum_ = get_I_e().get_value(lag);

    // NESTML generated code for the update block
  double __t = 0;
  // numerical integration with adaptive step size control:
  // ------------------------------------------------------
  // gsl_odeiv_evolve_apply performs only a single numerical
  // integration step, starting from t and bounded by step;
  // the while-loop ensures integration over the whole simulation
  // step (0, step] if more than one integration step is needed due
  // to a small integration step size;
  // note that (t+IntegrationStep > step) leads to integration over
  // (t, step] and afterwards setting t to step, but it does not
  // enforce setting IntegrationStep to step-t; this is of advantage
  // for a consistent and efficient integration across subsequent
  // simulation intervals
  while ( __t < B_.__step )
  {

    const int status = gsl_odeiv_evolve_apply(B_.__e,
                                              B_.__c,
                                              B_.__s,
                                              &B_.__sys,              // system of ODE
                                              &__t,                   // from t
                                              B_.__step,              // to t <= step
                                              &B_.__integration_step, // integration step size
                                              S_.ode_state);          // neuronal state

    if ( status != GSL_SUCCESS )
    {
      throw nest::GSLSolverFailure( get_name(), status );
    }
  }
  /* replace analytically solvable variables with precisely integrated values  */
  S_.ode_state[State_::v] += (0.001 * B_.spike_inputs_grid_sum_[SPIKES - MIN_SPIKE_RECEPTOR]) * 1.0 * 1000.0;
  if (S_.ode_state[State_::v] >= 30)
  {  
    S_.ode_state[State_::v] = P_.c;
    S_.ode_state[State_::u] += P_.d;
    set_spiketime(nest::Time::step(origin.get_steps()+lag+1));
    nest::SpikeEvent se;
    nest::kernel().event_delivery_manager.send(*this, se, lag);
  }
    // voltage logging
    B_.logger_.record_data(origin.get_steps() + lag);
  }
}

// Do not move this function as inline to h-file. It depends on
// universal_data_logger_impl.h being included here.
void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::handle(nest::DataLoggingRequest& e)
{
  B_.logger_.handle(e);
}


void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::handle(nest::SpikeEvent &e)
{
  assert(e.get_delay_steps() > 0);
  assert( e.get_rport() < B_.spike_inputs_.size() );

  double weight = e.get_weight();
  size_t nestml_buffer_idx = 0;
  B_.spike_inputs_[ nestml_buffer_idx - MIN_SPIKE_RECEPTOR ].add_value(
    e.get_rel_delivery_steps( nest::kernel().simulation_manager.get_slice_origin() ),
    weight * e.get_multiplicity() );
}

void izhikevich_tutorialc21a21f2a4e645e7bbe0935e48638809_nestml::handle(nest::CurrentEvent& e)
{
  assert(e.get_delay_steps() > 0);

  const double current = e.get_current();     // we assume that in NEST, this returns a current in pA
  const double weight = e.get_weight();
  get_I_e().add_value(
               e.get_rel_delivery_steps( nest::kernel().simulation_manager.get_slice_origin()),
               weight * current );
}

