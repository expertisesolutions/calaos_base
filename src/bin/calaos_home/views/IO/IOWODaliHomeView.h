/******************************************************************************
 **  Copyright (c) 2007-2014, Calaos. All Rights Reserved.
 **
 **  This file is part of Calaos.
 **
 **  Calaos is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Calaos is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Foobar; if not, write to the Free Software
 **  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ******************************************************************************/
#ifndef IOWODALIHOMEVIEW_H
#define IOWODALIHOMEVIEW_H

#include <Utils.h>
#include <GenlistItemBase.h>


class IOWODaliHomeView: public GenlistItemBase, public IOBaseElement
{
private:
    virtual void ioDeleted();

    EdjeObject *slider;

    void sliderObjectDeleted();

    void sliderSignalCallback(void *data, Evas_Object *edje_object, std::string emission, std::string source);

public:
    IOWODaliHomeView(Evas *evas, Evas_Object *parent, IOBase *io, std::string style_addition, Elm_Genlist_Item_Type flags = ELM_GENLIST_ITEM_NONE);
    virtual ~IOWODaliHomeView();

    virtual Evas_Object *getPartItem(Evas_Object *obj, std::string part);
    virtual std::string getLabelItem(Evas_Object *obj, std::string part);

    //Called when the real IO changed
    virtual void initView();
    virtual void updateView();

    void buttonClickOn();
    void buttonClickOff();
    void buttonClickMore();
    void buttonClickLess();
};

#endif // IOWODALIHOMEVIEW_H
