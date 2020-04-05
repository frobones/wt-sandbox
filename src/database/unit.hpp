#ifndef WT_TUTORIAL_UNIT_HPP
#define WT_TUTORIAL_UNIT_HPP

#include <Wt/Dbo/Dbo.h>

#include <string>

#include "unit_enum.hpp"

namespace dbo = Wt::Dbo;

class Unit {
public:
    std::string name_;
    Faction faction_;
    bool is_limited_;
    Rarity rarity_;
    Element element_;
    Job job_1_;
    Job job_2_;
    Job job_3_;

    std::string image_uri;

    template<class Action>
    void persist(Action &a) {
        dbo::field(a, name_, "name");
        dbo::field(a, faction_, "faction");
        dbo::field(a, is_limited_, "isLimited");
        dbo::field(a, rarity_, "rarity");
        dbo::field(a, element_, "element");
        dbo::field(a, job_1_, "job_1");
        dbo::field(a, job_2_, "job_2");
        dbo::field(a, job_3_, "job_3");
        dbo::field(a, image_uri, "image");
    }
};


#endif //WT_TUTORIAL_UNIT_HPP
