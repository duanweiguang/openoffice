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



#ifndef ADC_DISPLAY_HI_LINKHELPER_HXX
#define ADC_DISPLAY_HI_LINKHELPER_HXX


// USED SERVICES
    // BASE CLASSES               
    // COMPONENTS
    // PARAMETERS
#include "hi_ary.hxx"
#include "hi_env.hxx"
#include <toolkit/out_position.hxx>
#include <toolkit/out_tree.hxx>


class LinkHelper
{
  public:
    typedef ary::idl::CodeEntity                CE;
    typedef output::Position                    OutPosition;

                        LinkHelper(
                            HtmlEnvironment_Idl &
                                                io_rEnv )
                            :   rEnv(io_rEnv) {}

    OutPosition         PositionOf_CurModule() const
	                    { return OutPosition( rEnv.CurPosition(),
											  output::ModuleFileName()); }

    OutPosition         PositionOf_CurXRefs(
						    const String &      i_ceName) const;
    OutPosition         PositionOf_Index() const
	                    { OutPosition ret1 = rEnv.OutputTree().IndexRoot();
	                      return OutPosition( ret1, String(output::IndexFile_A()) ); }

                                        
    const ary::idl::Module *  
                        Search_CurModule() const;
    const ary::idl::Module *  
                        Search_Module(
                            output::Node &      i_node ) const;
                               
    const CE *          Search_CeFromType(
                            ary::idl::Type_id   i_type ) const;

    void                Get_Link2Position(
                            StreamStr &         o_link,
                            OutPosition &       i_pos ) const
                        { rEnv.CurPosition().Get_LinkTo(o_link, i_pos); }

    void                Get_Link2Member(
                            StreamStr &         o_link,
                            OutPosition &       i_ownerPos,
                            const String &      i_memberName ) const
                        { Get_Link2Position(o_link, i_ownerPos);
                          o_link << "#" << i_memberName; }     
    const String &      XrefsSuffix() const;                               
                          
  private:                                                     
    // DATA
    HtmlEnvironment_Idl & rEnv;
};     

inline const ary::idl::CodeEntity *          
LinkHelper::Search_CeFromType( ary::idl::Type_id i_type ) const
{ 
    ary::idl::Ce_id nCe = rEnv.Data().CeFromType(i_type);
    if (nCe.IsValid())
        return &rEnv.Data().Find_Ce(nCe);
    return 0;
}    



String              nameChainLinker( 
                        const char *        i_levelName );


#endif
