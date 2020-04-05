/*
 * Copyright (C) 2008 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

#include <Wt/WAnimation.h>
#include <Wt/WPanel.h>
#include <Wt/WText.h>

#include "database/dbo.hpp"
#include "database/unit.hpp"
#include "gui.hpp"
#include "helper.hpp"

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
HelloApplication::HelloApplication(const Wt::WEnvironment& env) : WApplication(env) {
    Database db;
    db.Init();

    dbo::ptr<Unit> unit = db.GetUnit();

    useStyleSheet(Wt::WLink("https://www.w3schools.com/w3css/4/w3.css"));

    root()->addWidget(helper::get_unit_frame(*unit.get()));
}
