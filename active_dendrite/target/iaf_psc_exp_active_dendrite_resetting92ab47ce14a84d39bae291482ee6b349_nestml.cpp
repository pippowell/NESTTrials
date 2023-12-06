// #define DEBUG 1
/*
 *  iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml.cpp
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
 *  Generated from NESTML at time: 2023-12-06 08:40:50.576422
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

#include "iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml.h"

// ---------------------------------------------------------------------------
//   Recordables map
// ---------------------------------------------------------------------------
nest::RecordablesMap<iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml> iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::recordablesMap_;
namespace nest
{

  // Override the create() method with one call to RecordablesMap::insert_()
  // for each quantity to be recorded.
template <> void RecordablesMap<iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml>::create()
  {
    // add state variables to recordables map
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_V_m, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_V_m);
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_t_dAP, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_t_dAP);
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_I_dAP, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_I_dAP);
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_enable_I_syn, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_enable_I_syn);
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_syn_kernel__X__spikes_in, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_syn_kernel__X__spikes_in);
   insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_syn_kernel__X__spikes_in__d, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_syn_kernel__X__spikes_in__d);
    // add recordable inline expressions to recordables map
	insert_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml_names::_I_syn, &iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::get_I_syn);

    // Add vector variables  
  }
}

// ---------------------------------------------------------------------------
//   Default constructors defining default parameters and state
//   Note: the implementation is empty. The initialization is of variables
//   is a part of iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml's constructor.
// ---------------------------------------------------------------------------

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::Parameters_::Parameters_()
{
}

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::State_::State_()
{
}

// ---------------------------------------------------------------------------
//   Parameter and state extractions and manipulation functions
// ---------------------------------------------------------------------------

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::Buffers_::Buffers_(iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml &n):
  logger_(n)
  , spike_inputs_( std::vector< nest::RingBuffer >( NUM_SPIKE_RECEPTORS ) )
  , spike_inputs_grid_sum_( std::vector< double >( NUM_SPIKE_RECEPTORS ) )
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::Buffers_::Buffers_(const Buffers_ &, iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml &n):
  logger_(n)
  , spike_inputs_( std::vector< nest::RingBuffer >( NUM_SPIKE_RECEPTORS ) )
  , spike_inputs_grid_sum_( std::vector< double >( NUM_SPIKE_RECEPTORS ) )
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

// ---------------------------------------------------------------------------
//   Default constructor for node
// ---------------------------------------------------------------------------

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml():StructuralPlasticityNode(), P_(), S_(), B_(*this)
{
  init_state_internal_();
  recordablesMap_.create();
  pre_run_hook();
}

// ---------------------------------------------------------------------------
//   Copy constructor for node
// ---------------------------------------------------------------------------

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml(const iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml& __n):
  StructuralPlasticityNode(), P_(__n.P_), S_(__n.S_), B_(__n.B_, *this) {

  // copy parameter struct P_
  P_.C_m = __n.P_.C_m;
  P_.tau_m = __n.P_.tau_m;
  P_.tau_syn = __n.P_.tau_syn;
  P_.V_th = __n.P_.V_th;
  P_.V_reset = __n.P_.V_reset;
  P_.I_e = __n.P_.I_e;
  P_.E_L = __n.P_.E_L;
  P_.I_th = __n.P_.I_th;
  P_.I_dAP_peak = __n.P_.I_dAP_peak;
  P_.T_dAP = __n.P_.T_dAP;

  // copy state struct S_
  S_.V_m = __n.S_.V_m;
  S_.t_dAP = __n.S_.t_dAP;
  S_.I_dAP = __n.S_.I_dAP;
  S_.enable_I_syn = __n.S_.enable_I_syn;
  S_.syn_kernel__X__spikes_in = __n.S_.syn_kernel__X__spikes_in;
  S_.syn_kernel__X__spikes_in__d = __n.S_.syn_kernel__X__spikes_in__d;

  // copy internals V_
  V_.__h = __n.V_.__h;
  V_.__P__V_m__V_m = __n.V_.__P__V_m__V_m;
  V_.__P__V_m__syn_kernel__X__spikes_in = __n.V_.__P__V_m__syn_kernel__X__spikes_in;
  V_.__P__V_m__syn_kernel__X__spikes_in__d = __n.V_.__P__V_m__syn_kernel__X__spikes_in__d;
  V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in = __n.V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in;
  V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d = __n.V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d;
  V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in = __n.V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in;
  V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d = __n.V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d;
}

// ---------------------------------------------------------------------------
//   Destructor for node
// ---------------------------------------------------------------------------

iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::~iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml()
{
}

// ---------------------------------------------------------------------------
//   Node initialization functions
// ---------------------------------------------------------------------------
void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::calibrate_time( const nest::TimeConverter& tc )
{
  LOG( nest::M_WARNING,
    "iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml",
    "Simulation resolution has changed. Internal state and parameters of the model have been reset!" );

  init_state_internal_();
}
void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::init_state_internal_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::init_state_internal_()" << std::endl;
#endif

  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function
  // initial values for parameters
    

    P_.C_m = 250; // as pF
    

    P_.tau_m = 20; // as ms
    

    P_.tau_syn = 10; // as ms
    

    P_.V_th = 25; // as mV
    

    P_.V_reset = 0; // as mV
    

    P_.I_e = 0; // as pA
    

    P_.E_L = 0; // as mV
    

    P_.I_th = 100; // as pA
    

    P_.I_dAP_peak = 450; // as pA
    

    P_.T_dAP = 30; // as ms

  recompute_internal_variables();
  // initial values for state variables
    

    S_.V_m = 0; // as mV
    

    S_.t_dAP = 0; // as ms
    

    S_.I_dAP = 0; // as pA
    

    S_.enable_I_syn = 1.0; // as real
    

    S_.syn_kernel__X__spikes_in = 0; // as real
    

    S_.syn_kernel__X__spikes_in__d = 0 * pow(1000.0, (-1)); // as 1 / s
}

void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::init_buffers_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::init_buffers_()" << std::endl;
#endif
  // spike input buffers
  get_spike_inputs_().clear();
  get_spike_inputs_grid_sum_().clear();

  B_.logger_.reset();


}

void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::recompute_internal_variables(bool exclude_timestep) {
  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function

  if (exclude_timestep) {    
      

      V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m); // as real
      

      V_.__P__V_m__syn_kernel__X__spikes_in = S_.enable_I_syn * P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_syn) + 0.25 * pow(P_.tau_syn, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn, 2) * std::exp(V_.__h / P_.tau_syn)) * std::exp((-V_.__h) / P_.tau_syn - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn + 0.25 * pow(P_.tau_syn, 2))); // as real
      

      V_.__P__V_m__syn_kernel__X__spikes_in__d = 0.25 * S_.enable_I_syn * P_.tau_m * P_.tau_syn * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_syn)) * std::exp((-V_.__h) / P_.tau_syn - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn + 0.25 * pow(P_.tau_syn, 2))); // as real
      

      V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in = 1.0 * (V_.__h + P_.tau_syn) * std::exp((-V_.__h) / P_.tau_syn) / P_.tau_syn; // as real
      

      V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn); // as real
      

      V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn) / pow(P_.tau_syn, 2); // as real
      

      V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d = 1.0 * ((-V_.__h) + P_.tau_syn) * std::exp((-V_.__h) / P_.tau_syn) / P_.tau_syn; // as real
  }
  else {    
      

      V_.__h = __resolution; // as ms
      

      V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m); // as real
      

      V_.__P__V_m__syn_kernel__X__spikes_in = S_.enable_I_syn * P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_syn) + 0.25 * pow(P_.tau_syn, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn, 2) * std::exp(V_.__h / P_.tau_syn)) * std::exp((-V_.__h) / P_.tau_syn - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn + 0.25 * pow(P_.tau_syn, 2))); // as real
      

      V_.__P__V_m__syn_kernel__X__spikes_in__d = 0.25 * S_.enable_I_syn * P_.tau_m * P_.tau_syn * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn * std::exp(V_.__h / P_.tau_syn)) * std::exp((-V_.__h) / P_.tau_syn - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn + 0.25 * pow(P_.tau_syn, 2))); // as real
      

      V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in = 1.0 * (V_.__h + P_.tau_syn) * std::exp((-V_.__h) / P_.tau_syn) / P_.tau_syn; // as real
      

      V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn); // as real
      

      V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn) / pow(P_.tau_syn, 2); // as real
      

      V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d = 1.0 * ((-V_.__h) + P_.tau_syn) * std::exp((-V_.__h) / P_.tau_syn) / P_.tau_syn; // as real
  }
}
void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::pre_run_hook() {
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


void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::update(nest::Time const & origin,const long from, const long to)
{
  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function


  // the propagators are state dependent; update them!
  recompute_internal_variables();

  for ( long lag = from ; lag < to ; ++lag )
  {
    auto get_t = [origin, lag](){ return nest::Time( nest::Time::step( origin.get_steps() + lag + 1) ).get_ms(); };

    for (long i = 0; i < NUM_SPIKE_RECEPTORS; ++i)
    {
        get_spike_inputs_grid_sum_()[i] = get_spike_inputs_()[i].get_value(lag);
    }

    // NESTML generated code for the update block
  double V_m__tmp = (-P_.E_L) * V_.__P__V_m__V_m + P_.E_L + S_.V_m * V_.__P__V_m__V_m + V_.__P__V_m__syn_kernel__X__spikes_in * S_.syn_kernel__X__spikes_in + V_.__P__V_m__syn_kernel__X__spikes_in__d * S_.syn_kernel__X__spikes_in__d - S_.I_dAP * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + S_.I_dAP * P_.tau_m / P_.C_m - P_.I_e * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + P_.I_e * P_.tau_m / P_.C_m;
  double syn_kernel__X__spikes_in__tmp = V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in * S_.syn_kernel__X__spikes_in + V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d * S_.syn_kernel__X__spikes_in__d;
  double syn_kernel__X__spikes_in__d__tmp = V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in * S_.syn_kernel__X__spikes_in + V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d * S_.syn_kernel__X__spikes_in__d;
  /* replace analytically solvable variables with precisely integrated values  */
  S_.V_m = V_m__tmp;
  S_.syn_kernel__X__spikes_in = syn_kernel__X__spikes_in__tmp;
  S_.syn_kernel__X__spikes_in__d = syn_kernel__X__spikes_in__d__tmp;
  S_.syn_kernel__X__spikes_in__d += ((0.001 * B_.spike_inputs_grid_sum_[SPIKES_IN - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn) / (1 / 1000.0);
  if (S_.t_dAP > 0)
  {  
    S_.t_dAP -= __resolution;
    if (S_.t_dAP <= 0)
    {  
      S_.I_dAP = 0;
      S_.t_dAP = 0;
      S_.syn_kernel__X__spikes_in = 0;
      S_.syn_kernel__X__spikes_in__d = 0 * pow(1000.0, (-1));
      S_.enable_I_syn = 1.0;
    }
  }
  if (S_.syn_kernel__X__spikes_in > P_.I_th)
  {  
    S_.t_dAP = P_.T_dAP;
    S_.I_dAP = P_.I_dAP_peak;
    S_.enable_I_syn = 0.0;
  }
  if (S_.V_m > P_.V_th)
  {  
    set_spiketime(nest::Time::step(origin.get_steps()+lag+1));
    nest::SpikeEvent se;
    nest::kernel().event_delivery_manager.send(*this, se, lag);
    S_.V_m = P_.V_reset;
  }
    // voltage logging
    B_.logger_.record_data(origin.get_steps() + lag);
  }
}

// Do not move this function as inline to h-file. It depends on
// universal_data_logger_impl.h being included here.
void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::handle(nest::DataLoggingRequest& e)
{
  B_.logger_.handle(e);
}


void iaf_psc_exp_active_dendrite_resetting92ab47ce14a84d39bae291482ee6b349_nestml::handle(nest::SpikeEvent &e)
{
  assert(e.get_delay_steps() > 0);
  assert( e.get_rport() < B_.spike_inputs_.size() );

  double weight = e.get_weight();
  size_t nestml_buffer_idx = 0;
  B_.spike_inputs_[ nestml_buffer_idx - MIN_SPIKE_RECEPTOR ].add_value(
    e.get_rel_delivery_steps( nest::kernel().simulation_manager.get_slice_origin() ),
    weight * e.get_multiplicity() );
}

