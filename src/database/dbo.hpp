#ifndef _DBO_HPP_
#define _DBO_HPP_

#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>

namespace dbo = Wt::Dbo;

class database {
public:
    database();
    void run();

private:
    dbo::Session session;
};

#endif //_DBO_HPP_
