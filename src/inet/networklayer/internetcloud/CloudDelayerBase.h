//
// Copyright (C) 2012 OpenSim Ltd.
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

#ifndef __INET_CLOUDDELAYERBASE_H
#define __INET_CLOUDDELAYERBASE_H

#include "inet/common/INETDefs.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/contract/INetfilter.h"

namespace inet {

//forward declarations:

class INET_API CloudDelayerBase : public cSimpleModule, public NetfilterBase::HookBase
{
  public:
    CloudDelayerBase();
    ~CloudDelayerBase();

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void finish() override;
    virtual void handleMessage(cMessage *msg) override;

    /**
     * Returns true in outDrop if the msg is dropped in cloud,
     * otherwise returns calculated delay in outDelay.
     */
    virtual void calculateDropAndDelay(const cMessage *msg, int srcID, int destID, bool& outDrop, simtime_t& outDelay);

    virtual INetfilter::IHook::Result datagramPreRoutingHook(Packet *datagram) override;
    virtual INetfilter::IHook::Result datagramForwardHook(Packet *datagram) override;
    virtual INetfilter::IHook::Result datagramPostRoutingHook(Packet *datagram) override;
    virtual INetfilter::IHook::Result datagramLocalInHook(Packet *datagram) override;
    virtual INetfilter::IHook::Result datagramLocalOutHook(Packet *datagram) override;

  protected:
    INetfilter *networkProtocol;
};

} // namespace inet

#endif

