//
// $Id$
//
//
// Original author: Matt Chambers <matt.chambers .@. vanderbilt.edu>
//
// Copyright 2008 Vanderbilt University - Nashville, TN 37232
//
// Licensed under the Apache License, Version 2.0 (the "License"); 
// you may not use this file except in compliance with the License. 
// You may obtain a copy of the License at 
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software 
// distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and 
// limitations under the License.
//

#ifndef _SERIALIZER_MGF_HPP_
#define _SERIALIZER_MGF_HPP_


#include "pwiz/utility/misc/Export.hpp"
#include "MSData.hpp"
#include "BinaryDataEncoder.hpp"
#include "pwiz/utility/misc/IterationListener.hpp"


namespace pwiz {
namespace msdata {


/// MSData <-> MGF stream serialization
class PWIZ_API_DECL Serializer_MGF
{
    public:

    /// constructor
    Serializer_MGF();

    /// write MSData object to ostream as MGF;
    /// iterationListenerRegistry may be used to receive progress updates
    void write(std::ostream& os, const MSData& msd,
               const pwiz::util::IterationListenerRegistry* iterationListenerRegistry = 0,
               bool useWorkerThreads = true, bool continueOnError = false) const;

    /// read in MSData object from an MGF istream 
    /// note: istream may be managed by MSData's SpectrumList, to allow for 
    /// lazy evaluation of Spectrum data
    void read(boost::shared_ptr<std::istream> is, MSData& msd) const;

    private:
    class Impl;
    boost::shared_ptr<Impl> impl_;
    Serializer_MGF(Serializer_MGF&);
    Serializer_MGF& operator=(Serializer_MGF&);
};


} // namespace msdata
} // namespace pwiz


#endif // _SERIALIZER_MGF_HPP_
