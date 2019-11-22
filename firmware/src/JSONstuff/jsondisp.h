/*
This Source Code Form is subject to the terms of the GNU General Public License v3.0.
If a copy of the GPL was not distributed with this
file, You can obtain one at https://www.gnu.org/licenses/gpl-3.0.html
Copyright (c) 2019 Panda Team
*/

#pragma once

#include <nlohmann/json.hpp>
#include "cmd.h"

class CJSONDispatcher : public CCmdCallHandler //just connect handler here
{
protected:
    std::shared_ptr<CCmdDispatcher> m_pDisp;

    //void CallPrimitive()

    /*!
     *  @brief: returns all possible settings (enumerates all "get" handlers)
     *
     *  @param jResp - a JSON object to fill with the settings
     *
     */
    void DumpAllSettings(nlohmann::json &jResp);

public:
    void Call(nlohmann::json &jObj, nlohmann::json &jResp, CCmdCallDescr::ctype ct);    //recursive

    virtual typeCRes Call(CCmdCallDescr &d);

    CJSONDispatcher(const std::shared_ptr<CCmdDispatcher> &pDisp)
    {
        m_pDisp=pDisp;
    }
};


/*#ifndef JSONDISP_H
#define JSONDISP_H

#endif // JSONDISP_H*/
