#include <Core/Arguments.h>
#include <Core/Application.h>

namespace AEON
{
    inline int EntryPoint( int argc, char** argv )
    {
        auto    app = CreateApplication( { &argc, argv } );
                app->Run();
        delete  app;
        return  EXIT_SUCCESS;
    }
}

//* Why does the win32 documentation insist this is how you start an application
//* when main() works just fine???
//
//#ifdef AEON_COMPILER_MSC
//
//int wWinMain( HINSTANCE hInst, HINSTANCE hInstPrev, PWSTR cmdline, int cmdshow )
//{
//    return AEON::EntryPoint( __argc, __argv );
//}
//
//#else

int main( int argc, char** argv )
{
    return AEON::EntryPoint( argc, argv );
}

//#endif