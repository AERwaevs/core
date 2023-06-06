#pragma once

#include <Core/Application.h>
#include <Core/Arguments.h>

namespace aer
{

//* To be defined in a client program, returning the client application----------------------------
extern Application* CreateApplication( Arguments args );

int EntryPoint( int argc, char** argv )
{
    auto    app = CreateApplication( { &argc, argv } );
            app->Run();
    delete  app;
    return  EXIT_SUCCESS;
}

}


int main( int argc, char** argv )
{
    return aer::EntryPoint( argc, argv );
}