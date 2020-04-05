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

database::database() {
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

void database::run() {
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
        unit->image_uri = "";

        dbo::ptr<Unit> unit_ptr = session.add(std::move(unit));
    }

    /*****
     * Dbo tutorial section 4. Querying objects
     *****/

    {
        dbo::Transaction transaction(session);

        dbo::ptr<Unit> unit = session.find<Unit>().where("name = ?").bind("Mont Leonis");

        fprintf(stderr, "%s element is: %d\n", unit->name_.c_str(), static_cast<int>(unit->element_));

        dbo::ptr<Unit> unit2 = session.query< dbo::ptr<Unit> >
                              ("select u from unit u").where("name = ?").bind("Mont Leonis");

        int count = session.query<int>("select count(1) from unit")
                .where("name = ?").bind("Mont Leonis");
    }

    {
        dbo::Transaction transaction(session);

        typedef dbo::collection< dbo::ptr<Unit> > Units;

        Units units = session.find<Unit>();

        fprintf(stderr, "We have %d users\n", static_cast<int>(units.size()));

        for (const dbo::ptr<Unit> &unit : units)
            fprintf(stderr, "Unit %s is element %d\n", unit->name_.c_str(), static_cast<int>(unit->element_));
    }

#if 0
    /*****
     * Dbo tutorial section 5. Updating objects
     *****/

    {
        dbo::Transaction transaction(session);

        dbo::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe");

        joe.modify()->karma++;
        joe.modify()->password = "public";
    }

    {
        dbo::Transaction transaction(session);
        dbo::ptr<User> joe = session.find<User>().where("name = ?").bind("Joe");
        if (joe)
            joe.remove();
    }

    {
        dbo::Transaction transaction(session);

        dbo::ptr<User> silly = session.add(std::unique_ptr<User>{new User()});
        silly.modify()->name = "Silly";
        silly.remove();
    }
#endif
}
