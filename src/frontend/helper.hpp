//
// Created by frobones on 4/5/20.
//

#ifndef WT_TUTORIAL_HELPER_HPP
#define WT_TUTORIAL_HELPER_HPP

#include <Wt/WContainerWidget.h>

#include "database/unit.hpp"

class helper {
public:
    static std::unique_ptr<Wt::WContainerWidget> get_unit_frame(Unit unit);
};

#endif //WT_TUTORIAL_HELPER_HPP
