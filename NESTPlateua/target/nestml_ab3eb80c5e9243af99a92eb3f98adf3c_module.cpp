
/*
*  nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module.cpp
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
*  2023-12-06 08:02:12.900658
*/

// Includes from nestkernel:
#include "connection_manager_impl.h"
#include "connector_model_impl.h"
#include "dynamicloader.h"
#include "exceptions.h"
#include "genericmodel_impl.h"
#include "kernel_manager.h"
#include "model.h"
#include "model_manager_impl.h"
#include "nestmodule.h"
#include "target_identifier.h"

// Includes from sli:
#include "booldatum.h"
#include "integerdatum.h"
#include "sliexceptions.h"
#include "tokenarray.h"

// include headers with your own stuff
#include "nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module.h"


#include "iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml.h"


// -- Interface to dynamic module loader ---------------------------------------

/*
* There are three scenarios, in which MyModule can be loaded by NEST:
*
* 1) When loading your module with `Install`, the dynamic module loader must
* be able to find your module. You make the module known to the loader by
* defining an instance of your module class in global scope. (LTX_MODULE is
* defined) This instance must have the name
*
* <modulename>_LTX_mod
*
* The dynamicloader can then load modulename and search for symbol "mod" in it.
*
* 2) When you link the library dynamically with NEST during compilation, a new
* object has to be created. In the constructor the DynamicLoaderModule will
* register your module. (LINKED_MODULE is defined)
*
* 3) When you link the library statically with NEST during compilation, the
* registration will take place in the file `static_modules.h`, which is
* generated by cmake.
*/
#if defined(LTX_MODULE) | defined(LINKED_MODULE)
nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module_LTX_mod;
#endif

// -- DynModule functions ------------------------------------------------------

nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module::nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module()
{
#ifdef LINKED_MODULE
  // register this module at the dynamic loader
  // this is needed to allow for linking in this module at compile time
  // all registered modules will be initialized by the main app's dynamic loader
  nest::DynamicLoaderModule::registerLinkedModule( this );
#endif
}

nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module::~nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module()
{
}

const std::string
nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module::name() const
{
  return std::string("nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module"); // Return name of the module
}

//-------------------------------------------------------------------------------------
void
nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module::init( SLIInterpreter* i )
{
    // register neurons
    nest::kernel().model_manager.register_node_model<iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml>("iaf_psc_exp_active_dendrite_resettingab3eb80c5e9243af99a92eb3f98adf3c_nestml");
} // nestml_ab3eb80c5e9243af99a92eb3f98adf3c_module::init()