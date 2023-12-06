
/*
 *  nestml_e185671a259d41d699d13833724865c0_module.h
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
 *  2023-12-05 14:25:39.091322
 */

#ifndef NESTML_E185671A259D41D699D13833724865C0_MODULE_H
#define NESTML_E185671A259D41D699D13833724865C0_MODULE_H

#include "slimodule.h"
#include "slifunction.h"

#include "nest.h"
#include "nest_impl.h"


/**
* Class defining your model.
* @note For each model, you must define one such class, with a unique name.
*/
class nestml_e185671a259d41d699d13833724865c0_module : public SLIModule
{
public:
  // Interface functions ------------------------------------------

  /**
   * @note The constructor registers the module with the dynamic loader.
   *       Initialization proper is performed by the init() method.
   */
  nestml_e185671a259d41d699d13833724865c0_module();

  /**
   * @note The destructor does not do much in modules.
   */
  ~nestml_e185671a259d41d699d13833724865c0_module();

  /**
   * Initialize module by registering models with the network.
   * @param SLIInterpreter* SLI interpreter
   */
  void init( SLIInterpreter* );

  /**
   * Return the name of your model.
   */
  const std::string name() const;

public:
  // Classes implementing your functions -----------------------------

};

#endif