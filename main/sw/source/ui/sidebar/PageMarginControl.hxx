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

#ifndef _SW_SIDEBAR_PAGE_MARGIN_CONTROL_HXX_
#define _SW_SIDEBAR_PAGE_MARGIN_CONTROL_HXX_

#include <svx/sidebar/PopupControl.hxx>

#include <tools/fldunit.hxx>
#include <svl/poolitem.hxx>
#include <unotools/viewoptions.hxx>

#include <vector>

#define SWPAGE_NARROW_VALUE    720
#define SWPAGE_NORMAL_VALUE    1136
#define SWPAGE_WIDE_VALUE1     1440
#define SWPAGE_WIDE_VALUE2	   2880
#define SWPAGE_WIDE_VALUE3	   1800


namespace svx { namespace sidebar {
    class ValueSetWithTextControl;
} }

static const long MINBODY = 284; //0.5 cm in twips

namespace sw { namespace sidebar {

class PagePropertyPanel;


class PageMarginControl
    : public ::svx::sidebar::PopupControl
{
public:
    PageMarginControl(
        Window* pParent,
        PagePropertyPanel& rPanel,
        const SvxLongLRSpaceItem& aPageLRMargin,
        const SvxLongULSpaceItem& aPageULMargin,
        const bool bMirrored,
        const Size aPageSize,
        const sal_Bool bLandscape,
        const FieldUnit eFUnit,
        const SfxMapUnit eUnit );
    ~PageMarginControl(void);

private:
    ::svx::sidebar::ValueSetWithTextControl* mpMarginValueSet;

    FixedText maCustom;
    FixedText maLeft;
    FixedText maInner;
    MetricField maLeftMarginEdit;
    FixedText maRight;
    FixedText maOuter;
    MetricField maRightMarginEdit;
    FixedText maTop;
    MetricField maTopMarginEdit;
    FixedText maBottom;
    MetricField maBottomMarginEdit;

    // hidden metric field
    MetricField maWidthHeightField;

    long mnPageLeftMargin;
    long mnPageRightMargin;
    long mnPageTopMargin;
    long mnPageBottomMargin;
    bool mbMirrored;

    const SfxMapUnit meUnit;

    long mnUserCustomPageLeftMargin;
    long mnUserCustomPageRightMargin;
    long mnUserCustomPageTopMargin;
    long mnUserCustomPageBottomMargin;
    bool mbUserCustomMirrored;

    bool mbCustomValuesUsed;

    PagePropertyPanel& mrPagePropPanel;

    DECL_LINK( ImplMarginHdl, void* );
    DECL_LINK( ModifyLRMarginHdl, MetricField* );
    DECL_LINK( ModifyULMarginHdl, MetricField* );

    void SetMetricFieldMaxValues( const Size aPageSize );

    bool GetUserCustomValues();
    void StoreUserCustomValues();

    void FillValueSet(
        const bool bLandscape,
        const bool bUserCustomValuesAvailable );
    void SelectValueSetItem();
};

} } // end of namespace sw::sidebar

#endif
