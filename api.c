#include "library.h"
#include "data.h"

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

Library lib = {0};

EXPORT void init_library()
{
    initLibrary(&lib);
    loadLibrary(&lib);
}

EXPORT void shutdown_library()
{
    saveLibrary(&lib);
    freeLibrary(&lib);
}

EXPORT int get_book_count()
{
    return lib.book_count;
}

EXPORT int get_member_count()
{
    return lib.member_count;
}

EXPORT int get_record_count()
{
    return lib.record_count;
}