#ifndef _DBO_HPP_
#define _DBO_HPP_

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

#include "unit.hpp"

namespace dbo = Wt::Dbo;

class Database {
public:
    Database();
    void Init();
    dbo::ptr<Unit> GetUnit();

private:
    dbo::Session session;
};

#endif //_DBO_HPP_
