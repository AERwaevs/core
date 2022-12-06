#include <Core/Arguments.h>
#include <Core/Application.h>

//* To be defined in a client program, returning the client application----------------------------
extern AEON::Application* CreateApplication( AEON::Arguments args );

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

#ifdef AEON_PLATFORM_WINDOWS
#   include <windows.h>

//BOOL APIENTRY DllMain( HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved )
//{
//    return AEON::EntryPoint( __argc, __argv );
//}

#endif

#ifdef AEON_COMPILER_MSC

int WinMain( HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow )
{
    return AEON::EntryPoint( __argc, __argv );
}

#else

int main( int argc, char** argv )
{
    return AEON::EntryPoint( argc, argv );
}

#endif