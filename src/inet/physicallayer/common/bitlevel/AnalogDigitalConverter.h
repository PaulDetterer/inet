//
// Copyright (C) 2013 OpenSim Ltd.
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

#ifndef __INET_ANALOGDIGITALCONVERTER_H
#define __INET_ANALOGDIGITALCONVERTER_H

#include "inet/physicallayer/analogmodel/bitlevel/SignalAnalogModel.h"
#include "inet/physicallayer/common/bitlevel/SignalSampleModel.h"
#include "inet/physicallayer/contract/bitlevel/IAnalogDigitalConverter.h"

namespace inet {
namespace physicallayer {

class INET_API ScalarAnalogDigitalConverter : public IAnalogDigitalConverter
{
  protected:
    W power;
    // TODO: why centerFrequency and bandwidth here? why not in the shaper
    Hz centerFrequency;
    Hz bandwidth;
    double sampleRate;

  public:
    ScalarAnalogDigitalConverter();

    virtual const IReceptionSampleModel *convertAnalogToDigital(const IReceptionAnalogModel *analogModel) const override;
};

} // namespace physicallayer
} // namespace inet

#endif

