
/**
 *  izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml.h
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
 *  Generated from NESTML at time: 2023-12-04 13:23:19.091021
**/
#ifndef IZHIKEVICH_TUTORIALAC9B74CB1232433994E7C5B9F2B63062_NESTML
#define IZHIKEVICH_TUTORIALAC9B74CB1232433994E7C5B9F2B63062_NESTML

#ifndef HAVE_LIBLTDL
#error "NEST was compiled without support for dynamic loading. Please install libltdl and recompile NEST."
#endif

// C++ includes:
#include <cmath>

#include "config.h"

#ifndef HAVE_GSL
#error "The GSL library is required for the Runge-Kutta solver."
#endif

// External includes:
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

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
namespace izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names
{
    const Name _v( "v" );
    const Name _u( "u" );
    const Name _a( "a" );
    const Name _b( "b" );
    const Name _c( "c" );
    const Name _d( "d" );
}
}



/**
 * Function computing right-hand side of ODE for GSL solver.
 * @note Must be declared here so we can befriend it in class.
 * @note Must have C-linkage for passing to GSL. Internally, it is
 *       a first-class C++ function, but cannot be a member function
 *       because of the C-linkage.
 * @note No point in declaring it inline, since it is called
 *       through a function pointer.
 * @param void* Pointer to model neuron instance.
**/
extern "C" inline int izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_dynamics( double, const double y[], double f[], void* pnode );


#include "nest_time.h"
  typedef size_t nest_port_t;
  typedef size_t nest_rport_t;

/* BeginDocumentation
  Name: izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml

  Description:

    

  Parameters:
  The following parameters can be set in the status dictionary.
a [real]  describes time scale of recovery variable
b [real]  sensitivity of recovery variable
c [mV]  after-spike reset value of v
d [real]  after-spike reset value of u


  Dynamic state variables:
v [mV]  Membrane potential in mV
u [real]  Membrane potential recovery variable


  Sends: nest::SpikeEvent

  Receives: Spike, Current, DataLoggingRequest
*/
class izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml : public nest::StructuralPlasticityNode
{
public:
  /**
   * The constructor is only used to create the model prototype in the model manager.
  **/
  izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml();

  /**
   * The copy constructor is used to create model copies and instances of the model.
   * @node The copy constructor needs to initialize the parameters and the state.
   *       Initialization of buffers and interal variables is deferred to
   *       @c init_buffers_() and @c pre_run_hook() (or calibrate() in NEST 3.3 and older).
  **/
  izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml(const izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml &);

  /**
   * Destructor.
  **/
  ~izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml() override;

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
  void handle(nest::CurrentEvent &) override;      //! accept input current

  void handle(nest::DataLoggingRequest &) override;//! allow recording with multimeter
  nest_port_t handles_test_event(nest::SpikeEvent&, nest_port_t) override;
  nest_port_t handles_test_event(nest::CurrentEvent&, nest_port_t) override;
  nest_port_t handles_test_event(nest::DataLoggingRequest&, nest_port_t) override;

  // -------------------------------------------------------------------------
  //   Functions for getting/setting parameters and state values.
  // -------------------------------------------------------------------------

  void get_status(DictionaryDatum &) const override;
  void set_status(const DictionaryDatum &) override;


  // -------------------------------------------------------------------------
  //   Getters/setters for state block
  // -------------------------------------------------------------------------

  inline double get_v() const
  {
    return S_.ode_state[State_::v];
  }

  inline void set_v(const double __v)
  {
    S_.ode_state[State_::v] = __v;
  }

  inline double get_u() const
  {
    return S_.ode_state[State_::u];
  }

  inline void set_u(const double __v)
  {
    S_.ode_state[State_::u] = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for parameters
  // -------------------------------------------------------------------------

  inline double get_a() const
  {
    return P_.a;
  }

  inline void set_a(const double __v)
  {
    P_.a = __v;
  }

  inline double get_b() const
  {
    return P_.b;
  }

  inline void set_b(const double __v)
  {
    P_.b = __v;
  }

  inline double get_c() const
  {
    return P_.c;
  }

  inline void set_c(const double __v)
  {
    P_.c = __v;
  }

  inline double get_d() const
  {
    return P_.d;
  }

  inline void set_d(const double __v)
  {
    P_.d = __v;
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
    SPIKES = 0,
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
  friend class nest::RecordablesMap<izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml>;
  friend class nest::UniversalDataLogger<izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml>;

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
    //!  describes time scale of recovery variable
    double a;
    //!  sensitivity of recovery variable
    double b;
    //!  after-spike reset value of v
    double c;
    //!  after-spike reset value of u
    double d;

    double __gsl_error_tol;

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

    // non-ODE state variables
    //! Symbolic indices to the elements of the state vector y
    enum StateVecElems
    {
      v,
      u,
      // moved state variables from synapse (numeric)
      // moved state variables from synapse (analytic)
      // final entry to easily get the vector size
      STATE_VEC_SIZE
    };

    //! state vector, must be C-array for GSL solver
    double ode_state[STATE_VEC_SIZE];

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
    Buffers_(izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml &);
    Buffers_(const Buffers_ &, izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml &);

    /**
     * Logger for all analog data
    **/
    nest::UniversalDataLogger<izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml> logger_;

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

nest::RingBuffer
 I_e;   //!< Buffer for input (type: pA)    
    inline nest::RingBuffer& get_I_e() {
        return I_e;
    }

double I_e_grid_sum_;

    // -----------------------------------------------------------------------
    //   GSL ODE solver data structures
    // -----------------------------------------------------------------------

    gsl_odeiv_step* __s;    //!< stepping function
    gsl_odeiv_control* __c; //!< adaptive stepsize control function
    gsl_odeiv_evolve* __e;  //!< evolution function
    gsl_odeiv_system __sys; //!< struct describing system

    // __integration_step should be reset with the neuron on ResetNetwork,
    // but remain unchanged during calibration. Since it is initialized with
    // step_, and the resolution cannot change after nodes have been created,
    // it is safe to place both here.
    double __step;             //!< step size in ms
    double __integration_step; //!< current integration time step, updated by GSL
  };

  // -------------------------------------------------------------------------
  //   Getters/setters for inline expressions
  // -------------------------------------------------------------------------
  

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
  
inline nest::RingBuffer& get_I_e() {
    return B_.get_I_e();
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
  static nest::RecordablesMap<izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml> recordablesMap_;
  friend int izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_dynamics( double, const double y[], double f[], void* pnode );


}; /* neuron izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml */

inline nest_port_t izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::send_test_event(nest::Node& target, nest_rport_t receptor_type, nest::synindex, bool)
{
  // You should usually not change the code in this function.
  // It confirms that the target of connection @c c accepts @c nest::SpikeEvent on
  // the given @c receptor_type.
  nest::SpikeEvent e;
  e.set_sender(*this);
  return target.handles_test_event(e, receptor_type);
}

inline nest_port_t izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::handles_test_event(nest::SpikeEvent&, nest_port_t receptor_type)
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

inline nest_port_t izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::handles_test_event(nest::CurrentEvent&, nest_port_t receptor_type)
{
  // You should usually not change the code in this function.
  // It confirms to the connection management system that we are able
  // to handle @c CurrentEvent on port 0. You need to extend the function
  // if you want to differentiate between input ports.
  if (receptor_type != 0)
  {
    throw nest::UnknownReceptorType(receptor_type, get_name());
  }
  return 0;
}

inline nest_port_t izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::handles_test_event(nest::DataLoggingRequest& dlr, nest_port_t receptor_type)
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

inline void izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::get_status(DictionaryDatum &__d) const
{
  // parameters
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_a, get_a());
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_b, get_b());
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_c, get_c());
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_d, get_d());

  // initial values for state variables in ODE or kernel
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_v, get_v());
  def<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_u, get_u());

  StructuralPlasticityNode::get_status( __d );

  (*__d)[nest::names::recordables] = recordablesMap_.get_list();
  def< double >(__d, nest::names::gsl_error_tol, P_.__gsl_error_tol);
  if ( P_.__gsl_error_tol <= 0. ){
    throw nest::BadProperty( "The gsl_error_tol must be strictly positive." );
  }
}

inline void izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml::set_status(const DictionaryDatum &__d)
{
  // parameters
  double tmp_a = get_a();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_a, tmp_a, this);
  double tmp_b = get_b();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_b, tmp_b, this);
  double tmp_c = get_c();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_c, tmp_c, this);
  double tmp_d = get_d();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_d, tmp_d, this);

  // initial values for state variables in ODE or kernel
  double tmp_v = get_v();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_v, tmp_v, this);
  double tmp_u = get_u();
  nest::updateValueParam<double>(__d, nest::izhikevich_tutorialac9b74cb1232433994e7c5b9f2b63062_nestml_names::_u, tmp_u, this);

  // We now know that (ptmp, stmp) are consistent. We do not
  // write them back to (P_, S_) before we are also sure that
  // the properties to be set in the parent class are internally
  // consistent.
  StructuralPlasticityNode::set_status(__d);

  // if we get here, temporaries contain consistent set of properties
  set_a(tmp_a);
  set_b(tmp_b);
  set_c(tmp_c);
  set_d(tmp_d);
  set_v(tmp_v);
  set_u(tmp_u);




  updateValue< double >(__d, nest::names::gsl_error_tol, P_.__gsl_error_tol);
  if ( P_.__gsl_error_tol <= 0. )
  {
    throw nest::BadProperty( "The gsl_error_tol must be strictly positive." );
  }

  // recompute internal variables in case they are dependent on parameters or state that might have been updated in this call to set_status()
  recompute_internal_variables();
};



#endif /* #ifndef IZHIKEVICH_TUTORIALAC9B74CB1232433994E7C5B9F2B63062_NESTML */
