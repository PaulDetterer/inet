//
// Copyright (C) 2013 Opensim Ltd.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef __INET_MODULEOPERATIONS_H
#define __INET_MODULEOPERATIONS_H

#include "inet/common/lifecycle/LifecycleOperation.h"

namespace inet {

/**
 * This operation represents the process of turning on a module
 * after a stop or crash operation.
 *
 * The operation should be applied to the module of a network node. Operation
 * stages are organized bottom-up similarly to the OSI network layers.
 */
class INET_API ModuleStartOperation : public LifecycleOperation
{
  public:
    enum Stage {
        STAGE_LOCAL,    // for changes that don't depend on other modules
        STAGE_PHYSICAL_LAYER,
        STAGE_LINK_LAYER,
        STAGE_NETWORK_LAYER,
        STAGE_TRANSPORT_LAYER,
        STAGE_ROUTING_PROTOCOLS,
        STAGE_APPLICATION_LAYER,
        STAGE_LAST
    };

  public:
    virtual int getNumStages() const override { return STAGE_LAST + 1; }
};

/**
 * This operation represents the process of orderly stopping down a module.
 *
 * Operation stages are organized top-down similarly to the OSI network layers.
 */
class INET_API ModuleStopOperation : public LifecycleOperation
{
  public:
    enum Stage {
        STAGE_LOCAL,    // for changes that don't depend on other modules
        STAGE_APPLICATION_LAYER,
        STAGE_ROUTING_PROTOCOLS,
        STAGE_TRANSPORT_LAYER,
        STAGE_NETWORK_LAYER,
        STAGE_LINK_LAYER,
        STAGE_PHYSICAL_LAYER,
        STAGE_LAST    // for changes that others shouldn't depend on
    };

  public:
    virtual int getNumStages() const override { return STAGE_LAST + 1; }
};

/**
 * This operation represents the process of crashing a module. The
 * difference between this operation and ShutdownOperation is that the
 * module will not do a graceful shutdown (e.g. routing protocols will
 * not have chance of notifying peers about broken routes).
 *
 * The operation has only one stage, and the execution must finish in zero
 * simulation time.
 */
class INET_API ModuleCrashOperation : public LifecycleOperation
{
  public:
    enum Stage {
        STAGE_CRASH,    // the only stage, must execute within zero simulation time
        STAGE_LAST
    };

  public:
    virtual int getNumStages() const override { return STAGE_LAST + 1; }
};

} // namespace inet

#endif

