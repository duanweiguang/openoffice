/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef ARY_IDL_IT_BUILTIN_HXX
#define ARY_IDL_IT_BUILTIN_HXX

// BASE CLASSES
#include "it_named.hxx"




namespace ary
{
namespace idl
{


/** A type defined by the IDL language.
*/
class BuiltInType : public Named_Type
{
  public:
    enum E_ClassId { class_id = 2200 };

    // LIFECYCLE
                        BuiltInType(
                            const char *        i_sName );
    virtual             ~BuiltInType();

  private:
    // Interface csv::ConstProcessorClient:
    virtual void        do_Accept(
                            csv::ProcessorIfc & io_processor ) const;
    // Interface Object:
    virtual ClassId     get_AryClass() const;

    // Interface Type:
    virtual void        inq_Get_Text(
                            StringVector &      o_module,
                            String &            o_name,
                            Ce_id &             o_nRelatedCe,
                            int &               o_nSequenceCount,
                            const Gate &        i_rGate ) const;
};




}   // namespace idl
}   // namespace ary
#endif
