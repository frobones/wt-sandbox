/*
 * Copyright (C) 2010 Emweb bv, Herent, Belgium.
 *
 * See the LICENSE file for terms of use.
 */

/*****
 * This file is part of the Wt::Dbo tutorial:
 * http://www.webtoolkit.eu/wt/doc/tutorial/dbo/tutorial.html
 *****/

#include <string>

#include "dbo.hpp"
#include "unit.hpp"

/*****
 * Dbo tutorial section 2. Mapping a single class
 *****/

Database::Database() {
    /*****
     * Dbo tutorial section 2. A first session
     *****/

    /*
     * Setup a session, would typically be done once at application startup.
     *
     * For testing, we'll be using Sqlite2's special :memory: database. You
     * can replace this with an actual filename for actual persistence.
     */
    std::unique_ptr<dbo::backend::Sqlite3> sqlite3(new dbo::backend::Sqlite3(":memory:"));
    //sqlite2->setProperty("show-queries", "true");
    session.setConnection(std::move(sqlite3));

    session.mapClass<Unit>("unit");

    /*
     * Try to create the schema (will fail if already exists).
     */
    session.createTables();
}

void Database::Init() {
    {
        dbo::Transaction transaction(session);

        std::unique_ptr<Unit> unit{new Unit()};
        unit->name_ = "Mont Leonis";
        unit->faction_ = Faction::LEONIS;
        unit->is_limited_ = false;
        unit->rarity_ = Rarity::MR;
        unit->element_ = Element::EARTH;
        unit->job_1_ = Job::LORD;
        unit->job_2_ = Job::PALADIN;
        unit->job_3_ = Job::KNIGHT;
        unit->image_uri = "http://wotvffbe.gamea.co/file/imgbank/fm874m0k/426irsj7/e120d9b9def38020a4fdbcd1628e887d963b1da7_s.jpg";

        dbo::ptr<Unit> unit_ptr = session.add(std::move(unit));
    }
}

dbo::ptr<Unit> Database::GetUnit() {
    {
        dbo::Transaction transaction(session);
        return session.find<Unit>().where("name = ?").bind("Mont Leonis");
    }
}
