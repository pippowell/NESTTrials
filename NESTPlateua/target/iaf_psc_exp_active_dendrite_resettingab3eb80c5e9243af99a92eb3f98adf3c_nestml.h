
/**
 *  iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml.h
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
 *  Generated from NESTML at time: 2023-12-06 08:02:12.261396
**/
#ifndef IAF_PSC_EXP_ACTIVE_DENDRITE_RESETTINGAB3EB80C5E9243AF99A92EB3F98ADF3C_NESTML
#define IAF_PSC_EXP_ACTIVE_DENDRITE_RESETTINGAB3EB80C5E9243AF99A92EB3F98ADF3C_NESTML

#ifndef HAVE_LIBLTDL
#error "NEST was compiled without support for dynamic loading. Please install libltdl and recompile NEST."
#endif

// C++ includes:
#include <cmath>

#include "config.h"

// Includes from nestkernel:
#include "structural_plasticity_node.h"
#include "connection.h"
#include "dict_util.h"
#include "event.h"
#include "nest_types.h"
#include "ring_buffer.h"
#include "universal_data_logger.h"

// Includes from sli:
#include "dictdatum.h"

namespace nest
{
namespace iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names
{
    const Name _V_m( "V_m" );
    const Name _t_dAP( "t_dAP" );
    const Name _I_dAP( "I_dAP" );
    const Name _enable_I_syn( "enable_I_syn" );
    const Name _syn_kernel__X__spikes_in( "syn_kernel__X__spikes_in" );
    const Name _syn_kernel__X__spikes_in__d( "syn_kernel__X__spikes_in__d" );
    const Name _I_syn( "I_syn" );
    const Name _C_m( "C_m" );
    const Name _tau_m( "tau_m" );
    const Name _tau_syn( "tau_syn" );
    const Name _V_th( "V_th" );
    const Name _V_reset( "V_reset" );
    const Name _I_e( "I_e" );
    const Name _E_L( "E_L" );
    const Name _I_th( "I_th" );
    const Name _I_dAP_peak( "I_dAP_peak" );
    const Name _T_dAP( "T_dAP" );
}
}




#include "nest_time.h"
  typedef size_t nest_port_t;
  typedef size_t nest_rport_t;

/* BeginDocumentation
  Name: iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml

  Description:

    

  Parameters:
  The following parameters can be set in the status dictionary.
C_m [pF]  capacity of the membrane
tau_m [ms]  membrane time constant
tau_syn [ms]  time constant of synaptic current
V_th [mV]  action potential threshold
V_reset [mV]  reset voltage
I_e [pA]  external current
E_L [mV]  resting potential
I_th [pA]  dendritic action potential
 current-threshold for a dendritic action potential
I_dAP_peak [pA]  current clamp value for I_dAP during a dendritic action potential
T_dAP [ms]  time window over which the dendritic current clamp is active


  Dynamic state variables:
V_m [mV]  membrane potential
t_dAP [ms]  dendritic action potential timer
I_dAP [pA]  dendritic action potential current magnitude
enable_I_syn [real]  set to 1 to allow synaptic currents to


  Sends: nest::SpikeEvent

  Receives: Spike,  DataLoggingRequest
*/
class iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml : public nest::StructuralPlasticityNode
{
public:
  /**
   * The constructor is only used to create the model prototype in the model manager.
  **/
  iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml();

  /**
   * The copy constructor is used to create model copies and instances of the model.
   * @node The copy constructor needs to initialize the parameters and the state.
   *       Initialization of buffers and interal variables is deferred to
   *       @c init_buffers_() and @c pre_run_hook() (or calibrate() in NEST 3.3 and older).
  **/
  iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml(const iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml &);

  /**
   * Destructor.
  **/
  ~iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml() override;

  // -------------------------------------------------------------------------
  //   Import sets of overloaded virtual functions.
  //   See: Technical Issues / Virtual Functions: Overriding, Overloading,
  //        and Hiding
  // -------------------------------------------------------------------------

  using nest::Node::handles_test_event;
  using nest::Node::handle;

  /**
   * Used to validate that we can send nest::SpikeEvent to desired target:port.
  **/
  nest_port_t send_test_event(nest::Node& target, nest_rport_t receptor_type, nest::synindex, bool) override;


  // -------------------------------------------------------------------------
  //   Functions handling incoming events.
  //   We tell nest that we can handle incoming events of various types by
  //   defining handle() for the given event.
  // -------------------------------------------------------------------------


  void handle(nest::SpikeEvent &) override;        //! accept spikes

  void handle(nest::DataLoggingRequest &) override;//! allow recording with multimeter
  nest_port_t handles_test_event(nest::SpikeEvent&, nest_port_t) override;
  nest_port_t handles_test_event(nest::DataLoggingRequest&, nest_port_t) override;

  // -------------------------------------------------------------------------
  //   Functions for getting/setting parameters and state values.
  // -------------------------------------------------------------------------

  void get_status(DictionaryDatum &) const override;
  void set_status(const DictionaryDatum &) override;


  // -------------------------------------------------------------------------
  //   Getters/setters for state block
  // -------------------------------------------------------------------------

  inline double get_V_m() const
  {
    return S_.V_m;
  }

  inline void set_V_m(const double __v)
  {
    S_.V_m = __v;
  }

  inline double get_t_dAP() const
  {
    return S_.t_dAP;
  }

  inline void set_t_dAP(const double __v)
  {
    S_.t_dAP = __v;
  }

  inline double get_I_dAP() const
  {
    return S_.I_dAP;
  }

  inline void set_I_dAP(const double __v)
  {
    S_.I_dAP = __v;
  }

  inline double get_enable_I_syn() const
  {
    return S_.enable_I_syn;
  }

  inline void set_enable_I_syn(const double __v)
  {
    S_.enable_I_syn = __v;
  }

  inline double get_syn_kernel__X__spikes_in() const
  {
    return S_.syn_kernel__X__spikes_in;
  }

  inline void set_syn_kernel__X__spikes_in(const double __v)
  {
    S_.syn_kernel__X__spikes_in = __v;
  }

  inline double get_syn_kernel__X__spikes_in__d() const
  {
    return S_.syn_kernel__X__spikes_in__d;
  }

  inline void set_syn_kernel__X__spikes_in__d(const double __v)
  {
    S_.syn_kernel__X__spikes_in__d = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for parameters
  // -------------------------------------------------------------------------

  inline double get_C_m() const
  {
    return P_.C_m;
  }

  inline void set_C_m(const double __v)
  {
    P_.C_m = __v;
  }

  inline double get_tau_m() const
  {
    return P_.tau_m;
  }

  inline void set_tau_m(const double __v)
  {
    P_.tau_m = __v;
  }

  inline double get_tau_syn() const
  {
    return P_.tau_syn;
  }

  inline void set_tau_syn(const double __v)
  {
    P_.tau_syn = __v;
  }

  inline double get_V_th() const
  {
    return P_.V_th;
  }

  inline void set_V_th(const double __v)
  {
    P_.V_th = __v;
  }

  inline double get_V_reset() const
  {
    return P_.V_reset;
  }

  inline void set_V_reset(const double __v)
  {
    P_.V_reset = __v;
  }

  inline double get_I_e() const
  {
    return P_.I_e;
  }

  inline void set_I_e(const double __v)
  {
    P_.I_e = __v;
  }

  inline double get_E_L() const
  {
    return P_.E_L;
  }

  inline void set_E_L(const double __v)
  {
    P_.E_L = __v;
  }

  inline double get_I_th() const
  {
    return P_.I_th;
  }

  inline void set_I_th(const double __v)
  {
    P_.I_th = __v;
  }

  inline double get_I_dAP_peak() const
  {
    return P_.I_dAP_peak;
  }

  inline void set_I_dAP_peak(const double __v)
  {
    P_.I_dAP_peak = __v;
  }

  inline double get_T_dAP() const
  {
    return P_.T_dAP;
  }

  inline void set_T_dAP(const double __v)
  {
    P_.T_dAP = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for internals
  // -------------------------------------------------------------------------

  inline double get___h() const
  {
    return V_.__h;
  }

  inline void set___h(const double __v)
  {
    V_.__h = __v;
  }
  inline double get___P__V_m__V_m() const
  {
    return V_.__P__V_m__V_m;
  }

  inline void set___P__V_m__V_m(const double __v)
  {
    V_.__P__V_m__V_m = __v;
  }
  inline double get___P__V_m__syn_kernel__X__spikes_in() const
  {
    return V_.__P__V_m__syn_kernel__X__spikes_in;
  }

  inline void set___P__V_m__syn_kernel__X__spikes_in(const double __v)
  {
    V_.__P__V_m__syn_kernel__X__spikes_in = __v;
  }
  inline double get___P__V_m__syn_kernel__X__spikes_in__d() const
  {
    return V_.__P__V_m__syn_kernel__X__spikes_in__d;
  }

  inline void set___P__V_m__syn_kernel__X__spikes_in__d(const double __v)
  {
    V_.__P__V_m__syn_kernel__X__spikes_in__d = __v;
  }
  inline double get___P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in() const
  {
    return V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in;
  }

  inline void set___P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in(const double __v)
  {
    V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in = __v;
  }
  inline double get___P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d() const
  {
    return V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d;
  }

  inline void set___P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d(const double __v)
  {
    V_.__P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d = __v;
  }
  inline double get___P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in() const
  {
    return V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in;
  }

  inline void set___P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in(const double __v)
  {
    V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in = __v;
  }
  inline double get___P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d() const
  {
    return V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d;
  }

  inline void set___P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d(const double __v)
  {
    V_.__P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d = __v;
  }


  // -------------------------------------------------------------------------
  //   Initialization functions
  // -------------------------------------------------------------------------
  void calibrate_time( const nest::TimeConverter& tc ) override;

protected:

private:
  void recompute_internal_variables(bool exclude_timestep=false);

private:

  static const nest_port_t MIN_SPIKE_RECEPTOR = 0;
  static const nest_port_t PORT_NOT_AVAILABLE = -1;

  enum SynapseTypes
  {
    SPIKES_IN = 0,
    MAX_SPIKE_RECEPTOR = 1
  };

  static const size_t NUM_SPIKE_RECEPTORS = MAX_SPIKE_RECEPTOR - MIN_SPIKE_RECEPTOR;



  /**
   * Reset state of neuron.
  **/

  void init_state_internal_();

  /**
   * Reset internal buffers of neuron.
  **/
  void init_buffers_() override;

  /**
   * Initialize auxiliary quantities, leave parameters and state untouched.
  **/
  void pre_run_hook() override;

  /**
   * Take neuron through given time interval
  **/
  void update(nest::Time const &, const long, const long) override;

  // The next two classes need to be friends to access the State_ class/member
  friend class nest::RecordablesMap<iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml>;
  friend class nest::UniversalDataLogger<iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml>;

  /**
   * Free parameters of the neuron.
   *


   *
   * These are the parameters that can be set by the user through @c `node.set()`.
   * They are initialized from the model prototype when the node is created.
   * Parameters do not change during calls to @c update() and are not reset by
   * @c ResetNetwork.
   *
   * @note Parameters_ need neither copy constructor nor @c operator=(), since
   *       all its members are copied properly by the default copy constructor
   *       and assignment operator. Important:
   *       - If Parameters_ contained @c Time members, you need to define the
   *         assignment operator to recalibrate all members of type @c Time . You
   *         may also want to define the assignment operator.
   *       - If Parameters_ contained members that cannot copy themselves, such
   *         as C-style arrays, you need to define the copy constructor and
   *         assignment operator to copy those members.
  **/
  struct Parameters_
  {    
    //!  capacity of the membrane
    double C_m;
    //!  membrane time constant
    double tau_m;
    //!  time constant of synaptic current
    double tau_syn;
    //!  action potential threshold
    double V_th;
    //!  reset voltage
    double V_reset;
    //!  external current
    double I_e;
    //!  resting potential
    double E_L;
    //!  dendritic action potential
    //!  current-threshold for a dendritic action potential
    double I_th;
    //!  current clamp value for I_dAP during a dendritic action potential
    double I_dAP_peak;
    //!  time window over which the dendritic current clamp is active
    double T_dAP;

    /**
     * Initialize parameters to their default values.
    **/
    Parameters_();
  };

  /**
   * Dynamic state of the neuron.
   *
   *
   *
   * These are the state variables that are advanced in time by calls to
   * @c update(). In many models, some or all of them can be set by the user
   * through @c `node.set()`. The state variables are initialized from the model
   * prototype when the node is created. State variables are reset by @c ResetNetwork.
   *
   * @note State_ need neither copy constructor nor @c operator=(), since
   *       all its members are copied properly by the default copy constructor
   *       and assignment operator. Important:
   *       - If State_ contained @c Time members, you need to define the
   *         assignment operator to recalibrate all members of type @c Time . You
   *         may also want to define the assignment operator.
   *       - If State_ contained members that cannot copy themselves, such
   *         as C-style arrays, you need to define the copy constructor and
   *         assignment operator to copy those members.
  **/
  struct State_
  {    
    //!  membrane potential
    double V_m;
    //!  dendritic action potential timer
    double t_dAP;
    //!  dendritic action potential current magnitude
    double I_dAP;
    //!  set to 1 to allow synaptic currents to
    double enable_I_syn;
    double syn_kernel__X__spikes_in;
    double syn_kernel__X__spikes_in__d;

    State_();
  };

  struct DelayedVariables_
  {
  };

  /**
   * Internal variables of the neuron.
   *
   *
   *
   * These variables must be initialized by @c pre_run_hook (or calibrate in NEST 3.3 and older), which is called before
   * the first call to @c update() upon each call to @c Simulate.
   * @node Variables_ needs neither constructor, copy constructor or assignment operator,
   *       since it is initialized by @c pre_run_hook() (or calibrate() in NEST 3.3 and older). If Variables_ has members that
   *       cannot destroy themselves, Variables_ will need a destructor.
  **/
  struct Variables_
  {
    double __h;
    double __P__V_m__V_m;
    double __P__V_m__syn_kernel__X__spikes_in;
    double __P__V_m__syn_kernel__X__spikes_in__d;
    double __P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in;
    double __P__syn_kernel__X__spikes_in__syn_kernel__X__spikes_in__d;
    double __P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in;
    double __P__syn_kernel__X__spikes_in__d__syn_kernel__X__spikes_in__d;
  };

  /**
   * Buffers of the neuron.
   * Usually buffers for incoming spikes and data logged for analog recorders.
   * Buffers must be initialized by @c init_buffers_(), which is called before
   * @c pre_run_hook() (or calibrate() in NEST 3.3 and older) on the first call to @c Simulate after the start of NEST,
   * ResetKernel or ResetNetwork.
   * @node Buffers_ needs neither constructor, copy constructor or assignment operator,
   *       since it is initialized by @c init_nodes_(). If Buffers_ has members that
   *       cannot destroy themselves, Buffers_ will need a destructor.
  **/
  struct Buffers_
  {
    Buffers_(iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml &);
    Buffers_(const Buffers_ &, iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml &);

    /**
     * Logger for all analog data
    **/
    nest::UniversalDataLogger<iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml> logger_;

    // -----------------------------------------------------------------------
    //   Buffers and sums of incoming spikes/currents per timestep
    // -----------------------------------------------------------------------
    // Buffer containing the incoming spikes
    

inline std::vector< nest::RingBuffer >& get_spike_inputs_()
{
    return spike_inputs_;
}
std::vector< nest::RingBuffer > spike_inputs_;

    // Buffer containing the sum of all the incoming spikes
    

inline std::vector< double >& get_spike_inputs_grid_sum_()
{
    return spike_inputs_grid_sum_;
}
std::vector< double > spike_inputs_grid_sum_;
  };

  // -------------------------------------------------------------------------
  //   Getters/setters for inline expressions
  // -------------------------------------------------------------------------
  inline double get_I_syn() const
  {
    return S_.syn_kernel__X__spikes_in * 1.0;
  }



  // -------------------------------------------------------------------------
  //   Getters/setters for input buffers
  // -------------------------------------------------------------------------

  // Buffer containing the incoming spikes
  

inline std::vector< nest::RingBuffer >& get_spike_inputs_()
{
    return B_.get_spike_inputs_();
}

  

inline std::vector< double >& get_spike_inputs_grid_sum_()
{
    return B_.get_spike_inputs_grid_sum_();
}

  // -------------------------------------------------------------------------
  //   Member variables of neuron model.
  //   Each model neuron should have precisely the following four data members,
  //   which are one instance each of the parameters, state, buffers and variables
  //   structures. Experience indicates that the state and variables member should
  //   be next to each other to achieve good efficiency (caching).
  //   Note: Devices require one additional data member, an instance of the
  //   ``Device`` child class they belong to.
  // -------------------------------------------------------------------------


  Parameters_       P_;        //!< Free parameters.
  State_            S_;        //!< Dynamic state.
  DelayedVariables_ DV_;       //!< Delayed state variables.
  Variables_        V_;        //!< Internal Variables
  Buffers_          B_;        //!< Buffers.

  //! Mapping of recordables names to access functions
  static nest::RecordablesMap<iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml> recordablesMap_;

}; /* neuron iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml */

inline nest_port_t iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml::send_test_event(nest::Node& target, nest_rport_t receptor_type, nest::synindex, bool)
{
  // You should usually not change the code in this function.
  // It confirms that the target of connection @c c accepts @c nest::SpikeEvent on
  // the given @c receptor_type.
  nest::SpikeEvent e;
  e.set_sender(*this);
  return target.handles_test_event(e, receptor_type);
}

inline nest_port_t iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml::handles_test_event(nest::SpikeEvent&, nest_port_t receptor_type)
{
    // You should usually not change the code in this function.
    // It confirms to the connection management system that we are able
    // to handle @c SpikeEvent on port 0. You need to extend the function
    // if you want to differentiate between input ports.
    if (receptor_type != 0)
    {
      throw nest::UnknownReceptorType(receptor_type, get_name());
    }
    return 0;
}

inline nest_port_t iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml::handles_test_event(nest::DataLoggingRequest& dlr, nest_port_t receptor_type)
{
  // You should usually not change the code in this function.
  // It confirms to the connection management system that we are able
  // to handle @c DataLoggingRequest on port 0.
  // The function also tells the built-in UniversalDataLogger that this node
  // is recorded from and that it thus needs to collect data during simulation.
  if (receptor_type != 0)
  {
    throw nest::UnknownReceptorType(receptor_type, get_name());
  }

  return B_.logger_.connect_logging_device(dlr, recordablesMap_);
}

inline void iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml::get_status(DictionaryDatum &__d) const
{
  // parameters
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_C_m, get_C_m());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_tau_m, get_tau_m());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_tau_syn, get_tau_syn());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_th, get_V_th());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_reset, get_V_reset());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_e, get_I_e());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_E_L, get_E_L());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_th, get_I_th());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_dAP_peak, get_I_dAP_peak());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_T_dAP, get_T_dAP());

  // initial values for state variables in ODE or kernel
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_m, get_V_m());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_t_dAP, get_t_dAP());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_dAP, get_I_dAP());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_enable_I_syn, get_enable_I_syn());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_syn_kernel__X__spikes_in, get_syn_kernel__X__spikes_in());
  def<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_syn_kernel__X__spikes_in__d, get_syn_kernel__X__spikes_in__d());

  StructuralPlasticityNode::get_status( __d );

  (*__d)[nest::names::recordables] = recordablesMap_.get_list();
}

inline void iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml::set_status(const DictionaryDatum &__d)
{
  // parameters
  double tmp_C_m = get_C_m();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_C_m, tmp_C_m, this);
  double tmp_tau_m = get_tau_m();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_tau_m, tmp_tau_m, this);
  double tmp_tau_syn = get_tau_syn();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_tau_syn, tmp_tau_syn, this);
  double tmp_V_th = get_V_th();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_th, tmp_V_th, this);
  double tmp_V_reset = get_V_reset();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_reset, tmp_V_reset, this);
  double tmp_I_e = get_I_e();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_e, tmp_I_e, this);
  double tmp_E_L = get_E_L();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_E_L, tmp_E_L, this);
  double tmp_I_th = get_I_th();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_th, tmp_I_th, this);
  double tmp_I_dAP_peak = get_I_dAP_peak();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_dAP_peak, tmp_I_dAP_peak, this);
  double tmp_T_dAP = get_T_dAP();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_T_dAP, tmp_T_dAP, this);

  // initial values for state variables in ODE or kernel
  double tmp_V_m = get_V_m();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_V_m, tmp_V_m, this);
  double tmp_t_dAP = get_t_dAP();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_t_dAP, tmp_t_dAP, this);
  double tmp_I_dAP = get_I_dAP();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_I_dAP, tmp_I_dAP, this);
  double tmp_enable_I_syn = get_enable_I_syn();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_enable_I_syn, tmp_enable_I_syn, this);
  double tmp_syn_kernel__X__spikes_in = get_syn_kernel__X__spikes_in();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_syn_kernel__X__spikes_in, tmp_syn_kernel__X__spikes_in, this);
  double tmp_syn_kernel__X__spikes_in__d = get_syn_kernel__X__spikes_in__d();
  nest::updateValueParam<double>(__d, nest::iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml_names::_syn_kernel__X__spikes_in__d, tmp_syn_kernel__X__spikes_in__d, this);

  // We now know that (ptmp, stmp) are consistent. We do not
  // write them back to (P_, S_) before we are also sure that
  // the properties to be set in the parent class are internally
  // consistent.
  StructuralPlasticityNode::set_status(__d);

  // if we get here, temporaries contain consistent set of properties
  set_C_m(tmp_C_m);
  set_tau_m(tmp_tau_m);
  set_tau_syn(tmp_tau_syn);
  set_V_th(tmp_V_th);
  set_V_reset(tmp_V_reset);
  set_I_e(tmp_I_e);
  set_E_L(tmp_E_L);
  set_I_th(tmp_I_th);
  set_I_dAP_peak(tmp_I_dAP_peak);
  set_T_dAP(tmp_T_dAP);
  set_V_m(tmp_V_m);
  set_t_dAP(tmp_t_dAP);
  set_I_dAP(tmp_I_dAP);
  set_enable_I_syn(tmp_enable_I_syn);
  set_syn_kernel__X__spikes_in(tmp_syn_kernel__X__spikes_in);
  set_syn_kernel__X__spikes_in__d(tmp_syn_kernel__X__spikes_in__d);





  // recompute internal variables in case they are dependent on parameters or state that might have been updated in this call to set_status()
  recompute_internal_variables();
};



#endif /* #ifndef IAF_PSC_EXP_ACTIVE_DENDRITE_RESETTINGAB3EB80C5E9243AF99A92EB3F98ADF3C_NESTML */
