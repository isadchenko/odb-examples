// file      : template/database.hxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

//
// Create concrete database based on the DATABASE_* macros.
//

#include <string>
#include <memory>   // std::auto_ptr
#include <cstdlib>  // std::exit
#include <iostream>

#include <odb/database.hxx>

#if defined(DATABASE_MYSQL)
#  include <odb/mysql/database.hxx>
#endif

inline std::auto_ptr<odb::database>
create_database (int& argc, char* argv[])
{
  using namespace std;
  using namespace odb;

  if (argc > 1 && argv[1] == string ("--help"))
  {
    cerr << "Usage: " << argv[0] << " [options]" << endl
         << "Options:" << endl;

#if defined(DATABASE_MYSQL)
    mysql::database::print_usage (cerr);
#endif

    exit (0);
  }

#if defined(DATABASE_MYSQL)
  return auto_ptr<database> (new mysql::database (argc, argv));
#endif
}
